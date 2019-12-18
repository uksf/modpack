#include "SignalrClient.h"
#include "ClientMessage.h"
#include "ServerMessage.h"
#include "../UKSF.hpp"
#include <future>
#include <hub_connection_builder.h>

void SignalrClient::initialize(const std::string url) {
	logMessage("Signalr: Initialising");
	this->setNewState(CONNECTION_STATE::DISCONNECTED);

	this->m_connection = std::make_shared<signalr::hub_connection>(signalr::hub_connection_builder::create(url)
																   .with_logging(std::make_shared <logger>(), signalr::trace_level::errors)
																   .build());

	this->m_connection->on("Receive", [](const signalr::value& value) {
		logMessage("Signalr: received message tid: %u", std::this_thread::get_id());
		const auto procedure = static_cast<CLIENT_MESSAGE_TYPE>(static_cast<int>(value.as_array()[0].as_double()));
		const std::map<std::string, signalr::value> args = value.as_array()[1].as_map();
		UKSF::getInstance()->addToReceiveQueue(ClientMessage(procedure, args));
	});

	logMessage("Signalr: Initialization complete");
}

void SignalrClient::connect() {
	if (this->getState() == CONNECTION_STATE::DISCONNECTING) return;
	logMessage("Signalr: Connecting");
	this->setNewState(CONNECTION_STATE::CONNECTING);

	this->m_connection->start([this](const std::exception_ptr exception) {
		if (exception) {
			try {
				std::rethrow_exception(exception);
			} catch (const std::exception & ex) {
				logMessage("Signalr: Failed to connect: %s", ex.what());
				this->setNewState(CONNECTION_STATE::DISCONNECTED);
			}
		} else {
			logMessage("Signalr: Connected");
			this->setNewState(CONNECTION_STATE::CONNECTED);
			/*Engine::getInstance()->addToFunctionQueue([]() {
				Data::getInstance()->populateClientMaps();
			});*/
		}
	});
}

void SignalrClient::updateConnectionState() {
	if (this->m_connection == nullptr) return;
	if (this->m_connection->get_connection_state() == signalr::connection_state::disconnected) {
		this->setNewState(CONNECTION_STATE::DISCONNECTED);
	}
}

void SignalrClient::disconnect() {
	if (this->getState() == CONNECTION_STATE::DISCONNECTED || this->getState() == CONNECTION_STATE::DISCONNECTING) return;
	logMessage("Signalr: Disconnecting");
	this->setNewState(CONNECTION_STATE::DISCONNECTING);

	std::promise<void> task;
	if (this->m_connection && this->m_connection->get_connection_state() != signalr::connection_state::disconnected) {
		this->m_connection->stop([this, &task](const std::exception_ptr exception) {
			try {
				if (exception) {
					std::rethrow_exception(exception);
				}

				logMessage("Signalr: Disconnected");
			} catch (const std::exception & e) {
				logMessage("Signalr: Failed to disconnect: %s", e.what());
			}
			this->m_connection = nullptr;
			task.set_value();
		});
	} else {
		logMessage("Signalr: Already disconnected");
		this->m_connection = nullptr;
		task.set_value();
	}
	task.get_future().get();
	this->setNewState(CONNECTION_STATE::DISCONNECTED);
}

CONNECTION_STATE SignalrClient::getState() const {
	return this->m_state;
}

void SignalrClient::setNewState(const CONNECTION_STATE state) {
	{
		std::lock_guard<std::mutex> lock(m_lockable_mutex);
		this->m_state = state;
	}
}

void SignalrClient::sendMessage(const ServerMessage message) const {
	if (message.getType() == SERVER_MESSAGE_TYPE::EMPTY_EVENT) return;
	logMessage("Signalr: Send message tid: %u", std::this_thread::get_id());
	const std::vector<signalr::value> arr{ static_cast<double>(message.getType()), message.getValue() };
	const signalr::value args(arr);

	if (this->m_connection) {
		this->m_connection->invoke("Invoke", args, [](const signalr::value& value, const std::exception_ptr exception) {
			try {
				if (exception) {
					std::rethrow_exception(exception);
				}

				if (value.is_string()) {
					logMessage("Signalr: Invoke returned: %s", value.as_string().c_str());
				}
			} catch (const std::exception & e) {
				logMessage("Signalr: Error while sending data: %s", e.what());
			}
		});
	}
}
