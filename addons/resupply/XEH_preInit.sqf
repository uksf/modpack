#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

private _action = [QGVAR(containerAtions), "Resupply", "", {}, {true}, {call FUNC(getResupplyActions)}] call ace_interact_menu_fnc_createAction;
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

    private _containers = _crate nearEntities [QGVAR(container), 25];
    _containers isNotEqualTo []
}] call ace_interact_menu_fnc_createAction;

["UKSF_S_Empty", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
["UKSF_S_MedicalBox", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
["CargoNet_01_barrels_F", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

ADDON = true;
