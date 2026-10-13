call compile preprocessFileLineNumbers "settings.sqf";
lc_fnc_roundTrip = compile preprocessFileLineNumbers "roundtrip.sqf";
lc_fnc_statsServer = compile preprocessFileLineNumbers "stats.sqf";

lc_fnc_createObjects = {
    params ["_source"];
    if (!isNil "lc_objectsCreated") exitWith {};
    lc_objectsCreated = true;
    private _loaded = count ([uksf_persistence_persistentObjectsHash] call CBA_fnc_hashKeys);
    lc_loadedCount = _loaded;
    private _saved = count (uksf_persistence_dataNamespace getVariable ["uksf_persistence_objects", []]);
    ["loaded", format ["%1 %2", _source, _loaded]] call lc_fnc_log;
    if (!lc_createOnce || {_saved == 0}) then {
        for "_i" from 0 to (lc_objects - 1) do {
            private _position = [3000 + (_i mod 20) * 6, 3000 + floor (_i / 20) * 6 + lc_offset, 0];
            private _box = createVehicle ["Box_NATO_Ammo_F", _position, [], 0, "CAN_COLLIDE"];
            [_box] call uksf_persistence_fnc_markObjectAsPersistent;
        };
        (createVehicle ["Box_NATO_Wps_F", [2998, 2991, 0], [], 0, "CAN_COLLIDE"]) setPosASL [2998.1234, 2991.5678, 5];
    };
    private _helipads = nearestObjects [[3004, 2995, 0], ["Land_HelipadEmpty_F"], 2];
    ["helipads", count _helipads] call lc_fnc_log;
    if (lc_legacyCopy > 0 && {_loaded < lc_objects}) then {
        [_helipads#0] call uksf_persistence_fnc_markObjectAsPersistent;
    };
    private _savedMarkers = (uksf_persistence_dataNamespace getVariable ["uksf_persistence_mapMarkers", []]) select {_x param [9, ""] == "LC Marker"};
    ["markers", str _savedMarkers] call lc_fnc_log;
    if (_savedMarkers isEqualTo []) then {
        private _marker = createMarker ["_USER_DEFINED #0/990/1", [3010.25, 2990.75]];
        _marker setMarkerType "hd_dot";
        _marker setMarkerColor "ColorRed";
        _marker setMarkerDir 42.5;
        _marker setMarkerText "LC Marker";
        ["uksf_persistence_markerCreated", [[_marker] call uksf_persistence_fnc_serializeMarker]] call CBA_fnc_serverEvent;
    };
    if (lc_roundTrip) then {[_saved] call lc_fnc_roundTrip};
    if (lc_stats) then {call lc_fnc_statsServer};
    ["ready", count ([uksf_persistence_persistentObjectsHash] call CBA_fnc_hashKeys)] call lc_fnc_log;
};

if (lc_captureFreeze > 0) then {
    [{(missionNamespace getVariable ["lc_loadedCount", 0]) > 0 && {(missionNamespace getVariable ["uksf_persistence_saveObjectQueue", []]) isNotEqualTo []}}, {
        [lc_captureFreeze] call lc_fnc_freeze;
    }] call CBA_fnc_waitUntilAndExecute;
};

["uksf_persistence_loadingFinished", {["event"] call lc_fnc_createObjects}] call CBA_fnc_addEventHandler;
[{["timeout"] call lc_fnc_createObjects}, [], 45] call CBA_fnc_waitAndExecute;
