#include "script_component.hpp"

[{
    params ["_args"];
    _args params ["_waitingMsgSent"];

    if !(SLX_XEH_MACHINE select 8) exitWith {};
    if (isNil QGVAR(settings) || {!isServer && isNil QEGVAR(modules,serverModulesRead)}) exitWith {
        if !(_waitingMsgSent) then {
            _args set [0, true];
            INFO("Waiting on settings from server...");
        };
    };

    [_this select 1] call CBA_fnc_removePerFrameHandler;
    INFO("Settings received from server.");

    private _uniqueModulesHandled = [];
    {
        [_x] call {
            params ["_logic"];
            private _logicType = typeOf _logic;
            _logic hideObject true;

            if (_logic getVariable [QGVAR(initalized), false]) exitWith {};
            private _config = (configFile >> "CfgVehicles" >> _logicType);
            if !(isClass _config) exitWith {};

            private _isGlobal = getNumber (_config >> "isGlobal") > 0;
            private _isDisposable = getNumber (_config >> "isDisposable") > 0;
            private _isPersistent = getNumber (_config >> "isPersistent") > 0 || getNumber (_config >> "isGlobal") > 1;
            private _isSingular  = getNumber (_config >> "isSingular") > 0;
            private _function = getText (_config >> "function");
            if (isNil _function) then {
                _function = compile _function;
            } else {
                _function = missionNamespace getVariable _function;
            };
            if (_isSingular && {_logicType in _uniqueModulesHandled}) then {
                WARNING_1("Module [%1] - More than 1 singular module placed", _logicType);
            };
            if (_isSingular) then {_uniqueModulesHandled pushBack _logicType;};
            if (_isGlobal || isServer) then {
                [_logic, (synchronizedObjects _logic), true] call _function;
            };
            if !(_isPersistent) then {
                _logic setVariable [QGVAR(initalized), true];
            };
            if (_isDisposable) then {
                deleteVehicle _logic;
            };
        };
    } forEach GVAR(moduleInitCollection);

    if (isServer) then {
        GVAR(serverModulesRead) = true;
        publicVariable QGVAR(serverModulesRead);
        publicVariable QGVAR(settings);
    };
    INFO("Settings initialized.");
}, 0, [false]] call CBA_fnc_addPerFrameHandler;

[{
    {deleteGroup _x; false} count allGroups;
}, 300, []] call cba_fnc_addPerFrameHandler;

if (isMultiplayer && !is3DENMultiplayer) then {
    GVAR(HCs) = (entities "HeadlessClient_F");
} else {
    GVAR(HCs) pushBack player;
};

if (hasInterface) then {
    call FUNC(fpsAction);
};

if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
