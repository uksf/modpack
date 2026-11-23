#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Connects an oxygen supply and starts its delayed breathing loop.

    Parameter(s):
        0: User <OBJECT>

    Return Value:
        Nothing

    Example:
        [player] call uksf_halohaho_fnc_connectOxygen
*/
params ["_unit"];
call FUNC(disconnectOxygen);
GVAR(oxygenConnected) = true;
private _generation = GVAR(oxygenGeneration);
GVAR(oxygenUnit) = _unit;
GVAR(oxygenKilledEH) = _unit addEventHandler ["Killed", {call FUNC(disconnectOxygen)}];
playSound QGVAR(hiss);
_unit removeItem QGVAR(airSupply);
"Oxygen connected" call CBA_fnc_notify;

[{
    params ["_unit", "_generation"];
    if (GVAR(oxygenConnected) && {GVAR(oxygenGeneration) == _generation} && {alive _unit} && {_unit isEqualTo player}) then {
        GVAR(oxygenSound) = playSoundUI [QPATHTOF(data\sounds\breatheOxygenLoop.ogg), 0.15, 1, false, 0, true];
    };
}, [_unit, _generation], 2] call CBA_fnc_waitAndExecute;

[{
    params ["_generation"];
    if (GVAR(oxygenConnected) && {GVAR(oxygenGeneration) == _generation}) then {
        call FUNC(disconnectOxygen);
    };
}, [_generation], OXYGEN_TIME] call CBA_fnc_waitAndExecute;
