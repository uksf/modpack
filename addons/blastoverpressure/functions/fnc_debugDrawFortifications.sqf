#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Debug visualisation for fortification destruction results.
        Draws summary text near detonation point showing counts.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Effective range <NUMBER>
        2: Destroyed count <NUMBER>
        3: Damaged count <NUMBER>
        4: Protected count <NUMBER>

    Return Value:
        None
*/
params ["_positionASL", "_effectiveRange", "_destroyedCount", "_damagedCount", "_protectedCount"];

private _startTime = CBA_missionTime;
private _duration = 5;
private _positionATL = ASLToATL _positionASL;

[{
    params ["_args", "_perFrameHandlerID"];
    _args params ["_startTime", "_duration", "_positionATL", "_destroyedCount", "_damagedCount", "_protectedCount"];

    if (CBA_missionTime > _startTime + _duration) exitWith {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
    };

    private _textPosition = _positionATL vectorAdd [0, 0, 3];
    private _text = format ["Fortifications: %1 destroyed | %2 damaged | %3 protected", _destroyedCount, _damagedCount, _protectedCount];
    drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Actions\clear_empty_ca.paa", [1, 0.5, 0, 1], _textPosition, 0.5, 0.5, 0, _text, 2, 0.03, "RobotoCondensed"];

}, 0, [
    _startTime, _duration, _positionATL, _destroyedCount, _damagedCount, _protectedCount
]] call CBA_fnc_addPerFrameHandler;
