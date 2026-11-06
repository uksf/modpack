#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calls code with the world position of a single left click on the map of an open map app.
        A double click opens cTab's marker menu, so a click runs its code only when no second click follows it.
        The launcher removes the handlers when the app closes.

    Parameter(s):
        0: Map control passed to the app's open code <CONTROL>
        1: Code, called with [world position, map control] <CODE>

    Return Value:
        Nothing

    Example:
        [_map, {params ["_position"]}] call uksf_ctab_fnc_addMapClickHandler
*/
params ["_map", "_code"];

_map setVariable [QGVAR(clickCode), _code];
_map setVariable [QGVAR(pendingClick), -1];

[_map, "MouseButtonClick", {
    params ["_map", "_button", "_screenX", "_screenY"];
    if (_button != 0) exitWith {};

    private _click = diag_frameNo;
    _map setVariable [QGVAR(pendingClick), _click];
    [{
        params ["_map", "_click", "_position"];
        if (isNull _map || {_map getVariable [QGVAR(pendingClick), -1] != _click}) exitWith {};

        _map setVariable [QGVAR(pendingClick), -1];
        [_position, _map] call (_map getVariable QGVAR(clickCode));
    }, [_map, _click, _map ctrlMapScreenToWorld [_screenX, _screenY]], DOUBLE_CLICK_TIME] call CBA_fnc_waitAndExecute;
}] call FUNC(addMapHandler);

[_map, "MouseButtonDblClick", {
    params ["_map"];
    _map setVariable [QGVAR(pendingClick), -1];
}] call FUNC(addMapHandler);
