#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts captive escort animations

    Parameters:
        0: Escorting unit <OBJECT>
        1: Captive unit <OBJECT>

    Return value:
        Nothing
*/
params ["_escorter", "_unit"];

detach _unit;
_unit attachTo [_escorter, [-0.2, 0.9, 0]];

private _animChangedEHID = _unit getVariable ["ace_captives_handcuffAnimEHID", -1];
if (_animChangedEHID >= 0) then {
    _unit removeEventHandler ["AnimChanged", _animChangedEHID];
};

_animChangedEHID = _unit addEventHandler ["AnimChanged", {}];
_unit setVariable ["ace_captives_handcuffAnimEHID", _animChangedEHID];

["ace_common_switchMove", [_unit, animationState _escorter]] call CBA_fnc_globalEvent;
_unit playActionNow QGVAR(hvtdefault);

private _idPFH = [{
    params ["_args", "_idPFH"];
    _args params ["_escorter", "_unit"];

    if (isNull _escorter || {stance _escorter == "PRONE"}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [QGVAR(ace_doEscortCaptive), [_escorter, _unit, false], _escorter] call CBA_fnc_targetEvent;
    };

    _unit playMoveNow (animationState _escorter);
}, 0, _this] call CBA_fnc_addPerFrameHandler;

_unit setVariable [QGVAR(escortIdPFH), _idPFH];
