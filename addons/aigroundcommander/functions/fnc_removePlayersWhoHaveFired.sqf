#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        removes players from the playersWhoHaveFired list every defined number of seconds

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer) exitWith {};


// wait and execute to clear out the above list, default 10mins
[{
    params ["_time"];
    GVAR(playersThatHaveFired) = (GVAR(playersThatHaveFired) select {_time < ((_x#1) + 600}));
    call FUNC(removePlayersWhoHaveFired);
},[time],600] call cba_fnc_waitandexecute;
