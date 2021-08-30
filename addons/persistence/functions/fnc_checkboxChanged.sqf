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
private _state = cbChecked _ctrlCheckbox;

private _id = ([[_object, false, true], [_object, true]] select _state) call FUNC(edenAttributeChanged);
if (isNil "_id") then {
    _id = "";
};

private _ctrlEditbox = ((allcontrols (ctrlParent _ctrlCheckbox) - [ctrlParentControlsGroup _ctrlCheckbox]) select {ctrlClassName _x == QGVAR(Edit)})#0;
if (!isNil "_ctrlEditbox" && {!isNull _ctrlEditbox}) then {
    private _ctrlEditboxValue = _ctrlEditbox controlsGroupCtrl 100;
    _ctrlEditbox ctrlEnable _state;
    _ctrlEditbox ctrlShow _state;
    _ctrlEditboxValue ctrlSetText (["", _id] select _state);
};
