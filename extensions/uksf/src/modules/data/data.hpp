#pragma once

#define COMPONENT data

#include "../common_component.hpp"

#include <future>

#define ENABLED_DEFAULT true
#define FREQUENCY_DEFAULT 10

using namespace nlohmann;
using namespace Poco::Net;

class uksf_data : public singleton<uksf_data> {
public:
    uksf_data();

    void getData() const;

private:
    bool _enabled = ENABLED_DEFAULT;
    int _frequency = ENABLED_DEFAULT;
    clock_t _delta = 0;

    std::string _serverName;
    std::string _mapName;
    std::string _missionName;
};
