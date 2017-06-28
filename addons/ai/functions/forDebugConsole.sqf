

if (
    !(alive player)
) exitWith {};

[{

    if (alive player) then {
        private _emptyPos = (getPosATL player) nearEntities ["Car",30];
        hint format ["Posns: %1", _emptyPos];
    };
}];


_pos = position player findEmptyPosition [0,30];
hint format ["Posn: %1", _pos];

////////////////////////


params ["_unit", "", "", "_instigator"]; 
 
if (!alive _unit) exitwith {}; 
 
[{ 
    params ["_unit","_instigator"]; 
 
    if (alive _unit) then { 
        _wpn = currentWeapon _unit; 
        _instigatorPos = _unit doTarget (selectRandom units group _instigator); 
        _unit Fire _wpn; 
        shots = 0; 
        _unit addEventHandler ["fired", { 
            hint format ["Shots: %1",shots]; 
            if (shots < 20) then { 
            _unit Fire _wpn; 
            shots = shots + 1; 
            }; 
            _unit removeEventHandler ["fired", 1]; 
        }]; 
    }; 
}];
