#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(ammoConfigCache) = createHashMap;
GVAR(fortificationClassCache) = createHashMap;

GVAR(explicitFortificationTier1) = createHashMapFromArray [
    ["Land_Bunker_F", true],
    ["Land_Bunker_01_big_F", true],
    ["Land_Bunker_01_blocks_1_F", true],
    ["Land_Bunker_01_blocks_3_F", true],
    ["Land_Bunker_01_HQ_F", true],
    ["Land_Bunker_01_small_F", true],
    ["Land_Bunker_01_tall_F", true]
];

GVAR(explicitFortificationTier2) = createHashMapFromArray [
    ["Land_SandbagBarricade_01_F", true],
    ["Land_SandbagBarricade_01_half_F", true],
    ["Land_SandbagBarricade_01_hole_F", true],
    ["Land_Barricade_01_4m_F", true],
    ["Land_Barricade_01_10m_F", true],
    ["Land_CzechHedgehog_01_F", true],
    ["Land_CzechHedgehog_01_old_F", true],
    ["Land_CzechHedgehog_01_new_F", true],
    ["Land_ConcreteHedgehog_01_F", true],
    ["Land_ConcreteHedgehog_01_half_F", true],
    ["Land_ConcreteHedgehog_01_palette_F", true],
    ["ACE_ConcertinaWireCoil", true],
    ["Land_ConcretePipe_F", true]
];

#include "initSettings.inc.sqf"

[QGVAR(processFortifications), {
    _this call FUNC(processFortifications);
}] call CBA_fnc_addEventHandler;

[QGVAR(fortificationDustEffect), {
    params ["_position"];
    if !(hasInterface) exitWith {};

    private _dustEffect = "#particlesource" createVehicleLocal _position;
    _dustEffect setParticleParams [
        ["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 12, 8, 0],
        "", "Billboard", 1, 3, [0, 0, 0], [0, 0, 1], 1, 1.275, 1, 0,
        [1, 3, 6], [[0.5, 0.4, 0.3, 0.6], [0.6, 0.5, 0.4, 0.3], [0.7, 0.6, 0.5, 0]],
        [0, 1], 0.1, 0.05, "", "", objNull, 0, false, -1, [[3, 3, 3, 0]]
    ];
    _dustEffect setParticleRandom [3, [2, 2, 1], [2, 2, 2], 1, 0.5, [0, 0, 0, 0.1], 0, 0, 360];
    _dustEffect setDropInterval 0.01;

    [{
        deleteVehicle _this;
    }, _dustEffect, 0.5] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

ADDON = true;
