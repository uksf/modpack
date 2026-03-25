#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Register AI Commander objective debug provider with Zeus.

    Parameters:
        None

    Return Value:
        None
*/

private _key = QGVAR(debug);
private _menuName = "AI Commander";
private _menuPriority = -25;
private _fnc_menuCondition = {GVAR(enabled)};

private _fnc_serverGetter = {
    GVAR(objectives) = GVAR(objectives) select {!isNull _x};
    GVAR(commanders) = GVAR(commanders) select {!isNull _x};

    private _objectiveData = GVAR(objectives) apply {
        private _position2D = getPosATL _x;
        private _ownerSide = _x getVariable [QGVAR(ownerSide), sideUnknown];
        private _colour = [_ownerSide] call FUNC(getSideColour);
        private _state = _x getVariable [QGVAR(currentState), "not_owned"];
        private _priority = _x getVariable [QGVAR(priority), 5];
        private _forcePoolCurrent = _x getVariable [QGVAR(forcePoolGroups), 0];
        private _forcePoolStart = _x getVariable [QGVAR(forcePoolStartGroups), _forcePoolCurrent];
        private _objectiveName = _x getVariable [QGVAR(objectiveName), "OBJ"];

        [_position2D, _objectiveName, _state, _priority, _forcePoolCurrent, _forcePoolStart, _colour]
    };

    private _groupData = [];
    private _seenGroups = createHashMap;
    {
        private _commander = _x;
        private _commanderName = vehicleVarName _commander;
        if (_commanderName isEqualTo "") then {_commanderName = str _commander;};

        private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
        private _colour = [_commanderSide] call FUNC(getSideColour);
        private _managed = _commander getVariable [QGVAR(managedGroups), []];

        {
            private _group = _x getOrDefault ["group", grpNull];
            if (isNull _group || {isNull leader _group} || {!alive (leader _group)}) then {continue};
            private _groupKey = str _group;
            if (_seenGroups getOrDefault [_groupKey, false]) then {continue};
            _seenGroups set [_groupKey, true];

            private _leader = leader _group;
            private _posAGL = getPosATL _leader;
            private _actionType = _x getOrDefault ["actionType", "none"];
            private _groupType = _x getOrDefault ["groupType", "man"];
            private _actionId = _x getOrDefault ["actionId", "none"];
            private _targetObjective = _x getOrDefault ["targetObjectiveName", "none"];

            private _wpPos = [];
            private _wpState = "no_wp";
            private _waypoints = waypoints _group;
            if (_waypoints isNotEqualTo []) then {
                private _wpIndex = (currentWaypoint _group) max 0;
                if (_wpIndex < count _waypoints) then {
                    _wpPos = waypointPosition (_waypoints#_wpIndex);
                    _wpState = "moving_wp";
                };
            };

            _groupData pushBack [
                _posAGL,
                _wpPos,
                _wpState,
                _commanderName,
                _actionType,
                _groupType,
                _actionId,
                _targetObjective,
                _colour
            ];
        } forEach _managed;
    } forEach GVAR(commanders);

    private _intelMerged = createHashMap;
    {
        private _commander = _x;
        private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
        if (_commanderSide isNotEqualTo west) then {continue};

        private _commanderName = vehicleVarName _commander;
        if (_commanderName isEqualTo "") then {_commanderName = str _commander;};

        private _cellSize = (_commander getVariable [QGVAR(gridCellSize), 500]) max 1;
        private _intelGrid = _commander getVariable [QGVAR(intelGrid), createHashMap];
        if !(_intelGrid isEqualType createHashMap) then {continue};

        {
            private _cell = _intelGrid getOrDefault [_x, createHashMap];
            if !(_cell isEqualType createHashMap) then {continue};
            if (_cell isEqualTo createHashMap) then {continue};

            private _state = _cell getOrDefault ["state", "unknown"];
            if !(_state in ["enemy_present", "unknown"]) then {continue};

            private _grid = _cell getOrDefault ["grid", []];
            if !(_grid isEqualType [] && {count _grid >= 2}) then {continue};

            private _cellKey = format ["%1:%2", _grid#0, _grid#1];
            private _lastUpdated = _cell getOrDefault ["lastUpdatedAt", -1];
            private _enemyUnits = _cell getOrDefault ["enemyUnits", 0];
            private _enemyGroups = _cell getOrDefault ["enemyGroups", 0];
            private _position2D = [((_grid#0) + 0.5) * _cellSize, ((_grid#1) + 0.5) * _cellSize];

            private _existing = _intelMerged getOrDefault [_cellKey, createHashMap];
            private _replace = false;
            if (_existing isEqualTo createHashMap) then {
                _replace = true;
            } else {
                private _existingState = _existing getOrDefault ["state", "unknown"];
                private _existingLast = _existing getOrDefault ["lastUpdatedAt", -1];

                if (_state isEqualTo "enemy_present" && {_existingState isEqualTo "unknown"}) then {
                    _replace = true;
                } else {
                    if (_state isEqualTo _existingState && {_lastUpdated > _existingLast}) then {
                        _replace = true;
                    };
                };
            };

            if (_replace) then {
                _intelMerged set [_cellKey, createHashMapFromArray [
                    ["position2D", _position2D],
                    ["grid", _grid],
                    ["state", _state],
                    ["enemyUnits", _enemyUnits],
                    ["enemyGroups", _enemyGroups],
                    ["commanderName", _commanderName],
                    ["lastUpdatedAt", _lastUpdated]
                ]];
            };
        } forEach keys _intelGrid;
    } forEach GVAR(commanders);

    private _intelData = [];
    {
        private _entry = _intelMerged getOrDefault [_x, createHashMap];
        if (_entry isEqualType createHashMap && {_entry isNotEqualTo createHashMap}) then {
            _intelData pushBack [
                _entry getOrDefault ["position2D", [0, 0]],
                _entry getOrDefault ["grid", [0, 0]],
                _entry getOrDefault ["state", "unknown"],
                _entry getOrDefault ["enemyUnits", 0],
                _entry getOrDefault ["enemyGroups", 0],
                _entry getOrDefault ["commanderName", "BLUFOR_CMD"]
            ];
        };
    } forEach keys _intelMerged;

    [_objectiveData, _groupData, _intelData]
};

private _fnc_draw3d = {
    params ["_data", "_cameraPosition", "_maxDistance"];
    private _objectiveData = _data#0;
    private _groupData = _data#1;

    {
        _x params ["_position2D", "_objectiveName", "_state", "_priority", "_forcePoolCurrent", "_forcePoolStart", "_colour"];

        if (_cameraPosition distance2D _position2D <= _maxDistance) then {
            private _positionAGL = ASLToAGL [_position2D#0, _position2D#1, (getTerrainHeightASL _position2D) + 0.25];
            drawIcon3D ["\a3\ui_f\data\map\markers\military\objective_ca.paa", _colour, _positionAGL, 0.7, 0.7, 0, _objectiveName, 1, 0.024, "TahomaB", "center"];
            drawIcon3D ["", _colour, _positionAGL, 0, 0, 0, format ["State: %1  Priority: %2", _state, _priority], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING];
            drawIcon3D ["", _colour, _positionAGL, 0, 0, 0, format ["Pool: %1/%2", _forcePoolCurrent, _forcePoolStart], 1, 0.02, "TahomaB", "center", false, 0, DEBUG_ICON_SPACING * 2];
        };
    } forEach _objectiveData;

    {
        _x params [
            "_groupPosAGL",
            "_wpPos",
            "_wpState",
            "_commanderName",
            "_actionType",
            "_groupType",
            "_actionId",
            "_targetObjective",
            "_colour"
        ];

        if (_cameraPosition distance2D _groupPosAGL <= _maxDistance) then {
            private _drawPos = [_groupPosAGL#0, _groupPosAGL#1, (_groupPosAGL#2) + 1.5 + ((_forEachIndex mod 3) * 0.15)];
            private _summary = format ["%1 | %2 | %3 -> %4", _commanderName, _groupType, _actionType, _targetObjective];
            drawIcon3D ["\a3\ui_f\data\map\markers\nato\b_inf.paa", _colour, _drawPos, 0.8, 0.8, 0, _summary, 1, 0.028, "TahomaB", "center"];
            drawIcon3D ["", _colour, _drawPos, 0, 0, 0, format ["task=%1 action=%2 wp=%3", _actionType, _actionId, _wpState], 1, 0.024, "TahomaB", "center", false, 0, 0.065];

            if (_wpPos isEqualType [] && {count _wpPos >= 2}) then {
                private _wpDraw = [_wpPos#0, _wpPos#1, ((_wpPos#2) max 0) + 0.4];
                drawLine3D [_drawPos, _wpDraw, _colour];
                drawIcon3D ["\a3\ui_f\data\map\groupicons\waypoint.paa", _colour, _wpDraw, 0.6, 0.6, 0, "WP", 1, 0.022, "TahomaB", "center"];
            };
        };
    } forEach _groupData;

};

private _fnc_drawMap = {
    params ["_data", "_map"];
    private _objectiveData = _data#0;
    private _intelData = _data param [2, []];

    {
        _x params ["_position2D", "_objectiveName", "_state", "_priority", "_forcePoolCurrent", "_forcePoolStart", "_colour"];

        _map drawIcon ["\a3\ui_f\data\map\markers\military\objective_ca.paa", _colour, _position2D, 20, 20, 0, format ["%1 | %2 | P%3 | %4/%5", _objectiveName, _state, _priority, _forcePoolCurrent, _forcePoolStart], 1, 0.032, "TahomaB", "right"];
    } forEach _objectiveData;

    {
        _x params ["_position2D", "_grid", "_state", "_enemyUnits", "_enemyGroups", "_commanderName"];
        private _colour = if (_state isEqualTo "enemy_present") then {[1, 0.15, 0.15, 0.9]} else {[0.6, 0.8, 1, 0.55]};
        private _icon = if (_state isEqualTo "enemy_present") then {"\a3\ui_f\data\map\markers\military\warning_ca.paa"} else {"\a3\ui_f\data\map\markers\military\dot_ca.paa"};
        private _label = if (_state isEqualTo "enemy_present") then {
            format ["BLUFOR intel | g:%1,%2 | ENY u:%3 g:%4 | %5", _grid#0, _grid#1, _enemyUnits, _enemyGroups, _commanderName]
        } else {
            format ["BLUFOR intel | g:%1,%2 | UNKNOWN | %3", _grid#0, _grid#1, _commanderName]
        };

        _map drawIcon [_icon, _colour, _position2D, 14, 14, 0, _label, 1, 0.028, "TahomaB", "right"];
    } forEach _intelData;
};

[QEGVAR(zeus,registerDebugAction), [_key, _menuName, _menuPriority, _fnc_menuCondition]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugServerGetter), [_key, _fnc_serverGetter]] call CBA_fnc_localEvent;
[QEGVAR(zeus,registerDebugDraw), [_key, _fnc_draw3d, _fnc_drawMap]] call CBA_fnc_localEvent;
