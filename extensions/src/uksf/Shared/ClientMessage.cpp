#include "ClientMessage.h"
#include <string>

ClientMessage::ClientMessage(const CLIENT_MESSAGE_TYPE procedureType, const std::map<std::string, signalr::value> args) {
	this->m_ProcedureType = procedureType;
	this->m_Parameters = args;
}

signalr::value ClientMessage::getParameter(const std::string key) {
	if (this->m_Parameters.contains(key)) {
		return this->m_Parameters[key];
	}
	return "";
}

CLIENT_MESSAGE_TYPE ClientMessage::getType() const {
	return this->m_ProcedureType;
}
