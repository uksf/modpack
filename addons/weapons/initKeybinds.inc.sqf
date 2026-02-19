#include "\a3\editor_f\Data\Scripts\dikCodes.h"

["UKSF", QGVAR(transmitSoflamData), ["Transmit SOFLAM data", "Transmit SOFLAM laser position data to MicroDAGR"], {false}, {
    // Conditions: canInteract
    if !([ACE_player, objNull, ["isNotInside"]] call ace_common_fnc_canInteractWith) exitWith {false};
    // Conditions: specific
    if !(((currentWeapon ACE_player) isKindOf ["UK3CB_BAF_Soflam_Laserdesignator", EGVAR(common,configWeapons)]) && {cameraView == "GUNNER"} && {isLaserOn ACE_player}) exitWith {false};

    // Get data
    private _distance = call FUNC(getSoflamDistance);
    private _direction = call ace_vector_fnc_getDirection;
    _direction params ["_azimuth", "_inclination"];

    // Send data to connected GPS
    ["ace_vector_rangefinderData", [_distance, _azimuth, _inclination]] call CBA_fnc_localEvent;
    false
}, [15, [false, false, false]], false, 0] call CBA_fnc_addKeybind; // Tab Key


["3CB", "UK3CB_Key_Load_Static_Weapon", ["Load static weapon", "Load static weapon with a new magazine"], {
    call UK3CB_BAF_Weapons_Static_fnc_load_static_weapon
}, {false}, [DIK_R, [false, false, false]]] call CBA_fnc_addKeybind; // R

["3CB", "UK3CB_Key_Getout_Of_Static_Weapon_Unarmed", ["Get out of static weapons (unarmed)", "Get out of static weapons with no weapon equipped"], {
    [_this, 0] call UK3CB_BAF_Weapons_Static_fnc_getout_of_static_weapon
}, {false}, [DIK_4, [false, false, false]]] call CBA_fnc_addKeybind; // 4

["3CB", "UK3CB_Key_Getout_Of_Static_Weapon_Primary", ["Get out of static weapons (armed)", "Get out of static weapons with primary weapon equipped"], {
    [_this, 1] call UK3CB_BAF_Weapons_Static_fnc_getout_of_static_weapon
}, {false}, [DIK_1, [false, false, false]]] call CBA_fnc_addKeybind; // 1

["3CB", "UK3CB_Key_Toggle_Range_Table", ["Toggle range table", "Toggle on/off the M6 mortar range table"], {
    call UK3CB_BAF_Weapons_Static_fnc_toggle_range_table
}, {false}, [DIK_B, [false, true, false]]] call CBA_fnc_addKeybind; // CTRL + B

["3CB", "UK3CB_Key_Deploy_Static_Weapon", ["Deploy static weapon", "Assemble and get in to the static weapon (M6 only)"], {
    call UK3CB_BAF_Weapons_Static_fnc_rapid_deploy_weapon
}, {false}, [DIK_3, [false, false, false]]] call CBA_fnc_addKeybind; // 3

["3CB", "UK3CB_Key_Activate_M6_Reticle", ["Activate pointer", "Activate the mortar pointer for 6 secs (M6 only)"], {
    player setVariable ["UK3CB_BAF_M6_reticle_timer", 6];
    true
}, {false}, [DIK_GRAVE, [true, false, false]]] call CBA_fnc_addKeybind; // SHIFT + `

["M119A3", "RotateRight", ["Rotate right", "Rotate the gun to the right"], {
    private _arty = vehicle player;
    if (_arty == player) exitWith {};
    if !(_arty isKindOf "TBD_M119") exitWith {};

    // Get the current animation source phase
    private _currentPhase = _arty animationSourcePhase "howitzer_rotation_source";
    // Edit it
    _currentPhase = _currentPhase + 4;

    if (_currentPhase > 1440) then {
        _currentPhase = 1440;
    };

    // Set the new animation source phase
    _arty animateSource ["howitzer_rotation_source", _currentPhase, 30];
}, {},
[0x20, [false, false, false]], true, 0.1] call CBA_fnc_addKeybind;

["M119A3", "RotateLeft", ["Rotate left", "Rotate the gun to the left"], {
    private _arty = vehicle player;
    if (_arty == player) exitWith {};
    if !(_arty isKindOf "TBD_M119") exitWith {};

    // Get the current animation source phase
    private _currentPhase = _arty animationSourcePhase "howitzer_rotation_source";
    // Edit it
    _currentPhase = _currentPhase - 4;

    if (_currentPhase < -1440) then {
        _currentPhase = 1440;
    };

    // Set the new animation source phase
    _arty animateSource ["howitzer_rotation_source", _currentPhase, 30];
}, {},
[0x1E, [false, false, false]], true, 0.1] call CBA_fnc_addKeybind;
