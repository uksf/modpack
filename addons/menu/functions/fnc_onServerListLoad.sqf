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

lbClear _control;
{
    _x params ["_name", "_port"];
    private _index = _control lbAdd _name;
    _control lbSetData [_index, _port];
} forEach [["Primary","2302"],["Secondary","2322"],["Tertiary","2332"]];

_control lbSetCurSel 0;
