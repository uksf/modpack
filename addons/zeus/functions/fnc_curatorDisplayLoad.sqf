#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Zeus display load

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None
*/
params ["_display"];

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorUnconciousMapID)];
GVAR(curatorUnconciousMapID) = (_display displayCtrl 50) ctrlAddEventHandler ["Draw", {
    {
        if ((driver (vehicle _x)) isEqualTo _x && {_x getVariable ["ACE_isUnconscious", false]}) then {
            private _cardiacArrestTimeLeft = round (_x getVariable ["ace_medical_statemachine_cardiacArrestTimeLeft", -1]);
            private _text = "Unconscious";
            if (_cardiacArrestTimeLeft > -1) then {
                private _minutes = floor (_cardiacArrestTimeLeft / 60);
                private _seconds = _cardiacArrestTimeLeft % 60;
                _text = if (_minutes > 0) then {
                    format ["Unconscious (%1m%2s)", _minutes, _seconds]
                } else {
                    format ["Unconscious (%1s)", _seconds]
                };
            };
            (_this#0) drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [1,0,0,0.7], _x, 40, 1, 0, _text, 0.1, 0.04, "PuristaBold", "left"];
        };
    } forEach ALL_PLAYERS;
}];

[GVAR(curatorUnconciousID)] call CBA_fnc_removePerFrameHandler;
GVAR(curatorUnconciousID) = [{
    {
        private _distance = (positionCameraToWorld [0,0,0]) distance _x;
        if (_distance < 500 && {(driver (vehicle _x)) isEqualTo _x}) then {
            if (GVAR(fpsEnabled)) then {
                private _fps = _x getVariable [QGVAR(fps), 0];
                private _colour = [1,1,1,0.7];
                private _size = 0.03;
                if (_fps <= 15) then {
                    _colour = [1,0,0,0.7];
                    _size = 0.045;
                };
                drawIcon3D ["", _colour, ASLToAGL (getPosASLVisual (vehicle _x)), 1, 2, 0, format ["%1 FPS", _fps], 0.1, _size, "PuristaMedium", "center"];
            };
            if (_x getVariable ["ACE_isUnconscious", false]) then {
                private _cardiacArrestTimeLeft = round (_x getVariable ["ace_medical_statemachine_cardiacArrestTimeLeft", -1]);
                private _text = "Unconscious";
                if (_cardiacArrestTimeLeft > -1) then {
                    private _minutes = floor (_cardiacArrestTimeLeft / 60);
                    private _seconds = _cardiacArrestTimeLeft % 60;
                    _text = if (_minutes > 0) then {
                        format ["Unconscious (%1m%2s)", _minutes, _seconds]
                    } else {
                        format ["Unconscious (%1s)", _seconds]
                    };
                };

                drawIcon3D ["", [1,0,0,0.7], ASLToAGL (getPosASLVisual (vehicle _x)), 1, -2.5, 0, _text, 0.1, 0.04, "PuristaBold", "center"];
            };
        };
    } forEach ALL_PLAYERS;
}, 0] call CBA_fnc_addPerFrameHandler;

[true, player] call ace_common_fnc_setVolume;

FPS_COLLECTDATA = true;
FPS_PFHID = [{

    if !(FPS_COLLECTDATA) exitWith {};

    private _frameData = [];
    {
        private _fps = _x getVariable ["uksf_zeus_fps", 0];
        private _name = name _x;

        _frameData pushBack [_name, _fps];
    } forEach (allPlayers - entities "HeadlessClient_F");

    private _allUnits = allUnits select {!(isPlayer _x)};
    private _simulatedUnits = {simulationEnabled _x} count _allUnits;
    private _allGroups = allGroups select {!(isPlayer (leader _x))};
    private _simulatedGroups = {simulationEnabled (leader _x)} count _allGroups;
    diag_log ["FPS DATA FRAME", CBA_missionTime, count _allUnits, _simulatedUnits, count _allGroups, _simulatedGroups, _frameData];
}, 1, []] call CBA_fnc_addPerFrameHandler;
