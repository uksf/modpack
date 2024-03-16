#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a debug sphere
        Can create a singleton sphere that will get overriden on another call
        Sphere types are 10cm, 25cm, 100cm, 250cm

    Parameters:
        0: Position AGL <ARRAY>
        1: Type <STRING> (Optional)
        2: Singleton <BOOLEAN> (Optional) (Default: true)

    Return value:
        Sphere <OBJECT>

    Example:
        [getPosAsl player] call uksf_common_fnc_debugCreateSphere; // Create a singleton sphere at player position
        [getPosAsl player, "25cm", false] call uksf_common_fnc_debugCreateSphere; // Create a sphere at player position
*/
params ["_position", ["_type", "25cm", [""]], ["_singleton", true, [false]]];

private _sphereType = format ["Sign_Sphere%1_Geometry_F", _type];
_position = AGLToASL ASLToATL _position; // createVehicle expects ATL for some reason
private _sphere = createVehicle [_sphereType, _position, [], 0, "CAN_COLLIDE"];

if (isNull _sphere) exitWith {};

if (_singleton) exitWith {
    if (!isNull GVAR(debugSingletonSphere)) then {
        deleteVehicle GVAR(debugSingletonSphere);
    };

    GVAR(debugSingletonSphere) = _sphere;
};

GVAR(debugSpheres) pushBack _sphere;
