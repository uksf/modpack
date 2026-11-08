#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Bins spent L118 casings at an ammo crate.
        Cleanup deletes unattended casings within 15 m of the crate. That covers the
        gun, the crew space beside it, and a casing kicked a short way from the breech,
        and leaves anything further out to be carried in. Bin deletes the casing the
        player is carrying, after ACE carry has released it.
        Modes: canCleanup, cleanup, canBin, bin.

    Parameter(s):
        0: Crate <OBJECT>
        1: Player <OBJECT>
        2: Mode <STRING>

    Return Value:
        Whether the action applies, for the can* modes <BOOL>

    Example:
        [_crate, player, "cleanup"] call uksf_weapons_fnc_l118BinCasings
*/
params ["_crate", "_player", "_mode"];

private _casingClass = "tbd_mortars_105mm_casing_spent";
private _radius = 15;
private _carried = _player getVariable ["ace_dragging_carriedObject", objNull];
private _carryingCasing = !isNull _carried && {typeOf _carried isEqualTo _casingClass};

if (_mode in ["canBin", "bin"]) exitWith {
    if (_mode isEqualTo "bin" && {_carryingCasing}) then {
        [_player, _carried] call ace_dragging_fnc_dropObject_carry;
        [{
            params ["_casing"];
            if (isNull _casing) exitWith {};
            _casing call CBA_fnc_deleteEntity;
        }, [_carried]] call CBA_fnc_execNextFrame;
        hint "Binned casing.";
    };
    _carryingCasing
};

private _casings = nearestObjects [_crate, [_casingClass], _radius] select {
    _x isNotEqualTo _carried && {isNull attachedTo _x}
};

if (_mode isEqualTo "canCleanup" || {_casings isEqualTo []}) exitWith {
    _casings isNotEqualTo []
};

{
    _x call CBA_fnc_deleteEntity;
} forEach _casings;

private _count = count _casings;
hint format ["Binned %1 casing%2.", _count, ["s", ""] select (_count isEqualTo 1)];
_count > 0
