#include "script_component.hpp"
/*
    Author:
        Kex, edited by Tim Beswick

    Description:
        Called when display curator is loaded

    Parameter(s):
        0: Curator display <DISPLAY>

    Return Value:
        Boolean
*/

private _handled = false;

curatorMouseOver params ["_typeName", "_clickedObject"];
if (_typeName isEqualType objNull) then {
    private _ctrlKeyPressed = param [5];

    switch (true) do {
        case (_ctrlKeyPressed): {
            missionnamespace setVariable ["bis_fnc_curatorObjectPlaced_mouseOver",[_typeName, _clickedObject]];
            private _logic = [getPos _clickedObject, "LOGIC"] call Ares_fnc_CreateLogic;
            [_logic, [], true] call Achilles_fnc_moduleRemoteControl;
            _handled = true;
        };
        case (_clickedObject isKindOf "Land_ClutterCutter_small_F"): {
            switch (true) do {
                case (not isNil {_clickedObject getVariable "source"}): {
                    [_clickedObject] spawn Achilles_fnc_lightSourceAttributes;
                    _handled = true;
                };
            };
        };
    };
};

_handled
