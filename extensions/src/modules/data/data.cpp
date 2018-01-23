#include "data.hpp"

uksf_data::uksf_data() {
    uksf::get_instance().pre_init.connect([this]() {
        LOG_DEBUG("DATA PREINIT");
        game_value enabled_args({
            QGVAR(enabled),
            "CHECKBOX",
            "Data System",
            "UKSF",
            ENABLED_DEFAULT,
            true
        });
        sqf::call(uksf_common::cba_settings_fnc_init, enabled_args);
        game_value frequency_args({
            QGVAR(frequency),
            "SLIDER",
            "Data System Frequency",
            "UKSF",
            {5, 60, FREQUENCY_DEFAULT, 0},
            true
        });
        sqf::call(uksf_common::cba_settings_fnc_init, frequency_args);

        if (sqf::is_server()) {
            get_instance().stop_thread();
        }
    });

    uksf::get_instance().post_init.connect([this]() {
        LOG_DEBUG("DATA POSTINIT");
        _enabled = sqf::get_variable(sqf::mission_namespace(), QGVAR(enabled), ENABLED_DEFAULT);
        _frequency = sqf::get_variable(sqf::mission_namespace(), QGVAR(frequency), FREQUENCY_DEFAULT);

        if (!_enabled) {
            LOG(INFO) << "Data system is disabled";
        } else {
            LOG(INFO) << "Data system is enabled";
            if (sqf::is_server()) {
                get_instance().start_thread();
            }
        }
    });

    uksf::get_instance().mission_ended.connect([this]() {
        LOG_DEBUG("DATA MISSION ENDED");
        get_instance().stop_thread();
    });
}

void uksf_data::function() {
    {
        LOCK;
        std::string json = "{";
        std::vector<object> players = sqf::all_players();
        for (std::vector<object>::iterator i = players.begin(); i != players.end(); ++i) {
            const auto player = *i;
            if (!sqf::is_kind_of(player, "HeadlessClient_F")) {
                const std::string player_uid = "\"player\":\"" + sqf::get_player_uid(player) + "\"";
                const vector3 position = sqf::position(player);
                const std::string position_string = "\"position\":\"[" + std::to_string(position.x) + "," + std::to_string(position.y) + "," + std::
                    to_string(position.z) + "]\"";

                if (i != players.begin()) {
                    json += ",";
                }
                json += "{" + player_uid + ", {" + position_string + "}}";
            }
        }
        sqf::system_chat(json);
        sqf::diag_log(json);
        LOG_DEBUG(json);
    }
    SLEEP(_frequency);
}
