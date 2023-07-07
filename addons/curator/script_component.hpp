#define COMPONENT curator
#define COMPONENT_BEAUTIFIED Curator
#include "\u\uksf\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define CURATOR_ICON "\A3\Ui_F_Curator\Data\Logos\arma3_zeus_icon_ca.paa"

#define UID_DOWNEY "76561198202076008"
#define UID_WOODS "76561198043837316"
#define UID_CARR "76561198136488003"
#define UID_CONWAY "76561198068496098"
#define UID_DELTA "76561198056452447"

#define CURATOR_WHITELIST (WHITELIST + [UID_DOWNEY, UID_WOODS, UID_CARR, UID_CONWAY, UID_DELTA])
#define CURATOR_WHITELISTED (getPlayerUID player) in CURATOR_WHITELIST
#define CURATOR_ADMIN_OR_HOST IS_ADMIN || {isServer && {hasInterface}}
#define CURATOR_ADMIN_OR_WHITELISTED CURATOR_ADMIN_OR_HOST || {CURATOR_WHITELISTED}
#define CURATOR_MULTIPLAYER_ADMIN_OR_WHITELISTED isMultiplayer && {CURATOR_ADMIN_OR_WHITELISTED}

#define CONDITION_LOGIN ((CURATOR_ADMIN_OR_WHITELISTED) || {!GVAR(curatorsLocked)}) && {(GVAR(curatorPlayers) find (name player)) isEqualTo -1} && {(GVAR(curatorPlayers) find "") > -1}
#define CONDITION_LOGOUT ((CURATOR_ADMIN_OR_WHITELISTED) || {!GVAR(curatorsLocked)}) && {(GVAR(curatorPlayers) find (name player)) != -1}
#define CONDITION_LOCK CURATOR_MULTIPLAYER_ADMIN_OR_WHITELISTED && {!GVAR(curatorsLocked)}
#define CONDITION_UNLOCK CURATOR_MULTIPLAYER_ADMIN_OR_WHITELISTED && {GVAR(curatorsLocked)}
#define CONDITION_KICKALL CURATOR_MULTIPLAYER_ADMIN_OR_WHITELISTED && {({_x != ""} count GVAR(curatorPlayers)) > 1}
