#pragma once
#include "common.hpp"

game_value uksf_common::CBA_Settings_fnc_init = {};
bool uksf_common::thread_run = false;
object uksf_common::player = game_value();

uksf_common::uksf_common() {
    uksf::getInstance().preStart.connect([this]() {
        LOG(DEBUG) << "COMMON PRESTART";
        uksfCommonSetPlayer = client::host::registerFunction(
            "uksfCommonSetPlayer",
            "Sets player object",
            userFunctionWrapper<uksfCommonSetPlayerFunction>,
            GameDataType::NOTHING,
            GameDataType::OBJECT
        );
    });

    uksf::getInstance().preInit.connect([this]() {
        LOG(DEBUG) << "COMMON PREINIT";
        CBA_Settings_fnc_init = sqf::get_variable(sqf::ui_namespace(), "CBA_Settings_fnc_init");
    });

    uksf::getInstance().postInit.connect([this]() { LOG(DEBUG) << "COMMON POSTINIT"; });

    uksf::getInstance().onFrame.connect([this]() { thread_run = (sqf::time() > (int)(sqf::get_variable(sqf::mission_namespace(), "CBA_common_lastTime", 0))); });
}

game_value uksf_common::uksfCommonSetPlayerFunction(game_value_parameter param) {
    player = (object)param;
    return game_value();
}

float uksf_common::getZoom() {
    float safeZoneW = sqf::safe_zone_w();
    float deltaX = ((sqf::world_to_screen(sqf::position_camera_to_world(vector3(5000, 0, 10000)))->x) - 0.5f);
    float trigRatio = (((safeZoneW / 2.0f) * 5000.0f) / (10000.0f * deltaX));
    float configFOV = (trigRatio / (safeZoneW / sqf::safe_zone_h()));
    return (0.75f / configFOV);
}

bool uksf_common::lineOfSight(object& target, object& source, bool zoomCheck, bool groupCheck) {
    bool los = false;
    std::optional<vector2> screenPosition = sqf::world_to_screen(sqf::get_pos(target));
    bool onScreen = (screenPosition.has_value() && ((abs(screenPosition->x) < 1.5f) && (abs(screenPosition->y) < 1.5f))
    );
    bool visible = (sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                          sqf::eye_pos(target)) > 0);
    los = (onScreen && visible);

    if (onScreen && !los && groupCheck) {
        std::vector<object> units = sqf::units(target);
        for (auto& unit : units) {
            std::optional<vector2> screenPosition = sqf::world_to_screen(sqf::get_pos(unit));
            bool onScreen = (screenPosition.has_value() && ((abs(screenPosition->x) < 1.5f) && (abs(
                screenPosition->y) < 1.5f)));
            los = (onScreen && (sqf::check_visibility(source, "VIEW", sqf::vehicle(source), sqf::eye_pos(source),
                                                      sqf::eye_pos(unit)) > 0));
            if (los) {
                target = std::ref(unit);
                break;
            }
        }
    }

    if (los && zoomCheck) {
        float distanceMultiplier = (200 + (4 * 200 * (std::max(0.0f, (float)(sqf::current_vision_mode(source) - 1)))));
        if (!sqf::is_kind_of(sqf::vehicle(target), "CAManBase")) { distanceMultiplier *= 2.5f; }
        float distanceCheck = std::min(sqf::get_object_view_distance().object_distance,
                                       1000 + (distanceMultiplier * getZoom()));
        float distance = (sqf::get_pos_world(target)).distance(sqf::get_pos_world(source));
        los = (distance < distanceCheck);
    }

    return los;
}

side uksf_common::getSide(int sideNumber) {
    switch (sideNumber) {
    case 1:
        return sqf::west();
    case 2:
        return sqf::independent();
    case 0:
    default:
        return sqf::east();
    }
}
