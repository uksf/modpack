#include "script_component.hpp"

if (isMultiplayer) then {
    [] spawn {
        sleep 0.25;
        while {isNull (uiNamespace getVariable "RscDisplayLoading")} do {
            startLoadingScreen ["Loading"];
        };
        private _step = (1 / GVAR(curatorsMax));
        for "_index" from 1 to GVAR(curatorsMax) do {
            progressLoadingScreen (_step * _index);
            uiSleep 1;
        };
        endLoadingScreen;
        call COMPILE_FILE_SYS(PREFIX,lobby,XEH_missionDisplayLoad);

        call FUNC(addCuratorActions);
        if (!isMultiplayer) then {
            call FUNC(curatorLogin);
        };
    };
};
