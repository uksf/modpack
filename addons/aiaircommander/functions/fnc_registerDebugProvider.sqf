#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers AI air commander debug provider with Zeus

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_aiaircommander_fnc_registerDebugProvider
*/

private _key = QGVAR(debug);
private _menuName = "AI Air Commander";
private _menuPriority = -25;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    private _aaSites = GVAR(aaSites) apply {
        private _position = getPosATL _x;
        private _vehicle = _x getVariable [QGVAR(aaVehicle), objNull];
        private _occupied = alive _vehicle;
        [_position, _occupied, netId _vehicle]
    };

    private _airspaceCentres = GVAR(airspaceCentre) apply {getPosATL _x};
    private _enemyAirfields = GVAR(enemyAirfields) apply {getPosATL _x};

    private _spawnPoints = [];
    {_spawnPoints pushBack [getPosATL _x, "aa"]} forEach GVAR(aaSpawns);
    {_spawnPoints pushBack [getPosATL _x, "heli"]} forEach GVAR(heliSpawns);
    {_spawnPoints pushBack [getPosATL _x, "plane"]} forEach GVAR(planeSpawns);

    [
        _aaSites,
        _airspaceCentres,
        _enemyAirfields,
        _spawnPoints
    ]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    _data params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

    // AA sites
    {
        _x params ["_position", "_occupied", "_vehicleNetId"];
        private _colour = [[1,0,0,1], [0,1,0,1]] select _occupied;
        if (_cameraPosition distance2D _position < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, ASLToAGL (ATLToASL _position), 0.5, 0.5, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 1, 0.025, "TahomaB", "center"];
        };
        if (_occupied) then {
            private _vehicle = objectFromNetId _vehicleNetId;
            if (!isNull _vehicle) then {
                private _vehiclePosition = ASLToAGL (getPosASL _vehicle);
                if (_cameraPosition distance2D _vehiclePosition < _maxDistance) then {
                    drawIcon3D ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _vehiclePosition, 0.4, 0.4, 0, "AA Vehicle", 1, 0.02, "TahomaB", "center"];
                    drawLine3D [ASLToAGL (ATLToASL _position), _vehiclePosition, [0,1,0,1]];
                };
            };
        };
    } forEach _aaSites;

    // Airspace centres
    {
        if (_cameraPosition distance2D _x < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _x), 0.75, 0.75, 0, "Airspace Centre", 1, 0.025, "TahomaB", "center"];
        };
    } forEach _airspaceCentres;

    // Enemy airfields
    {
        if (_cameraPosition distance2D _x < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _x), 0.5, 0.5, 0, "Enemy Airfield", 1, 0.025, "TahomaB", "center"];
        };
    } forEach _enemyAirfields;

    // Air spawn points
    {
        _x params ["_position", "_type"];
        if (_cameraPosition distance2D _position < _maxDistance) then {
            drawIcon3D ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], ASLToAGL (ATLToASL _position), 0.4, 0.4, 0, format ["Spawn: %1", toUpper _type], 1, 0.02, "TahomaB", "center"];
        };
    } forEach _airSpawnPoints;
};

private _fnc_drawMap = {
    params ["_data", "_map"];
    _data params ["_aaSites", "_airspaceCentres", "_enemyAirfields", "_airSpawnPoints"];

    // AA sites
    {
        _x params ["_position", "_occupied", "_vehicleNetId"];
        private _colour = [[1,0,0,1], [0,1,0,1]] select _occupied;
        _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, _position, 24, 24, 0, format ["AA %1", ["EMPTY", "MANNED"] select _occupied], 1, 0.04, "TahomaB", "right"];
        if (_occupied) then {
            private _vehicle = objectFromNetId _vehicleNetId;
            if (!isNull _vehicle) then {
                _map drawIcon ["\a3\ui_f\data\map\markers\military\triangle_ca.paa", _colour, getPosATL _vehicle, 18, 18, 0, "AA Vehicle", 1, 0.03, "TahomaB", "right"];
                _map drawLine [_position, getPosATL _vehicle, [0,1,0,1]];
            };
        };
    } forEach _aaSites;

    // Airspace centres
    {
        _map drawIcon ["\a3\ui_f\data\map\markers\military\circle_ca.paa", [0.4,0.7,1,1], _x, 30, 30, 0, "Airspace", 1, 0.04, "TahomaB", "right"];
    } forEach _airspaceCentres;

    // Enemy airfields
    {
        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], _x, 24, 24, 0, "Airfield", 1, 0.04, "TahomaB", "right"];
    } forEach _enemyAirfields;

    // Air spawn points
    {
        _x params ["_position", "_type"];
        _map drawIcon ["\a3\ui_f\data\map\markers\military\dot_ca.paa", [0.4,0.7,1,1], _position, 20, 20, 0, format ["Spawn: %1", toUpper _type], 1, 0.03, "TahomaB", "right"];
    } forEach _airSpawnPoints;
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;
