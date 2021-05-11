#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets selected respawn point on respawn button click

    Parameter(s):
        0 COntrol Group <CONTROL>

    Return Value:
        None
*/

disableSerialization;

with uiNamespace do {
    params ["_controlGroup"];

    private _parentDisplay = ctrlParent _controlGroup;

    if (_parentDisplay != findDisplay 12) exitWith {};

    (uiNamespace getVariable ["BIS_RscRespawnControlsMap_ctrlHeaderRespawnButton", controlNull]) ctrlAddEventhandler ["ButtonDown", {
        private _respawnSelection = lbCurSel (uiNamespace getVariable "BIS_RscRespawnControlsMap_ctrlLocList");
        private _respawnData = ["get", _respawnSelection] call BIS_fnc_showRespawnMenuPositionMetadata;
        TRACE_2("Respawn button pressed",_respawnSelection,_respawnData);

        GVAR(selectedRespawn) = _respawnData#0#0;
    }];
};
