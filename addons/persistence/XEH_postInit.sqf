#include "script_component.hpp"

[{
    if (isServer) then {
        if (GVAR(useApiPersistence) && {GVAR(dataSaved)}) then {
            call FUNC(loadServerDataApi);
        } else {
            if (GVAR(dataSaved)) then {
                call FUNC(loadServerDataProfile);
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
