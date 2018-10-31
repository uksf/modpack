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
            handleHttpStatusCode(200, response);
            std::ostream& outputStream = response.send();
            Poco::DynamicStruct jsonData;
            std::string serverName = sqf::server_name();
            if (serverName != "") {
                std::string map = sqf::world_name();
                std::string mission = sqf::mission_name();
                float uptime = sqf::time();
                size_t players = sqf::all_players().size();
                size_t maxPlayers = sqf::playable_units().size();

                jsonData.insert("map", map);
                jsonData.insert("mission", mission);
                jsonData.insert("uptime", uptime);
                jsonData.insert("players", players);
                jsonData.insert("maxPlayers", maxPlayers);
            }
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
