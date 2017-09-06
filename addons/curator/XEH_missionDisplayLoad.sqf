#include "script_component.hpp"

[] spawn {
    uiSleep 0.5;
    startLoadingScreen ["Loading"];
    for "_index" from 1 to GVAR(curatorsMax) do {
        progressLoadingScreen ((1 / GVAR(curatorsMax)) * _index);
        uiSleep 1;
    };
    endLoadingScreen;
    call COMPILE_FILE_SYS(PREFIX,lobby,XEH_missionDisplayLoad);

    call FUNC(addCuratorActions);
    if (!isMultiplayer) then {
        call FUNC(curatorLogin);
    };
};
