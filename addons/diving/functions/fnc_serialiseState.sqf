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
*/

private _diving = GVAR(updatePFHID) != -1;
if (!_diving) exitWith {
    [false]
};

[
    _diving,
    GVAR(currentGasLiters),
    GVAR(currentVolume),
    GVAR(currentPressure),
    GVAR(currentPercentO2),
    GVAR(currentPercentN2),
    GVAR(currentPercentHe),
    GVAR(previousAmbientPressure),
    GVAR(previousDepth),
    GVAR(saturationO2),
    GVAR(saturationHe),
    GVAR(saturationN2),
    GVAR(remainingDiveTime),
    GVAR(elapsedDiveTime),
    GVAR(maxDepth),
    GVAR(previousDepth),
    GVAR(previousAmbientPressure),

    GVAR(ascendRate),
    GVAR(decompressDepthB),
    GVAR(decompressDepth),
    GVAR(decompressTime),
    GVAR(decompressPreviousDepth),
    GVAR(deepStopDepth),
    GVAR(deepStopTime),
    GVAR(needDecompress),
    GVAR(needDeepStop),

    GVAR(pain),
    GVAR(toxicO2Timeout),
    GVAR(toxicN2Timeout),
    GVAR(toxicDecompressionTimeout),
    GVAR(toxicDeepStopTimeout),
    GVAR(toxicAscendTimeout),
    GVAR(noAirTimeout)
]
