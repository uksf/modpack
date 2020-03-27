#include "\a3\functions_f_jets\functions\aircraftcarrier\defines.inc"
#include "script_component.hpp"
/*
    Author: Jiri Wainar, edited by Tim Beswick

    Description:
    Creates a hold action for launching player's aircraft from the carrier.
    Edit:
        Add exclude check via config setting

    Parameter(s):
        0: trigger that is adding the action

    Returns:
    Handle to the hold action.

    Example:
    [_trigger,_target] call bis_fnc_carrier01CatapultActionAdd;
*/
//debug
/*
if (player getVariable ["addDebug",true]) then
{
    player setVariable ["addDebug",false];

    [] spawn
    {
        while {true} do
        {
            sleep 0.1;

            hintSilent parseText format["<t font='EtelkaMonospacePro'><t align='left'>Catapult ID:</t><t align='right'>%1</t><br/><t align='left'>Catapult ID (last):</t><t align='right'>%2</t><br/><t align='left'>Catapult State:</t><t align='right'>%3</t></t>",GET_CATAPULT_ID,GET_CATAPULT_LAST_ID,GET_CATAPULT_STATE];
        };
    };
};
*/

private _trigger = param [0, objNull];
private _target = param [1, objNull,[[],objNull]];

if (_target isEqualType []) then
{
    _target = (_target select {_x isKindOf "Plane" && {_x isEqualTo cameraOn}}) param [0, objNull];

    //["[ ] Launch action added to object %1 (%2)",_target,typeOf _target] call bis_fnc_logFormat;
};

if (isNull _target) exitWith {["[x] Adding of launch action failed, valid airplane cannot be detected."] call bis_fnc_error;};

//terminate if catapult launch action is already present on cameraOn or player's vehicle
if ({GET_ACTION_ID(_x) > -1} count [vehicle player,cameraOn] > 0) exitWith {};

// Exclude aircraft if explicitly excluded in config
if (getNumber (EGVAR(common,configVehicles) >> typeOf _target >> "CatapultExclude") == 1) exitWith {};

//["[ ] Catapult action successfully added to airplane %1 (%2).",_target,typeOf _target] call bis_fnc_logFormat;

//store carrier deck trigger on player
SET_TRIGGER(_trigger);

//store airplane with action on trigger
SET_AIRPLANE(_trigger,_target);

private _onStart =
{
    private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {SET_CATAPULT_STATE(LAUNCH_CANCELLED)};

    SET_CATAPULT_STATE(LAUNCH_STARTED);

    _catapultData params
    [
        ["_part", objNull],
        ["_memPoint", ""],
        ["_dirOffset", 0],
        ["_animations", 0],
        ["_actionName", ""]
    ];

    ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_UP);

    //animate plane to catapult and lock it to it
    _catapultData spawn bis_fnc_carrier01CatapultLockTo;

    //execute custom code from mision config
    private _codeStart = getText(missionConfigFile >> "CfgCarrier" >> "LaunchSettings" >> "codeStart");

    if (_codeStart != "") then
    {
        call compile _codeStart;
    };
};

private _onProgress =
{
    private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {SET_CATAPULT_STATE(LAUNCH_CANCELLED)};
    private _currentProgress = param [4,-1,[123]];

    SET_CATAPULT_STATE(_currentProgress);

    _catapultData params
    [
        ["_part", objNull],
        ["_memPoint", ""],
        ["_dirOffset", 0],
        ["_animations", 0],
        ["_actionName", ""]
    ];

    private _plane = cameraOn;

    //["[ ] %1 | %2 | %3",IS_ATTACHED_TO_CATAPULT,_currentProgress,(_currentProgress - 11)/12 max 0.2 min 1] call bis_fnc_logFormat;

    //control throttle
    if (IS_ATTACHED_TO_CATAPULT || {!(isNull attachedTo _plane)}) then
    {
        if (_currentProgress > 11) then
        {
                private _throttleCurrent = _plane animationSourcePhase "throttle";
                private _throttle = (_currentProgress - 11)/12 max _throttleCurrent min 1;

                _plane setAirplaneThrottle _throttle;
        };
    }
    else
    {
        _plane setAirplaneThrottle 0.2;
    };
};

private _onCompleted =
{
    private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {};

    SET_CATAPULT_STATE(LAUNCH_COMPLETED);

    _catapultData params
    [
        ["_part", objNull],
        ["_memPoint", ""],
        ["_dirOffset", 0],
        ["_animations", 0],
        ["_actionName", ""]
    ];

    private _plane = cameraOn;

    //set throttle to max
    _plane setAirplaneThrottle 1;

    ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_DOWN);

    private _dirCatapult = (getDir _part - _dirOffset - 180) % 360;

    [_plane,_dirCatapult] call BIS_fnc_AircraftCatapultLaunch;

    //execute custom code from mision config
    private _codeEnd = getText(missionConfigFile >> "CfgCarrier" >> "LaunchSettings" >> "codeEnd");

    if (_codeEnd != "") then
    {
        call compile _codeEnd;
    };

    ATTACHED_TO_CATAPULT(false);
};

private _onInterrupted =
{
    private _catapultData = GET_CATAPULTS_DATA(GET_TRIGGER) param [GET_CATAPULT_LAST_ID,[]]; if (count _catapultData == 0) exitWith {};

    SET_CATAPULT_STATE(LAUNCH_CANCELLED);

    _catapultData params
    [
        ["_part", objNull],
        ["_memPoint", ""],
        ["_dirOffset", 0],
        ["_animations", 0],
        ["_actionName", ""]
    ];

    //set throttle to 0
    cameraOn setAirplaneThrottle 0;

    ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_DOWN);
    ATTACHED_TO_CATAPULT(false);
};

private _cfgSettings = missionConfigFile >> "CfgCarrier" >> "LaunchSettings";
private _duration = getNumber(_cfgSettings >> "duration") max 6;
private _distance = getNumber(_cfgSettings >> "distance"); if (_distance == 0) then {_distance = 15} else {_distance = _distance max 0.1 min 15};
private _condShow = getText(_cfgSettings >> "condShow"); if (_condShow == "") then {_condShow = "true"};
private _condProgress = getText(_cfgSettings >> "condProgres"); if (_condProgress == "") then {_condProgress = "true"};

//add the launch action
private _actionID =
[
/* 0 object */                            _target,
/* 1 action title */                    if (isLocalized "STR_A3_action_useCatapult") then {localize "STR_A3_action_useCatapult"} else {"Initiate Launch Sequence"},
/* 2 idle icon */                        "\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_takeOff1_ca.paa",
/* 3 progress icon */                    "\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_takeOff2_ca.paa",
/* 4 condition to show */                format["([{%1},%2] call bis_fnc_carrier01CatapultID) != -1",_condShow,_distance],
/* 5 condition to progress */            format["([{%1},%2] call bis_fnc_carrier01CatapultID) != -1",_condProgress,_distance],
/* 6 code executed on start */            _onStart,
/* 7 code executed per tick */            _onProgress,
/* 8 code executed on completion */        _onCompleted,
/* 9 code executed on interruption */    _onInterrupted,
/* 10 arguments */                        [],
/* 11 action duration */                _duration,
/* 12 priority */                        1000,
/* 13 remove on completion */            true,
/* 14 show unconscious */                false
]
call BIS_fnc_holdActionAdd;

SET_ACTION_ID(_target,_actionID);
