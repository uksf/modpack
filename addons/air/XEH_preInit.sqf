#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

["CAManBase", "respawn", {
    player setVariable ["UK3CB_voice_enabled", 0, true];
}] call CBA_fnc_addClassEventHandler;

["CUP_C130J_Base", "init", {
    params ["_plane"];
    _plane addAction ["Jump (Static Line)", QUOTE(call FUNC(staticLineJump)), nil, 5, true, true, "", QUOTE([ARR_2(_target,_this)] call FUNC(canStaticLineJump))];
}] call CBA_fnc_addClassEventHandler;

ADDON = true;
