#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops captive escort animations

    Parameters:
        0: Escorting unit <OBJECT>
        1: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_escorter", "_unit"];

private _idPFH = _unit getVariable [QGVAR(escortIdPFH), -1];
[_idPFH] call CBA_fnc_removePerFrameHandler;

if !(isNull _escorter) then {
    private _pos = (getPos _escorter) vectorAdd ((vectorDir _escorter) vectorMultiply 2);
    _pos set [2, ((getPosATL _escorter)#2) + 1.65];
    _unit lookAt _pos;
};

[{
    params ["_escorter", "_unit"];

    private _animChangedEHID = _unit getVariable ["ace_captives_handcuffAnimEHID", -1];
    if (_animChangedEHID >= 0) then {
        _unit removeEventHandler ["AnimChanged", _animChangedEHID];
    };

    _unit playActionNow QGVAR(clearAction);

    if (!(isNull _escorter) && {(stance _escorter) == "CROUCH"} && {vehicle _unit == _unit}) then {
        ["ace_common_switchMove", [_unit, "acts_aidlpsitmstpssurwnondnon05"]] call CBA_fnc_globalEvent;

        _animChangedEHID = _unit addEventHandler ["AnimChanged", {
            params ["_unit", "_newAnimation"];

            if ((_newAnimation != "acts_aidlpsitmstpssurwnondnon05") && {!(_unit getVariable ["ACE_isUnconscious", false])}) then {
                ["ace_common_switchMove", [_unit, "acts_aidlpsitmstpssurwnondnon05"]] call CBA_fnc_globalEvent;
            };
        }];
    } else {
        _animChangedEHID = _unit addEventHandler ["AnimChanged", {call ace_captives_fnc_handleAnimChangedHandcuffed}];
        if (vehicle _unit == _unit) then {
            ["ace_common_switchMove", [_unit, "ace_amovpercmstpscapwnondnon"]] call CBA_fnc_globalEvent;
        };
    };

    _unit setVariable ["ace_captives_handcuffAnimEHID", _animChangedEHID];
}, _this, 0.2] call CBA_fnc_waitAndExecute;
