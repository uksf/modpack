#include "http.hpp"
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

uksf_http::uksf_http() {
    uksf::getInstance().postStart.connect([this]() {
        LOG_DEBUG("HTTP POSTSTART");
        if (sqf::is_server()) {
            startThread();
        }
    });

    uksf::getInstance().preInit.connect([this]() {
        LOG_DEBUG("HTTP PREINIT");
    });

    uksf::getInstance().postInit.connect([this]() {
        LOG_DEBUG("HTTP POSTINIT");
    });

    uksf::getInstance().missionEnded.connect([this]() {
        LOG_DEBUG("HTTP MISSION ENDED");
    });
}

void uksf_http::initThread() {
    initOnly = true;
    routeFactory = new router();
    if (server != nullptr) {
        server->stop();
    }
    server = new Poco::Net::HTTPServer(routeFactory, Poco::Net::ServerSocket(6000), new Poco::Net::HTTPServerParams);
    server->start();
}

uksf_http::~uksf_http() {
    server->stop();
    server = nullptr;
    stopThread();
}
