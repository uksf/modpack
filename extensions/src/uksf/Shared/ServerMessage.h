#pragma once

#include "Shared.hpp"
#include <signalr_value.h>

class ServerMessage {
public:
	ServerMessage(SERVER_MESSAGE_TYPE procedureType, signalr::value args);
	ServerMessage() = default;
	~ServerMessage() = default;

    SERVER_MESSAGE_TYPE getType() const;
    signalr::value getValue() const;

private:
	SERVER_MESSAGE_TYPE m_ProcedureType;
	signalr::value m_Args;
};