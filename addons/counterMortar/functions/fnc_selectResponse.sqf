#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        selects response between air units, ground units and counter battery

    Parameters:
        0: _counterBatteryUnit <OBJECT>

    Return value:
        Nothing
*/

params ["_counterBatteryUnit"];

if (GVAR(counterInProgress) == 1) exitWith {};

if (count (GVAR(groundVehicleTypes) + GVAR(airVehicleTypes) + GVAR(counterBatteryUnits)) == 0) exitWith {diag_log "UKSF: ANTI MORTAR --- No counter units defined, check preInit ---"};
// probably needs some kind of removal of the class EH to prevent spam

// private _forceChance = 4; // for debug
private _forceChance = random 10;
private _bluforMortarPos = getPos _counterBatteryUnit;

GVAR(counterInProgress) = 1; // set in progress to 1 to stop spam missions

// create a motor force
if (_forceChance > 0 && _forceChance <= 2.5 && (count GVAR(groundVehicleTypes)) != 0) exitWith {
    [_bluforMortarPos,1] call FUNC(selectSpawnLocation);
};


// create a heli force
if (_forceChance > 2.5 && _forceChance <= 5 && (count GVAR(airVehicleTypes)) != 0) exitWith {
    [_bluforMortarPos,2] call FUNC(selectSpawnLocation);
};


// counter battery
if (_forceChance > 5 && _forceChance <= 10  && (count GVAR(counterBatteryUnits)) != 0) exitWith {
    private _index = GVAR(counterBatteryUnits) findIf {_bluforMortarPos inRangeOfArtillery [[_x], currentMagazine _x];};
    if (_index > -1) then {
        private _counterBatteryUnit = GVAR(counterBatteryUnits) select _index;
        [_bluforMortarPos,_counterBatteryUnit] call FUNC(counterBattery);
    };
};
