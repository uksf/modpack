#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Resets dive variables

    Parameter(s):
        None

    Return Value:
        None
*/

GVAR(currentAmbientPressure) = (GVAR(currentDepth) / 10) + 1;
GVAR(currentDepth) = 0;
GVAR(remainingDiveTime) = 0;
GVAR(maxDepth) = 0;
GVAR(previousDepth) = 0;
GVAR(previousAmbientPressure) = 0;

GVAR(ascendRate) = 0;
GVAR(decompressDepthB) = 0;
GVAR(decompressDepth) = 0;
GVAR(decompressTime) = 0;
GVAR(decompressPreviousDepth) = 0;
GVAR(deepStopDepth) = 0;
GVAR(deepStopTime) = 0;
GVAR(needDecompress) = false;
GVAR(needDeepStop) = false;

GVAR(pain) = 0;
GVAR(toxicO2Timeout) = 10;
GVAR(toxicN2Timeout) = 10;
GVAR(toxicDecompressionTimeout) = 10;
GVAR(toxicDeepStopTimeout) = 180;
GVAR(toxicAscendTimeout) = 10;
GVAR(noAirTimeout) = 120;

GVAR(warningTextO2) = "";
GVAR(warningTextN2) = "";
GVAR(warningTextAscendRate) = "";
GVAR(warningTextLowPressure) = "";
GVAR(warningTextDecompression) = "";

