#pragma once

#include "Lockable.h"
#include "Singleton.hpp"
#include "ServerMessage.h"
#include <concurrent_queue.h>
#include <log_writer.h>
#include <hub_connection.h>

class logger final : public signalr::log_writer {
	void __cdecl write(const std::string& entry) override {
		logMessage(entry.c_str());
	}
};

class SignalrClient final : public Singleton<SignalrClient>, public Lockable {
public:
	SignalrClient() = default;
	~SignalrClient() = default;

	void initialize(std::string url);
	void disconnect();
	void connect();
	void updateConnectionState();

	[[nodiscard]] CONNECTION_STATE getState() const;

	void sendMessage(ServerMessage message) const;

private:
	std::shared_ptr<signalr::hub_connection> m_connection;
	CONNECTION_STATE m_state = CONNECTION_STATE::DISCONNECTED;

	void setNewState(CONNECTION_STATE state);
};
