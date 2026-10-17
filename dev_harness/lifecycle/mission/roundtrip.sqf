params [["_loaded", -1]];

if (!isServer) exitWith {
    [{!isNil "lc_rtPhase" && {!isNull player} && {alive player}}, {
        if (lc_rtPhase == "A") exitWith {
            [{!isNil "lc_rtGo"}, {
                player addItemToUniform "ACE_morphine";
                player addItemToUniform "ACE_morphine";
                player addItem "Chemlight_blue";
                [player, player, ["Chemlight_blue"], true] call ace_attach_fnc_attach;
                player setVariable ["ACE_hasEarPlugsIn", true, true];
                [player, 0.3, "leftleg", "bullet"] call ace_medical_fnc_addDamageToUnit;
                player moveInCargo lc_rtVehicle;
                [{
                    ["lc_note", ["rtReady", str [typeOf vehicle player, player getVariable ["ace_attach_attached", []]]]] call CBA_fnc_serverEvent;
                    [] call uksf_persistence_fnc_startShutdown;
                }, [], 10] call CBA_fnc_waitAndExecute;
            }] call CBA_fnc_waitUntilAndExecute;
        };
        [{!isNil "uksf_persistence_data"}, {
            ["lc_note", ["redeployData", count uksf_persistence_data]] call CBA_fnc_serverEvent;
            uksf_persistence_selectedRespawn = "respawn_west_persistence";
            call uksf_persistence_fnc_loadRedeployData;
            [{["lc_probePlayer", [player]] call CBA_fnc_serverEvent}, [], 20] call CBA_fnc_waitAndExecute;
        }, [], 120, {["lc_note", ["noRedeployData"]] call CBA_fnc_serverEvent}] call CBA_fnc_waitUntilAndExecute;
    }] call CBA_fnc_waitUntilAndExecute;
};

lc_fnc_rtDump = {
    params ["_label"];
    [uksf_persistence_persistentObjectsHash, {
        if (!isNull _value && {alive _value} && {!(typeOf _value in ["Box_NATO_Ammo_F", "Box_NATO_Wps_F"])}) then {
            [_label, format ["%1 %2", _key, str ([_value] call uksf_persistence_fnc_getObjectData)]] call lc_fnc_log;
        };
    }] call CBA_fnc_hashEachPair;
};

lc_fnc_rtPersistent = {
    params ["_type", "_position"];
    private _object = createVehicle [_type, _position, [], 0, "NONE"];
    [_object] call uksf_persistence_fnc_markObjectAsPersistent;
    _object
};

addMissionEventHandler ["PlayerDisconnected", {
    params ["", "_uid"];
    [{
        params ["_uid"];
        ["playerData", format ["%1 %2", _uid, str (uksf_persistence_dataNamespace getVariable [_uid, []])]] call lc_fnc_log;
    }, [_uid], 0.5] call CBA_fnc_waitAndExecute;
}];

if (_loaded == 0) exitWith {
    lc_rtPhase = "A";
    publicVariable "lc_rtPhase";

    private _mrap = ["B_MRAP_01_hmg_F", [3040, 2960, 0]] call lc_fnc_rtPersistent;
    _mrap setFuel 0.37;
    _mrap setDamage 0.2;
    clearWeaponCargoGlobal _mrap;
    clearMagazineCargoGlobal _mrap;
    clearItemCargoGlobal _mrap;
    clearBackpackCargoGlobal _mrap;
    _mrap addWeaponCargoGlobal ["arifle_MX_F", 2];
    _mrap addMagazineCargoGlobal ["30Rnd_65x39_caseless_mag", 5];
    _mrap addItemCargoGlobal ["FirstAidKit", 3];
    _mrap addBackpackCargoGlobal ["B_AssaultPack_mcamo", 1];
    _mrap setVehicleAmmo 0.5;
    ["ACE_Wheel", _mrap, true] call ace_cargo_fnc_loadItem;
    private _crate = createVehicle ["Box_NATO_Equip_F", [3045, 2945, 0], [], 0, "NONE"];
    clearItemCargoGlobal _crate;
    _crate addItemCargoGlobal ["ACE_fieldDressing", 7];
    _crate setVariable ["ace_cargo_customName", "LC Crate", true];
    ["cargoLoaded", [_crate, _mrap, true] call ace_cargo_fnc_loadItem] call lc_fnc_log;
    _mrap setVariable ["ace_cargo_customName", "LC Truck", true];
    _mrap setVariable ["ace_medical_isMedicalVehicle", true, true];
    _mrap setVariable ["ace_medical_medicClass", 1, true];
    _mrap setVariable ["ace_isRepairVehicle", 1, true];
    private _light = createVehicle ["Chemlight_green", [0, 0, 0], [], 0, "CAN_COLLIDE"];
    _light attachTo [_mrap, [0, -2, 1]];
    _mrap setVariable ["ace_attach_attached", [[_light, "Chemlight_green"]], true];
    lc_rtVehicle = _mrap;
    publicVariable "lc_rtVehicle";

    private _plane = ["B_Plane_CAS_01_dynamicLoadout_F", [3120, 2900, 0]] call lc_fnc_rtPersistent;
    _plane setPylonLoadout [1, "PylonMissile_1Rnd_Mk82_F", true];
    _plane setAmmoOnPylon [3, 1];
    _plane setFuel 0.5;

    private _fence = ["Land_BagFence_Round_F", [3020, 2950, 0]] call lc_fnc_rtPersistent;
    _fence setVectorDirAndUp [[0.6, 0.8, 0], [0.0995, 0, 0.995]];
    _fence setVariable ["uksf_persistence_isAceFortification", true, true];
    _fence setVariable ["uksf_persistence_aceFortifySide", east, true];

    private _tent = ["Land_MedicalTent_01_MTP_closed_F", [3060, 2930, 0]] call lc_fnc_rtPersistent;
    _tent setVariable ["ace_medical_isMedicalFacility", true, true];
    _tent setVariable ["ace_isRepairFacility", 1, true];

    private _truck = ["B_Truck_01_ammo_F", [3080, 2960, 0]] call lc_fnc_rtPersistent;
    _truck setAmmoCargo 0.4;

    private _quad = ["B_Quadbike_01_F", [3090, 2930, 0]] call lc_fnc_rtPersistent;
    ["quadId", _quad getVariable ["uksf_persistence_persistenceID", ""]] call lc_fnc_log;
    [{(_this#0) setDamage 1}, [_quad], 5] call CBA_fnc_waitAndExecute;

    private _grenades = allMissionObjects "Box_NATO_Grenades_F";
    ["grenadeIds", str (_grenades apply {_x getVariable ["uksf_persistence_persistenceID", ""]})] call lc_fnc_log;
    {deleteVehicle _x} forEach _grenades;

    private _poly = createMarker ["_USER_DEFINED #0/992/1", [3000, 3000]];
    _poly setMarkerShape "POLYLINE";
    _poly setMarkerPolyline [3000, 3000, 3050.5, 3020.25, 3100, 2990];
    _poly setMarkerColor "ColorBlue";
    ["uksf_persistence_markerCreated", [[_poly] call uksf_persistence_fnc_serializeMarker]] call CBA_fnc_serverEvent;
    private _gone = createMarker ["_USER_DEFINED #0/993/1", [3020, 3020]];
    _gone setMarkerType "hd_destroy";
    _gone setMarkerText "LC Deleted";
    ["uksf_persistence_markerCreated", [[_gone] call uksf_persistence_fnc_serializeMarker]] call CBA_fnc_serverEvent;
    [{
        deleteMarker "_USER_DEFINED #0/993/1";
        ["uksf_persistence_markerDeleted", ["_USER_DEFINED #0/993/1"]] call CBA_fnc_serverEvent;
    }, [], 2] call CBA_fnc_waitAndExecute;

    ["uksf_persistence_shutdownStarted", {
        ["rtA"] call lc_fnc_rtDump;
        ["markersSaved", str uksf_persistence_mapMarkers] call lc_fnc_log;
    }] call CBA_fnc_addEventHandler;

    [{!isNil "lc_hcReady" && {!isNull lc_rtVehicle}}, {
        lc_rtGo = true;
        publicVariable "lc_rtGo";
    }] call CBA_fnc_waitUntilAndExecute;
};

lc_rtPhase = "B";
publicVariable "lc_rtPhase";
["customLoaded", str (missionNamespace getVariable ["lc_customLoaded", "none"])] call lc_fnc_log;
["customExpected", str lc_customSaved] call lc_fnc_log;
["markersLoaded", str (uksf_persistence_dataNamespace getVariable ["uksf_persistence_mapMarkers", []])] call lc_fnc_log;
["grenadeBoxes", count allMissionObjects "Box_NATO_Grenades_F"] call lc_fnc_log;
["deletedLoaded", str (uksf_persistence_dataNamespace getVariable ["uksf_persistence_deletedObjects", []])] call lc_fnc_log;
{
    ["playerLoaded", format ["%1 %2", _x, str (uksf_persistence_dataNamespace getVariable [_x, []])]] call lc_fnc_log;
} forEach uksf_persistence_playerUids;
[{["rtB"] call lc_fnc_rtDump}, [], 15] call CBA_fnc_waitAndExecute;

["lc_probePlayer", {
    params ["_unit"];
    private _uid = getPlayerUID _unit;
    [_unit, _uid] call uksf_persistence_fnc_storePlayerData;
    ["playerRestored", format ["%1 %2", _uid, str (uksf_persistence_dataNamespace getVariable [_uid, []])]] call lc_fnc_log;
}] call CBA_fnc_addEventHandler;
