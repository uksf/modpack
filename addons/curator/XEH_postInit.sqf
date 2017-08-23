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
};
