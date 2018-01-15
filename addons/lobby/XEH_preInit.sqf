#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(unitGroups) = [];
GVAR(firstRespawn) = true;
[QGVAR(respawned), {[QEGVAR(common,addObjectsToCurators), []] call CBA_fnc_serverEvent}] call CBA_fnc_addEventHandler;

if (isServer) then {
    [QGVAR(addGroup), {
        params ["_groupName"];
        if (({(groupId _x) isEqualTo _groupName} count GVAR(unitGroups)) == 0) then {
            private _group = createGroup west;
            _group setGroupIdGlobal [_groupName];
            GVAR(unitGroups) pushBack _group;
            publicVariable QGVAR(unitGroups);
        };
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
