#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ButtonDown event handler to store selected respawn point on respawn

    Parameter(s):
        0 Control Group <CONTROL>

    Return Value:
        None
*/
#define IDC_RSCRESPAWNCONTROLS_HEADERRESPAWNBUTTON 88829

disableSerialization;

[{
    params ["_controlGroup"];


    private _parentDisplay = ctrlParent _controlGroup;
    if (_parentDisplay != findDisplay 12) exitWith {};

    private _controlRespawnButton = _controlGroup controlsGroupCtrl IDC_RSCRESPAWNCONTROLS_HEADERRESPAWNBUTTON;
    _controlRespawnButton ctrlAddEventhandler ["ButtonDown", {
        private _respawnSelection = lbCurSel (uiNamespace getVariable "BIS_RscRespawnControlsMap_ctrlLocList");
        private _respawnData = ["get", _respawnSelection] call BIS_fnc_showRespawnMenuPositionMetadata;
        TRACE_2("Respawn button pressed",_respawnSelection,_respawnData);

        GVAR(selectedRespawn) = _respawnData#0#0;
    }];
}, _this] call CBA_fnc_execNextFrame;
