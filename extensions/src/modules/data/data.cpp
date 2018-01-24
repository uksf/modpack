#include "data.hpp"

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

        if (!_enabled) {
            LOG(INFO) << "Data system is disabled";
        } else {
            LOG(INFO) << "Data system is enabled";
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
    json::value json = json::value::object();
    json[L"missionName"] = json::value::string(conversions::to_string_t(sqf::mission_name()));
    json::value jsonPlayers = json::value::array();
    int index = 0;
    for (const auto player : players) {
        json::value jsonPlayer = json::value::object();
        jsonPlayer[L"uid"] = json::value::string(conversions::to_string_t(sqf::get_player_uid(player)));

        const vector3 position = sqf::position(player);
        json::value jsonPosition = json::value::object();
        jsonPosition[L"x"] = json::value::string(conversions::to_string_t(std::to_string(position.x)));
        jsonPosition[L"y"] = json::value::string(conversions::to_string_t(std::to_string(position.y)));
        jsonPosition[L"z"] = json::value::string(conversions::to_string_t(std::to_string(position.z)));
        jsonPlayer[L"position"] = jsonPosition;

        const object vehicle = sqf::vehicle(player);
        if (!sqf::is_kind_of(vehicle, "CAManBase")) {
            jsonPlayer[L"vehicle"] = json::value::string(conversions::to_string_t(sqf::type_of(vehicle)));
        } else {
            jsonPlayer[L"vehicle"] = json::value::string(L"");
        }

        jsonPlayers[index] = jsonPlayer;
        index++;
    }
    json[L"players"] = jsonPlayers;
    const sqf_string_const_ref jsonString = sqf_string_const_ref(json.serialize().c_str());
    sqf::system_chat(jsonString);
    sqf::diag_log(jsonString);
    LOG_DEBUG(jsonString);
    std::async(getInstance().sendData, json);
}

void uksf_data::sendData(json::value json) {
    http_client client(U("http://localhost:5000/api/test/data"));
    client.request(http::methods::PUT, json.serialize());
}

