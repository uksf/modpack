#include "script_component.hpp"

[{
    startLoadingScreen ["Loading"];
    [{
        params ["_args", "_idPFH"];
        _args params ["_index", "_max"];

        if (_index > _max) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            endLoadingScreen;
            call FUNC(addCuratorActions);
            if (!isMultiplayer) then {
                call FUNC(curatorLogin);
            };
        };
        progressLoadingScreen ((1 / GVAR(curatorsMax)) * _index);
        _args set [0, _index + 1];
    }, 0.9, [1, GVAR(curatorsMax)]] call CBA_fnc_addPerFrameHandler;
}, [], 0.5] call CBA_fnc_waitAndExecute;
