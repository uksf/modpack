#include "ServerMessage.h"

ServerMessage::ServerMessage(const SERVER_MESSAGE_TYPE procedureType, const signalr::value args) {
	this->m_ProcedureType = procedureType;
	this->m_Args = args;
}

SERVER_MESSAGE_TYPE ServerMessage::getType() const {
	return this->m_ProcedureType;
}

signalr::value ServerMessage::getValue() const {
	return this->m_Args;
}
