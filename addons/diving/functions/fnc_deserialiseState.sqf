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

private _savedN2 = _state getOrDefault ["saturationN2", []];
private _savedHe = _state getOrDefault ["saturationHe", []];
private _current = (_state getOrDefault ["version", 1]) == DIVE_STATE_VERSION
    && {count _savedN2 == COMPARTMENT_COUNT}
    && {count _savedHe == COMPARTMENT_COUNT};
if (!_current) exitWith {
    call FUNC(reset);
    if (GVAR(updatePFHID) == -1) then {
        [true] call FUNC(loop);
    };
};

GVAR(currentDepth) = _state getOrDefault ["currentDepth", 0];
GVAR(currentAmbientPressure) = _state getOrDefault ["currentAmbientPressure", 1];
GVAR(previousDepth) = _state getOrDefault ["previousDepth", 0];
GVAR(saturationHe) = _savedHe;
GVAR(saturationN2) = _savedN2;
GVAR(partialPressureO2) = _state getOrDefault ["partialPressureO2", 0.21];
GVAR(partialPressureN2) = _state getOrDefault ["partialPressureN2", 0.79];
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
GVAR(deepStopDone) = _state getOrDefault ["deepStopDone", false];
GVAR(decompressEndN2) = _state getOrDefault ["decompressEndN2", []];
GVAR(decompressEndHe) = _state getOrDefault ["decompressEndHe", []];
GVAR(connectedGas) = _state getOrDefault ["connectedGas", false];
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

if (GVAR(updatePFHID) == -1) then {
    [true] call FUNC(loop);
};
