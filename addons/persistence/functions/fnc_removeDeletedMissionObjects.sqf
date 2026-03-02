#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes mission-placed objects that were deleted during a previous session
        from the persistent objects hash

    Parameter(s):
        None

    Return Value:
        None
*/

{
    private _id = _x;
    if ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashHasKey) then {
        private _object = [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashGet;
        TRACE_2("Removing deleted mission object",_id,_object);
        deleteVehicle _object;
        [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashRem;
    };
} forEach (GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []]);
