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
    GVAR(breathedN2) = 0.79;
    GVAR(breathedHe) = 0;

    GVAR(rateConstantsN2) = [5, 8, 12.5, 18.5, 27, 38.3, 54.3, 77, 109, 146, 187, 239, 305, 390, 498, 635] apply {(ln 2) / _x};
    GVAR(buhlmannA_N2) = [1.1696, 1.0, 0.8618, 0.7562, 0.62, 0.5043, 0.441, 0.4, 0.375, 0.35, 0.3295, 0.3065, 0.2835, 0.261, 0.248, 0.2327];
    GVAR(buhlmannB_N2) = [0.5578, 0.6514, 0.7222, 0.7825, 0.8126, 0.8434, 0.8693, 0.891, 0.9092, 0.9222, 0.9319, 0.9403, 0.9477, 0.9544, 0.9602, 0.9653];
    GVAR(rateConstantsHe) = [1.88, 3.02, 4.72, 6.99, 10.21, 14.48, 20.53, 29.11, 41.2, 55.19, 70.69, 90.34, 115.29, 147.42, 188.24, 240.03] apply {(ln 2) / _x};
    GVAR(buhlmannA_He) = [1.6189, 1.383, 1.1919, 1.0458, 0.922, 0.8205, 0.7305, 0.6502, 0.595, 0.5545, 0.5333, 0.5189, 0.5181, 0.5176, 0.5172, 0.5119];
    GVAR(buhlmannB_He) = [0.477, 0.5747, 0.6527, 0.7223, 0.7582, 0.7957, 0.8279, 0.8553, 0.8757, 0.8903, 0.8997, 0.9073, 0.9122, 0.9171, 0.9217, 0.9267];

    GVAR(partialPressureO2) = 0.21;
    GVAR(partialPressureN2) = 0.79;
    GVAR(lastTickTime) = 0;
    GVAR(inWater) = false;
    GVAR(sprintBlocked) = false;
    GVAR(bentTime) = -BENT_COOLDOWN;


    GVAR(currentAmbientPressure) = 1;
    GVAR(remainingDiveTime) = 0;
    GVAR(maxDepth) = 0;
    GVAR(connectedGas) = false;

#include "initSettings.inc.sqf"

    call FUNC(reset);
};

if (isServer) then {
    GVAR(playerDataHash) = createHashMap;
};

ADDON = true;
