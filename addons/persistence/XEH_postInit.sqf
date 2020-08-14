#include "script_component.hpp"

[{
    if (isServer && {GVAR(dataSaved)}) then {
        GVAR(missionObjects) = allMissionObjects "All";
        TRACE_1("Mission objects",GVAR(missionObjects));
        [{
            {
                private _id = _x;
                if ([GVAR(persistentObjectsHash), _id] call CBA_fnc_hashHasKey) then {
                    private _object = [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashGet;
                    TRACE_2("Removing deleted mission object",_id,_object);
                    deleteVehicle _object;
                    [GVAR(persistentObjectsHash), _id] call CBA_fnc_hashRem;
                };
            } forEach (GVAR(dataNamespace) getVariable [QGVAR(deletedObjects), []]);

            [{[] call FUNC(loadAllObjectData)}] call CBA_fnc_execNextFrame;
        }] call CBA_fnc_execNextFrame;
    };

    if (hasInterface) then {
        TRACE_1("Requesting player redeploy data",_data);
        [QGVAR(requestRedeployData), [player]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_execNextFrame;
