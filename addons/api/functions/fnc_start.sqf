#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the API bridge extension. Only runs on dedicated servers and headless clients.

    Parameters:
        None

    Return Value:
        None
*/

if (hasInterface) exitWith {};

private _result = "uksf" callExtension "start";
INFO_1("Extension start: %1",_result);

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name != "uksf") exitWith {};
    [_function, _data] call FUNC(handleCommand);
}];

addMissionEventHandler ["MPEnded", {
    call FUNC(stop);
}];
