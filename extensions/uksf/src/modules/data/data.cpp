#pragma once
#include "data.hpp"
#include "secret.hpp"

uksf_data::uksf_data() {
    uksf::getInstance().preInit.connect([this]() {
        LOG_DEBUG("DATA PREINIT");
        game_value enabledArgs({
            QGVAR(enabled),
            "CHECKBOX",
            "Data System",
            "UKSF",
            ENABLED_DEFAULT,
            true
        });
        sqf::call(uksf_common::cbaSettingsFncInit, enabledArgs);
        game_value frequencyArgs({
            QGVAR(frequency),
            "SLIDER",
            "Data System Frequency",
            "UKSF",
            {5, 60, FREQUENCY_DEFAULT, 0},
            true
        });
        sqf::call(uksf_common::cbaSettingsFncInit, frequencyArgs);
    });

    uksf::getInstance().postInit.connect([this]() {
        LOG_DEBUG("DATA POSTINIT");
        _enabled = sqf::get_variable(sqf::mission_namespace(), QGVAR(enabled), ENABLED_DEFAULT);
        _frequency = sqf::get_variable(sqf::mission_namespace(), QGVAR(frequency), FREQUENCY_DEFAULT);

        if (_enabled && sqf::is_server()) {
            LOG(INFO) << "Data system is enabled";
            _serverName = sqf::server_name();
            _mapName = sqf::world_name();
            _missionName = sqf::mission_name();
        } else {
            LOG(INFO) << "Data system is disabled";
        }
    });

    uksf::getInstance().onFrame.connect([this]() {
        if (_enabled && uksf_common::threadRun && clock() > _delta) {
            _delta += _frequency * CLOCKS_PER_SEC;
            getData();
        }
    });

    uksf::getInstance().missionEnded.connect([this]() {
        LOG_DEBUG("DATA MISSION ENDED");
    });
}

void uksf_data::getData() const {
    std::vector<object> players = sqf::all_players();
    if (players.size() == 0) return;
    json jsonObject;
    jsonObject["timeStamp"] = uksf_common::getTimeStamp();
    jsonObject["serverName"] = _serverName;
    jsonObject["mapName"] = _mapName;
    jsonObject["missionName"] = _missionName;
    json jsonPlayers = json::array();
    int index = 0;
    for (const auto player : players) {
        // Player UID, same as Steam64ID
        json jsonPlayer = json::object();
        jsonPlayer["uid"] = sqf::get_player_uid(player);

        // Player position and direction
        const vector3 position = sqf::position(player);
        json jsonPosition = json::object();
        jsonPosition["x"] = std::to_string(position.x);
        jsonPosition["y"] = std::to_string(position.y);
        jsonPosition["z"] = std::to_string(position.z);
        jsonPlayer["position"] = jsonPosition;
        jsonPlayer["direction"] = std::to_string(sqf::direction(player));

        // Player damage status
        json jsonStatus = json::object();
        jsonStatus["vanillaDamage"] = std::to_string(sqf::damage(player));
        jsonStatus["unconcious"] = sqf::get_variable(player, "ACE_isUnconscious", false);
        jsonStatus["heartRate"] = sqf::get_variable(player, "ace_medical_heartRate", "0");
        const game_value bodyParts = sqf::get_variable(player, "ace_medical_bodyPartStatus", {"0","0","0","0","0","0"});
        json jsonBodyParts = json::object();
        jsonBodyParts["HitHead"] = bodyParts[0];
        jsonBodyParts["HitBody"] = bodyParts[1];
        jsonBodyParts["HitLeftArm"] = bodyParts[2];
        jsonBodyParts["HitRightArm"] = bodyParts[3];
        jsonBodyParts["HitLeftLeg"] = bodyParts[4];
        jsonBodyParts["HitRightLeg"] = bodyParts[5];
        jsonStatus["hitPoints"] = jsonBodyParts;
        const game_value bloodPressure = sqf::get_variable(player, "ace_medical_bloodPressure", { "0","0" });
        json jsonBloodPressure = json::object();
        jsonBloodPressure["bloodPressureL"] = bloodPressure[0];
        jsonBloodPressure["bloodPressureH"] = bloodPressure[1];
        jsonStatus["bloodPressure"] = jsonBloodPressure;
        jsonPlayer["status"] = jsonStatus;

        // Player equipment
        jsonPlayer["currentWeapon"] = sqf::current_weapon(player);

        // Player vehicle
        const object vehicle = sqf::vehicle(player);
        if (!sqf::is_kind_of(vehicle, "CAManBase")) {
            jsonPlayer["vehicle"] = sqf::type_of(vehicle);
            jsonPlayer["vehicleRole"] = sqf::assigned_vehicle_role(player);
            jsonPlayer["vehicleDamage"] = sqf::damage(vehicle);
            jsonPlayer["vehicleWeapon"] = sqf::current_weapon(vehicle);
        } else {
            jsonPlayer["vehicle"] = "";
        }

        jsonPlayers[index] = jsonPlayer;
        index++;
    }
    jsonObject["players"] = jsonPlayers;
    json::string_t jsonString = jsonObject.dump();
    sqf::system_chat(jsonString);
    LOG_DEBUG(jsonString);
    std::thread sendDataThread(&uksf_data::sendData, jsonString);
    sendDataThread.detach();
}

void uksf_data::sendData(json::string_t jsonString) {
    try {
        HTTPClientSession session("localhost", 5000);
        HTTPRequest request(HTTPRequest::HTTP_PUT, "/api/test/data");
        request.setContentType("application/json");
        request.setContentLength(jsonString.length());
        //HTTPBasicCredentials credentials(USERNAME, PASSWORD);
        //credentials.authenticate(request);
        std::ostream& ostream = session.sendRequest(request);
        ostream << jsonString;
        HTTPResponse response;
        session.receiveResponse(response);
    } catch (Poco::Exception& exception) {
        LOG_DEBUG(exception.displayText());
    }
}
