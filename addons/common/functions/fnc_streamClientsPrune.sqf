#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Drops null player entries from a stream-client list.

    Parameter(s):
        0: List <ARRAY>

    Return Value:
        The same list <ARRAY>

    Example:
        [_list] call uksf_common_fnc_streamClientsPrune
*/
params ["_list"];

for "_index" from ((count _list) - 1) to 0 step -1 do {
    if (isNull ((_list select _index) select 0)) then {
        _list deleteAt _index;
    };
};

_list
