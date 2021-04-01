#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _romeoClasses = QUOTE(
    getNumber (_x >> 'scope') == 2
    && getNumber (_x >> 'containerIgnore') == 0
    && inheritsFrom _x == (EGVAR(common,configVehicles) >> QQGVAR(rx))
) configClasses EGVAR(common,configVehicles);
_romeoClasses = [QGVAR(rx), QGVAR(rf)] + (_romeoClasses apply {configName _x});

GVAR(romeoClasses) = _romeoClasses apply {
    private _class = EGVAR(common,configVehicles) >> _x;
    private _name = getText (_class >> "displayName");
    private _description = getText (_class >> "description");
    [_x, _name, _description]
};

private _golfClasses = QUOTE(
    getNumber (_x >> 'scope') == 2
    && getNumber (_x >> 'containerIgnore') == 0
    && inheritsFrom _x == (EGVAR(common,configVehicles) >> QQGVAR(gx))
) configClasses EGVAR(common,configVehicles);
_golfClasses = [QGVAR(gx), QGVAR(gmed)] + (_golfClasses apply {configName _x});

GVAR(golfClasses) = _golfClasses apply {
    private _class = EGVAR(common,configVehicles) >> _x;
    private _name = getText (_class >> "displayName");
    private _description = getText (_class >> "description");
    [_x, _name, _description]
};

private _action = [QGVAR(containerRomeoActions), "Resupply - Romeo", "", {}, {true}, {call FUNC(getRomeoActions)}] call ace_interact_menu_fnc_createAction;
[QGVAR(container), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(containerGolfActions), "Resupply - Golf", "", {}, {true}, {call FUNC(getGolfActions)}] call ace_interact_menu_fnc_createAction;
[QGVAR(container), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(containerLoad), "Load into container", "", {
    params ["_crate", "_player"];

    [2, [_crate], {
        params ["_args"];
        _args params ["_crate"];

        deleteVehicle _crate;
    }, {
        hint "Failed to load into container";
    }, "Loading into container"] call ace_common_fnc_progressBar;
}, {
    params ["_crate"];

    private _containers = _crate nearEntities [QGVAR(container), 10];
    _containers isNotEqualTo []
}] call ace_interact_menu_fnc_createAction;

{
    [_x, 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
} forEach [QGVAR(rx), QGVAR(rf), QGVAR(gx), QGVAR(gmed)];

ADDON = true;
