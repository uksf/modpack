#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (hasInterface) then {
    GVAR(dataPublishTime) = 0;
    GVAR(updatePFHID) = -1;
    GVAR(diveComputerUpdatePFHID) = -1;

    GVAR(elapsedDiveTime) = 0;
    GVAR(currentGasLiters) = 6;
    GVAR(currentVolume) = 6;
    GVAR(currentPressure) = 6;
    GVAR(currentDepth) = 0;

    GVAR(currentPercentO2) = 0.21;
    GVAR(currentPercentN2) = 0.79;
    GVAR(currentPercentHe) = 0;

    GVAR(saturationO2) = 0;
    GVAR(partialPressureO2) = 0.21;
    GVAR(saturationN2) = 0;
    GVAR(partialPressureN2) = 0.78;
    GVAR(saturationHe) = 0;
    GVAR(partialPressureHe) = 0;

    GVAR(saturationCoefficient) = (ln 2) / 4;

    GVAR(currentAmbientPressure) = 1;
    GVAR(remainingDiveTime) = 0;
    GVAR(maxDepth) = 0;
    GVAR(previousDepth) = 0;
    GVAR(previousAmbientPressure) = 0;
    GVAR(ascendRate) = 0;
    GVAR(decompressDepthB) = 0;
    GVAR(decompressDepth) = 0;
    GVAR(decompressTime) = 0;
    GVAR(deepStopDepth) = 0;
    GVAR(deepStopTime) = 0;
    GVAR(needDecompress) = false;
    GVAR(needDeepStop) = false;
    GVAR(connectedGas) = false;
    GVAR(wearMaskOnLand) = true;
    GVAR(surfaceCheckPFHID) = -1;

    call FUNC(reset);
};

if (isServer) then {
    GVAR(playerDataHash) = createHashMap;
};

ADDON = true;
