#include "script_component.hpp"

if (hasInterface) then {
    ["Man", "respawn", {
        private _index = (GVAR(curatorPlayers) find (name player));
        if (_index > -1) then {
            [QGVAR(curatorUnassign), [GVAR(curatorObjects) select _index]] call CBA_fnc_serverEvent;
            [QGVAR(curatorAssign), [player]] call CBA_fnc_serverEvent;
        } else {
            if (WHITELISTED) then {
                call FUNC(curatorLogin);
            };
        };
    }, true, [], true] call CBA_fnc_addClassEventHandler;

    [{
        !(isNull (findDisplay 46))
    },{
        [] spawn {
            if (isMultiplayer) then {
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
                call EFUNC(lobby,missionLoad);
            };

            {
               call FUNC(addCuratorActions);
                if (!isMultiplayer) then {
                    call FUNC(curatorLogin);
                }; 
            } call CBA_fnc_directCall;            
        };
    }] call CBA_fnc_waitUntilAndExecute;
};
