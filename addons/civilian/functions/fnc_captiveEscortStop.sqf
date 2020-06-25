#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops captive escort animations

    Parameters:
        0: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

[GVAR(escortPFHID)] call CBA_fnc_removePerFrameHandler;

ACE_player playActionNow QGVAR(clearAction);

private _pos = (getPos ACE_player) vectorAdd ((vectorDir ACE_player) vectorMultiply 2);
_pos set [2, ((getPosATL ACE_player)#2) + 1.65];
_unit lookAt _pos;

[{
    params ["_unit"];

    ["ace_common_playActionNow", [_unit, QGVAR(clearAction)], _unit] call CBA_fnc_targetEvent;

    private _animChangedEHID = _unit getVariable ["ace_captives_handcuffAnimEHID", -1];
    if (_animChangedEHID >= 0) then {
        _unit removeEventHandler ["AnimChanged", _animChangedEHID];
    };

    if ((stance ACE_player) == "CROUCH") then {
        ["ace_common_switchMove", [_unit, "acts_aidlpsitmstpssurwnondnon05"], _unit] call CBA_fnc_targetEvent;

        _animChangedEHID = _unit addEventHandler ["AnimChanged", {
            params ["_unit", "_newAnimation"];

            if ((_newAnimation != "acts_aidlpsitmstpssurwnondnon05") && {!(_unit getVariable ["ACE_isUnconscious", false])}) then {
                ["ace_common_switchMove", [_unit, "acts_aidlpsitmstpssurwnondnon05"], _unit] call CBA_fnc_targetEvent;
            };
        }];
    } else {
        ["ace_common_switchMove", [_unit, "ace_amovpercmstpscapwnondnon"], _unit] call CBA_fnc_targetEvent;
        _animChangedEHID = _unit addEventHandler ["AnimChanged", {call ace_captives_fnc_handleAnimChangedHandcuffed}];
    };

    _unit setVariable ["ace_captives_handcuffAnimEHID", _animChangedEHID, true];
}, _this, 0.1] call CBA_fnc_waitAndExecute;
