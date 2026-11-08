#include "script_component.hpp"

[{
    tbd_m119_m119_towingList pushBack [QGVAR(landrover_lightgun.*), [0.11, -2.34, -2.03], -0.10];
}] call CBA_fnc_execNextFrame;

if (hasInterface) then {
    GVAR(uavLookPFH) = -1;
    ["ACE_controlledUAV", FUNC(uavLook)] call CBA_fnc_addEventHandler;
    call FUNC(addSpotlightActions);
    call FUNC(addSwapDriverActions);
    call FUNC(initCameraOverlay);

    addUserActionEventHandler ["ReloadMagazine", "Activate", FUNC(reloadTurret)];
};

["LandVehicle", "init", {
    params ["_vehicle"];
    if (!local _vehicle) exitWith {};
    private _paths = [[-1]];
    _paths append allTurrets [_vehicle, true];
    {
        private _path = _x;
        {
            private _weapon = _x;
            if !(_weapon isKindOf ["SmokeLauncher", configFile >> "CfgWeapons"]) then { continue };
            private _compatible = compatibleMagazines _weapon;
            private _loaded = (_vehicle magazinesTurret _path) findIf { _x in _compatible };
            if (_loaded >= 0) then { continue };
            private _mag = _compatible param [0, ""];
            if (_mag == "") then { continue };
            _vehicle addMagazineTurret [_mag, _path];
        } forEach (_vehicle weaponsTurret _path);
    } forEach _paths;
}, true] call CBA_fnc_addClassEventHandler;
