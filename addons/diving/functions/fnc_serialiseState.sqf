#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serialises diving simulation state for persistence save

    Parameter(s):
        None

    Return Value:
        Array of data <ARRAY>

    Example:
        call uksf_diving_fnc_serialiseState
*/

private _diving = GVAR(updatePFHID) != -1;
if (!_diving) exitWith {
    [false]
};

private _state = createHashMap;
_state set ["version", DIVE_STATE_VERSION];
_state set ["currentGasLiters", GVAR(currentGasLiters)];
_state set ["currentVolume", GVAR(currentVolume)];
_state set ["currentPressure", GVAR(currentPressure)];
_state set ["currentPercentO2", GVAR(currentPercentO2)];
_state set ["currentPercentN2", GVAR(currentPercentN2)];
_state set ["currentPercentHe", GVAR(currentPercentHe)];
_state set ["currentDepth", GVAR(currentDepth)];
_state set ["currentAmbientPressure", GVAR(currentAmbientPressure)];
_state set ["previousDepth", GVAR(previousDepth)];
_state set ["saturationHe", GVAR(saturationHe)];
_state set ["saturationN2", GVAR(saturationN2)];
_state set ["partialPressureO2", GVAR(partialPressureO2)];
_state set ["partialPressureN2", GVAR(partialPressureN2)];
_state set ["remainingDiveTime", GVAR(remainingDiveTime)];
_state set ["elapsedDiveTime", GVAR(elapsedDiveTime)];
_state set ["maxDepth", GVAR(maxDepth)];
_state set ["ascendRate", GVAR(ascendRate)];
_state set ["deepStopDepth", GVAR(deepStopDepth)];
_state set ["deepStopTime", GVAR(deepStopTime)];
_state set ["needDeepStop", GVAR(needDeepStop)];
_state set ["deepStopDone", GVAR(deepStopDone)];
_state set ["connectedGas", GVAR(connectedGas)];
_state set ["toxicO2Timeout", GVAR(toxicO2Timeout)];
_state set ["toxicN2Timeout", GVAR(toxicN2Timeout)];
_state set ["toxicDecompressionTimeout", GVAR(toxicDecompressionTimeout)];
_state set ["toxicDeepStopTimeout", GVAR(toxicDeepStopTimeout)];
_state set ["sprintBlocked", GVAR(sprintBlocked)];
_state set ["toxicAscendTimeout", GVAR(toxicAscendTimeout)];
_state set ["noAirTimeout", GVAR(noAirTimeout)];

[true, _state]
