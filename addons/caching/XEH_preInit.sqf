#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(cachedGroupsData) = createHashMap;
GVAR(cachedGroupsPositions) = [];

if (isServer) then {
    [QGVAR(cache), {
        params ["_group"];

        if (_group isEqualType objNull) then {
            _group = group _group;
        };
        [QGVAR(setCacheState), [_group, true]] call CBA_fnc_localEvent;

    }] call CBA_fnc_addEventHandler;

    [QGVAR(uncache), {
        params ["_group"];

        if (_group isEqualType objNull) exitWith {
            _group = group _group;
        };
        [QGVAR(setCacheState), [_group, false]] call CBA_fnc_localEvent;

    }] call CBA_fnc_addEventHandler;



    [QGVAR(setCacheState), {
        params ["_group", "_state"]; // will cache = true, will uncache = false

        if (_state) exitWith {
            // delete group and store details
            systemChat format ["Group %1 was cached.", _group];
            [_group] call FUNC(storeGroupDataAndDelete);
        };

        [_uid, _groupData] call FUNC(recreateGroup);

    }] call CBA_fnc_addEventHandler;
};

#include "initSettings.sqf"

ADDON = true;
