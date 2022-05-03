#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers serializer and deserializer functions to handle saving and loading of data for persistence outside of the main system

    Parameter(s):
        0: Unique ID <STRING>
        0: Serializer function <CODE>
        1: Deserializer function <CODE>

    Return Value:
        None
*/
if (!isServer) exitWith {
    [QGVAR(registerSerializer), _this] call CBA_fnc_serverEvent;
};

params ["_id", ["_serialize", {}], ["_deserialize", {}]];

if (GVAR(serializers) findIf {_x#0 == _id} != -1 || GVAR(deserializers) findIf {_x#0 == _id} != -1) exitWith {
    WARNING_1("Serializer with the same id (%1) already registered",_id);
};

GVAR(serializers) pushBack [_id, _serialize];
GVAR(deserializers) pushBack [_id, _deserialize];
