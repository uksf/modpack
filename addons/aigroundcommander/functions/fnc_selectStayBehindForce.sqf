#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Selects which group wil stay behind

    Parameters:
        0: Group <GROUP>
        
    Return value:
        Nothing
*/
params ["_group"];

if (!local (leader _group)) exitWith {};

if (GVAR(numberOfStayBehindGroups) > 0) then {
    private _stayBehindGroup = selectRandom GVAR(responseGroups);
    _stayBehindGroup setVariable [QGVAR(isStayBehindGroup),true,true];
    GVAR(responseGroups) deleteAt (GVAR(responseGroups) find _stayBehindGroup);
    GVAR(numberOfStayBehindGroups) = 0;
};

if (_group getVariable [QGVAR(isStayBehindGroup),false]) then {
    [_group,(getPos (leader _group)), 300, 7,"MOVE","SAFE"] call cba_fnc_taskPatrol;
    deleteVehicle (vehicle (leader _group));
} else {
    [_group,(getPos (assignedVehicle (leader _group))),0,"GETIN","AWARE","YELLOW","NORMAL"] call cba_fnc_addWaypoint;
    [_group,(_group getVariable [QGVAR(spawnPosition),[0,0,0]]),50,"MOVE","AWARE","YELLOW","FULL","FILE","[this] call uksf_aigroundCommander_fnc_handleDelete"] call cba_fnc_addWaypoint;
};




// params array syntax does default value and typechecking
// grpNull sets _group as grpNull when nothing is passed to the function
// [grpNull, objNull] does type checking against those types and only allows the parameter to be those types. any other type will throw a script error
// params [["_group", grpNull, [grpNull, objNull]]];

// if you need the parameter to eventually be a single type, you can compare against one type and convert it with a command
// if (_group isEqualType objNull) then {
//     _group = group _group;
// };