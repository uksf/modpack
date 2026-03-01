#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a client event report on the server. Merges received events
        into the server buffer for later API delivery.

    Parameters:
        0: Player UID <STRING>
        1: Player name <STRING>
        2: Events <ARRAY> — array of event hashmaps

    Return Value:
        None
*/
params [["_uid", "", [""]], ["_name", "", [""]], ["_events", [], [[]]]];

if (_uid == "" || {_events isEqualTo []}) exitWith {};

private _playerData = GVAR(serverBuffer) getOrDefault [_uid, createHashMapFromArray [["name", _name], ["events", []]]];
_playerData set ["name", _name];
(_playerData get "events") append _events;
GVAR(serverBuffer) set [_uid, _playerData];
