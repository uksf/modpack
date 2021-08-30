#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserialises diving simulation state for persistence load

    Parameter(s):
        0: Data array <ARRAY>

    Return Value:
        Nothing
*/
params ["_data"];

private _diving = _data#0;

if (!_diving) exitWith {};

GVAR(currentGasLiters) = _data#1;
GVAR(currentVolume) = _data#2;
GVAR(currentPressure) = _data#3;
GVAR(currentPercentO2) = _data#4;
GVAR(currentPercentN2) = _data#5;
GVAR(currentPercentHe) = _data#9;
GVAR(previousAmbientPressure) = _data#7;
GVAR(previousDepth) = _data#8;
GVAR(saturationO2) = _data#9;
GVAR(saturationHe) = _data#10;
GVAR(saturationN2) = _data#11;
GVAR(remainingDiveTime) = _data#12;
GVAR(elapsedDiveTime) = _data#13;
GVAR(maxDepth) = _data#14;
GVAR(previousDepth) = _data#15;
GVAR(previousAmbientPressure) = _data#16;

GVAR(ascendRate) = _data#17;
GVAR(decompressDepthB) = _data#18;
GVAR(decompressDepth) = _data#19;
GVAR(decompressTime) = _data#20;
GVAR(decompressPreviousDepth) = _data#21;
GVAR(deepStopDepth) = _data#22;
GVAR(deepStopTime) = _data#23;
GVAR(needDecompress) = _data#24;
GVAR(needDeepStop) = _data#25;

GVAR(pain) = _data#26;
GVAR(toxicO2Timeout) = _data#27;
GVAR(toxicN2Timeout) = _data#28;
GVAR(toxicDecompressionTimeout) = _data#29;
GVAR(toxicDeepStopTimeout) = _data#30;
GVAR(toxicAscendTimeout) = _data#31;
GVAR(noAirTimeout) = _data#32;

if (_diving && GVAR(updatePFHID) == -1) then {
    [true] call FUNC(loop);
};
