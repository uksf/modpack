#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies prefab object data to given object

    Parameters:
        0: Object <OBJECT>
        1: Object data <ARRAY>

    Return value:
        Nothing
*/
params ["_object", "_objectData"];

if !(isServer) exitWith {};

_objectData params ["", "_objectState"];
_objectState params ["_hidden", "_damageAllowed", "_simulationEnabled", "_damage", "_fuel", "_inventory", "_aceMedical", "_aceRepair"];
_aceMedical params ["_medicalVehicle", "_medicalFacility"];
_aceRepair params ["_repairVehicle", "_repairFacility"];

_object hideObjectGlobal _hidden;
_object allowDamage _damageAllowed;
_object enableSimulationGlobal _simulationEnabled;
_object setDamage _damage;
_object setFuel _fuel;

[_object, _inventory] spawn {
    params ["_object", "_inventory"];
    _inventory params ["_weapons", "_magazines", "_items", "_backpacks"];

    clearWeaponCargoGlobal _object;
    clearMagazineCargoGlobal _object;
    clearItemCargoGlobal _object;
    clearBackpackCargoGlobal _object;
    {_object addWeaponCargoGlobal [_x, (_weapons#1)#_forEachIndex]} forEach (_weapons#0);
    {_object addMagazineCargoGlobal [_x, (_magazines#1)#_forEachIndex]} forEach (_magazines#0);
    {_object addItemCargoGlobal [_x, (_items#1)#_forEachIndex]} forEach (_items#0);
    {_object addBackpackCargoGlobal [_x, (_backpacks#1)#_forEachIndex]} forEach (_backpacks#0);
};

_object setVariable ["ace_medical_isMedicalVehicle", _medicalVehicle, true];
_object setVariable ["ace_medical_isMedicalFacility", _medicalFacility, true];
_object setVariable ["ace_isRepairVehicle", _repairVehicle, true];
_object setVariable ["ace_isRepairFacility", _repairFacility, true];

_object setVariable [QEGVAR(persistence,excluded), true];
