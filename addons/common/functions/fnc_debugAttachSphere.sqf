#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a debug sphere attached to a vehicle at a model-relative offset.
        Singleton - each call replaces the previously attached sphere.
        Sphere types are 10cm, 25cm, 100cm, 250cm

    Parameters:
        0: Vehicle <OBJECT>
        1: Offset (model-relative) <ARRAY>
        2: Type <STRING> (Optional) (Default: "25cm")

    Return Value:
        Sphere <OBJECT>

    Example:
        [cursorObject, [1.0, -7.5, -1.3]] call uksf_common_fnc_debugAttachSphere;
        [cursorObject, [1.0, -7.5, -1.3], "10cm"] call uksf_common_fnc_debugAttachSphere;
*/
params [["_vehicle", objNull, [objNull]], ["_offset", [0, 0, 0], [[]], 3], ["_type", "25cm", [""]]];

if (isNull _vehicle) exitWith {objNull};

if (!isNull GVAR(debugAttachedSphere)) then {
    deleteVehicle GVAR(debugAttachedSphere);
};

private _sphereType = format ["Sign_Sphere%1_Geometry_F", _type];
private _sphere = createVehicle [_sphereType, [0, 0, 0], [], 0, "CAN_COLLIDE"];

if (isNull _sphere) exitWith {objNull};

_sphere attachTo [_vehicle, _offset];
GVAR(debugAttachedSphere) = _sphere;
_sphere
