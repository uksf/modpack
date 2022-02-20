#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Adds ace interactions for halo/haho

    Parameter(s):
        None

    Return Value:
        Nothing
*/

private _fnc_children = {
    params ["", "_player"];

    private _actions = [];

    private _action = [QGVAR(connectOxygen), "Connect Oxygen", "", {
        params ["", "_player"];

        GVAR(oxygenConnected) = true;
        playSound QGVAR(hiss);
        _player removeItem QGVAR(airSupply);
        "Oxygen connected" call CBA_fnc_notify;

        [{
            [{
                params ["", "_idPFH"];

                if (!GVAR(oxygenConnected)) exitWith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                };

                playSound QGVAR(breatheOxygenShort);
            }, 5, []] call CBA_fnc_addPerFrameHandler;
        }, [], 2] call CBA_fnc_waitAndExecute;

        [{
            if (GVAR(oxygenConnected)) then {
                GVAR(oxygenConnected) = false;
            };
        }, [], OXYGEN_TIME] call CBA_fnc_waitAndExecute;

    }, {!GVAR(oxygenConnected) && {[_player, QGVAR(airSupply)] call ace_common_fnc_hasItem}}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(disconnectOxygen), "Disconnect Oxygen", "", {
        GVAR(oxygenConnected) = false;
        "Oxygen disconnected" call CBA_fnc_notify;
    }, {GVAR(oxygenConnected)}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

private _action = [QGVAR(halohaho), "HALO/HAHO", "", {}, {isPlayer _player && goggles _player == "G_mas_usl_jumpmask"}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
