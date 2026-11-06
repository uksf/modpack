#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace self interactions for a gunner to switch the weapon spotlight between off, white and IR

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_vehicles_fnc_addSpotlightActions
*/

private _parent = [QGVAR(spotlight), "Spotlight", "\a3\ui_f\data\IGUI\Cfg\Actions\ico_cpt_land_on_ca.paa", {}, {
    (_target unitTurret _player) in ([_target] call FUNC(spotlightTurrets))
}] call ace_interact_menu_fnc_createAction;

private _modes = [
    [QGVAR(spotlightWhite), "White", "white"],
    [QGVAR(spotlightIR), "IR", "ir"],
    [QGVAR(spotlightOff), "Off", ""]
] apply {
    _x params ["_name", "_displayName", "_mode"];
    [_name, _displayName, "", {
        [QGVAR(setSpotlight), [_target, _target unitTurret _player, _actionParams]] call CBA_fnc_serverEvent;
    }, {
        (_target getVariable [format [QGVAR(spotlight_%1), _target unitTurret _player], ""]) != _actionParams
    }, {}, _mode] call ace_interact_menu_fnc_createAction
};

{
    private _class = _x;
    [_class, 1, ["ACE_SelfActions"], _parent, true] call ace_interact_menu_fnc_addActionToClass;
    {
        [_class, 1, ["ACE_SelfActions", QGVAR(spotlight)], _x, true] call ace_interact_menu_fnc_addActionToClass;
    } forEach _modes;
} forEach ["Car", "Tank", "Ship"];
