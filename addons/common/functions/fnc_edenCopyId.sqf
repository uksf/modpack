#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Copies ID to clipboard

    Parameter(s):
        0: Button control <CONTROL>

    Return Value:
        Nothing
*/
params ["_ctrlButton"];

private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
private _ctrlEdit = _ctrlGroup controlsgroupctrl 100;
private _id = ctrlText _ctrlEdit;
copyToClipboard _id;

[format ["Copied id '%1' to clipboard", _id]] call BIS_fnc_3DENNotification;
