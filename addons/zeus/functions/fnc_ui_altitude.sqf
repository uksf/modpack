#include "script_component.hpp"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"
/*
    Author:
        Tim Beswick

    Description:
        Initialises paradrop altitude zeus display

    Parameter(s):
        0: Control <CONTROL>

    Return Value:
        None
*/

params ["_control"];

private _display = ctrlParent _control;
private _ctrlButtonOK = _display displayCtrl 1;
_control ctrlRemoveAllEventHandlers "SetFocus";

private _fnc_onSliderMove = {
    params ["_slider"];

    private _display = ctrlParent _slider;
    (_display displayCtrl 83573) ctrlSetText (str round sliderPosition _slider);
};

private _slider = _display displayCtrl 83572;
private _edit = _display displayCtrl 83573;

_slider sliderSetRange [80, 10000];
_slider sliderSetSpeed [1, 1];
_slider sliderSetPosition 2000;
_edit ctrlSetText "2000";

_slider ctrlAddEventHandler ["SliderPosChanged", _fnc_onSliderMove];

private _fnc_onConfirm = {
    params [["_ctrlButtonOK", controlNull, [controlNull]]];

    private _display = ctrlParent _ctrlButtonOK;
    if (isNull _display) exitWith {};
    private _altitude = round sliderPosition (_display displayCtrl 83572);
    
    [QGVAR(paradrop), [GVAR(paradropUnits), GVAR(paradropMapPoints)#0, GVAR(paradropMapPoints)#1, _altitude]] call CBA_fnc_serverEvent;
};

private _fnc_onUnload = {
    GVAR(paradropUnits) = [];
    GVAR(paradropMapPoints) = [];
    (findDisplay IDD_RSCDISPLAYCURATOR) displayRemoveEventHandler ["MouseButtonDown", GVAR(curatorMapPointHandle)];
    (findDisplay IDD_RSCDISPLAYCURATOR) displayRemoveEventHandler ["KeyDown", GVAR(curatorCancelHandle)];
    ((findDisplay IDD_RSCDISPLAYCURATOR) displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorMapDrawEH)];
};

_display displayAddEventHandler ["Unload", _fnc_onUnload];
_ctrlButtonOK ctrlAddEventHandler ["ButtonClick", _fnc_onConfirm];
