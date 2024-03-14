#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Zeus display load

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None
*/
params ["_display"];

(_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorViewMapID)];
GVAR(curatorViewMapID) = (_display displayCtrl 50) ctrlAddEventHandler ["Draw", {
    params ["_map"];

    if (!GVAR(showVirtualised)) exitWith {};

    {
        _x params ["_id", "_position"];

        private _groupData = GVAR(groupDataMap) get _id;
        _groupData params ["_side", "_vehicleDetails", "_unitDetails"];

        private _text = format ["%1, V: %2, U: %3", _side, count _vehicleDetails, count _unitDetails];
        _map drawIcon ["\a3\ui_f\data\gui\cfg\Hints\icon_text\group_1_ca.paa", [1,0.4,0,1], _position, 40, 40, 0, _text, 0.1, 0.04, "PuristaBold", "right"];
    } forEach GVAR(groupPositionMap);
}];

[GVAR(curatorViewPFHID)] call CBA_fnc_removePerFrameHandler;
GVAR(curatorViewPFHID) = [{
    if (!GVAR(showVirtualised)) exitWith {};

    private _cameraPosition = positionCameraToWorld [0,0,0];
    {
        _x params ["_id", "_position"];

        private _distanceToDistance = _cameraPosition distance _position;
        if (_distanceToDistance < 3500) then {
            private _groupData = GVAR(groupDataMap) get _id;
            _groupData params ["_side", "_vehicleDetails", "_unitDetails"];

            drawIcon3D ["\a3\ui_f\data\gui\cfg\Hints\icon_text\group_1_ca.paa", [1,0.4,0,1], _position, 1, 1, 0, format ["%1", _side], 0.1, 0.03, "PuristaBold", "center"];
            drawIcon3D ["", [1,0.4,0,1], _position, 0, 0, 0, format ["%1 Vehicles", count _vehicleDetails], 0.1, 0.03, "PuristaBold", "center", false, 0, 0.035];
            drawIcon3D ["", [1,0.4,0,1], _position, 0, 0, 0, format ["%1 Units", count _unitDetails], 0.1, 0.03, "PuristaBold", "center", false, 0, 0.05];
        };
    } forEach GVAR(groupPositionMap);
}, 0] call CBA_fnc_addPerFrameHandler;
