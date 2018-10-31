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
    std::string arg_line = GetCommandLineA();
    std::transform(arg_line.begin(), arg_line.end(), arg_line.begin(), ::tolower);

    auto portIterator = arg_line.find("-apiport"sv);
    if (portIterator != std::string::npos) {
        auto port_start = portIterator + 8;
        port_start = arg_line.find_first_not_of("=\"", port_start);
        size_t port_end = arg_line.find("\"", port_start);
        std::string port = arg_line.substr(port_start, port_end - port_start);

        server = new Poco::Net::HTTPServer(routeFactory, Poco::Net::ServerSocket(atoi(port.c_str())), new Poco::Net::HTTPServerParams);
    } else {
        server = new Poco::Net::HTTPServer(routeFactory, Poco::Net::ServerSocket(6000), new Poco::Net::HTTPServerParams);
    }
    server->start();
}

uksf_http::~uksf_http() {
    server->stop();
    server = nullptr;
    stopThread();
}
