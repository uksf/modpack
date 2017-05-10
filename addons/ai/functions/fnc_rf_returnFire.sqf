 
/*
    Author:
        Adam Bridgford, Tim Beswick

    Description:
        Makes unit fire 20 rounds fast.
        
    Parameter(s):
        0: Unit hit <OBJECT>
        1: Unit causing the damage <SCALAR>
        
    Return Value:
        Nothing
*/
 
 params ["_unit","_instigator"];
 
        _wpn = currentWeapon _unit;
        hint format ["%1",_wpn];
        _unit doTarget _instigator;
        _unit Fire _wpn;
        shots = 0;
        hint format ["Shots: %1",shots];
        _unit addEventHandler ["fired", {
            hint "Fired EH";
            if (shots < 20) then {
            _unit forceWeaponFire [(currentWeapon _unit), "FullAuto"];
            shots = shots + 1;
            hint "Fired EH Bottom";
            };
            _unit removeEventHandler ["fired", 1];
        }] forEach units group _unit;
