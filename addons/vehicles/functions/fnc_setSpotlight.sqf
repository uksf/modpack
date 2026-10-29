#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches the weapon spotlight of a vehicle turret on, to IR, or off.
        Runs on the server. The light is attached to the gun muzzle and turns with it.

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Turret path <ARRAY>
        2: Mode, "" for off, "white" or "ir" <STRING>

    Return Value:
        None

    Example:
        [vehicle player, [0], "ir"] call uksf_vehicles_fnc_setSpotlight
*/
params ["_vehicle", "_turret", "_mode"];

if !(_mode in ["", "white", "ir"] && {_turret in ([_vehicle] call FUNC(spotlightTurrets))}) exitWith {};

private _key = format [QGVAR(spotlight_%1), _turret];
deleteVehicle (_vehicle getVariable [_key + "_object", objNull]);
_vehicle setVariable [_key, _mode, true];
if (_mode isEqualTo "") exitWith {};

private _config = [_vehicle, _turret] call CBA_fnc_getTurret;
private _muzzle = getText (_config >> "gunBeg");
private _breech = getText (_config >> "gunEnd");
private _direction = vectorNormalized ((_vehicle selectionPosition _muzzle) vectorDiff (_vehicle selectionPosition _breech));

private _light = createVehicle [[QGVAR(spotlight), QGVAR(spotlightIR)] select (_mode isEqualTo "ir"), [0, 0, 0], [], 0, "CAN_COLLIDE"];
_light attachTo [_vehicle, [0, 0, 0], _muzzle, true];
_light setVectorDirAndUp [_direction, [0, 0, 1]];
_vehicle setVariable [_key + "_object", _light];

GVAR(spotlights) pushBack [_vehicle, _light];
if (GVAR(spotlightCleanupHandle) == -1) then {
    GVAR(spotlightCleanupHandle) = [{
        GVAR(spotlights) = GVAR(spotlights) select {
            _x params ["_vehicle", "_light"];
            private _keep = alive _vehicle && {!isNull _light};
            if (!_keep) then {deleteVehicle _light};
            _keep
        };
        if (GVAR(spotlights) isEqualTo []) then {
            [GVAR(spotlightCleanupHandle)] call CBA_fnc_removePerFrameHandler;
            GVAR(spotlightCleanupHandle) = -1;
        };
    }, 5] call CBA_fnc_addPerFrameHandler;
};
