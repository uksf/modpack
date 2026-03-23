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

    GVAR(saturationCoefficients) = [(ln 2) / 4, (ln 2) / 12.5, (ln 2) / 27];
    GVAR(buhlmannA_N2) = [1.2599, 1.0000, 0.8618];
    GVAR(buhlmannB_N2) = [0.5050, 0.6514, 0.7562];
    GVAR(buhlmannA_He) = [1.7435, 1.3838, 1.1919];
    GVAR(buhlmannB_He) = [0.1911, 0.2810, 0.3446];

    GVAR(saturationO2) = [0, 0, 0];
    GVAR(partialPressureO2) = 0.21;
    GVAR(saturationN2) = [0, 0, 0];
    GVAR(partialPressureN2) = 0.78;
    GVAR(saturationHe) = [0, 0, 0];
    GVAR(partialPressureHe) = 0;

    GVAR(surfaceOffgasPFHID) = -1;

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

#include "initSettings.inc.sqf"

    call FUNC(reset);
};

if (isServer) then {
    GVAR(playerDataHash) = createHashMap;
};

ADDON = true;
