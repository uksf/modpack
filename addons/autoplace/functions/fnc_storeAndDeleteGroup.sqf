#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Serialises group data to virtualisation storage, then removes the live group.
        Falls back to re-enabling caching/virtualisation if virtualisation is unavailable.

    Parameters:
        0: Group <GROUP>

    Return Value:
        Nothing

    Example:
        [_group] call uksf_autoplace_fnc_storeAndDeleteGroup
*/
params ["_group"];

if (!isServer) exitWith {};
if (isNull _group) exitWith {};
if ((units _group) isEqualTo []) exitWith {};

if (isNil QEFUNC(virtualisation,virtualiseGroup)) exitWith {
    [QEGVAR(caching,enableCache), _group] call CBA_fnc_serverEvent;
    [QEGVAR(virtualisation,include), _group] call CBA_fnc_serverEvent;
};

[_group] call EFUNC(virtualisation,virtualiseGroup);
