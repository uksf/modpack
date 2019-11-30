#include "UKSF.hpp"

#include "Modules/Common/Common.hpp"
#include "Shared/SignalrClient.h"
#include "Shared/ProcedureEngine.h"
#include "Shared/ClientMessage.h"
#include "Shared/ServerMessage.h"
#include "Modules/Server/Server.h"

#include <shellapi.h>

// ReSharper disable CppInconsistentNaming
void __cdecl intercept::pre_start() {
	logMessage("MAIN PRESTART");
	UKSF::getInstance()->preStart();
}
void __cdecl intercept::post_start() {
	logMessage("MAIN POSTSTART");
	UKSF::getInstance()->postStart();
}

void __cdecl intercept::pre_init() {
	logMessage("MAIN PREINIT");
	UKSF::getInstance()->preInit();
}

void __cdecl intercept::post_init() {
	logMessage("MAIN POSTINIT");
	UKSF::getInstance()->postInit();
}

void __cdecl intercept::on_frame() {
	UKSF::getInstance()->onFrame();
}

void __cdecl intercept::mission_ended() {
	logMessage("MAIN MISSION ENDED");
	UKSF::getInstance()->missionEnded();
}
// ReSharper restore CppInconsistentNaming

UKSF::UKSF() {
	this->preStart.connect([this]() {
		this->initialize();
	});
}

UKSF::~UKSF() {
	try {
		this->stop();
	} catch (...) {

	}
}

void UKSF::initialize() {
	this->isClient = sqf::has_interface();
	this->isDedicated = sqf::is_dedicated();
	logMessage("Client: %s, Dedicated: %s", this->isClient ? "true" : "false", this->isDedicated ? "true" : "false");

    const std::string args = GetCommandLineA();
	const auto nameIterator = args.find("-name"sv);
	if (nameIterator != std::string::npos) {
		auto nameStart = nameIterator + 5;
		nameStart = args.find_first_not_of('=', nameStart);
		const size_t nameEnd = args.find(' ', nameStart);
		this->name = args.substr(nameStart, nameEnd - nameStart);
		logMessage("Name '%s'", this->name.c_str());
	}

	const auto portIterator = args.find("-port"sv);
	if (portIterator != std::string::npos) {
		auto portStart = portIterator + 5;
		portStart = args.find_first_not_of('=', portStart);
		const size_t portEnd = args.find(' ', portStart);
		this->port = args.substr(portStart, portEnd - portStart);
		logMessage("Port '%s'", this->port.c_str());
	}

	if (this->name.empty()) {
		logMessage("Name is empty. Stopping");
		std::exit(1);
	}

	if (this->port.empty()) {
		logMessage("Port is empty. Stopping");
		std::exit(1);
	}

	this->clearQueues();

	// TODO: Integrate autorization before allowing clients to connect
	// Best approach is to use launcher arguments to attach the token (not credentials) to the arguments and read here
	// Could double up as a method to only allow UKSF members to run UKSF mods (force exit if not authorized, but only if api reachable)
	// Definitely kick off UKSF server if not authorized
	/*if (sqf::has_interface()) {
		this->preInit.connect([this]() {
			if (sqf::is_multiplayer()) {
				this->start();
			}
		});
	}*/

	Common::getInstance();
	ProcedureEngine::getInstance()->initialize();

	std::string url = this->getUrlString();
	SignalrClient::getInstance()->initialize(url);

	Server::getInstance();

	this->onFrame.connect([this]() {
		if (!this->m_functionQueue.empty()) {
			logMessage("Engine: Running function");
			std::function<void()> function;
			if (this->m_functionQueue.try_pop(function)) {
				function();
			}
		}
	});


	if (this->isDedicated) {
		this->start();
	}
}

void UKSF::start() {
	logMessage("Engine: Starting");
	this->clearQueues();
	this->m_stopRequested = false;
	this->m_workerThread = std::thread(&UKSF::doWork, this);
	this->setNewState(STATE::RUNNING);
	logMessage("Engine: Started");
}

void UKSF::stop() {
	if (this->getState() == STATE::STOPPED || this->getState() == STATE::STOPPING) return;
	logMessage("Engine: Stopping");
	this->m_stopRequested = true;

	while (SignalrClient::getInstance()->getState() != CONNECTION_STATE::DISCONNECTED) {
		Sleep(10);
	}

	this->setNewState(STATE::STOPPING);
	if (this->m_workerThread.joinable()) {
		this->m_workerThread.join();
	}

	this->clearQueues();
	this->setNewState(STATE::STOPPED);
	logMessage("Engine: Stopped");
}

STATE UKSF::getState() const {
	return this->m_state;
}

std::string UKSF::getUrlString() {
	std::stringstream url;
	if (this->isClient) {
		const auto playerUID = sqf::get_player_uid(sqf::player());
		//url << "https://api.uk-sf.co.uk/hub/gameclient?uid=" << playerUID;
		url << "http://localhost:5000/hub/gameclient?uid=" << playerUID;
	} else {
		url << "http://localhost:5000/hub/gameserver?port=" << this->port << "&type=" << (this->isDedicated ? "0" : "1") << "&name=" << this->name;
	}

	return url.str();
}

void UKSF::setNewState(const STATE state) {
	{
		std::lock_guard<std::mutex> lock(m_lockable_mutex);
		this->m_state = state;
	}
}

void UKSF::clearQueues() {
	{
		std::lock_guard<std::mutex> lock(m_lockable_mutex);
		this->m_gameFunctionQueue.clear();
		this->m_functionQueue.clear();
		this->m_sendQueue.clear();
		this->m_receiveQueue.clear();
	}
}

void UKSF::doWork() {
	while (this->getState() == STATE::RUNNING) {
		SignalrClient::getInstance()->updateConnectionState();
		const auto signalrState = SignalrClient::getInstance()->getState();

		if (this->m_stopRequested) {
			if (signalrState == CONNECTION_STATE::CONNECTED) {
				logMessage("Engine: Running stop request");
				SignalrClient::getInstance()->disconnect();
			}
		} else {
			// If disconnected
			if (signalrState == CONNECTION_STATE::DISCONNECTED && signalrState != CONNECTION_STATE::CONNECTING) {
				// Connect
				logMessage("Engine: Not connected");
				SignalrClient::getInstance()->connect();
			}

			// Run queued functions (all)
			while (!this->m_functionQueue.empty()) {
				logMessage("Engine: Running function");
				std::function<void()> function;
				if (this->m_functionQueue.try_pop(function)) {
					function();
				}
			}

			// If connected
			if (signalrState == CONNECTION_STATE::CONNECTED) {
				// Send to signalr (x1)
				if (!this->m_sendQueue.empty()) {
					ServerMessage message;
					if (this->m_sendQueue.try_pop(message)) {
						SignalrClient::getInstance()->sendMessage(message);
					}
				}

				// Run received from signalr (x1)
				if (!this->m_receiveQueue.empty()) {
					ClientMessage message;
					if (this->m_receiveQueue.try_pop(message)) {
						ProcedureEngine::getInstance()->runProcedure(message);
					}
				}

				this->threadTick();
			}
		}

		// Sleep 1ms
		Sleep(1);
	}
}

void UKSF::addToGameFunctionQueue(const std::function<void()> function) {
	this->m_gameFunctionQueue.push(function);
}

void UKSF::addToFunctionQueue(const std::function<void()> function) {
	this->m_functionQueue.push(function);
}

void UKSF::addToSendQueue(const ServerMessage message) {
	this->m_sendQueue.push(message);
}

void UKSF::addToReceiveQueue(const ClientMessage message) {
	this->m_receiveQueue.push(message);
}
