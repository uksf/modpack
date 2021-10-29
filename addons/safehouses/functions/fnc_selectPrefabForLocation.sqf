#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Selects the best prefab for the location based on nearby objects and prefab anchor objects
        If no best anchor can be found, select a random prefab
        If a pre-assigned prefab Id is given, use that prefab data if present

    Parameters:
        0: Position <ARRAY>
        1: Pre-assigned prefab ID <STRING>

    Return value:
        Array of prefab data and optional terrain object center
*/
params ["_position", "_prefabId"];

private _buildings = [GVAR(missionObjects), _position] call FUNC(getLocationBuildings);

if (_prefabId in GVAR(prefabs)) exitWith {
    // If a nearby building with anchor type exists, use it, else just use prefab
    private _prefab = GVAR(prefabs) get _prefabId;
    private _type = _prefab#3#0#0;
    private _anchorTypes = _buildings select {typeOf _x == _type};
    if (_anchorTypes isEqualTo []) exitWith {
        [_prefab, objNull]
    };

    [_prefab, _anchorTypes#0]
};

private _prefabs = values GVAR(prefabs);
if (_buildings isEqualTo []) exitWith {
    [selectRandom _prefabs, objNull]
};

// Find buildings with matching prefab anchors
private _buildingsWithMatchingPrefabs = _buildings apply {
    private _type = typeOf _x;
    private _matchingPrefabs = _prefabs select {_x#3#0#0 == _type};

    if (_matchingPrefabs isEqualTo []) then {
        [objNull]
    } else {
        [_x, _matchingPrefabs]
    };
} select {!(isNull (_x#0))};

// If none, return random prefab
if (_buildingsWithMatchingPrefabs isEqualTo []) exitWith {
    [selectRandom _prefabs, objNull]
};

// Select a random building, and use one of the matching prefabs
private _building = selectRandom _buildingsWithMatchingPrefabs;
[selectRandom (_building#1), _building#0]
