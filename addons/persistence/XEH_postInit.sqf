#include "script_component.hpp"

if (isServer && {GVAR(dataSaved)}) then {
    [{
        GVAR(missionObjects) = allMissionObjects "All";
        [{
            {
                private _id = _x;
                if ([GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashHasKey) then {
                    private _object = [GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashGet;
                    TRACE_2("Removing deleted mission object",_id,_object);
                    deleteVehicle _object;
                    [GVAR(hashPersistentVehicles), _id] call CBA_fnc_hashRem;
                };
            } forEach (GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []]);

            [{call FUNC(loadVehicleData)}] call CBA_fnc_execNextFrame;
        }] call CBA_fnc_execNextFrame;
    }] call CBA_fnc_execNextFrame;
};
