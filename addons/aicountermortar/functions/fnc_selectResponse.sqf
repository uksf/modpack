#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Selects response to unit firing a mortar between air units, ground units and counter battery

    Parameters:
        0: Unit who fired a mortar <OBJECT>

    Return value:
        Nothing
*/
params ["_counterBatteryUnit"];

if (GVAR(counterInProgress)) exitWith {};

GVAR(counterInProgress) = true;

// private _forceChance = 4; // for debug
private _forceChance = random 10;
private _mortarPosition = getPos _counterBatteryUnit;

// create a motor force
if (_forceChance <= 2.5 && !(GVAR(groundVehiclePool) isEqualTo [])) exitWith {
    [_mortarPosition, 1] call FUNC(selectSpawnLocation);
};

// create a heli force
if (_forceChance > 2.5 && _forceChance <= 5 && !(GVAR(airVehiclePool) isEqualTo [])) exitWith {
    [_mortarPosition, 2] call FUNC(selectSpawnLocation);
};

// counter battery
if (_forceChance > 5  && !(GVAR(counterBatteryUnits) isEqualTo [])) exitWith {
    private _inRangeUnits = GVAR(counterBatteryUnits) select {_mortarPosition inRangeOfArtillery [[_x], currentMagazine _x]};
    if !(_inRangeUnits isEqualTo []) then {
        private _counterBatteryUnit = selectRandom _inRangeUnits;
        [_mortarPosition, _counterBatteryUnit] call FUNC(counterBattery);
    };
};
