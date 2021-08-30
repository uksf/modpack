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

[{
    params ["_planter"];

    // plant IED 1m to front of planter
    private _planterDir = getDir _planter;
    private _iedPos = _planter getPos [1.1, _planterDir];
    ([objNull, _iedPos, random 360, "IEDUrbanSmall_Remote_Mag", "PressurePlate", []] call ACE_Explosives_fnc_placeExplosive) params ["_explosive"];
    _explosive setVectorUp surfaceNormal position _explosive;
    [QGVAR(revealMineToAllExceptBlufor), [_explosive]] call CBA_fnc_globalEvent;
    _planter call BIS_fnc_ambientAnim__terminate;
}, [_planter], 20] call CBA_fnc_waitAndExecute;
