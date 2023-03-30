#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets group details and stores them.
        Currently doing this to a variable, can change this later to a DB or name space etc.

    Parameters:
        0: Group to virtualise <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _createUUID = {
    private _hexDigits = [
        "0", "1", "2", "3", "4", "5", "6", "7",
        "8", "9", "a", "b", "c", "d", "e", "f"
    ];
    private _versionByte = "4";
    private _variantByte = selectRandom ["8", "9", "a", "b"];

    private _uuid = [];
    for "_i" from 0 to 29 do {
        _uuid pushBack selectRandom _hexDigits;
    };

    _uuid insert [8, ["-"]];
    _uuid insert [13, ["-", _versionByte]];
    _uuid insert [17, ["-", _variantByte]];
    _uuid insert [22, ["-"]];
    _uuid joinString ""
};

private _leader = leader _group;
private _id = call _createUUID;// call CBA_fnc_createUUID; // CBA 3.15.9
private _position = getPos _leader;
GVAR(virtualisedGroupsPositionMap) pushBack [_id, _position];

private _side = side _group;
private _combatMode = combatMode _group;
private _formationDirection = formationDirection _leader;
private _waypointsArray = [_group] call FUNC(getGroupWaypoints);

private _type = SAVED_TYPE_INFANTRY;
private _unitDetails = [];
if ((vehicle _leader) isKindOf "LandVehicle") then { // need a better way to do this
    _unitDetails = [_group] call FUNC(getVehicleUnitDetails);
    _type = SAVED_TYPE_VEHICLE;
} else {
    _unitDetails = [_group] call FUNC(getInfantryUnitDetails);
};
GVAR(virtualisedGroups) set [_id, [_type, _side, _unitDetails, _waypointsArray, _combatMode, _formationDirection]];
TRACE_3("virtualised group",_id,_type,_group);

deleteVehicle (vehicle _leader);
{deleteVehicle _x} forEach units _group;
[QGVAR(deleteGroup), _group, _group] call CBA_fnc_targetEvent;
