#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    [QGVAR(disableCache), {call FUNC(disableCache)}] call CBA_fnc_addEventHandler;
    [QGVAR(enableCache), {call FUNC(enableCache)}] call CBA_fnc_addEventHandler;

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
        params ["_group", "_state"]; // Cached = true, Uncached = false

        {
            _x enableSimulationGlobal !_state;
            _x hideObjectGlobal _state;
            _x setVariable [QGVAR(hiddenByCaching), _state, true];
        } forEach (units _group);

        private _leader = leader _group;
        private _vehicle = objectParent _leader;
        if (!(isNull _vehicle)) then {
            {
                _x enableSimulationGlobal !_state;
                _x hideObjectGlobal _state;
                _x setVariable [QGVAR(hiddenByCaching), _state, true];
            } forEach (crew _vehicle);
        };
    }] call CBA_fnc_addEventHandler;

    {
        [_x, "initPost", {(group (_this#0)) setVariable [QGVAR(excluded), true, true]}, true] call CBA_fnc_addClassEventHandler;
    } forEach ["B_UAV_AI", "O_UAV_AI", "I_UAV_AI"];
};

#include "initSettings.inc.sqf"

ADDON = true;
