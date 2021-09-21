#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets logic ID

    Parameter(s):
        0: Logic <OBJECT>

    Return Value:
        Id <STRING>
*/
if !(is3DEN) exitWith {};

if (_this isEqualTo []) exitWith {
    {[_x] call FUNC(edenSetIdAttribute)} forEach (all3DENEntities#3);
};

params ["_logic"];

private _id = "";
private _attributes = _logic get3DENAttribute QGVAR(id);
if (_attributes isNotEqualTo []) then {
    private _attribute = _attributes#0;
    if (_attribute isEqualType "") then {
        _id = _attribute;
    };
};

private _setId = true;
if (_id != "") then {
    private _storedLogic = GVAR(edenLogicIdMap) getOrDefault [_id, objNull];
    if (!isNull _storedLogic && {_storedLogic == _logic}) then {
        _setId = false;
    };
};

if (_setId) then {
    private _ids = keys GVAR(edenLogicIdMap);
    while {_id == "" || _id in _ids} do {
        _id = format ['%1_%2_%3', typeOf _logic, diag_frameNo, round random 99999];
    };

    GVAR(edenLogicIdMap) set [_id, _logic];
    _logic set3DENAttribute [QGVAR(id), _id];
};

_id
