#define DEBUG_SYNCHRONOUS

#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\x\cba\addons\xeh\script_xeh.hpp"

#include "\u\uksf\addons\main\whitelist.hpp"

#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) FUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

#define ARR_12(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12
#define ARR_14(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14
#define ARR_16(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16
#define ARR_17(ARG1,ARG2,ARG3,ARG4,ARG5,ARG6,ARG7,ARG8,ARG9,ARG10,ARG11,ARG12,ARG13,ARG14,ARG15,ARG16,ARG17) ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8, ARG9, ARG10, ARG11, ARG12, ARG13, ARG14, ARG15, ARG16, ARG17

#define PFORMAT_10(MESSAGE,A,B,C,D,E,F,G,H,I,J) \
    format ['%1: A=%2, B=%3, C=%4, D=%5, E=%6, F=%7, G=%8, H=%9, I=%10, J=%11', MESSAGE, RETNIL(A), RETNIL(B), RETNIL(C), RETNIL(D), RETNIL(E), RETNIL(F), RETNIL(G), RETNIL(H), RETNIL(I), RETNIL(J)]
#ifdef DEBUG_MODE_FULL
    #define TRACE_10(MESSAGE,A,B,C,D,E,F,G,H,I,J) LOG_SYS_FILELINENUMBERS('TRACE',PFORMAT_10(str diag_frameNo + ' ' + (MESSAGE),A,B,C,D,E,F,G,H,I,J))
#else
    #define TRACE_10(MESSAGE,A,B,C,D,E,F,G,H,I,J) /* disabled */
#endif

#define SERVER_COMMAND QUOTE(brexit)

#define WHITELISTED (getPlayerUID player) in WHITELIST
#define ADMIN_OR_HOST IS_ADMIN || {isServer && {hasInterface}}
#define ADMIN_OR_WHITELISTED ADMIN_OR_HOST || {WHITELISTED}
#define MULTIPLAYER_ADMIN_OR_WHITELISTED isMultiplayer && {ADMIN_OR_WHITELISTED}

#define MACRO_ADDWEAPON(WEAPON,COUNT) class _xx_##WEAPON { \
    weapon = #WEAPON; \
    count = COUNT; \
}
#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}
#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}
#define MACRO_ADDBACKPACK(BACKPACK,COUNT) class _xx_##BACKPACK { \
    backpack = #BACKPACK; \
    count = COUNT; \
}

#define INVENTORY_EMPTY class TransportMagazines {}; \
class TransportItems {}; \
class TransportBackpacks {}; \
class TransportWeapons {};

#define INVENTORY_AIRCRAFT class TransportMagazines { \
    MACRO_ADDMAGAZINE(ACE_M14,2); \
    MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2); \
    MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2); \
    MACRO_ADDMAGAZINE(B_IR_Grenade,2); \
}; \
class TransportItems { \
    MACRO_ADDITEM(Toolkit,1); \
    MACRO_ADDITEM(ACE_elasticBandage,4); \
    MACRO_ADDITEM(ACE_packingBandage,4); \
    MACRO_ADDITEM(ACE_morphine,4); \
}; \
class TransportBackpacks { \
    MACRO_ADDBACKPACK(B_Parachute,6); \
}; \
class TransportWeapons {};
