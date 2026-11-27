#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Resets dive variables and returns tissues to surface equilibrium on air

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_reset
*/

GVAR(currentDepth) = 0;
GVAR(currentAmbientPressure) = 1;
GVAR(remainingDiveTime) = 0;
GVAR(maxDepth) = 0;
GVAR(previousDepth) = 0;
GVAR(ascendRate) = 0;
GVAR(deepStopDone) = false;
GVAR(stopRecalcTime) = 0;

call FUNC(clearDecompression);

if (GVAR(sprintBlocked)) then {
    player allowSprint true;
    GVAR(sprintBlocked) = false;
};

GVAR(toxicO2Timeout) = 10;
GVAR(toxicN2Timeout) = 10;
GVAR(toxicDecompressionTimeout) = 10;
GVAR(toxicDeepStopTimeout) = 180;
GVAR(toxicAscendTimeout) = 10;
GVAR(noAirTimeout) = NO_AIR_TIMEOUT;

GVAR(warningTextO2) = "";
GVAR(warningTextN2) = "";
GVAR(warningTextAscendRate) = "";
GVAR(warningTextLowPressure) = "";
GVAR(warningTextDecompression) = "";
GVAR(warningText) = "";

GVAR(currentPressure) = GVAR(currentGasLiters) / GVAR(currentVolume);
if (GVAR(currentPercentO2) > 0) then {
    private _breathingVolumePerMinute = AIR_USAGE_IDLE / GVAR(currentPercentO2);
    private _currentAirUsage = _breathingVolumePerMinute / 60;
    GVAR(remainingDiveTime) = GVAR(currentGasLiters) / _currentAirUsage;
} else {
    GVAR(remainingDiveTime) = 0;
};
GVAR(connectedGas) = false;
