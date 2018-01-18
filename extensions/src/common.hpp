#pragma once
#include "uksf.hpp"

static auto RENG = std::default_random_engine{};
// TODO: Find the best way to dynamically detect if weapon is anti-air capable. (canLock & airLock used too often in other non-aa weapons)
static const std::set<std::string> WEAPONS_EXCLUDE = { "throw" , "put", "binocular", "rangefinder" };
static const std::set<std::string> WEAPONS_AA = { "cup_launch_fim92stinger", "cup_launch_9k32strela", "cup_launch_igla", "launch_titan_base" };

class uksf_common : public singleton<uksf_common> {
public:
    uksf_common();

    types::registered_sqf_function uksfCommonSetPlayer;
    static game_value uksfCommonSetPlayerFunction(game_value_parameter param);

    static game_value CBA_Settings_fnc_init;
    static bool thread_run;
    static object player;

    static float getZoom();
    static bool lineOfSight(object& target, object& source, bool zoomCheck, bool groupCheck);
    static side getSide(int sideNumber);
};
