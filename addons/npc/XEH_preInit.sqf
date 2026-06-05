#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// [[clipId, npc], ...] currently-playing clips tracked by the tick handler.
GVAR(active) = [];
GVAR(tickRunning) = false;

// Raised locally with [unit, text, uttId, time] when the local player's speech
// is transcribed. Sub-plan #5 consumes this to forward to the API; for now a
// TRACE handler makes it observable in-game.
[QGVAR(transcript), {
    params ["_unit", "_text", "_uttId", "_time"];
    TRACE_4("npc transcript",_unit,_text,_uttId,_time);
}] call CBA_fnc_addEventHandler;

ADDON = true;
