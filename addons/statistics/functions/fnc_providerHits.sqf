#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hits provider setup. Uses a class event handler on all infantry to detect
        hits dealt by the local player. HitPart (Entity) fires on the shooter's PC
        and returns an array of sub-arrays (one per component hit simultaneously).
        We only process the first entry to count one hit per projectile impact.
        Body part is determined by scanning all hit selections.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerHits
*/
["CAManBase", "HitPart", {
    if (_this isEqualTo []) exitWith {};

    // Only process the first entry for filtering — all sub-arrays share the same
    // target, shooter, and projectile, just different selections
    (_this#0) params ["_target", "_shooter", "_projectile"];
    private _startTime = diag_tickTime;

    if (_shooter isNotEqualTo player) exitWith {};
    if (_target isEqualTo _shooter) exitWith {};

    // Use config side to handle ACE unconscious group-switching correctly
    private _targetSide = getNumber (configOf _target >> "side");
    private _shooterSide = getNumber (configOf _shooter >> "side");
    if (_targetSide isEqualTo _shooterSide) exitWith {};
    if (_targetSide isEqualTo 3) exitWith {}; // civilian

    // Read shot data from projectile (set by shots provider at time of firing)
    private _shotId = "";
    private _weapon = currentWeapon _shooter;
    if (!isNull _projectile) then {
        _shotId = _projectile getVariable [QGVAR(shotId), ""];
        _weapon = _projectile getVariable [QGVAR(weapon), _weapon];
    };
    private _distance = _shooter distance _target;

    // Scan all hit selections across sub-arrays to determine the best body part
    private _allSelections = [];
    {_allSelections append (_x#5)} forEach _this;
    private _selectionsLower = _allSelections apply {toLower _x};

    private _bodyPart = "torso";
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
        ["distance", round _distance]
    ]] call FUNC(addEvent);

    ["hits", _startTime] call FUNC(addProviderTiming);
}] call CBA_fnc_addClassEventHandler;
