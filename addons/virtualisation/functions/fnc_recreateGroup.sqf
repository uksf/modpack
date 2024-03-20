#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Recreates a group

    Parameters:
        0: Group data <ARRAY>
        1: Exclude from virtualisation <BOOLEAN> (Optional)

    Return value:
        Nothing
*/
params ["_groupData", ["_exclude", false]];
_groupData params ["_side", "_vehicleDetails", "_unitDetails", "_waypoints", "_combatMode", "_formationDirection"];

private _group = createGroup _side;
if (_exclude) then {
    [QGVAR(exclude), _group] call CBA_fnc_localEvent;
};

private _setGroupArgs = [_group, _waypoints, _combatMode, _formationDirection];
private _setGroupParams = {
    params ["_group", "_waypoints", "_combatMode", "_formationDirection"];

    _group setCombatMode _combatMode;
    _group setFormDir _formationDirection;
    [_group, _waypoints] call FUNC(addWaypoints);
};

private _recreateInfantryArgs = [_group, _unitDetails, _setGroupParams, _setGroupArgs];
private _recreateInfantry = {
    call FUNC(recreateInfantry);
};

// Start recreating asynchronously. If no vehicles, go straight to units
if (_vehicleDetails isNotEqualTo []) then {
    [_group, _vehicleDetails, _recreateInfantry, _recreateInfantryArgs] call FUNC(recreateVehicles);
} else {
    _recreateInfantryArgs call _recreateInfantry;
};

call FUNC(sendDataToClients);
