#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Populates given vehicle with given unit array.
        If turret array is given, units will be removed from the given turret indices

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Units <ARRAY>
        1: Turrets <ARRAY> (Optional)
        1: Side <SCALAR> (Optional)

    Return Value:
        Nothing
*/
#define TIMEOUT 30

params [["_vehicle", objNull], ["_units", []], ["_turrets", []], ["_side", -1]];

if (isServer) then {
    [{
        params ["_vehicle", "_units", "_turrets", "_side"];
        if (!isNull (driver _vehicle)) then {
            _side = switch (_side) do {
                case -1: { side (driver _vehicle) };
                case 0: { east };
                case 1: { west };
                case 2: { resistance };
                case 3: { civilian };
                default { sideUnknown };
            };

            private _group = createGroup _side;
            [{
                params ["_args", "_idPFH"];
                _args params ["_vehicle", "_units", "_index", "_group", "_turrets", "_time"];

                if (_index isEqualTo (count _units) || {isNull _vehicle} || {time > (_time + TIMEOUT)}) exitWith {
                    [_idPFH] call CBA_fnc_removePerFrameHandler;
                    if (count _turrets > 0) then {
                        [{
                            params ["_vehicle", "_turrets"];
                            {
                                [_vehicle turretUnit [_x]] join grpNull;
                                deleteVehicle (_vehicle turretUnit [_x]);
                            } forEach _turrets;
                        }, [_vehicle, _turrets], 2] call cba_fnc_waitAndExecute;
                    };
                };

                private _unit = (_group createUnit [(_units select _index), [0,0,0], [], 0, "NONE"]);
                _unit moveInCargo _vehicle;

                _args set [2, _index + 1];
            }, 1, [_vehicle, _units, 0, _group, _turrets, time]] call CBA_fnc_addPerFrameHandler;
        };
    }, [_vehicle, _units, _turrets, _side], 2] call cba_fnc_waitAndExecute;
};
