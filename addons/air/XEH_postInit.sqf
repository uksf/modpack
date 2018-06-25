#include "script_component.hpp"

player setVariable ["UK3CB_voice_enabled", 0, true];

["CUP_C130J_Base", "init", {
    params ["_plane"];

    _plane addAction ["Eject (Static Line)", QUOTE(_this call FUNC(staticLineJump)), nil, 5, true, true, "", QUOTE([ARR_2(_target,_this)] call FUNC(canStaticLineJump))];
}, true, nil, true] call CBA_fnc_addClassEventHandler;
