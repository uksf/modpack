#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates icons on persistent objects with type names, colour coding, and distance filtering

    Parameter(s):
        None

    Return Value:
        None
*/
#define INTERVAL 10
#define MAX_DISTANCE 2000

[QGVAR(requestPersistentObjectsHash), [player]] call CBA_fnc_serverEvent;

GVAR(persistentObjectIconsPFHID) = [{
    params ["_args"];
    _args params ["_time"];

    if (CBA_missionTime > (_time + INTERVAL)) then {
        [QGVAR(requestPersistentObjectsHash), [player]] call CBA_fnc_serverEvent;
        _args set [0, CBA_missionTime];
    };

    {
        _x params ["_id", "_object"];

        if (isNull _object) then {continue};

        private _pos = _object modelToWorld [0,0,0];
        private _dist = player distance _pos;
        if (_dist > MAX_DISTANCE) then {continue};

        private _type = typeOf _object;
        private _colour = [1,1,1,1];
        if (_object isKindOf "AllVehicles") then {
            _colour = [0.3,0.5,1,1];
        } else {
            if (_object isKindOf "Building") then {
                _colour = [1,0.9,0.2,1];
            } else {
                if (_object isKindOf "Thing") then {
                    _colour = [0.2,1,0.2,1];
                };
            };
        };

        private _label = format ["%1\n%2 (%3m)", _type, _id, round _dist];
        drawIcon3D ["", _colour, _pos, 0.5, 0.5, 0, _label, 0, 0.03, "TahomaB", "center"];
    } forEach GVAR(persistentObjects);
}, 0, [0]] call CBA_fnc_addPerFrameHandler;
