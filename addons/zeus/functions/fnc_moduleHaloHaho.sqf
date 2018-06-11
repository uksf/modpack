/*
    Author:
        Tim Beswick

    Description:
        Starts selection of units to drop in to then given location

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"

params ["_logic"];

if (!local _logic) exitWith {};

["Select units and press 'Return'. Press 'Escape' to cancel"] call ace_zeus_fnc_showMessage;

private _display = findDisplay IDD_RSCDISPLAYCURATOR;
GVAR(curatorSelectionHandle) = _display displayAddEventHandler ["KeyDown", {
    params ["_display", "_key"];

    switch (true) do {
        case (_key == DIK_ESCAPE): {
            _display displayRemoveEventHandler ["KeyDown", GVAR(curatorSelectionHandle)];
            true
        };
        case (_key == DIK_NUMPADENTER);
        case (_key == DIK_RETURN): {
            _display displayRemoveEventHandler ["KeyDown", GVAR(curatorSelectionHandle)];

            GVAR(haloHahoUnits) = curatorSelected#0;
            GVAR(haloHahoMapPoints) = [];

            ["Open the map and left click on a start and end position. Press 'Escape' to cancel"] call ace_zeus_fnc_showMessage;
            GVAR(curatorCancelHandle) = _display displayAddEventHandler ["KeyDown", {
                params ["_display", "_key"];

                if (_key == DIK_ESCAPE) then {
                    _display displayRemoveEventHandler ["MouseButtonDown", GVAR(curatorMapPointHandle)];
                    _display displayRemoveEventHandler ["KeyDown", GVAR(curatorCancelHandle)];
                    true
                };
            }];

            GVAR(curatorMapPointHandle) = [findDisplay 312, "MouseButtonDown", {
                params ["_display", "_mouseButton", "", "", "_shift", "_ctrl", "_alt"];

                if (_mouseButton != 0) exitWith {};
                if (ctrlShown (_display displayCtrl 50)) then {
                    private _position = ((_display displayCtrl 50) ctrlMapScreenToWorld getMousePosition);
                    _position set [2, 2000];
                    GVAR(haloHahoMapPoints) pushBack _position;
                };
                if ((count GVAR(haloHahoMapPoints)) >= 2) exitWith {
                    _display displayRemoveEventHandler ["MouseButtonDown", GVAR(curatorMapPointHandle)];
                    _display displayRemoveEventHandler ["KeyDown", GVAR(curatorCancelHandle)];
                    
                    ["Dropping in %1 units", count GVAR(haloHahoUnits)] call ace_zeus_fnc_showMessage;
                    {
                        [QGVAR(textTiles), [parseText format ["<t align = 'center' color = '#00CC00'>STANDBY FOR PICKUP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
                        true
                    } count GVAR(haloHahoUnits);

                    private _positionA = GVAR(haloHahoMapPoints)#0;
                    private _positionB = GVAR(haloHahoMapPoints)#1;
                    private _vectorDirection = _positionA vectorFromTo _positionB;
                    private _heading = (_vectorDirection#0 atan2 _vectorDirection#1);
                    private _start = _positionA getPos [1500, _heading - 180];
                    private _end = _positionB getPos [1000, _heading];
                    _start set [2, 2000];
                    _end set [2, 2000];
                    private _distanceToTravel = vectorMagnitude (_start vectorDiff _end);
                    private _timeToTake = _distanceToTravel / (50 + (random 10));
                    private _frameStep = _distanceToTravel / (_timeToTake * 30);

                    private _plane = createVehicle ["CUP_B_C130J_GB", [0,0,2000], [], 0, "NONE"];
                    _plane engineOn true;
                    _plane setDir _heading;
                    _plane setVectorDirAndUp [_vectorDirection, [0,0,1]];
                    _plane setPosASL _start;

                    [{
                        params ["_args", "_idPFH"];
                        _args params ["_plane", "_start", "_end", "_vectorDirection", "_frameStep", "_positionA", "_positionB", "_previousPosition", "_positionAReached", "_positionBReached"];

                        if (!(alive _plane) || {(_previousPosition distance2D _end) < 25}) exitWith {
                            [_idPFH] call CBA_fnc_removePerFrameHandler;
                            deleteVehicle _plane;
                        };

                        private _unitsIn = _plane getVariable [QGVAR(unitsIn), false];
                        if (!_unitsIn && {(_previousPosition distance2D _positionA) < 1000}) then {
                            _plane setVariable [QGVAR(unitsIn), true, true];
                            {[QGVAR(moveInCargo), [_x, _plane], _x] call CBA_fnc_targetEvent; true} count GVAR(haloHahoUnits);
                        };

                        private _positionPreAReached = _plane getVariable [QGVAR(positionPreAReached), false];
                        if (!_positionPreAReached && {(_previousPosition distance2D _positionA) < 500}) then {
                            _positionPreAReached = true;
                            _plane setVariable [QGVAR(positionPreAReached), _positionPreAReached, true];
                            _plane animate ["ramp_top", 1];
                            _plane animate ["ramp_bottom", 0.7];
                            {
                                [QGVAR(textTiles), [parseText format ["<t align = 'center' color = '#FF0000'>STANDBY TO JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
                                true
                            } count GVAR(haloHahoUnits);
                        };
                        if (_positionPreAReached && {!_positionAReached} && {(_previousPosition distance2D _positionA) < 25}) then {
                            _args set [8, true];
                            {
                                [QGVAR(textTiles), [parseText format ["<t align = 'center' color = '#00CC00'>GREEN LIGHT - JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5], _x] call CBA_fnc_targetEvent;
                                true
                            } count GVAR(haloHahoUnits);
                        };
                        if (_positionPreAReached && {_positionAReached} && {!_positionBReached} && {(_previousPosition distance2D _positionB) < 25}) then {
                            _args set [9, true];
                            _plane animate ["ramp_top", 0];
                            _plane animate ["ramp_bottom", 0];
                        };

                        private _newPosition = _previousPosition vectorAdd (_vectorDirection vectorMultiply _frameStep);
                        _plane setPosASL _newPosition;
                        _plane setVectorUp [0,0,1];
                        _args set [7, _newPosition];
                    }, 0, [_plane, _start, _end, _vectorDirection, _frameStep, _positionA, _positionB, _start, false, false]] call CBA_fnc_addPerFrameHandler;
                };
            }] call CBA_fnc_addBISEventHandler;

            true
        };
    };
}];

deleteVehicle _logic;
