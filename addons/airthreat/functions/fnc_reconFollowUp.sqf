#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Triggers a follow-up strike mission at a position observed by a
        recon aircraft. Fires after a 2-5 minute delay. The recon aircraft
        stays on station until the strike completes. If the recon is
        destroyed before the strike fires, the strike uses the stored
        observed position. Server only — called via CBA server event.

    Parameters:
        0: Observed position <ARRAY> - The position the recon observed
        1: Recon group <GROUP> - The recon aircraft's group
        2: Recon vehicle <OBJECT> - The recon aircraft

    Return Value:
        Nothing

    Example:
        [_observedPosition, _reconGroup, _reconVehicle] call uksf_airthreat_fnc_reconFollowUp
*/
params [
    ["_observedPosition", [0, 0, 0], [[]]],
    ["_reconGroup", grpNull, [grpNull]],
    ["_reconVehicle", objNull, [objNull]]
];

if !(isServer) exitWith {};

// Tell recon to stay on station
if (!isNull _reconVehicle && {alive _reconVehicle}) then {
    _reconVehicle setVariable [QGVAR(reconState), "strikeActive", true];
};

private _delay = 120 + random 180;

[{
    params ["_observedPosition", "_reconGroup", "_reconVehicle"];

    if !(GVAR(casStrikeEnabled)) exitWith {
        // No strike — release recon
        if (!isNull _reconVehicle && {alive _reconVehicle}) then {
            _reconVehicle setVariable [QGVAR(reconState), "complete", true];
        };
    };

    if !(call FUNC(canSpawnMission)) exitWith {
        if (!isNull _reconVehicle && {alive _reconVehicle}) then {
            _reconVehicle setVariable [QGVAR(reconState), "complete", true];
        };
    };

    // Spawn strike on server — pass recon vehicle reference for coordination
    [QGVAR(spawnStrike), [_observedPosition, _reconVehicle]] call CBA_fnc_localEvent;

    INFO("Recon follow-up strike dispatched");
}, [_observedPosition, _reconGroup, _reconVehicle], _delay] call CBA_fnc_waitAndExecute;
