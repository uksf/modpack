#include "server.hpp"
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include "../../../modules/common_component.hpp"

namespace resources {
    server::server() = default;
    server::~server() = default;

    void server::handle_get(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        try {
            std::string serverName = sqf::server_name();
            handleHttpStatusCode(200, response);
            std::ostream& outputStream = response.send();

            Poco::DynamicStruct jsonData;
            jsonData.insert("servername", serverName);
            outputStream << jsonData.toString();
            outputStream.flush();
        } catch (exception& exception) {
            handleHttpStatusCode(exception.code(), response);
            std::ostream& outputStream = response.send();
            outputStream << toJson(exception);
        }
    }

    void server::handle_options(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        response.set("Allow", "GET, OPTIONS");
        response.setContentType("text/plain; charset=utf-8");

        handleHttpStatusCode(200, response);
        std::ostream& outputStream = response.send();
        outputStream.flush();
    }
}
