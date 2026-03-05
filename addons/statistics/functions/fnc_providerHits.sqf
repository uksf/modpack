#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hits provider setup. Listens to the shotFired event from the shots provider
        and attaches a HitPart handler to each projectile. This ensures hits are
        only tracked for shots fired by the local player.
        Each hit is correlated to a shot via the shotId stored on the projectile
        by the shots provider.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerHits
*/
[QGVAR(shotFired), {
    params ["_unit", "_weapon", "_projectile"];

    if (isNull _projectile) exitWith {};

    private _side = side group _unit;

    _projectile addEventHandler ["HitPart", {
        params ["_projectile", "_hitEntity", "_projectileOwner", "_position", "_velocity", "_normal", "_components", "_radius", "_surfaceType"];
        private _startTime = diag_tickTime;

        if (_hitEntity isKindOf "CAManBase") then {
            private _targetSide = side group _hitEntity;
            private _shooterSide = _projectile getVariable [QGVAR(shooterSide), sideUnknown];
            if (_targetSide isNotEqualTo _shooterSide && {_targetSide isNotEqualTo civilian}) then {
                private _weapon = _projectile getVariable [QGVAR(weapon), ""];
                private _shooter = _projectile getVariable [QGVAR(shooter), _projectileOwner];
                private _distance = if (isNull _shooter) then {0} else {_shooter distance _hitEntity};
                private _shotId = _projectile getVariable [QGVAR(shotId), ""];

                private _bodyPart = "torso";
                private _componentsLower = _components apply {toLower _x};
                if (_componentsLower findIf {_x find "head" != -1 || {_x find "face" != -1} || {_x find "neck" != -1}} != -1) then {
                    _bodyPart = "head";
                } else {
                    if (_componentsLower findIf {_x find "leg" != -1 || {_x find "foot" != -1}} != -1) then {
                        _bodyPart = "legs";
                    } else {
                        if (_componentsLower findIf {_x find "hand" != -1 || {_x find "arm" != -1}} != -1) then {
                            _bodyPart = "arms";
                        };
                    };
                };

                [createHashMapFromArray [
                    ["type", "hit"],
                    ["shotId", _shotId],
                    ["weapon", _weapon],
                    ["bodyPart", _bodyPart],
                    ["distance", round _distance]
                ]] call FUNC(addEvent);
            };
        };

        ["hits", _startTime] call FUNC(addProviderTiming);
    }];

    _projectile setVariable [QGVAR(shooterSide), _side];
    _projectile setVariable [QGVAR(weapon), _weapon];
    _projectile setVariable [QGVAR(shooter), _unit];
}] call CBA_fnc_addEventHandler;
