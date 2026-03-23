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
_state set ["currentGasLiters", GVAR(currentGasLiters)];
_state set ["currentVolume", GVAR(currentVolume)];
_state set ["currentPressure", GVAR(currentPressure)];
_state set ["currentPercentO2", GVAR(currentPercentO2)];
_state set ["currentPercentN2", GVAR(currentPercentN2)];
_state set ["currentPercentHe", GVAR(currentPercentHe)];
_state set ["currentDepth", GVAR(currentDepth)];
_state set ["currentAmbientPressure", GVAR(currentAmbientPressure)];
_state set ["previousAmbientPressure", GVAR(previousAmbientPressure)];
_state set ["previousDepth", GVAR(previousDepth)];
_state set ["saturationO2", GVAR(saturationO2)];
_state set ["saturationHe", GVAR(saturationHe)];
_state set ["saturationN2", GVAR(saturationN2)];
_state set ["partialPressureO2", GVAR(partialPressureO2)];
_state set ["partialPressureN2", GVAR(partialPressureN2)];
_state set ["partialPressureHe", GVAR(partialPressureHe)];
_state set ["remainingDiveTime", GVAR(remainingDiveTime)];
_state set ["elapsedDiveTime", GVAR(elapsedDiveTime)];
_state set ["maxDepth", GVAR(maxDepth)];
_state set ["ascendRate", GVAR(ascendRate)];
_state set ["decompressDepthB", GVAR(decompressDepthB)];
_state set ["decompressDepth", GVAR(decompressDepth)];
_state set ["decompressTime", GVAR(decompressTime)];
_state set ["deepStopDepth", GVAR(deepStopDepth)];
_state set ["deepStopTime", GVAR(deepStopTime)];
_state set ["needDecompress", GVAR(needDecompress)];
_state set ["needDeepStop", GVAR(needDeepStop)];
_state set ["connectedGas", GVAR(connectedGas)];
_state set ["wearMaskOnLand", GVAR(wearMaskOnLand)];
_state set ["toxicO2Timeout", GVAR(toxicO2Timeout)];
_state set ["toxicN2Timeout", GVAR(toxicN2Timeout)];
_state set ["toxicDecompressionTimeout", GVAR(toxicDecompressionTimeout)];
_state set ["toxicDeepStopTimeout", GVAR(toxicDeepStopTimeout)];
_state set ["toxicAscendTimeout", GVAR(toxicAscendTimeout)];
_state set ["noAirTimeout", GVAR(noAirTimeout)];
_state set ["warningTextO2", GVAR(warningTextO2)];
_state set ["warningTextN2", GVAR(warningTextN2)];
_state set ["warningTextAscendRate", GVAR(warningTextAscendRate)];
_state set ["warningTextLowPressure", GVAR(warningTextLowPressure)];
_state set ["warningTextDecompression", GVAR(warningTextDecompression)];
_state set ["surfaceOffgasActive", GVAR(surfaceOffgasPFHID) != -1];

[true, _state]
