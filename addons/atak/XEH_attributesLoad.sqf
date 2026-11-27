#include "script_component.hpp"
#define IDC_BAR 86100
#define IDC_ATAK 86102
#define IDC_OVERWATCH 86103

params ["_display"];

private _overwatch = _display displayCtrl IDC_OVERWATCH;
if (isNull _overwatch) exitWith {};
ctrlDelete _overwatch;

private _bar = _display displayCtrl IDC_BAR;
private _atak = _display displayCtrl IDC_ATAK;
if (isNull _bar || {isNull _atak}) exitWith {};
private _barPos = ctrlPosition _bar;
private _atakPos = ctrlPosition _atak;
_barPos set [2, (_atakPos select 0) + (_atakPos select 2) + 0.002 - (_barPos select 0)];
_bar ctrlSetPosition _barPos;
_bar ctrlCommit 0;
