#include "script_component.hpp"

//--- Get default values
if (_this isequaltype objnull) exitwith {
    str [
        [
            getweaponcargo _this,
            getmagazinecargo _this,
            getitemcargo _this,
            getbackpackcargo _this
        ],
        false
    ]
};

//--- Set new contents only where the object is local
if !(isserver) exitwith {};

params [
    ["_entity",objnull,[objnull]],
    ["_data",[],[[],{},""]]
];

//--- Eden saves the data as a string to save space. Convert it back to an array.
if (_data isequaltype "") then {_data = call compile _data;};
if (_data isequaltype {}) then {_data = call _data;};

_data params [
    ["_input",[],[[]]],
    ["_isVirtual",[],[true]]
];

//--- Clear the existing contents
clearweaponcargoglobal _entity;
clearmagazinecargoglobal _entity;
clearbackpackcargoglobal _entity;
clearitemcargoglobal _entity;

_entity call FUNC(removeVirtualItemCargo);
_entity call FUNC(removeVirtualWeaponCargo);
_entity call FUNC(removeVirtualMagazineCargo);
_entity call FUNC(removeVirtualBackpackCargo);

//--- Go through saved data and add items based on type
if (_isVirtual) then {
    [_entity,(_input select 0) select 0,true] call FUNC(addVirtualWeaponCargo);
    [_entity,(_input select 1) select 0,true] call FUNC(addVirtualMagazineCargo);
    [_entity,(_input select 2) select 0,true] call FUNC(addVirtualItemCargo);
    [_entity,(_input select 3) select 0,true] call FUNC(addVirtualBackpackCargo);
} else {
    //--- Weapons
    _list = _input select 0;
    _classes = _list select 0;
    _values = _list select 1;
    {_entity addweaponcargoglobal [_x,_values select _foreachindex];} foreach _classes;

    //--- Magazines
    _list = _input select 1;
    _classes = _list select 0;
    _values = _list select 1;
    {_entity addmagazinecargoglobal [_x,_values select _foreachindex];} foreach _classes;

    //--- Items
    _list = _input select 2;
    _classes = _list select 0;
    _values = _list select 1;
    {_entity additemcargoglobal [_x,_values select _foreachindex];} foreach _classes;

    //--- Backpacks
    _list = _input select 3;
    _classes = _list select 0;
    _values = _list select 1;
    {_entity addbackpackcargoglobal [_x,_values select _foreachindex];} foreach _classes;
};
