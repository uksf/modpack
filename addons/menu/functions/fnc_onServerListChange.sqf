#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        On change of server select

    Parameter(s):
        0: Control <CONTROL>
        1: Index <SCALAR>

    Return Value:
        Nothing
*/
params ["_control", "_index"];

private _port = _control lbData _index;
uiNamespace setVariable [QGVAR(selectedPort), _port];
