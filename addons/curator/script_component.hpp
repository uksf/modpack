#define COMPONENT curator
#define COMPONENT_BEAUTIFIED Curator
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CURATOR_ICON "\A3\Ui_F_Curator\Data\Logos\arma3_zeus_icon_ca.paa"

#define CONDITION_LOGIN ((ADMIN_OR_HOST) || {!GVAR(curatorsLocked)}) && {(GVAR(curatorPlayers) find (name player)) isEqualTo -1} && {(GVAR(curatorPlayers) find "") > -1}
#define CONDITION_LOGOUT ((ADMIN_OR_HOST) || {!GVAR(curatorsLocked)}) && {(GVAR(curatorPlayers) find (name player)) != -1}
#define CONDITION_LOCK MULTIPLAYER_ADMIN_OR_WHITELISTED && {!GVAR(curatorsLocked)}
#define CONDITION_UNLOCK MULTIPLAYER_ADMIN_OR_WHITELISTED && {GVAR(curatorsLocked)}
#define CONDITION_KICKALL MULTIPLAYER_ADMIN_OR_WHITELISTED && {({_x != ""} count GVAR(curatorPlayers)) > 1}
