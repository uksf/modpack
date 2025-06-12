#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _fnc_getDetails = {
    private _class = EGVAR(common,configVehicles) >> _this;
    private _name = getText (_class >> "displayName");
    private _description = getText (_class >> "description");
    [_this, _name, _description]
};

private _romeoClasses = QUOTE(
    getNumber (_x >> 'scope') == 2
    && getNumber (_x >> 'containerIgnore') == 0
    && inheritsFrom _x == (EGVAR(common,configVehicles) >> QQGVAR(rx))
) configClasses EGVAR(common,configVehicles);
_romeoClasses = [QGVAR(rx)] + (_romeoClasses apply {configName _x}) + [QGVAR(rf)];

private _golfClasses = QUOTE(
    getNumber (_x >> 'scope') == 2
    && getNumber (_x >> 'containerIgnore') == 0
    && inheritsFrom _x == (EGVAR(common,configVehicles) >> QQGVAR(gx))
) configClasses EGVAR(common,configVehicles);
_golfClasses = [QGVAR(gx)] + (_golfClasses apply {configName _x}) + [QGVAR(g14), QGVAR(g14ba), QGVAR(g14bl), QGVAR(g14d)];

private _otherClasses = [QEGVAR(vehicles,L119)];

GVAR(romeoClasses) = _romeoClasses apply {_x call _fnc_getDetails};
GVAR(golfClasses) = _golfClasses apply {_x call _fnc_getDetails};
GVAR(otherClasses) = _otherClasses apply {_x call _fnc_getDetails};

private _action = [QGVAR(containerRomeoActions), "Resupply - Romeo", "", {}, {true}, {call FUNC(getRomeoActions)}] call ace_interact_menu_fnc_createAction;
[QGVAR(container), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(containerGolfActions), "Resupply - Golf", "", {}, {true}, {call FUNC(getGolfActions)}] call ace_interact_menu_fnc_createAction;
[QGVAR(container), 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(containerOtherActions), "Resupply - Other", "", {}, {true}, {call FUNC(getOtherActions)}] call ace_interact_menu_fnc_createAction;
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
} forEach [QGVAR(rx), QGVAR(rf), QGVAR(gx), QGVAR(g14), QGVAR(g14ba), QGVAR(g14bl), QGVAR(g14d), QEGVAR(vehicles,L119)];

{
    _x params ["_id", "_fuseMode", "_fuseModeName", "_regex"];

    private _action = [_id, format ["Set %1 fuse", _fuseModeName], "", {
        params ["_crate", "", "_actionParams"];
        _actionParams params ["_fuseMode", "_fuseModeName", "_regex"];

        private _mortarRoundCount = {_x regexMatch _regex} count (magazineCargo _crate);

        [_mortarRoundCount, [_crate, _fuseMode], {
            params ["_args"];
            _args params ["_crate", "_fuseMode"];

            [_crate, _fuseMode] call FUNC(setMortarFuse);
        }, {
            hint "Failed to set fuses";
        }, format ["Setting %1 %2 fuses", _mortarRoundCount, _fuseModeName]] call ace_common_fnc_progressBar;
    }, {
        params ["_crate", "", "_actionParams"];
        _actionParams params ["", "", "_regex"];

        ({_x regexMatch _regex} count (magazineCargo _crate)) > 0
    }, {}, [_fuseMode, _fuseModeName, _regex]] call ace_interact_menu_fnc_createAction;

    {
        [_x, 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
    } forEach [QGVAR(r5), QGVAR(r6), QGVAR(g8), QGVAR(g9), QGVAR(g10), QGVAR(g11)];
} forEach [
    [QGVAR(setImpactFuse), MORTAR_FUSE_MODE_IMPACT, "impact", "UK3CB_BAF_1Rnd_.*Mo_AB_Shells"],
    [QGVAR(setProximityFuse), MORTAR_FUSE_MODE_PROXIMITY, "proximity", "UK3CB_BAF_1Rnd_.*Mo_Shells"]
];

ADDON = true;
