#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Executes a strike run by creating a laser target at the target
        position and forcing the aircraft to fire its weapons at it.
        Uses the same approach as ZEN's CAS module — the aircraft fires
        its actual loaded weapons repeatedly over a short engagement
        window to ensure reliable delivery. Runs from waypoint
        completion statements on HC.

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

// Reveal target and force engagement — use _laserTarget directly, not laserTarget command
// (laserTarget returns a unit's projected laser spot, not a createVehicle'd LaserTargetE)
private _driver = driver _aircraft;
(group _driver) reveal [_laserTarget, 4];
_driver doWatch _laserTarget;
_driver doTarget _laserTarget;

// Collect all bomb weapons on the aircraft
private _bombWeapons = (weapons _aircraft) select {
    toLower ((_x call BIS_fnc_itemType) select 1) isEqualTo "bomblauncher"
};

// Fire weapons repeatedly over a 3-second engagement window (ZEN CAS approach)
// Single fireAtTarget may miss due to bomb glide path; repeated calls give the AI
// multiple release opportunities during the approach
if (_bombWeapons isNotEqualTo []) then {
    [{
        params ["_args", "_idPFH"];
        _args params ["_aircraft", "_driver", "_laserTarget", "_bombWeapons", "_endTime"];

        if (!alive _aircraft || {CBA_missionTime >= _endTime}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        {
            _driver fireAtTarget [_laserTarget, _x];
        } forEach _bombWeapons;
    }, 0.1, [_aircraft, _driver, _laserTarget, _bombWeapons, CBA_missionTime + 3]] call CBA_fnc_addPerFrameHandler;
};

// Clean up laser target after engagement window
[{
    params ["_laserTarget"];
    deleteVehicle _laserTarget;
}, [_laserTarget], 10] call CBA_fnc_waitAndExecute;
