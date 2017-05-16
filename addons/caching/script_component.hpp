#define COMPONENT caching
#define COMPONENT_BEAUTIFIED Caching
#include "\u\uksf\addons\main\script_mod.hpp"

//#define DEBUG_MODE_FULL
//#define DISABLE_COMPILE_CACHE
//#define CBA_DEBUG_SYNCHRONOUS

#include "\u\uksf\addons\main\script_macros.hpp"

#define SERVER_CONDITION !(dynamicSimulationEnabled _x) && \
        {!(isPlayer (leader _x))} && \
        {!(_x getVariable [QGVAR(excluded), false])} && \
        {!((vehicle (leader _x)) isKindOf "Air")} && \
        {(((leader _x) getVariable [QGVAR(time), 0]) + 15) < diag_tickTime}

#define CLIENT_CONDITION !(isPlayer (leader _x)) && \
        {((leader _x) distance _player) > GVAR(distance)} && \
        {((leader _x) distance _player) < (getObjectViewDistance select 0)} && \
        {!(_x getVariable [QGVAR(excluded), false])} && \
        {!((vehicle (leader _x)) isKindOf "Air")} && \
        {(((leader _x) getVariable [QGVAR(time), 0]) + 10) < diag_tickTime || {!(simulationEnabled (leader _x))}} && \
        {[leader _x, _player, true, true] call EFUNC(common,lineOfSight)}
