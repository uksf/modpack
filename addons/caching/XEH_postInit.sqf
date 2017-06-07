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
    [{call FUNC(checkGroupsServer)}, 5, []] call cba_fnc_addPerFrameHandler;
};

if (hasInterface) then {
    [{call FUNC(checkGroupsClient)}, 1, []] call cba_fnc_addPerFrameHandler;
};

//Debug shizzle
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
            private _pos = worldToScreen (getPos _x);
            private _onScreen = ((count _pos) > 0) && {(abs (_pos select 0)) < 1.5} && {(abs (_pos select 1)) < 1.5};
            if (_onScreen) then {
                _colour = [1,1,0,1];
                private _distance = (getObjectViewDistance select 0) min (1000 + ((200 + (4 * 200 * ((currentVisionMode _player) - 1))) * ((call CBA_fnc_getFov) select 1)));
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
            drawIcon3D ["\a3\ui_f_curator\data\logos\arma3_curator_eye_32_ca.paa", _colour, getPos _x, 0.5, 0.5, 0, _text, 0, 0.01, "TahomaB", "center", true];
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
            private _onScreen = ((count _pos) > 0) && {(abs (_pos select 0)) < 1.5} && {(abs (_pos select 1)) < 1.5};
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
*/
