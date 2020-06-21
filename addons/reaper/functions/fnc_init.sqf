#include "script_component.hpp"
/*
    Author:
        Karel Kroonen & Tim Beswick

    Description:
        Controls drone behaviour to be changed and the altitude to be changed.

    Parameter(s):
        0: UAV <OBJECT>

    Return Value:
        Nothing
*/
params ["_uav"];

if (local _uav) then {
    _uav setVariable ["acex_headless_blacklist", true, true];
    _uav setVariable ["NOAI", 1, true];
    _uav setVariable [QGVAR(diveMode), false, true];
    _uav setVariable [QGVAR(observationMode), true, true];
    _uav setVariable [QGVAR(targetHeightASL), 1500, true];
    _uav setVariable [QGVAR(customWaypoint), false, true];
};

GVAR(handlerUav) = [{
    params ["_args"];
    _args params ["_uav", "_heightChanged", "_lastWaypoint"];

    if (local _uav) then {
        private _height = ((getWPPos [_uav, 1])#2);
        private _diveMode = _uav getVariable QGVAR(diveMode);
        private _observationMode = _uav getVariable QGVAR(observationMode);
        private _targetHeightASL = _uav getVariable QGVAR(targetHeightASL);
        private _customWaypoint = _uav getVariable QGVAR(customWaypoint);
        private _currentWaypoint = currentWaypoint (group _uav);
        private _specificDistance = (getPosATL _uav) select 2;
        if (((getWPPos [_uav, _currentWaypoint]) select 2) != 0) then {
            _specificDistance = (getWPPos [_uav, _currentWaypoint]) select 2;
        };

        // Sets the height of all current waypoints to _targetHeightASL if set.
        if (_customWaypoint && !_heightChanged) then {
            if (!(((getWPPos [_uav, _currentWaypoint]) select 2) == _targetHeightASL)) then {
                {
                    _x setWPpos [((getWPPos _x) select 0), ((getWPPos _x) select 1), _targetHeightASL];
                } forEach waypoints (group _uav);
                _height = _targetHeightASL;
            };
        };

        // Slows down the drone if it is in observation mode and close to its waypoint, unlimits speed when it's far from its waypoint.
        if (_observationMode && ((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint])) < (waypointLoiterRadius [_uav, _currentWaypoint] + 500)) then {
            _uav forceSpeed 33;
        } else {
            if (!_diveMode) then {
                _uav forceSpeed -1;
            };
        };

        // Limits speed of the drone when it is getting close to its waypoint (so target can be acquired).
        // Then nosedives the drone in order for the hellfire to get a lock on the laser.
        // Once waypoint is completed drone speed is unlimited and drone climbs back to its original altitude.
        if (_diveMode && ((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint]) < (4000 min (_specificDistance * 3))) && !_heightChanged) then {
            _uav forceSpeed 33;
            if (((getPosATL _uav) distance2D (getWPPos [_uav, _currentWaypoint])) < (_specificDistance * 1.5)) then {
                _targetHeightASL = 200 max (_specificDistance - 200);
                _heightChanged = true;
                _uav forceSpeed -1;
            };
        } else {
            if (_lastWaypoint < _currentWaypoint) then {
                _heightChanged = false;
                _uav setVariable [QGVAR(diveMode), false, true];
                _uav forceSpeed -1;
                _targetHeightASL = 200 max _height;
            };
        };

        // Updates flyInHeight based on ATL and ASL
        _uav flyinHeight 200;
        _uav flyInHeightASL [_targetHeightASL, _targetHeightASL, _targetHeightASL];

        // Update vars
        _args set [1, _heightChanged];
        _args set [2, _currentWaypoint];
    };
}, 0, [_uav, false, 1]] call cba_fnc_addPerFrameHandler;
