#define COMPONENT aiQrf
#define COMPONENT_BEAUTIFIED AI Quick Reaction Forces
#include "\u\uksf\addons\main\script_mod.hpp"
#include "\u\uksf\addons\main\script_macros.hpp"

#define HIT_MAX_SHOOTER_SPEED 30
#define HIT_MAX_DISTANCE_TO_SHOOTER 1000

#define SUPPORT_MIN_SUPPRESSED_KNOWS_ABOUT 2
#define SUPPORT_DISTANCE_TO_RETRY 10
#define SUPPORT_CONDITION_BASE private _group = group _x; \
    ((side _x) isEqualTo (side _unit)) && \
    {_group != group _unit && \
    {_x isEqualTo (leader _group) && \
    {!(_group getVariable [QGVAR(supportTasked), false]) && \
    {!((behaviour _unit) isEqualTo "COMBAT")}}}}

#define SUPPORT_CONDITION_PROXIMITY ((side _x) isEqualTo (side _unit)) && \
    {_x getVariable [QGVAR(hasSupportRadio), true]}
