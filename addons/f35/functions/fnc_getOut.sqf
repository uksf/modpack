/*
    Author:
        Tim Beswick, USAF Team

    Description:
        Run on get out

    Parameters:
        0: Plane <OBJECT>
        0: Position <STRING>
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane", "_position", "_unit"];

if (_unit isEqualTo player && local _plane) then {
    if (!isNil QGVAR(stealthHandler)) then {[GVAR(stealthHandler)] call CBA_fnc_removePerFrameHandler;};
    if (!isNil QGVAR(animationHandler)) then {[GVAR(animationHandler)] call CBA_fnc_removePerFrameHandler;};
    if (!isNil QGVAR(screenHandler)) then {[GVAR(screenHandler)] call CBA_fnc_removePerFrameHandler;};
    if (!isNil QGVAR(sonicHandler)) then {[GVAR(sonicHandler)] call CBA_fnc_removePerFrameHandler;};
    if (!isNil QGVAR(afterburnerHandler)) then {[GVAR(afterburnerHandler)] call CBA_fnc_removePerFrameHandler;};

    _plane setcaptive false;
    _unit setcaptive false;

    if (speed _plane >= 20) then {
        _velocity = velocity _plane;
        _unit setVelocity [_velocity select 0, _velocity select 1, (_velocity select 2) + 50];
    };

    _plane animate ["bayL_hatch_1",0];
    _plane animate ["bayL_hatch_1_w",0];
    _plane animate ["bayL_hatch_1_b",0];
    _plane animate ["bayR_hatch_1",0];
    _plane animate ["bayR_hatch_1_w",0];
    _plane animate ["bayR_hatch_1_b",0];
    _plane animate ["bayL_hatch_2",0];
    _plane animate ["bayL_hatch_2_b",0];
    _plane animate ["bayR_hatch_2",0];
    _plane animate ["bayR_hatch_2_b",0];
};
