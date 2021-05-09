#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace interactions for diving

    Parameter(s):
        None

    Return Value:
        None
*/

private _fnc_children = {
    params ["", "_player"];

    private _actions = [];

    private _action = [QGVAR(toggleDiveComputer), "Toggle Dive Computer", QPATHTOF(data\ui\iconDiveComputer.paa), {[GVAR(diveComputerUpdatePFHID) == -1] call FUNC(toggleDiveComputer);}, {QGVAR(diveComputer) in (assignedItems _player)}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

     _action = [QGVAR(resetElapsedDiveTime), "Reset Dive Time", QPATHTOF(data\ui\iconDiveComputer.paa), {GVAR(elapsedDiveTime) = 0;}, {QGVAR(diveComputer) in (assignedItems _player) && GVAR(elapsedDiveTime) != 0}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    {
        private _className = _x;
        private _config = EGVAR(common,configWeapons) >> _className;
        private _name = getText (_config >> "displayName");
        private _icon = getText (_config >> "picture");

        private _action = [format [QGVAR(useCylinder_%1), _className], format ["Use %1", _name], _icon, {
            params ["", "", "_actionParams"];
            _actionParams params ["", "_config", "_name"];

            [_config, _name] call FUNC(useCylinder);
        }, {
            params ["", "_player", "_actionParams"];
            _actionParams params ["_className"];

            [_player, _className] call ace_common_fnc_hasItem
        }, {}, [_className, _config, _name]] call ace_interact_menu_fnc_createAction;

        _actions pushBack [_action, [], _player];
    } forEach [
        QGVAR(cylinderSingleCompressedAir),
        QGVAR(cylinderDoubleCompressedAir),
        QGVAR(cylinderSingleEan28),
        QGVAR(cylinderDoubleEan28),
        QGVAR(cylinderSingleEan32),
        QGVAR(cylinderDoubleEan32),
        QGVAR(cylinderSingleEan36),
        QGVAR(cylinderDoubleEan36),
        QGVAR(cylinderSingleEan40),
        QGVAR(cylinderDoubleEan40),
        QGVAR(cylinderSingleHeliox85),
        QGVAR(cylinderDoubleHeliox85),
        QGVAR(cylinderSingleHeliox12),
        QGVAR(cylinderDoubleHeliox12),
        QGVAR(cylinderSingleHeliox21),
        QGVAR(cylinderDoubleHeliox21),
        QGVAR(cylinderSingleTx2135),
        QGVAR(cylinderDoubleTx2135),
        QGVAR(cylinderSingleTx1845),
        QGVAR(cylinderDoubleTx1845),
        QGVAR(cylinderSingleTx1555),
        QGVAR(cylinderDoubleTx1555),
        QGVAR(cylinderSingleTx1265),
        QGVAR(cylinderDoubleTx1265),
        QGVAR(cylinderDoubleTx1070),
        QGVAR(cylinderSingleTx1070)
    ];

    _actions
};

private _action = [QGVAR(dive), "Diving", "", {}, {isPlayer _player && {(vest _player) in [QGVAR(rebreather), "UKSF_LARV_1", "UKSF_LARV_2"]}}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
