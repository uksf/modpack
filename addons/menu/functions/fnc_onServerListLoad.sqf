#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On load of server select

    Parameter(s):
        0: Control <CONTROL>

    Return Value:
        Nothing
*/
params ["_control"];

private _servers = [
    ["Primary","2302"],
    ["Secondary","2322"],
    ["Tertiary","2332"],
    ["Quaternary","2342"]
];

if (CONFIGURATION_IS_RC) then {
    _servers insert [0, [
        ["Rc","2392"]
    ]];
};
if (CONFIGURATION_IS_DEVELOPMENT) then {
    _servers insert [0, [
        ["Dev","2382"]
    ]];
};
TRACE_2("servers",CONFIGURATION,_servers);

lbClear _control;
{
    _x params ["_name", "_port"];

    private _index = _control lbAdd _name;
    _control lbSetData [_index, _port];
} forEach _servers;

_control lbSetCurSel 0;
