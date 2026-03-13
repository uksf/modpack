#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hits provider setup. Uses a class event handler on all infantry to detect
        hits dealt by the local player. HitPart (Entity) fires on the shooter's PC,
        so we filter to only record when the shooter is the local player.
        Each hit is correlated to a shot via the shotId stored on the projectile
        by the shots provider.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerHits
*/
["CAManBase", "HitPart", {
    {
        _x params ["_target", "_shooter", "_projectile", "_position", "_velocity", "_selection", "_ammo", "_vector", "_radius", "_surfaceType", "_isDirect"];

        if (_shooter != player) exitWith {};
        if (_target isEqualTo _shooter) exitWith {};
        if (side group _target isEqualTo side group _shooter) exitWith {};
        if (side group _target isEqualTo civilian) exitWith {};

        private _weapon = currentWeapon _shooter;
        private _distance = _shooter distance _target;
        private _shotId = if (!isNull _projectile) then {
            _projectile getVariable [QGVAR(shotId), ""]
        } else {
            ""
        };

        private _bodyPart = "torso";
        private _selectionsLower = _selection apply {toLower _x};
        if (_selectionsLower findIf {_x find "head" != -1 || {_x find "face" != -1} || {_x find "neck" != -1}} != -1) then {
            _bodyPart = "head";
        } else {
            if (_selectionsLower findIf {_x find "leg" != -1 || {_x find "foot" != -1}} != -1) then {
                _bodyPart = "legs";
            } else {
                if (_selectionsLower findIf {_x find "hand" != -1 || {_x find "arm" != -1}} != -1) then {
                    _bodyPart = "arms";
                };
            };
        };

        [createHashMapFromArray [
            ["type", "hit"],
            ["shotId", _shotId],
            ["weapon", _weapon],
            ["bodyPart", _bodyPart],
            ["distance", round _distance],
            ["direct", _isDirect]
        ]] call FUNC(addEvent);
    } forEach _this;
}] call CBA_fnc_addClassEventHandler;
