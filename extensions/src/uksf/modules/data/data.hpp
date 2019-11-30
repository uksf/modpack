#pragma once

#define COMPONENT data

#include "../SharedComponent.hpp"
//
//#define ENABLED_DEFAULT true
//#define FREQUENCY_DEFAULT 10
//
//using namespace nlohmann;
//
//class uksf_data : public singleton<uksf_data>, public threaded<uksf_data> {
//public:
//    uksf_data();
//
//    void function() override;
//    void getData() const;
//    static void sendData(const json::string_t& jsonString);
//
//private:
//    bool _enabled = ENABLED_DEFAULT;
//    int _frequency = ENABLED_DEFAULT;
//    double _delta = 0;
//    clock_t _currentTime = clock();
//    clock_t _previousTime = _currentTime;
//
//    std::string _serverName;
//    std::string _mapName;
//    std::string _missionName;
//};
