#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Determines if any effects are needed based on diving state

    Parameter(s):
        None

    Return Value:
        None
*/

if (GVAR(noAirTimeout) <= 0) exitWith {
    player setDamage 1;
};

GVAR(warningTextLowPressure) = ["", "!LOW AIR!"] select (GVAR(currentPressure) < 50);

if (GVAR(needDeepStop) && (GVAR(deepStopTime) > 1) && ((GVAR(currentDepth) - 2) > GVAR(deepStopDepth))) then {
    player allowSprint true;
    GVAR(toxicDeepStopTimeout) = GVAR(toxicDeepStopTimeout) - 1;
    GVAR(deepStopDepth) = 0;
    GVAR(deepStopTime) = 0;
};

if (GVAR(toxicDeepStopTimeout) <= 0) then {
    player allowSprint false;
};

if (GVAR(deepStopTime) <= 0) then {
    GVAR(deepStopTime) = 0;
    GVAR(deepStopDepth) = 0;
    GVAR(needDeepStop) = false;
    GVAR(toxicDeepStopTimeout) = 180;
};

if (GVAR(currentDepth) > GVAR(maxDepth)) then {
    GVAR(warningTextO2) = "!ppO2!";
    playSound QGVAR(beep);
    GVAR(toxicO2Timeout) = GVAR(toxicO2Timeout) - 1;
    if (GVAR(toxicO2Timeout) == 0) then {
        call FUNC(effectToxicO2);
        GVAR(toxicO2Timeout) = 2;
    };
} else {
    GVAR(warningTextO2) = "";
    GVAR(toxicO2Timeout) = 10;
};

if ((GVAR(decompressTime) > 0) && (GVAR(ascendRate) > 1)) then {
    GVAR(warningTextAscendRate) = "!ASC RATE!";
    playSound QGVAR(beep);
    GVAR(toxicAscendTimeout) = GVAR(toxicAscendTimeout) - 1;
    if (GVAR(toxicAscendTimeout) == 0) then {
        GVAR(pain) = player getVariable ["ace_medical_pain", 0];
        [player, GVAR(pain) + 0.1] call ace_medical_fnc_adjustPainLevel;
        GVAR(toxicAscendTimeout) = 5;
    };
} else {
    GVAR(warningTextAscendRate) = "";
    GVAR(toxicAscendTimeout) = 10;
};

if ((GVAR(decompressTime) > 0) && (GVAR(currentDepth) < (GVAR(decompressDepth) - 2.5))) then {
    GVAR(toxicDecompressionTimeout) = GVAR(toxicDecompressionTimeout) - 1;
    GVAR(warningTextDecompression) = "!DECO!";
    playSound QGVAR(beep);
    if (GVAR(toxicDecompressionTimeout) == 0) then {
        call FUNC(effectToxicDecompression);
        GVAR(toxicDecompressionTimeout) = 2;
    };
} else {
    GVAR(warningTextDecompression) = "";
    GVAR(toxicDecompressionTimeout) = 10;
};

if (GVAR(partialPressureN2) > 3.5 ) then {
    GVAR(warningTextN2) = "!ppN2!";
    GVAR(toxicN2Timeout) = GVAR(toxicN2Timeout) - 1;
    if (GVAR(toxicN2Timeout) == 0) then {
        call FUNC(effectToxicN2);
        GVAR(toxicN2Timeout) = 2;
    };
} else {
    GVAR(warningTextN2) = "";
    GVAR(toxicN2Timeout) = 10;
};

if (GVAR(currentPressure) <= 0) then {
    GVAR(noAirTimeout) = GVAR(noAirTimeout) - 1;
};
