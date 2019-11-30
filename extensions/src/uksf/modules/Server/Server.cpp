#include "Server.h"
#include <signalr_value.h>
#include "../../Shared/ServerMessage.h"

constexpr auto interval = 5;

Server::Server() {
	if (!UKSF::getInstance()->isDedicated && UKSF::getInstance()->isClient) return;
	this->lastMissionTime = clock();

	UKSF::getInstance()->postStart.connect([]() {
		logMessage("SERVER POSTSTART");
	});

	UKSF::getInstance()->preInit.connect([]() {
		logMessage("SERVER PREINIT");
	});

	UKSF::getInstance()->postInit.connect([]() {
		logMessage("SERVER POSTINIT");
	});

	UKSF::getInstance()->threadTick.connect([this]() {
		this->sendUpdate();
	});
}

void Server::sendUpdate() {
    /*const auto missionTime = sqf::get_variable(sqf::mission_namespace(), "CBA_missionTime", 0).operator int();
	if (missionTime < lastMissionTime + 10) return;
	this->lastMissionTime = missionTime;*/
    const auto difference = (clock() - this->lastMissionTime) / CLOCKS_PER_SEC;
	if (difference < interval) return;
	this->lastMissionTime = clock();

	std::map<std::string, signalr::value> dataMap;
	this->addBasicInformation(dataMap);

	if (UKSF::getInstance()->isDedicated) {
		const std::string serverName = sqf::server_name();
		if (!serverName.empty()) {
			const std::string map = sqf::world_name();
			const std::string mission = sqf::mission_name();
			const auto allPlayers = sqf::all_players();
			const size_t hc = sqf::entities("HeadlessClient_F").size();
			const auto playerCount = allPlayers.size() - hc;

			std::map<std::string, signalr::value> playersMap;
			for (const auto& player : allPlayers) {
				std::map<std::string, signalr::value> playerMap;
				auto playerUID = sqf::get_player_uid(player);
				auto playerName = sqf::name(player);

				playerMap.insert(std::pair<std::string, signalr::value>("playerName", signalr::value(playerName)));
				playersMap.insert(std::pair<std::string, signalr::value>(playerUID, signalr::value(playerMap)));
			}
			dataMap.insert(std::pair<std::string, signalr::value>("map", signalr::value(map)));
			dataMap.insert(std::pair<std::string, signalr::value>("mission", signalr::value(mission)));
			dataMap.insert(std::pair<std::string, signalr::value>("playerCount", signalr::value(double(playerCount))));
			dataMap.insert(std::pair<std::string, signalr::value>("playersMap", signalr::value(playersMap)));
		}
	}

	UKSF::getInstance()->addToSendQueue(ServerMessage(SERVER_MESSAGE_TYPE::SERVER_INFO, signalr::value(dataMap)));
}

void Server::addBasicInformation(std::map<std::string, signalr::value>& dataMap) {
	logMessage("Server update Port '%s', Name '%s'", UKSF::getInstance()->port.c_str(), UKSF::getInstance()->name.c_str());
    const char* port = UKSF::getInstance()->port.c_str();
	const char* name = UKSF::getInstance()->name.c_str();
	dataMap.insert(std::pair<std::string, signalr::value>("timestamp", signalr::value(getTimeStamp())));
	dataMap.insert(std::pair<std::string, signalr::value>("port", signalr::value(port)));
	dataMap.insert(std::pair<std::string, signalr::value>("type", signalr::value(double(UKSF::getInstance()->isDedicated ? 0 : 1))));
	dataMap.insert(std::pair<std::string, signalr::value>("name", signalr::value(name)));
	dataMap.insert(std::pair<std::string, signalr::value>("processId", signalr::value(double(GetCurrentProcessId()))));
	dataMap.insert(std::pair<std::string, signalr::value>("state", signalr::value(sqf::get_client_state_number())));
	dataMap.insert(std::pair<std::string, signalr::value>("uptime", signalr::value(float(clock()))));
	dataMap.insert(std::pair<std::string, signalr::value>("missionUptime", signalr::value(sqf::time())));
}
