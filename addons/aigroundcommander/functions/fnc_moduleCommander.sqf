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
*/
#define PLAYER_FIRED_TIMEOUT 1200

(_this select 1) params ["_module"];

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


["CAManBase", "init", {
    params ["_unit"];

    if (side _unit != EAST) exitWith {TRACE_1("exit side",side _unit)}; // TODO: This side check should be a setting, for cases where we're not fighting OPFOR

    _unit addMPEventHandler ["MPKilled", {
        params ["_unit", "_killer", "_instigator"];

        TRACE_3("",_unit,_killer,_instigator);
        if (isNull _instigator || {!isPlayer _instigator || {surfaceIsWater (getPos _instigator) || {(vehicle _instigator) isKindOf "Air"}}}) exitWith {TRACE_4("exit other",isNull _instigator,isPlayer _instigator,surfaceIsWater (getPos _instigator),(vehicle _instigator) isKindOf "Air")};

        GVAR(enemyAggressionLevel) = GVAR(enemyAggressionLevel) + 1;

        TRACE_1("",GVAR(enemyAggressionLevel));
        private _index = GVAR(killerPlayers) findIf {_instigator == (_x#0)};
        if (_index != -1) then {
            GVAR(killerPlayers) set [_index, [_instigator, time + PLAYER_FIRED_TIMEOUT]];
        } else {
            GVAR(killerPlayers) pushBack [_instigator, time + PLAYER_FIRED_TIMEOUT];
        };
    }]
}, true, [], true] call CBA_fnc_addClassEventHandler;
