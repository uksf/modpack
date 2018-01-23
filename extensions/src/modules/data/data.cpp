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
    auto jsonString = json::value::object();
    jsonString[L"mission"] = json::value::string(sqf::mission_name());
    std::string json = "{";
    for (std::vector<object>::iterator i = players.begin(); i != players.end(); ++i) {
        const auto player = *i;
        if (!sqf::is_kind_of(player, "HeadlessClient_F")) {
            const std::string playerUid = "\"player\":\"" + sqf::get_player_uid(player) + "\"";
            const vector3 position = sqf::position(player);
            const std::string positionString = "\"position\":\"[" + std::to_string(position.x) + "," + std::to_string(position.y) + "," + std::
                to_string(position.z) + "]\"";

            if (i != players.begin()) {
                json += ",";
            }
            json += "{" + playerUid + ", {" + positionString + "}}";
        }
    }
    sqf::system_chat(json);
    sqf::diag_log(json);
    LOG_DEBUG(json);
    async(getInstance().sendData, json);
}

void uksf_data::sendData(std::string json) {
    http_client client(U("http://localhost:5000/data"));
    client.request(methods::POST);

}

