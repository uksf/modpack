#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(pathEventsByGroup) = createHashMap;

[QEGVAR(virtualisation,pathExpansionCompleted), {
    params ["_id", "_slot", "_status", "_intermediateCount"];
    private _events = GVAR(pathEventsByGroup) getOrDefault [_id, []];
    _events pushBack [_slot, _status, _intermediateCount];
    GVAR(pathEventsByGroup) set [_id, _events];
}] call CBA_fnc_addEventHandler;

ADDON = true;
