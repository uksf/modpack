#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hits provider setup. Listens for the shotFired event from the shots provider,
        then attaches a HitPart event handler to each projectile to detect hits
        on enemy infantry.

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

        if (!(_hitEntity isKindOf "CAManBase")) exitWith {};

        private _targetSide = side group _hitEntity;
        private _shooterSide = _projectile getVariable [QGVAR(shooterSide), sideUnknown];
        if (_targetSide isEqualTo _shooterSide) exitWith {};
        if (_targetSide isEqualTo civilian) exitWith {};

        private _weapon = _projectile getVariable [QGVAR(weapon), ""];
        private _shooter = _projectile getVariable [QGVAR(shooter), _projectileOwner];
        private _distance = if (isNull _shooter) then {0} else {_shooter distance _hitEntity};

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
            ["weapon", _weapon],
            ["bodyPart", _bodyPart],
            ["distance", round _distance]
        ]] call FUNC(addEvent);
    }];

    _projectile setVariable [QGVAR(shooterSide), _side];
    _projectile setVariable [QGVAR(weapon), _weapon];
    _projectile setVariable [QGVAR(shooter), _unit];
}] call CBA_fnc_addEventHandler;
