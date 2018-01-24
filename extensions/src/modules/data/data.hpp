#pragma once
#include "component.hpp"

#include <cpprest/http_client.h>

using namespace web;
using namespace utility;
using namespace http::client;

class uksf_data : public singleton<uksf_data> {
public:
    uksf_data();

    void getData() const;
    static void sendData(json::value json);

private:
    bool _enabled = ENABLED_DEFAULT;
    int _frequency = ENABLED_DEFAULT;
    clock_t _delta = 0;
};
