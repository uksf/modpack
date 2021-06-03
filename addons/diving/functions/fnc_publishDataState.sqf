#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Publishes serialised data state to server for persistence saving

    Parameter(s):
        None

    Return Value:
        Nothing
*/

// TODO_Debug: Undo once deemed not cause of server instability
// private _data = call FUNC(serialiseState);

// [QGVAR(playerDataPublish), [getPlayerUID player, _data]] call CBA_fnc_serverEvent;
