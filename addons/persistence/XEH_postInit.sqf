#include "script_component.hpp"

[{
    if (isServer) then {
        if (GVAR(useApiPersistence) && {GVAR(dataSaved)}) then {
            INFO("Waiting for API persistence data...");
            [{
                GVAR(apiLoadComplete)
            }, {
                INFO("API persistence data received, proceeding with load");
                call FUNC(initServer);

                GVAR(missionObjects) = +EGVAR(common,missionObjectsMinusUnits);
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

                    call FUNC(loadAllData);
                }] call CBA_fnc_execNextFrame;
            }, [], 60, {
                ERROR("API persistence load timed out after 60 seconds, proceeding without data");
                GVAR(dataNamespace) = call CBA_fnc_createNamespace;
                GVAR(playerUids) = [];
                call FUNC(initServer);
                INFO("No data saved, loading finished");
                [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
            }] call CBA_fnc_waitUntilAndExecute;
        } else {
            if (GVAR(dataSaved)) then {
                GVAR(missionObjects) = +EGVAR(common,missionObjectsMinusUnits);
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

                    call FUNC(loadAllData);
                }] call CBA_fnc_execNextFrame;
            } else {
                INFO("No data saved, loading finished");
                [QGVAR(loadingFinished), []] call CBA_fnc_localEvent;
            };
        };
    };

    if (hasInterface) then {
        call FUNC(addPersistenceActions);

        LOG("Requesting player redeploy data");
        [QGVAR(requestRedeployData), [player]] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_execNextFrame;
