#pragma once
#include "component.hpp"

#include <cpprest/http_client.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest_2_10")

using namespace web;
using namespace http;
using namespace http::client;

class uksf_data : public singleton<uksf_data> {
public:
    uksf_data();

    void getData() const;
    void sendData(std::string json);

private:
    bool _enabled = ENABLED_DEFAULT;
    int _frequency = ENABLED_DEFAULT;
    clock_t _delta = 0;
};
