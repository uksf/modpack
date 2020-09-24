#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Selects response to unit firing a mortar between air units, ground units and counter battery

    Parameters:
        0: Unit who fired <OBJECT>

    Return value:
        Nothing
*/
params ["_target"];

if (GVAR(counterInProgress)) exitWith {};

GVAR(counterInProgress) = true;

// private _forceChance = 7; // for debug
private _forceChance = random 10;
private _targetPosition = getPos _target;

// Do nothing
if (_forceChance > 8) exitWith {
    [{GVAR(counterInProgress) = false}, [], 1200] call CBA_fnc_waitAndExecute;
};

// Counter battery
if (_forceChance > 5 && !(GVAR(counterBatteryUnits) isEqualTo [])) exitWith {
    private _inRangeCounterArtillery = GVAR(counterBatteryUnits) select {_targetPosition inRangeOfArtillery [[_x], currentMagazine _x]};
    if !(_inRangeCounterArtillery isEqualTo []) then {
        private _counterArtillery = selectRandom _inRangeCounterArtillery;
        [QEGVAR(mission,fireMission), [_counterArtillery, _counterArtillery, _targetPosition], gunner _counterArtillery] call CBA_fnc_targetEvent;
    };

    [{GVAR(counterInProgress) = false}, [], 1200] call CBA_fnc_waitAndExecute;
};

// Create an airborne force
if (_forceChance > 2.5 && !(GVAR(airVehiclePool) isEqualTo [])) exitWith {
    private _spawnPosition = selectRandom GVAR(airSpawns);
    [getPos _spawnPosition, _targetPosition] call FUNC(createAirForce);
};

// Create a motor force
if !(GVAR(groundVehiclePool) isEqualTo []) exitWith {
    private _spawnPosition = selectRandom GVAR(groundSpawns);
    [getPos _spawnPosition, _targetPosition] call FUNC(createGroundForce);
};
