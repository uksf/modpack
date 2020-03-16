#include "script_component.hpp"
#include "\A3\ui_f\hpp\defineDIKCodes.inc"
/*
    Author:
        Tim Beswick

    Description:
        Starts selection of units to drop in to then given location

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

deleteVehicle _logic;

["Select units and press 'Return'. Press 'Escape' to cancel"] call ace_zeus_fnc_showMessage;
GVAR(paradropAltitude) = 2000;

private _display = findDisplay IDD_RSCDISPLAYCURATOR;
GVAR(curatorSelectionHandle) = _display displayAddEventHandler ["KeyDown", {
    params ["_display", "_key"];

    switch (true) do {
        case (_key == DIK_ESCAPE): {
            _display displayRemoveEventHandler ["KeyDown", GVAR(curatorSelectionHandle)];
            true
        };
        case (_key == DIK_NUMPADENTER);
        case (_key == DIK_RETURN): {
            _display displayRemoveEventHandler ["KeyDown", GVAR(curatorSelectionHandle)];

            GVAR(paradropUnits) = curatorSelected#0;
            GVAR(paradropMapPoints) = [];

            ["Open the map and left click on a start and end position. Press 'Escape' to cancel"] call ace_zeus_fnc_showMessage;
            GVAR(curatorCancelHandle) = _display displayAddEventHandler ["KeyDown", {
                params ["_display", "_key"];

                if (_key == DIK_ESCAPE) then {
                    _display displayRemoveEventHandler ["MouseButtonDown", GVAR(curatorMapPointHandle)];
                    _display displayRemoveEventHandler ["KeyDown", GVAR(curatorCancelHandle)];
                    if (!isNil QGVAR(curatorMapDrawEH)) then {
                        (_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorMapDrawEH)];
                    };
                    true
                };
            }];

            GVAR(curatorMapPointHandle) = [findDisplay 312, "MouseButtonDown", {
                params ["_display", "_mouseButton"];

                if (_mouseButton != 0) exitWith {};
                if (ctrlShown (_display displayCtrl 50)) then {
                    private _position = ((_display displayCtrl 50) ctrlMapScreenToWorld getMousePosition);
                    _position set [2, 0];
                    GVAR(paradropMapPoints) pushBack _position;

                    if ((count GVAR(paradropMapPoints)) == 1) then {
                        GVAR(curatorMapDrawEH) = [_display displayCtrl 50, "Draw", {
                            params ["_control"];

                            private _mousePosition = _control ctrlMapScreenToWorld getMousePosition;
                            _control drawIcon ["\a3\ui_f\data\IGUI\Cfg\Cursors\select_target_ca.paa", [1,0,0,1], _mousePosition, 24, 24, 0, "", 1, 0.03, "TahomaB", "right"];
                            _control drawLine [GVAR(paradropMapPoints)#0, _mousePosition, [1,0,0,1]];
                        }, [_object, _text, _icon]] call CBA_fnc_addBISEventHandler;
                    };
                };
                if ((count GVAR(paradropMapPoints)) >= 2) exitWith {
                    _display displayRemoveEventHandler ["MouseButtonDown", GVAR(curatorMapPointHandle)];
                    _display displayRemoveEventHandler ["KeyDown", GVAR(curatorCancelHandle)];
                    (_display displayCtrl 50) ctrlRemoveEventHandler ["Draw", GVAR(curatorMapDrawEH)];
                    showMap false;
                    ["Paradrop Altitude", [
                        ["SLIDER", ["Altitude (ft)", "Sets the altitude for the paradrop in feet (1m = ~3.3ft)"], [300, 20000, 6000, 0]]
                    ], {
                        params ["_dialogValues"];
                        _dialogValues params ["_altitude"];

                        [QGVAR(paradrop), [GVAR(paradropUnits), GVAR(paradropMapPoints)#0, GVAR(paradropMapPoints)#1, _altitude]] call CBA_fnc_serverEvent;
                    }, {}] call zen_dialog_fnc_create;
                };
            }] call CBA_fnc_addBISEventHandler;

            true
        };
    };
}];
