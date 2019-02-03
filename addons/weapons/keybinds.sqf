#include "\a3\editor_f\Data\Scripts\dikCodes.h"

["UKSF", QGVAR(transmitSoflamData), ["Transmit SOFLAM data", "Transmit SOFLAM laser position data to MicroDAGR"], {false}, {
    // Conditions: canInteract
    if !([ACE_player, objNull, ["isNotInside"]] call EFUNC(common,canInteractWith)) exitWith {false};
    // Conditions: specific
    if !(((currentWeapon ACE_player) isKindOf ["UK3CB_BAF_Soflam_Laserdesignator", configFile >> "CfgWeapons"]) && {cameraView == "GUNNER"} && {isLaserOn ACE_player}) exitWith {false};

    // Get data
    private _distance = call FUNC(getSoflamDistance);
    private _direction = call ace_vector_fnc_getDirection;
    _direction params ["_azimuth", "_inclination"];

    //Send data to connected GPS
    ["ace_vector_rangefinderData", [_distance, _azimuth, _inclination]] call CBA_fnc_localEvent;
    false
}, [15, [false, false, false]], false, 0] call CBA_fnc_addKeybind; //Tab Key
