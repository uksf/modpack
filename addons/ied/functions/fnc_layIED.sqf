#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        animates the planter and lays the IED.

    Parameters:
        0: planter <OBJECT>

    Return value:
        Nothing
*/
params ["_planter"];

if (!local _planter) exitWith {};

// _planter playMoveNow 'AinvPpneMstpSnonWnonDnon_Putdown_AmovPpneMstpSnonWnonDnon';
[_planter, "KNEEL_TREAT2", "ASIS"] call BIS_fnc_ambientAnim;
_planter removeItem 'IEDUrbanSmall_Remote_Mag';
private _planterDir = getDir _planter;
private _iedPos = _planter getPos [1.1, _planterDir];
[{
    params ["_planter", "_iedPos"];
    // plant IED 1m to front of planter
    ([objNull, _iedPos, random 360, "IEDUrbanSmall_Remote_Mag", "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
    _explosive setVectorUp surfaceNormal position _explosive;
    EAST revealMine _explosive;
    CIVILIAN revealMine _explosive;
    INDEPENDENT revealMine _explosive;
    _planter call BIS_fnc_ambientAnim__terminate;
}, [_planter, _iedPos], 20] call cba_fnc_waitAndExecute;


