#include "script_component.hpp"

if (!GVAR(enabled)) exitWith {
    INFO("Caching is disabled.");
    enableDynamicSimulationSystem false;
};

INFO("Caching is enabled.");
enableDynamicSimulationSystem true;
"Group" setDynamicSimulationDistance GVAR(distance);
"Vehicle" setDynamicSimulationDistance GVAR(distance);
"EmptyVehicle" setDynamicSimulationDistance 250;
"Prop" setDynamicSimulationDistance 50;
"IsMoving" setDynamicSimulationDistanceCoef 1.5;

if (isServer) then {
    [{
        private _groups = allGroups;
        private _count = count _groups;
        private _perFrame = ceil (_count / (diag_fps * 5));
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];
            
            if (_index >= _count) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(checkGroupsServer);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, 5, []] call cba_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    [{
        private _groups = allGroups;
        private _count = count _groups;
        private _perFrame = ceil (_count / diag_fps);
        [{
            params ["_args", "_idPFH"];
            _args params ["_groups", "_count", "_perFrame", "_index"];
            
            if (_index >= _count) exitWith {
                [_idPFH] call CBA_fnc_removePerFrameHandler;
            };

            [_groups select [_index, _perFrame]] call FUNC(checkGroupsClient);

            _args set [3, _index + _perFrame];
        }, 0, [_groups, _count, _perFrame, 0]] call cba_fnc_addPerFrameHandler;
    }, 1, []] call cba_fnc_addPerFrameHandler;
};

// Debug shizzle
/*
onEachFrame {
    private _player = if (!(isNull (getConnectedUAV player))) then {
        (gunner (getConnectedUAV player))
    } else {
        (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player])
    };
    {
        if (!(isPlayer _x)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPosVisual _x);
            private _onScreen = (count _pos) > 0 && {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH};
            if (_onScreen) then {
                _colour = [1,1,0,1];
                private _distanceMultiplier = (200 + (4 * 200 * (((currentVisionMode _player) - 1) max 0)));
                if (!((vehicle _x) isKindOf "CAManBase")) then {
                    _distanceMultiplier = _distanceMultiplier * 2.5;
                };
                private _distance = (getObjectViewDistance select 0) min (1000 + (_distanceMultiplier * ((call CBA_fnc_getFov) select 1)));
                private _zoom = ((_x distance _player) < _distance);
                if (_zoom) then {
                    _colour = [0,0,1,1];
                    private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _x]) > 0;
                    if (_los) then {
                        _colour = [0,1,0,1];
                    };
                };
            };
            private _text = "CANNOT MOVE";
            if (simulationEnabled _x) then {
                _text = "CAN MOVE";
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _x, 0.5, 0.5, 0, _text, 0, 0.01, "TahomaB", "center", true];
        };
    } count allUnits;
};
onEachFrame {
    private _player = if (!(isNull (getConnectedUAV player))) then {
        (gunner (getConnectedUAV player))
    } else {
        (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player])
    };
    {
        private _unit = leader _x;
        if (!(isPlayer _unit)) then {
            private _colour = [1,0,0,1];
            private _pos = worldToScreen (getPos _unit);
            private _onScreen = (count _pos) > 0 && {_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH};
            if (_onScreen) then {
                _colour = [1,1,0,1];
                private _distance = (getObjectViewDistance select 0) min (1000 + ((200 + (4 * 200 * ((currentVisionMode _player) - 1) max 0)) * ((call CBA_fnc_getFov) select 1)));
                private _zoom = ((_unit distance _player) < _distance);
                if (_zoom) then {
                    _colour = [0,0,1,1];
                    private _los = ([_player, "VIEW", (vehicle _player)] checkVisibility [eyePos _player, eyePos _unit]) > 0;
                    if (_los) then {
                        _colour = [0,1,0,1];
                    };
                };
            };
            private _text = ((_unit getVariable ["uksf_caching_time", diag_tickTime]) - diag_tickTime) toFixed 0;
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _unit, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    {
        private _unit = leader _x;
        if (!(isPlayer _unit)) then {
            private _colour = [1,0,0,1];
            if (simulationEnabled _unit) then {
                _colour = [0,1,0,1];
            };
            private _text = ((_unit getVariable ["uksf_caching_time", diag_tickTime]) - diag_tickTime) toFixed 0;
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _unit, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
        };
    } count allGroups;
};
onEachFrame {
    {
        if (!(isPlayer _x)) then {
            private _colour = [1,0,0,1];
            if (simulationEnabled _x) then {
                _colour = [0,1,0,1];
            };
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPosVisual _x, 0.5, 0.5, 0, "", 0, 0.025, "TahomaB", "center", true];
        };
    } count allUnits;
};
                if ((abs (_pos select 0)) < (safeZoneW - abs safeZoneX) && (abs (_pos select 1)) < (safeZoneH - abs safeZoneY)) then {
                    _colour = [0,1,0,1];
                };
onEachFrame { 
    { 
        private _unit = leader _x; 
        if (!(isPlayer _unit)) then { 
            private _colour = [1,0,0,1];               
            private _pos = worldToScreen (getPosWorld _unit);
            if (!(_pos isEqualTo [])) then {
                private _text = format ["%1,%2", _pos select 0, _pos select 1];
                if (_pos#0 > uksf_common_bufferedSafeX && _pos#0 < uksf_common_bufferedSafeW && _pos#1 > uksf_common_bufferedSafeY && _pos#1 < uksf_common_bufferedSafeH) then {
                    _colour = [0,1,0,1];
                };
                drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _unit, 0.5, 0.5, 0, _text, 0, 0.025, "TahomaB", "center", true];
            }; 
        };
    } count allGroups;
    drawLine3D [screenToWorld [safeZoneX, safeZoneY], screenToWorld [safeZoneX + safeZoneW, safeZoneY], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX + safeZoneW, safeZoneY], screenToWorld [safeZoneX + safeZoneW, safeZoneY + safeZoneH], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX + safeZoneW, safeZoneY + safeZoneH], screenToWorld [safeZoneX, safeZoneY + safeZoneH], [0,0,1,1]];
    drawLine3D [screenToWorld [safeZoneX, safeZoneY + safeZoneH], screenToWorld [safeZoneX, safeZoneY], [0,0,1,1]];
};
*/


