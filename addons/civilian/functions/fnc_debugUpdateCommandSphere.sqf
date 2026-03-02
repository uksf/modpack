#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates a command target sphere for a debug-tracked entity.
        Creates, repositions, or removes the sphere as appropriate.

    Parameter(s):
        0: Entity <OBJECT> - the vehicle or civilian
        1: Is active <BOOLEAN> - whether this command type is currently active
        2: Sphere array <ARRAY> - the array tracking [entity, sphere] pairs for this command type
        3: Position <ARRAY> - the target position (empty array if unavailable)
        4: Inactive colour <STRING> - texture to show when position is unavailable (empty string to skip)

    Return Value:
        None
*/
params ["_entity", "_isActive", "_sphereArray", "_position", ["_inactiveColour", ""]];

private _index = _sphereArray findIf {(_x#0) == _entity};
private _sphere = if (_index != -1) then {_sphereArray#_index#1} else {objNull};

if (_isActive) then {
    if (_position isNotEqualTo []) then {
        if (isNull _sphere) then {
            _sphere = createVehicle ["Sign_Sphere25cm_F", _position, [], 0, "CAN_COLLIDE"];
            _sphereArray pushBack [_entity, _sphere];
        } else {
            _sphere setPos _position;
        };
    } else {
        if (!isNull _sphere && {_inactiveColour != ""}) then {
            _sphere setObjectTextureGlobal [0, _inactiveColour];
        };
    };
} else {
    deleteVehicle _sphere;
    if (_index != -1) then {
        _sphereArray deleteAt _index;
    };
};
