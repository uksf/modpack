#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Sends a CBA target event to every live player on a stream-client list.

    Parameter(s):
        0: List <ARRAY>
        1: Event <STRING>
        2: Args <ANY>

    Return Value:
        Recipients <ARRAY>

    Example:
        [_list, QGVAR(debugStreamData), [_data]] call uksf_common_fnc_streamClientsFanout
*/
params ["_list", "_event", "_args"];

private _targets = [_list] call FUNC(streamClientsTargets);
if (_targets isNotEqualTo []) then {
    [_event, _args, _targets] call CBA_fnc_targetEvent;
};
_targets
