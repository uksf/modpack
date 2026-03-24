#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Build and validate commander spawn catalog from faction/groups module settings.

    Parameters:
        0: Commander module <OBJECT>

    Return Value:
        Catalog entries <ARRAY>
*/

params [["_commander", objNull, [objNull]]];

if (!isServer || {isNull _commander}) exitWith {[]};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _faction = _commander getVariable [QGVAR(faction), ""];
private _groupsRaw = _commander getVariable [QGVAR(groups), "[]"];

private _requestedGroups = [];
if (_groupsRaw isEqualType []) then {
    _requestedGroups = _groupsRaw;
} else {
    if (_groupsRaw isEqualType "") then {
        _requestedGroups = parseSimpleArray _groupsRaw;
    };
};

if !(_requestedGroups isEqualType []) then {
    _requestedGroups = [];
};

private _requestedLookup = _requestedGroups apply {
    if (_x isEqualType "") then {
        toLower _x
    } else {
        toLower (str _x)
    }
};
private _catalog = [];

if (_faction isEqualTo "" || {_requestedLookup isEqualTo []}) exitWith {
    _commander setVariable [QGVAR(groupCatalog), []];
    []
};

private _sideCfgName = switch (true) do {
    case (_commanderSide isEqualTo west): {"West"};
    case (_commanderSide isEqualTo east): {"East"};
    case (_commanderSide isEqualTo independent): {"Indep"};
    default {""};
};

if (_sideCfgName isEqualTo "") exitWith {
    _commander setVariable [QGVAR(groupCatalog), []];
    []
};

private _factionCfg = configFile >> "CfgGroups" >> _sideCfgName >> _faction;
if (!isClass _factionCfg) exitWith {
    _commander setVariable [QGVAR(groupCatalog), []];
    ["CATALOG", _commander, createHashMapFromArray [
        ["reason", "faction_not_found"],
        ["message", format ["faction=%1 sideCfg=%2", _faction, _sideCfgName]]
    ]] call FUNC(logExecution);
    []
};

{
    if (!isClass _x) then {continue};
    private _categoryName = configName _x;

    {
        if (!isClass _x) then {continue};

        private _groupClass = configName _x;
        if ((toLower _groupClass) in _requestedLookup) then {
            private _groupType = [_x] call FUNC(inferGroupType);
            if (_groupType isEqualTo "unsupported") then {continue};

            _catalog pushBack (createHashMapFromArray [
                ["groupClass", _groupClass],
                ["sideCfgName", _sideCfgName],
                ["faction", _faction],
                ["category", _categoryName],
                ["type", _groupType]
            ]);
        };
    } forEach configProperties [_x, "isClass _x"];
} forEach configProperties [_factionCfg, "isClass _x"];

_commander setVariable [QGVAR(groupCatalog), _catalog];

["CATALOG", _commander, createHashMapFromArray [
    ["reason", "built"],
    ["message", format ["requested=%1 validated=%2 faction=%3", count _requestedLookup, count _catalog, _faction]]
]] call FUNC(logExecution);

_catalog
