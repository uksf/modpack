#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Use diving cylinder

    Parameter(s):
        0: Cylinder config <CONFIG>
        1: Cylinder name <STRING>

    Return Value:
        None
*/
params ["_config", "_name"];

GVAR(currentGasLiters) = getNumber (_config >> QGVAR(cylinderGasLiters));
GVAR(currentVolume) = getNumber (_config >> QGVAR(cylinderVolume));
GVAR(currentPressure) = getNumber (_config >> QGVAR(cylinderPressure));
GVAR(currentPercentO2) = getNumber (_config >> QGVAR(cylinderPercentO2));
GVAR(currentPercentN2) = getNumber (_config >> QGVAR(cylinderPercentN2));
GVAR(currentPercentHe) = getNumber (_config >> QGVAR(cylinderPercentHe));

GVAR(noAirTimeout) = 120;

private _className = configName _config;
player removeItem _className;

private _replacement = getText (_config >> QGVAR(usedReplacement));
player addItem _replacement;

hint format ["Filled rebreather using %1", _name];
playSound QGVAR(hiss);
