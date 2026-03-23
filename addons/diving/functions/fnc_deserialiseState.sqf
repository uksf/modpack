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

    Example:
        [_data] call uksf_diving_fnc_deserialiseState
*/
params ["_data"];

private _diving = _data#0;
if (!_diving) exitWith {};

private _state = _data#1;

if !(_state isEqualType createHashMap) exitWith {};

GVAR(currentGasLiters) = _state getOrDefault ["currentGasLiters", 6];
GVAR(currentVolume) = _state getOrDefault ["currentVolume", 6];
GVAR(currentPressure) = _state getOrDefault ["currentPressure", 6];
GVAR(currentPercentO2) = _state getOrDefault ["currentPercentO2", 0.21];
GVAR(currentPercentN2) = _state getOrDefault ["currentPercentN2", 0.79];
GVAR(currentPercentHe) = _state getOrDefault ["currentPercentHe", 0];
GVAR(currentDepth) = _state getOrDefault ["currentDepth", 0];
GVAR(currentAmbientPressure) = _state getOrDefault ["currentAmbientPressure", 1];
GVAR(previousAmbientPressure) = _state getOrDefault ["previousAmbientPressure", 0];
GVAR(previousDepth) = _state getOrDefault ["previousDepth", 0];
GVAR(saturationO2) = _state getOrDefault ["saturationO2", [0, 0, 0]];
GVAR(saturationHe) = _state getOrDefault ["saturationHe", [0, 0, 0]];
GVAR(saturationN2) = _state getOrDefault ["saturationN2", [0, 0, 0]];
GVAR(partialPressureO2) = _state getOrDefault ["partialPressureO2", 0.21];
GVAR(partialPressureN2) = _state getOrDefault ["partialPressureN2", 0.78];
GVAR(partialPressureHe) = _state getOrDefault ["partialPressureHe", 0];
GVAR(remainingDiveTime) = _state getOrDefault ["remainingDiveTime", 0];
GVAR(elapsedDiveTime) = _state getOrDefault ["elapsedDiveTime", 0];
GVAR(maxDepth) = _state getOrDefault ["maxDepth", 0];
GVAR(ascendRate) = _state getOrDefault ["ascendRate", 0];
GVAR(decompressDepthB) = _state getOrDefault ["decompressDepthB", 0];
GVAR(decompressDepth) = _state getOrDefault ["decompressDepth", 0];
GVAR(decompressTime) = _state getOrDefault ["decompressTime", 0];
GVAR(deepStopDepth) = _state getOrDefault ["deepStopDepth", 0];
GVAR(deepStopTime) = _state getOrDefault ["deepStopTime", 0];
GVAR(needDecompress) = _state getOrDefault ["needDecompress", false];
GVAR(needDeepStop) = _state getOrDefault ["needDeepStop", false];
GVAR(connectedGas) = _state getOrDefault ["connectedGas", false];
GVAR(wearMaskOnLand) = _state getOrDefault ["wearMaskOnLand", true];
GVAR(toxicO2Timeout) = _state getOrDefault ["toxicO2Timeout", 10];
GVAR(toxicN2Timeout) = _state getOrDefault ["toxicN2Timeout", 10];
GVAR(toxicDecompressionTimeout) = _state getOrDefault ["toxicDecompressionTimeout", 10];
GVAR(toxicDeepStopTimeout) = _state getOrDefault ["toxicDeepStopTimeout", 180];
GVAR(toxicAscendTimeout) = _state getOrDefault ["toxicAscendTimeout", 10];
GVAR(noAirTimeout) = _state getOrDefault ["noAirTimeout", NO_AIR_TIMEOUT];
GVAR(warningTextO2) = _state getOrDefault ["warningTextO2", ""];
GVAR(warningTextN2) = _state getOrDefault ["warningTextN2", ""];
GVAR(warningTextAscendRate) = _state getOrDefault ["warningTextAscendRate", ""];
GVAR(warningTextLowPressure) = _state getOrDefault ["warningTextLowPressure", ""];
GVAR(warningTextDecompression) = _state getOrDefault ["warningTextDecompression", ""];

if (_state getOrDefault ["surfaceOffgasActive", false]) then {
    if (GVAR(surfaceOffgasPFHID) == -1) then {
        GVAR(surfaceOffgasPFHID) = [{call FUNC(surfaceOffgas)}, 1] call CBA_fnc_addPerFrameHandler;
    };
};

if (GVAR(updatePFHID) == -1) then {
    [true] call FUNC(loop);
};
