#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Cleans up various arrays at a regular interval

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer) exitWith {};

GVAR(killerPlayers) = GVAR(killerPlayers) select {time < (_x#1)};

private _groupsToDelete = GVAR(responseGroups) select {
    isNull _x
    || {
        _x getVariable [QGVAR(hasFinishedTask), false]
        && {!([getPosATL (leader _x), 1000] call EFUNC(common,anyNearPlayers))}
    }
    || {!([getPosATL (leader _x), 7500] call EFUNC(common,anyNearPlayers))}
};
// TODO: Make these distances settings (part of common component, might need to register custom conditions for each group, or a handler for each component)

{
    GVAR(responseGroups) deleteAt (GVAR(responseGroups) find _x);
    ((leader _x) getVariable [QEGVAR(common,assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
    _x call CBA_fnc_deleteEntity;
} forEach _groupsToDelete;

GVAR(transportGroups) = GVAR(transportGroups) - [objNull];
if (GVAR(transportGroups) isEqualTo []) then {
    GVAR(stayBehindGroupSelected) = false;
};
