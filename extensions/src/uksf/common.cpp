#include "common.hpp"

game_value uksf_common::cbaSettingsFncInit = game_value();
game_value uksf_common::cbaCommonPlayers = game_value();
game_value uksf_common::uksfPersistenceShutdown = game_value();
bool uksf_common::threadRun = false;

uksf_common::uksf_common() {

    uksf::getInstance().postStart.connect([this]() {
        LOG_DEBUG("COMMON PRESTART");
    });

    uksf::getInstance().preInit.connect([this]() {
        LOG_DEBUG("COMMON PREINIT");
        cbaSettingsFncInit = sqf::get_variable(sqf::ui_namespace(), "CBA_Settings_fnc_init");
        cbaCommonPlayers = sqf::get_variable(sqf::ui_namespace(), "CBA_fnc_players");
        uksfPersistenceShutdown = sqf::get_variable(sqf::ui_namespace(), "uksf_persistence_fnc_shutdown");
    });

    uksf::getInstance().postInit.connect([this]() { LOG_DEBUG("COMMON POSTINIT"); });

    //uksf::getInstance().onFrame.connect([this]() { threadRun = sqf::time() > int(sqf::get_variable(sqf::mission_namespace(), "CBA_common_lastTime", 0)) && !sqf::find_display(46).is_nil(); });
}

float uksf_common::getZoom() {
    const float safeZoneW = sqf::safe_zone_w();
    const float deltaX = sqf::world_to_screen(sqf::position_camera_to_world(vector3(5000, 0, 10000)))->x - 0.5f;
    const float trigRatio = safeZoneW / 2.0f * 5000.0f / (10000.0f * deltaX);
    const float configFov = trigRatio / (safeZoneW / sqf::safe_zone_h());
    return 0.75f / configFov;
}

bool uksf_common::lineOfSight(object& target, object& source, const bool zoomCheck, const bool groupCheck) {
    std::optional<vector2> screenPosition = sqf::world_to_screen(sqf::get_pos(target));
    const bool onScreen = screenPosition.has_value() && (abs(screenPosition->x) < 1.5f && abs(screenPosition->y) < 1.5f);
    const bool visible = sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                               sqf::eye_pos(target)) > 0;
    bool los = onScreen && visible;

    if (onScreen && !los && groupCheck) {
        std::vector<object> units = sqf::units(target);
        for (auto& unit : units) {
            std::optional<vector2> newScreenPosition = sqf::world_to_screen(sqf::get_pos(unit));
            const bool newOnScreen = newScreenPosition.has_value() && (abs(newScreenPosition->x) < 1.5f && abs(
                newScreenPosition->y) < 1.5f);
            los = newOnScreen && sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                                         sqf::eye_pos(unit)) > 0;
            if (los) {
                target = std::ref(unit);
                break;
            }
        }
    }

    if (los && zoomCheck) {
        float distanceMultiplier = 200 + 4 * 200 * std::max(0.0f, float(sqf::current_vision_mode(source) - 1));
        if (!sqf::is_kind_of(sqf::vehicle(target), "CAManBase")) { distanceMultiplier *= 2.5f; }
        const float distanceCheck = std::min(sqf::get_object_view_distance().object_distance,
                                              1000 + distanceMultiplier * getZoom());
        const float distance = sqf::get_pos_world(target).distance(sqf::get_pos_world(source));
        los = distance < distanceCheck;
    }

    return los;
}

side uksf_common::getSide(const int sideNumber) {
    switch (sideNumber) {
    case 1:
        return sqf::west();
    case 2:
        return sqf::independent();
    default:
        return sqf::east();
    }
}

std::string uksf_common::getTimeStamp() {
    const auto now = std::chrono::system_clock::now();
    const auto today = date::floor<days>(now);
    std::stringstream ss;
    ss << today << ' ' << make_time(now - today);
    return ss.str();
}
