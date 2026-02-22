#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ZEN context actions

    Parameter(s):
        None

    Return Value:
        None
*/
private _action = [QGVAR(ai), "UKSF AI", "", {}, {
    params ["", "_selectedObjects"];
    _selectedObjects isNotEqualTo [] && {({isPlayer _x} count _selectedObjects) == 0}
}, [], {
    private _actions = [];

    private _action = [QGVAR(supportRadio), "Remove Support Radio", "", {call FUNC(contextSupportRadio)}, {call FUNC(contextCanSupportRadio)}, [], {}, {call FUNC(contextSupportRadioModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(caching), "Exclude From Caching", QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa), {call FUNC(contextCaching)}, {call FUNC(contextCanCaching)}, [], {}, {call FUNC(contextCachingModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 100] call zen_context_menu_fnc_addAction;

_action = [QGVAR(tools), "Tools", "", {}, {true}, [], {
    private _actions = [];

    private _action = [QGVAR(cleanup), "Exclude From Cleanup", QPATHTOF(ui\Icon_Module_Cleanup_Exclude_ca.paa), {call FUNC(contextCleanup)}, {call FUNC(contextCanCleanup)}, [], {}, {call FUNC(contextCleanupModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(forceDelete), "Force Delete", QPATHTOF(ui\Icon_Module_Cleanup_ca.paa), {
        params ["", "_selectedObjects"];
        {deleteVehicle _x} forEach _selectedObjects;
    }, {
        params ["", "_selectedObjects"];
        _selectedObjects isNotEqualTo [] && {({isPlayer _x} count _selectedObjects) == 0}
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 85] call zen_context_menu_fnc_addAction;

_action = [QGVAR(visualise), "Visualise", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {}, {true}, [], {
    private _actions = [];

    private _action = [QGVAR(toggleAllVisualisations), "Show All", "", {
        private _availableKeys = [];
        if (EGVAR(aigroundcommander,enabled)) then { _availableKeys pushBack "aicommander" };
        if (EGVAR(sectorcontrol,enabled)) then { _availableKeys pushBack "sectorcontrol" };
        if (EGVAR(mission,dynamicPatrolAreasEnabled)) then { _availableKeys pushBack "dynamicpatrols" };
        if (EGVAR(arearating,ratingAreas) isNotEqualTo []) then { _availableKeys pushBack "arearating" };
        if (EGVAR(caching,enabled)) then { _availableKeys pushBack "cachedgroups" };
        if (EGVAR(radios,rebroStations) isNotEqualTo []) then {
            _availableKeys append ["rebroconnections", "rebronetwork"];
        };

        private _anyActive = _availableKeys findIf {GVAR(visualiseActiveToggles) getOrDefault [_x, false]} != -1 || GVAR(projectilesEnabled);
        {
            if (_anyActive) then {
                if (GVAR(visualiseActiveToggles) getOrDefault [_x, false]) then {
                    [_x] call FUNC(visualiseToggle);
                };
            } else {
                if !(GVAR(visualiseActiveToggles) getOrDefault [_x, false]) then {
                    [_x] call FUNC(visualiseToggle);
                };
            };
        } forEach _availableKeys;
        if (_anyActive) then {
            GVAR(projectilesEnabled) = false;
        } else {
            GVAR(projectilesEnabled) = true;
        };
    }, {true}, [], {}, {
        params ["_action"];
        private _allKeys = ["aicommander", "sectorcontrol", "dynamicpatrols", "arearating", "cachedgroups", "rebroconnections", "rebronetwork"];
        private _anyActive = _allKeys findIf {GVAR(visualiseActiveToggles) getOrDefault [_x, false]} != -1 || GVAR(projectilesEnabled);
        _action set [1, ["Show All", "Hide All"] select _anyActive];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _action = [QGVAR(toggleDistanceLimit), "Limit Draw Distance", "", {GVAR(visualiseDistanceLimited) = !GVAR(visualiseDistanceLimited)}, {true}, [], {}, {
        params ["_action"];
        _action set [1, ["Limit Draw Distance", "Max Draw Distance"] select GVAR(visualiseDistanceLimited)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -1000];

    _action = [QGVAR(toggleFPS), "Show Player FPS", "", {GVAR(fpsEnabled) = !GVAR(fpsEnabled)}, {isMultiplayer}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Player FPS", "Hide Player FPS"] select GVAR(fpsEnabled)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -5];

    _action = [QGVAR(toggleProjectiles), "Show Projectiles", "", {
        GVAR(projectilesEnabled) = !GVAR(projectilesEnabled);
        private _count = count GVAR(trackedProjectiles);
        TRACE_2("toggled projectile tracking",GVAR(projectilesEnabled),_count);
    }, {true}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Projectiles", "Hide Projectiles"] select GVAR(projectilesEnabled)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -10];

    _action = [QGVAR(toggleAICommander), "Show AI Commander", "", {
        ["aicommander"] call FUNC(visualiseToggle);
    }, {EGVAR(aigroundcommander,enabled)}, [], {}, {
        params ["_action"];
        _action set [1, ["Show AI Commander", "Hide AI Commander"] select (GVAR(visualiseActiveToggles) getOrDefault ["aicommander", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -20];

    _action = [QGVAR(toggleSectorControl), "Show Sector Control", "", {
        ["sectorcontrol"] call FUNC(visualiseToggle);
    }, {EGVAR(sectorcontrol,enabled)}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Sector Control", "Hide Sector Control"] select (GVAR(visualiseActiveToggles) getOrDefault ["sectorcontrol", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -30];

    _action = [QGVAR(toggleDynamicPatrols), "Show Dynamic Patrols", "", {
        ["dynamicpatrols"] call FUNC(visualiseToggle);
    }, {EGVAR(mission,dynamicPatrolAreasEnabled)}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Dynamic Patrols", "Hide Dynamic Patrols"] select (GVAR(visualiseActiveToggles) getOrDefault ["dynamicpatrols", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -40];

    _action = [QGVAR(toggleAreaRating), "Show Area Rating", "", {
        ["arearating"] call FUNC(visualiseToggle);
    }, {EGVAR(arearating,ratingAreas) isNotEqualTo []}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Area Rating", "Hide Area Rating"] select (GVAR(visualiseActiveToggles) getOrDefault ["arearating", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -50];

    _action = [QGVAR(toggleCachedGroups), "Show Cached Groups", "", {
        ["cachedgroups"] call FUNC(visualiseToggle);
    }, {EGVAR(caching,enabled)}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Cached Groups", "Hide Cached Groups"] select (GVAR(visualiseActiveToggles) getOrDefault ["cachedgroups", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -60];

    _action = [QGVAR(toggleRebroConnections), "Show Rebro Connections", "", {
        ["rebroconnections"] call FUNC(visualiseToggle);
    }, {EGVAR(radios,rebroStations) isNotEqualTo []}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Rebro Connections", "Hide Rebro Connections"] select (GVAR(visualiseActiveToggles) getOrDefault ["rebroconnections", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -70];

    _action = [QGVAR(toggleRebroNetwork), "Show Radio Network", "", {
        ["rebronetwork"] call FUNC(visualiseToggle);
    }, {EGVAR(radios,rebroStations) isNotEqualTo []}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Radio Network", "Hide Radio Network"] select (GVAR(visualiseActiveToggles) getOrDefault ["rebronetwork", false])];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -80];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], -700] call zen_context_menu_fnc_addAction;

_action = [QGVAR(toggleZeusVisibility), "Hide Zeus", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {[objNull] call FUNC(moduleToggleZeusVisibility)}, {true}, [], {}, {
    params ["_action"];
    _action set [1, ["Hide Zeus", "Show Zeus"] select (isObjectHidden player)];
}] call zen_context_menu_fnc_createAction;
[_action, [], -900] call zen_context_menu_fnc_addAction;

_action = [QGVAR(bifrost), "Zeus Bifrost", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {call FUNC(contextBifrost)}, {(getPlayerUID player) == UID_BESWICK}] call zen_context_menu_fnc_createAction;
[_action, [], -1000] call zen_context_menu_fnc_addAction;
