call compile preprocessFileLineNumbers "settings.sqf";

lc_fnc_createObjects = {
    params ["_source"];
    if (!isNil "lc_objectsCreated") exitWith {};
    lc_objectsCreated = true;
    private _loaded = count ([uksf_persistence_persistentObjectsHash] call CBA_fnc_hashKeys);
    ["loaded", format ["%1 %2", _source, _loaded]] call lc_fnc_log;
    for "_i" from 0 to (lc_objects - 1) do {
        private _position = [3000 + (_i mod 20) * 6, 3000 + floor (_i / 20) * 6 + lc_offset, 0];
        private _box = createVehicle ["Box_NATO_Ammo_F", _position, [], 0, "CAN_COLLIDE"];
        [_box] call uksf_persistence_fnc_markObjectAsPersistent;
    };
    createVehicle ["Box_NATO_Wps_F", [2998, 2991, 0], [], 0, "CAN_COLLIDE"];
    private _helipads = nearestObjects [[3004, 2995, 0], ["Land_HelipadEmpty_F"], 2];
    ["helipads", count _helipads] call lc_fnc_log;
    if (lc_legacyCopy > 0 && {_loaded < lc_objects}) then {
        [_helipads#0] call uksf_persistence_fnc_markObjectAsPersistent;
    };
    ["ready", count ([uksf_persistence_persistentObjectsHash] call CBA_fnc_hashKeys)] call lc_fnc_log;
};

["uksf_persistence_loadingFinished", {["event"] call lc_fnc_createObjects}] call CBA_fnc_addEventHandler;
[{["timeout"] call lc_fnc_createObjects}, [], 45] call CBA_fnc_waitAndExecute;
