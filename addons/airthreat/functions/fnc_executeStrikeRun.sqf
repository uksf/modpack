#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Executes a strike run by creating a laser target at the target
        position and forcing the aircraft to fire its weapons at it.
        Uses the same approach as BIS_fnc_moduleCAS — the aircraft fires
        its actual loaded weapons rather than spawning fake ordnance.
        Cleans up the laser target after the engagement.

    Parameters:
        0: Aircraft <OBJECT>
        1: Target position <ARRAY> - Position to strike

    Return Value:
        Nothing

    Example:
        [vehicle this, _targetPosition] call uksf_airthreat_fnc_executeStrikeRun
*/
params [["_aircraft", objNull, [objNull]], ["_targetPosition", [0, 0, 0], [[]]]];

if (isNull _aircraft || {!alive _aircraft}) exitWith {};

// Create laser target at strike position for guided weapons
private _laserTarget = createVehicle ["LaserTargetE", _targetPosition, [], 0, "NONE"];

// Reveal target and force engagement
private _driver = driver _aircraft;
(group _driver) reveal [laserTarget _laserTarget, 4];
_driver doWatch (laserTarget _laserTarget);
_driver doTarget (laserTarget _laserTarget);

// Filter to bomb weapons and fire a random one
private _bombWeapons = (weapons _aircraft) select {
    toLower ((_x call BIS_fnc_itemType) select 1) isEqualTo "bomblauncher"
};

if !(_bombWeapons isEqualTo []) then {
    _driver fireAtTarget [laserTarget _laserTarget, selectRandom _bombWeapons];
};

// Clean up laser target after engagement window
[{
    params ["_laserTarget"];
    deleteVehicle _laserTarget;
}, [_laserTarget], 10] call CBA_fnc_waitAndExecute;
