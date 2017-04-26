/*
    Author:
        Kex, edited by Tim Beswick

    Description:
        Integrates Ares Modules in Curator Interface Tree

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

disableSerialization;
private _display = findDisplay IDD_RSCDISPLAYCURATOR;
private _ctrl = _display displayCtrl IDC_RSCDISPLAYCURATOR_CREATE_MODULES;

_ctrl tvSort [[], false];
for "_i" from 0 to ((_ctrl tvCount []) - 1) do {
    _ctrl tvSort [[_i], false];
};

{
    private _treeCtrl = _display displayCtrl _x;
    for "_i" from 0 to ((_treeCtrl tvCount []) - 1) do {
        _treeCtrl tvCollapse [_i];
    };
    false
} count [
    IDC_RSCDISPLAYCURATOR_CREATE_UNITS_WEST,
    IDC_RSCDISPLAYCURATOR_CREATE_UNITS_EAST,
    IDC_RSCDISPLAYCURATOR_CREATE_UNITS_GUER,
    IDC_RSCDISPLAYCURATOR_CREATE_UNITS_CIV,
    IDC_RSCDISPLAYCURATOR_CREATE_UNITS_EMPTY
];

{
    private _treeCtrl = _display displayCtrl _x;
    for "_i" from 0 to ((_treeCtrl tvCount [0]) - 1) do {
        _treeCtrl tvCollapse [0, _i];
    };
    false
} count [
    IDC_RSCDISPLAYCURATOR_CREATE_GROUPS_WEST,
    IDC_RSCDISPLAYCURATOR_CREATE_GROUPS_EAST,
    IDC_RSCDISPLAYCURATOR_CREATE_GROUPS_GUER,
    IDC_RSCDISPLAYCURATOR_CREATE_GROUPS_CIV,
    IDC_RSCDISPLAYCURATOR_CREATE_GROUPS_EMPTY
];
