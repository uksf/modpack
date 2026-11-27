#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Init for Commander module/unit:
            - Create PFH
            - Establish time conditions for responses base on commander skil level

    Parameters:
        0: Module <OBJECT>

    Return value:
        Nothing

    Example:
        [_module] call uksf_aigroundcommander_fnc_moduleCommander
*/
#define PLAYER_FIRED_TIMEOUT 1200

if (is3DEN) exitWith {};

(_this select 1) params ["_module"];

GVAR(enabled) = true;
publicVariable QGVAR(enabled);

// TODO: Tick aggression down based on number of killer players at tick (more killers = less reduction)

[{
    params ["_module"];

    private _interval = _module getVariable [QGVAR(interval), 900];
    [{call FUNC(selectResponse)}, _interval] call CBA_fnc_addPerFrameHandler;
    [{call FUNC(cleanup)}, _interval / 4] call CBA_fnc_addPerFrameHandler;

    [{
        GVAR(tier1ResponseDeployed) = false;
        GVAR(tier2ResponseDeployed) = false;
    }, _interval * 1.5] call CBA_fnc_addPerFrameHandler;
}, [_module], 60] call CBA_fnc_waitAndExecute;


if (isServer && {isNil QGVAR(entityKilledHandler)}) then {
    GVAR(entityKilledHandler) = addMissionEventHandler ["EntityKilled", {
        params ["_unit", "_killer", "_instigator"];

        if !(_unit isKindOf "CAManBase" && {side group _unit isEqualTo east}) exitWith {};
        if (isNull _instigator || {!isPlayer _instigator || {surfaceIsWater (getPos _instigator) || {(vehicle _instigator) isKindOf "Air"}}}) exitWith {};

        GVAR(enemyAggressionLevel) = GVAR(enemyAggressionLevel) + 1;
        private _index = GVAR(killerPlayers) findIf {_instigator == (_x#0)};
        if (_index != -1) then {
            GVAR(killerPlayers) set [_index, [_instigator, CBA_missionTime + PLAYER_FIRED_TIMEOUT]];
        } else {
            GVAR(killerPlayers) pushBack [_instigator, CBA_missionTime + PLAYER_FIRED_TIMEOUT];
        };
    }];
};
