/*
    Author:
        Tim Beswick

    Description:
        Initialises persistence event handlers on client

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_enabled"];

GVAR(enabled) = _enabled;
TRACE_1("Client init",GVAR(enabled));
if (!GVAR(enabled)) exitWith {};

[QGVAR(firstKilled), {
    GVAR(data) = _this;
    TRACE_1("Client first killed",GVAR(data));
    GVAR(respawn) = createMarkerLocal [RESPAWN_MARKER, GVAR(data)#0];
    GVAR(respawn) setMarkerTypeLocal "flag_UK";
    GVAR(respawn) setMarkerTextLocal RESPAWN_NAME;
}] call CBA_fnc_addEventHandler;

[QGVAR(firstRespawn), {
    TRACE_1("Client first respawn",GVAR(data));
    if (!isNil QGVAR(respawn)) then {
        deleteMarkerLocal GVAR(respawn);
    };
    if (count GVAR(data) > 0 && {(GVAR(data)#0 distance2D (getPos player)) < 2}) then {
        player setDir GVAR(data)#1;
        [{player playMove ([GVAR(data)#2, ANIM_STANDING] select (GVAR(data)#2 == ANIM_STANDING))}, [], 1] call CBA_fnc_waitAndExecute;
        player setUnitLoadout GVAR(data)#3;
        player setDamage GVAR(data)#4;
        [player, GVAR(data)#5] call EFUNC(common,deserializeAceMedical);
    };
}] call CBA_fnc_addEventHandler;
