params ["_unit"];

_unit addMPEventHandler ["MPHit", {_this call UKSF_Mission_fnc_findNearby}];
