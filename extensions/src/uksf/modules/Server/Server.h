#pragma once

#include "../SharedComponent.hpp"

class Server : public Singleton<Server> {
public:
	Server();

private:
	clock_t lastMissionTime = -1;

    void sendUpdate();
    void addBasicInformation(std::map<std::string, signalr::value>& dataMap);
};
