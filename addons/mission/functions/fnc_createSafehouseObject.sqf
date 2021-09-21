#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates safehouse object

    Parameters:
        0: Anchor <OBJECT>
        1: Object data <ARRAY>
        2: Anchor persistence ID <STRING>

    Return value:
        Created object <OBJECT>
*/
params ["_anchor", "_objectData", "_anchorPersistenceId"];

if !(isServer) exitWith {};

_objectData params ["_type", "_anchorOffset", "_vectorDirAndUp", "_hidden", "_damage", "_fuel", "_inventory", "_aceMedical", "_aceRepair"];
_aceMedical params ["_medicalVehicle", "_medicalFacility"];
_aceRepair params ["_repairVehicle", "_repairFacility"];

private _position = _anchor modelToWorld _anchorOffset;
private _object = createVehicle [_type, _position, [], 0, "CAN_COLLIDE"];
_object setVectorDirAndUp _vectorDirAndUp;
_object hideObjectGlobal _hidden;
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

_object setVariable [QGVAR(safehouseAnchorPersistenceId), _anchorPersistenceId, true];

[_vehicle] call EFUNC(persistence,markObjectAsPersistent);

_object

// TODO:
// Mark all objects as persistent
// Mark all objects as belonging to a safehouse (use PID of anchor object)
// Add safehouse id to persistence
// Killed EH on anchor object, when destroyed:
    // Delete all safehouse objects
    // Remove id from persistence
    // Add id to destroyed persistence
    // Create destruction object (destroyed anchor) and mark as persistent and exclude from cleanup
