#pragma once
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <random>

#include "Date.h"
using namespace date;

#include "intercept.hpp"
using namespace intercept;

#include "Logging.hpp"

#define INVOKER_LOCK client::invoker_lock lock

class IProcedure;

enum class STATE {
	STOPPED,
	RUNNING,
	STOPPING
};

enum class CONNECTION_STATE {
	DISCONNECTED,
	DISCONNECTING,
	CONNECTING,
	CONNECTED
};

enum class SERVER_MESSAGE_TYPE {
	EMPTY_EVENT,
	UPDATE_SERVER_STATUS,
	REMOVE_SERVER_STATUS,
    SAFE_SHUTDOWN
};

enum class CLIENT_MESSAGE_TYPE {
	EMPTY_PROCEDURE,
	SHUTDOWN,
	SERVER_INFO
};

namespace {
	std::mt19937 reng = std::mt19937(static_cast<unsigned int>(time(nullptr)));

	std::string getTimeStamp() {
		const auto now = std::chrono::system_clock::now();
		const auto today = date::floor<days>(now);
		std::stringstream ss;
		ss << today << ' ' << make_time(now - today);
		return ss.str();
	}

	void logMessage(char const* format, ...) {
		char message[1024];
		va_list args;
		va_start(args, format);
		vsnprintf(message, sizeof message, format, args);
		LOG(INFO, message);
		va_end(args);
	}
}

//std::string arg_line = GetCommandLineA();
//std::transform(arg_line.begin(), arg_line.end(), arg_line.begin(), ::tolower);
//
//auto portIterator = arg_line.find("-apiport"sv);
//if (portIterator != std::string::npos) {
//	auto port_start = portIterator + 8;
//	port_start = arg_line.find_first_not_of("=\"", port_start);
//	size_t port_end = arg_line.find("\"", port_start);
//	std::string port = arg_line.substr(port_start, port_end - port_start);
