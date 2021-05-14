#define COMPONENT diving
#define COMPONENT_BEAUTIFIED Diving
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CYLINDER(BASE,NAME) ##BASE####NAME
#define CYLINDERS(varNAME,varDISPLAYNAME,varDESCRIPTION,varO2,varN2,varHE) class CYLINDER(GVAR(cylinderSingle),varNAME) : GVAR(cylinderSingleBase) { \
    scope = 2; \
    scopeArsenal = 2; \
    displayName = QUOTE(Single 6L cylinder (varDISPLAYNAME)); \
    descriptionShort = QUOTE(Single 6L cylinder filled with 300bar of varDESCRIPTION.); \
    GVAR(cylinderGasLiters) = 1800; \
    GVAR(cylinderVolume) = 6; \
    GVAR(cylinderPressure) = 300; \
    GVAR(cylinderPercentO2) = varO2; \
    GVAR(cylinderPercentN2) = varN2; \
    GVAR(cylinderPercentHe) = varHE; \
    GVAR(usedReplacement) = QGVAR(cylinderSingleEmpty); \
}; \
class CYLINDER(GVAR(cylinderDouble),varNAME) : GVAR(cylinderDoubleBase) { \
    scope = 2; \
    scopeArsenal = 2; \
    displayName = QUOTE(Linked 6L cylinders (varDISPLAYNAME)); \
    descriptionShort = QUOTE(Linked 6L cylinders filled with 300bar of varDESCRIPTION.); \
    GVAR(cylinderGasLiters) = 3600; \
    GVAR(cylinderVolume) = 12; \
    GVAR(cylinderPressure) = 300; \
    GVAR(cylinderPercentO2) = varO2; \
    GVAR(cylinderPercentN2) = varN2; \
    GVAR(cylinderPercentHe) = varHE; \
    GVAR(usedReplacement) = QGVAR(cylinderDoubleEmpty); \
}

#define SPEED_NORMAL 0.5
#define SPEED_FAST 2
#define AIR_USAGE_IDLE 10
#define AIR_USAGE_NORMAL 20
#define AIR_USAGE_FAST 40
