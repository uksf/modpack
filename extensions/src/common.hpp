#pragma once
#include "uksf.hpp"

#define LOG_DEBUG(A) LOG(INFO) << A

static auto reng = std::default_random_engine{};

class uksf_common : public singleton<uksf_common> {
public:
    uksf_common();

    static game_value cba_settings_fnc_init;
    static bool thread_run;

    static float get_zoom();
    static bool line_of_sight(object& target, object& source, bool zoom_check, bool group_check);
    static side get_side(int side_number);
};
