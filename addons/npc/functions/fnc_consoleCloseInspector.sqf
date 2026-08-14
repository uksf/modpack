#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Closes the local NPC inspector display.
*/
private _display = uiNamespace getVariable [QGVAR(consoleInspector), displayNull];
if (!isNull _display) then {_display closeDisplay 2};
