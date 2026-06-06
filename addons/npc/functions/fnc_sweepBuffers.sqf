#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Evicts stale partial reassembly buffers. A lost chunk would otherwise leave a
        buffer that never completes — a small permanent leak plus a silently dropped
        clip/turn. Drops any buffer key untouched for longer than the TTL.

    Parameter(s):
        0: Buffer HashMap (key -> partial buffer) <HASHMAP>
        1: Time HashMap (key -> last-touch diag_tickTime) <HASHMAP>
        2: TTL seconds <NUMBER>
        3: Label for logging <STRING>

    Return Value:
        None

    Example:
        [GVAR(rxBuffers), GVAR(rxBufferTimes), 30, "rx"] call uksf_npc_fnc_sweepBuffers
*/
params ["_buffers", "_times", "_ttl", "_label"];

private _now = diag_tickTime;

// Collect stale keys first — do not mutate the map while iterating it.
private _stale = [];
{
    if ((_now - _x) > _ttl) then { _stale pushBack _y };
} forEach _times; // HashMap forEach: _x = value (last-touch time), _y = key

{
    _buffers deleteAt _x;
    _times deleteAt _x;
    private _message = format ["NPC %1: evicted stale partial reassembly buffer '%2' (a chunk was lost)", _label, _x];
    WARNING(_message);
} forEach _stale;
