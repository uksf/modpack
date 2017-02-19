/*
    Author:
        Tim Beswick

    Description:
        Refills given crate based on crate contents at init

    Parameters:
        0: Crate <OBJECT>
        1: Type (default: 0) <SCALAR>

    Return value:
        Nothing

    Called from:
        [this, 0] call uksf_common_fnc_boxRefill;
*/
#include "script_component.hpp"

params ["_crate", ["_type", 0], ["_array", []]];

//Exit if client side
if (!isServer && isMultiplayer) exitWith {};

_typeName = switch (_type) do { 
    case 1: {"Weapon"}; 
    case 2: {"Magazine"};
    default {"Item"}; 
};

//Check crate contains items
_items = call compile format ["(get%1Cargo _crate) select 0", _typeName];
if (count _items == 0) exitWith {};

//Get backpacks (if any)
_backpacks = (getBackpackCargo _crate) select 0;
    
//clearItemCargoGlobal is broken for JIP clients, it hides weapons for JIP clients
call compile format ["clear%1CargoGlobal _crate", _typeName];
clearBackpackCargoGlobal _crate;
    
//Add only 5 of each item
{
    call compile format ["_crate add%1CargoGlobal [_x, 5]", _typeName];
} forEach _items;
{
    _crate addBackpackCargoGlobal [_x, 5];
} forEach _backpacks;

//PFH to handle items to be restocked
[{
    params ["_args", "_handle"];
    _args params ["_crate", "_items", "_typeName", "_backpacks"];
    
    if (!alive _crate) exitWith {
        [_handle] call cba_fnc_removePerFrameHandler;
    };
        
    _cargo = call compile format ["get%1Cargo _crate", _typeName];    
    {
        if (_x in (_cargo select 0)) then {
            _index = (_cargo select 0) find _x;
            
            if (_cargo select 1 select _index < 5) then {
                call compile format ["_crate add%1CargoGlobal [_x, 1]", _typeName];
            };
        } else {
            call compile format ["_crate add%1CargoGlobal [_x, 5]", _typeName];
        };
    } foreach _items;

    
    if ((count _backpacks) > 0) then {
        _backpackCargo = getBackpackCargo _crate;    
        {
            if (_x in (_backpackCargo select 0)) then {
                _index = (_backpackCargo select 0) find _x;
                
                if (_backpackCargo select 1 select _index < 5) then {
                    _crate addBackpackCargoGlobal [_x, 1];
                };
            } else {
                _crate addBackpackCargoGlobal [_x, 5];
            };
        } foreach _backpacks;
    } ;    
}, 0, [_crate, _items, _typeName, _backpacks]] call cba_fnc_addPerFrameHandler;
