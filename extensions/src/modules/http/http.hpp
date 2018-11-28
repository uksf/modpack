#pragma once

#define COMPONENT http

#include "../common_component.hpp"

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServer.h>
#include "../../network/router.hpp"

class uksf_http : public singleton<uksf_http>, public threaded<uksf_http>, public Poco::Util::ServerApplication {
public:
    uksf_http();
    ~uksf_http();

    void initThread() override;
private:
    Poco::Net::HTTPServer* server;
    Poco::Net::HTTPRequestHandlerFactory* routeFactory;
};
