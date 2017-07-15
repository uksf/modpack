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
#include "script_component.hpp"

params ["_curator", "_clickedObject", ["_handled", false]];

[format ["Double-clicked object %1", _clickedObject]] call Ares_fnc_LogMessage;

if (Ares_Ctrl_Key_Pressed or Ares_Shift_Key_Pressed) then {
    ["CTRL and/or Shift Key was pressed for double-click!"] call Ares_fnc_LogMessage;
    _handled = true;
    
    // Hack - trick the BIS function into thinking the mouse is over the double-clicked unit
    missionnamespace setVariable ["bis_fnc_curatorObjectPlaced_mouseOver",["OBJECT", _clickedObject]];
    
    if (Ares_Ctrl_Key_Pressed) then  {
        _logic = [getPos _clickedObject, "LOGIC"] call Ares_fnc_CreateLogic;
        [_logic, [], true] call BIS_fnc_moduleRemoteControl
    };

    closeDialog 1;
} else {
    if (_clickedObject isKindOf "Land_ClutterCutter_small_F") then {
        switch (true) do {
            case (not isNil {_clickedObject getVariable "source"}): {
                [_clickedObject] spawn Achilles_fnc_lightSourceAttributes;
            };
        };
    };
};

_handled;
