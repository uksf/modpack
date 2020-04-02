#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets object persistence ID when changing checkbox state

    Parameter(s):
        0: Object <OBJECT>

    Return Value:
        Nothing
*/
params ["_ctrlCheckbox"];

// Load
// _this spawn {};

private _object = (get3DENSelected "object")#0;
private _state = [false, true] select (cbChecked _ctrlCheckbox);
private _ctrlEditbox = ((allcontrols (ctrlParent _ctrlCheckbox) - [ctrlParentControlsGroup _ctrlCheckbox]) select {ctrlClassName _x == QGVAR(Edit)})#0;
private _ctrlEditboxValue = _ctrlEditbox controlsGroupCtrl 100;
_ctrlEditbox ctrlEnable _state;
_ctrlEditbox ctrlShow _state;

if (_state) then {
    // Persistence enabled
    private _id = [_object, true] call FUNC(edenAttributeChanged);
    _ctrlEditboxValue ctrlSetText _id;
} else {
    [_object, false, true] call FUNC(edenAttributeChanged);
    _ctrlEditboxValue ctrlSetText "";
};



