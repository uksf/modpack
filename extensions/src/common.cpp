#pragma once
#include "common.hpp"

game_value uksf_common::cba_settings_fnc_init = game_value();
bool uksf_common::thread_run = false;

uksf_common::uksf_common() {

    uksf::get_instance().post_start.connect([this]() {
        LOG_DEBUG("COMMON PRESTART");
    });

    uksf::get_instance().pre_init.connect([this]() {
        LOG_DEBUG("COMMON PREINIT");
        cba_settings_fnc_init = sqf::get_variable(sqf::ui_namespace(), "CBA_Settings_fnc_init");
    });

    uksf::get_instance().post_init.connect([this]() { LOG_DEBUG("COMMON POSTINIT"); });

    uksf::get_instance().on_frame.connect([this]() { thread_run = sqf::time() > int(sqf::get_variable(sqf::mission_namespace(), "CBA_common_lastTime", 0)); });
}

float uksf_common::get_zoom() {
    const float safe_zone_w = sqf::safe_zone_w();
    const float delta_x = sqf::world_to_screen(sqf::position_camera_to_world(vector3(5000, 0, 10000)))->x - 0.5f;
    const float trig_ratio = safe_zone_w / 2.0f * 5000.0f / (10000.0f * delta_x);
    const float config_fov = trig_ratio / (safe_zone_w / sqf::safe_zone_h());
    return 0.75f / config_fov;
}

bool uksf_common::line_of_sight(object& target, object& source, const bool zoom_check, const bool group_check) {
    std::optional<vector2> screen_position = sqf::world_to_screen(sqf::get_pos(target));
    const bool on_screen = screen_position.has_value() && (abs(screen_position->x) < 1.5f && abs(screen_position->y) < 1.5f);
    const bool visible = sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                               sqf::eye_pos(target)) > 0;
    bool los = on_screen && visible;

    if (on_screen && !los && group_check) {
        std::vector<object> units = sqf::units(target);
        for (auto& unit : units) {
            std::optional<vector2> new_screen_position = sqf::world_to_screen(sqf::get_pos(unit));
            const bool new_on_screen = new_screen_position.has_value() && (abs(new_screen_position->x) < 1.5f && abs(
                new_screen_position->y) < 1.5f);
            los = new_on_screen && sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                                         sqf::eye_pos(unit)) > 0;
            if (los) {
                target = std::ref(unit);
                break;
            }
        }
    }

    if (los && zoom_check) {
        float distance_multiplier = 200 + 4 * 200 * std::max(0.0f, float(sqf::current_vision_mode(source) - 1));
        if (!sqf::is_kind_of(sqf::vehicle(target), "CAManBase")) { distance_multiplier *= 2.5f; }
        const float distance_check = std::min(sqf::get_object_view_distance().object_distance,
                                              1000 + distance_multiplier * get_zoom());
        const float distance = sqf::get_pos_world(target).distance(sqf::get_pos_world(source));
        los = distance < distance_check;
    }

    return los;
}

side uksf_common::get_side(const int side_number) {
    switch (side_number) {
    case 1:
        return sqf::west();
    case 2:
        return sqf::independent();
    case 0:
    default:
        return sqf::east();
    }
}
