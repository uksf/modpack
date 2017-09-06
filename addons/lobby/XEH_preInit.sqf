#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(unitGroups) = [];
if (isServer) then {
    private _unitNameConfigs = ("true" configClasses (configFile >> "CfgUnitNames"));
    {
        private _unit = getArray _x;
        private _groupName = _unit select 0;
        if (({groupId _x != _groupName} count GVAR(unitGroups)) isEqualTo 0) then {
            private _group = createGroup [west, false];
            _group setGroupIdGlobal [_groupName];
            GVAR(unitGroups) pushBack _group;
        };
        false
    } count _unitNameConfigs;
    publicVariable QGVAR(unitGroups);
};

ADDON = true;
