#include "ProcedureEngine.h"
#include "IProcedure.h"
#include "ClientMessage.h"
#include <thread>
#include "../Procedures/Shutdown.h"

void ProcedureEngine::initialize() {
	this->addProcedure(new ProcShutdown());
}

void ProcedureEngine::addProcedure(IProcedure* cmd) {
	this->m_Procedures.insert(std::pair<CLIENT_MESSAGE_TYPE, IProcedure*>(cmd->getType(), cmd));
}

void ProcedureEngine::removeProcedure(IProcedure* cmd) {
	this->m_Procedures.erase(cmd->getType());
}

void ProcedureEngine::removeProcedure(const CLIENT_MESSAGE_TYPE cmd) {
	this->m_Procedures.erase(cmd);
}

IProcedure* ProcedureEngine::findProcedure(const CLIENT_MESSAGE_TYPE cmd) {
	const auto it = this->m_Procedures.find(cmd);
	if (it != this->m_Procedures.end()) {
		return static_cast<IProcedure*>(it->second);
	}
	return nullptr;
}

void ProcedureEngine::runProcedure(const ClientMessage message) {
	logMessage("Procedure: run procedure tid: %u", std::this_thread::get_id());
	if (message.getType() == CLIENT_MESSAGE_TYPE::EMPTY_PROCEDURE) {
		return;
	}

	IProcedure* function = this->findProcedure(message.getType());
	if (function) {
		function->call(message);
	}
}
