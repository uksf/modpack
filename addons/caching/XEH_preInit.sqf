#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    [QGVAR(disableCache), {call FUNC(disableCache)}] call CBA_fnc_addEventHandler;
    // [QGVAR(hideObjectGlobal), {
    //     params [["_object", objNull, [objNull, grpNull]], "_state"];

    //     if (_object isEqualType grpNull) then {
    //         {                
    //             _x hideObjectGlobal _state;
    //             _x setVariable [QGVAR(hiddenByCaching), _state, true];
    //         } forEach (units _object);
    //     } else {
    //         _object hideObjectGlobal _state;
    //         _object setVariable [QGVAR(hiddenByCaching), _state, true];
    //     };
    // }] call CBA_fnc_addEventHandler;

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
};
// [QGVAR(setDynamicSimulation), {(_this#0) enableDynamicSimulation (_this#1)}] call CBA_fnc_addEventHandler;

#include "initSettings.sqf"

ADDON = true;
