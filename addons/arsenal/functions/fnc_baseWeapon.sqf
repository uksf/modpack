/*
    Author: 

    Description:
    Return base weapon (i.e., weapon without any attachments)
    
    Parameter(s):
        0: STRING - weapon class
    
    Returns:
    STRING - weapon class
*/
/*
    Author:
        Karel Moricky, edited by Tim Beswick to remove %ALL error case

    Description:
        Return base weapon (i.e., weapon without any attachments).

    Parameter(s):
        0: Weapon class <STRING>

    Return Value:
        Weapon class <STRING>
*/
#include "script_component.hpp"

params [["_class", "", [""]]];

// Exit if %ALL
if (_class isEqualTo "%ALL") exitWith {
    _class
};

//--- Incorrect weapon class - terminate
private _cfg = configfile >> "cfgweapons" >> _class;
if !(isclass _cfg) exitwith {
    if (_class != "") then {["Class '%1' not found in CfgWeapons",_class] call bis_fnc_error};
    _class
};

//--- Get manual base weapon
private _base = gettext (_cfg >> "baseWeapon");
if (isclass (configfile >> "cfgweapons" >> _base)) exitwith {_base};

//--- Get first parent without any attachments
private _return = _class;
{
    if (count (_x >> "linkeditems") == 0) exitwith {_return = configname _x;};
} foreach (_cfg call bis_Fnc_returnparents);
_return
