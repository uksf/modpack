#define COMPONENT menu
#define COMPONENT_BEAUTIFIED Menu
#include "\u\uksf\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define DIRECTCONNECT_XSCALE (((safezoneW / safezoneH) min 1.2) / 40)
#define DIRECTCONNECTLIST_X (safeZoneX + 2 * DIRECTCONNECT_XSCALE)
#define DIRECTCONNECTBUTTON_X DIRECTCONNECTLIST_X + (9 * (pixelW * pixelGrid * 2))
#define DIRECTCONNECTLOGO_X (DIRECTCONNECTLIST_X - (1.8 * (pixelH * pixelGrid * 2)))
