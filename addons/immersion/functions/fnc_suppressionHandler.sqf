#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Handles suppression fired event queue

    Parameters:
        None

    Return value:
        None
*/

private _deleted = false;
{
    _x params ["_projectile", "_detectionDistance", "_hit"];

    if !(alive _projectile) then {
        GVAR(suppressionArray) set [_forEachIndex, objNull];
        _deleted = true;
    } else {
        private _distanceToPlayer = _projectile distance GVAR(suppression_currentUnit);
        if (_distanceToPlayer <= _detectionDistance) then {
            private _pPos = getPosATL _projectile;
            private _lis = lineIntersectsSurfaces [ATLToASL _pPos, eyePos GVAR(suppression_currentUnit), GVAR(suppression_currentUnit)];
            if !(_lis isEqualTo []) then {
                _detectionDistance = _detectionDistance * 0.65;
            };

            if (_distanceToPlayer <= _detectionDistance) then {
                private _factor  = 1 - (_distanceToPlayer / _detectionDistance);
                private _divisor = 25 - (9 * _factor);
                GVAR(suppression_lastShotAt) = time;

                if ((vehicle GVAR(suppression_currentUnit)) == GVAR(suppression_currentUnit) || {isTurnedOut GVAR(suppression_currentUnit)}) then {
                    [_factor] call FUNC(suppressionImpact);

                    if (_divisor != 0) then {
                        private _add = GVAR(suppression_buildup) * (_hit / _divisor);
                        GVAR(suppression_threshold) = (GVAR(suppression_threshold) + _add) min SUPPRESSION_MAX_VALUE;
                    };
                };
            };

            GVAR(suppressionArray) set [_forEachIndex, objNull];
            _deleted = true;
        };
    };
} forEach GVAR(suppressionArray);

if (_deleted) then {
    GVAR(suppressionArray) = GVAR(suppressionArray) - [objNull];
};
