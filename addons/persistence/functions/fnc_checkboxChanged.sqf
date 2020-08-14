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

private _object = (get3DENSelected "object")#0;
private _state = [false, true] select (cbChecked _ctrlCheckbox);
private _ctrlEditbox = ((allcontrols (ctrlParent _ctrlCheckbox) - [ctrlParentControlsGroup _ctrlCheckbox]) select {ctrlClassName _x == QGVAR(Edit)})#0;

private _id = ([[_object, false, true], [_object, true]] select _state) call FUNC(edenAttributeChanged);

if !(isNull _ctrlEditbox) then {
    private _ctrlEditboxValue = _ctrlEditbox controlsGroupCtrl 100;
    _ctrlEditbox ctrlEnable _state;
    _ctrlEditbox ctrlShow _state;
    _ctrlEditboxValue ctrlSetText (["", _id] select _state);
};
