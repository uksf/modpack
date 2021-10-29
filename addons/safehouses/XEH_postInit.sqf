#include "script_component.hpp"

if !(isServer) exitWith {};

GVAR(missionObjects) = +EGVAR(common,missionObjectsMinusUnits);

{
    _x call FUNC(initPrefab);
} forEach GVAR(prefabAreaModules);
