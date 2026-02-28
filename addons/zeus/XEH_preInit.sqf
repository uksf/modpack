#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loadout) = "";
GVAR(EHIDArray) = [];
GVAR(trackedProjectiles) = [];
GVAR(ammoTypeCache) = createHashMap;
GVAR(ammoNameCache) = createHashMap;
GVAR(debugActions) = createHashMap;
GVAR(debugServerGetters) = createHashMap;
GVAR(debugDraws) = createHashMap;
GVAR(debugData) = createHashMap;
GVAR(debugActiveToggles) = createHashMap;
GVAR(debugDistanceLimited) = false;
GVAR(debugStreamClients) = [];
GVAR(debugStreamPFH) = -1;
GVAR(debugHudControls) = [];
GVAR(debugMapDrawID) = -1;
GVAR(debugPFH) = -1;
GVAR(debugClientSources) = createHashMap;
GVAR(debugClientData) = createHashMap;
GVAR(debugClientSourcePFHs) = createHashMap;
GVAR(debugActiveClientSources) = createHashMap;
GVAR(debugLastGetterRun) = createHashMap;
GVAR(debugLastSentData) = createHashMap;
GVAR(debugLastSentKeys) = createHashMap;
GVAR(debugKill) = false;

[QGVAR(registerDebugAction), {
    params ["_key", "_menuName", ["_menuPriority", 0], ["_fnc_menuCondition", {true}]];
    TRACE_2("registerDebugAction",_key,_menuName);
    GVAR(debugActions) set [_key, [_menuName, _menuPriority, _fnc_menuCondition]];
}] call CBA_fnc_addEventHandler;

[QGVAR(registerDebugServerGetter), {
    params ["_key", "_fnc_serverGetter", ["_getterInterval", 5], ["_clientDataKey", ""]];
    TRACE_2("registerDebugServerGetter",_key,_getterInterval);
    GVAR(debugServerGetters) set [_key, [_fnc_serverGetter, _getterInterval, _clientDataKey]];
}] call CBA_fnc_addEventHandler;

[QGVAR(registerDebugDraw), {
    params ["_key", ["_fnc_draw3d", {}], ["_fnc_drawMap", {}], ["_fnc_drawHud", {}]];
    TRACE_1("registerDebugDraw",_key);
    GVAR(debugDraws) set [_key, [_fnc_draw3d, _fnc_drawMap, _fnc_drawHud]];
}] call CBA_fnc_addEventHandler;

[QGVAR(registerDebugClientSource), {
    params ["_sourceKey", "_fnc_clientGetter", "_interval", ["_fnc_onStart", {}], ["_fnc_onStop", {}]];
    GVAR(debugClientSources) set [_sourceKey, [_fnc_clientGetter, _interval, _fnc_onStart, _fnc_onStop]];
}] call CBA_fnc_addEventHandler;

if (isServer) then {
    [QGVAR(debugStreamToggle), {call FUNC(debugStreamToggle)}] call CBA_fnc_addEventHandler;

    [QGVAR(debugClientReport), {
        if (GVAR(debugKill)) exitWith {};
        params ["_sourceKey", "_player", "_data"];
        private _sourceData = GVAR(debugClientData) getOrDefault [_sourceKey, createHashMap];
        _sourceData set [getPlayerUID _player, [_player, _data, CBA_missionTime]];
        GVAR(debugClientData) set [_sourceKey, _sourceData];
    }] call CBA_fnc_addEventHandler;
};

["All", "Fired", {
    params ["_unit", "_weapon", "", "_magazine", "_ammo", "", "_projectile"];
    TRACE_3("Fired EH",_unit,_ammo,_projectile);

    if !(GVAR(debugActiveToggles) getOrDefault [QGVAR(projectiles), false]) exitWith {};

    private _isHeavy = [_ammo, _weapon, _magazine] call FUNC(isHeavyProjectile);
    TRACE_2("ammo classification",_isHeavy,_ammo);
    if !(_isHeavy) exitWith {};

    if (isNull _projectile) then {
        _projectile = nearestObject [_unit, _ammo];
        TRACE_1("projectile was null, tried nearestObject",_projectile);
    };

    if (!isNull _projectile) then {
        private _sideColor = switch (side _unit) do {
            case west:        { [0, 0.3, 0.6, 0.9] };
            case east:        { [0.5, 0, 0, 0.9] };
            case independent: { [0, 0.5, 0, 0.9] };
            default           { [0.4, 0, 0.5, 0.9] };
        };
        GVAR(trackedProjectiles) pushBack [_projectile, _ammo, _sideColor];
        private _count = count GVAR(trackedProjectiles);
        TRACE_3("tracked projectile",_projectile,_ammo,_count);
    } else {
        TRACE_2("projectile still null after nearestObject",_unit,_ammo);
    };
}, true] call CBA_fnc_addClassEventHandler;

[QGVAR(paradrop), {call FUNC(paradrop)}] call CBA_fnc_addEventHandler;
[QGVAR(moveInCargo), {_this#0 moveInCargo _this#1}] call CBA_fnc_addEventHandler;
[QGVAR(paradropFail), {
    params ["_player", "_failPosition"];

    [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' size = '1.2' color = '#FF0000'>FAILED TO JUMP</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 5]] call CBA_fnc_localEvent;
    _player setPosATL ([_failPosition, 15] call CBA_fnc_randPos);
    _player setVelocity [0, 0, 0];
}] call CBA_fnc_addEventHandler;

call FUNC(registerDebugProviders);

if (hasInterface) then {
    call FUNC(addContextActions);

    ["zen_curatorDisplayLoaded", {call FUNC(curatorDisplayLoad)}] call CBA_fnc_addEventHandler;
    ["zen_curatorDisplayUnloaded", {call FUNC(curatorDisplayUnload)}] call CBA_fnc_addEventHandler;

    [QGVAR(debugStreamData), {
        params ["_dataMap"];
        {
            GVAR(debugData) set [_x, _dataMap get _x];
        } forEach keys _dataMap;

        // Check provider conditions and auto-disable any that are no longer valid
        private _invalidKeys = [];
        {
            private _action = GVAR(debugActions) getOrDefault [_x, []];
            if (_action isEqualTo []) then { continue };
            _action params ["", "", "_fnc_menuCondition"];
            if !(call _fnc_menuCondition) then {
                _invalidKeys pushBack _x;
            };
        } forEach keys GVAR(debugActiveToggles);
        {
            [_x] call FUNC(debugToggle);
        } forEach _invalidKeys;
    }] call CBA_fnc_addEventHandler;

    [QGVAR(debugStartClientSource), {
        params ["_sourceKey"];
        private _source = GVAR(debugClientSources) getOrDefault [_sourceKey, []];
        if (_source isEqualTo []) exitWith {};
        _source params ["_fnc_clientGetter", "_interval", "_fnc_onStart"];

        call _fnc_onStart;

        private _pfhId = [{
            params ["_args", "_idPFH"];
            _args params ["_sourceKey", "_fnc_clientGetter"];

            if (GVAR(debugKill)) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
                GVAR(debugClientSourcePFHs) deleteAt _sourceKey;
            };
            private _data = call _fnc_clientGetter;
            if (_data isEqualTo []) exitWith {};
            [QGVAR(debugClientReport), [_sourceKey, player, _data]] call CBA_fnc_serverEvent;
        }, _interval, [_sourceKey, _fnc_clientGetter]] call CBA_fnc_addPerFrameHandler;

        GVAR(debugClientSourcePFHs) set [_sourceKey, _pfhId];
    }] call CBA_fnc_addEventHandler;

    [QGVAR(debugStopClientSource), {
        params ["_sourceKey"];
        private _pfhId = GVAR(debugClientSourcePFHs) getOrDefault [_sourceKey, -1];
        if (_pfhId != -1) then {
            [_pfhId] call CBA_fnc_removePerFrameHandler;
            GVAR(debugClientSourcePFHs) deleteAt _sourceKey;
        };

        private _source = GVAR(debugClientSources) getOrDefault [_sourceKey, []];
        if (_source isNotEqualTo []) then {
            _source params ["", "", "", "_fnc_onStop"];
            call _fnc_onStop;
        };
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
