#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (hasInterface) then {
    GVAR(previousTime) = -1;
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

    call FUNC(reset);
};

if (isServer) then {
    GVAR(playerDataHash) = createHashMap;
};

ADDON = true;
