#include "script_component.hpp"

[{
    {deleteGroup _x} foreach allGroups;
}, 300, []] call CBA_fnc_addPerFrameHandler;

GVAR(HCs) = [];
{
    GVAR(HCs) pushBack [owner _x];
} forEach (entities "HeadlessClient_F");