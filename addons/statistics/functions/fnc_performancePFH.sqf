#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Per-frame handler that sums all provider execution times for the current frame
        into a single debug variable, then resets the per-provider accumulators.
        RPT logging is gated behind DEBUG_MODE_FULL.

    Parameters:
        None (PFH)

    Return Value:
        None
*/
private _total = 0;
{
    _total = _total + _y;
} forEach GVAR(frameTimings);

GVAR(frameOverhead) = _total;

// Reset for next frame
{
    GVAR(frameTimings) set [_x, 0];
} forEach keys GVAR(frameTimings);

#ifdef DEBUG_MODE_FULL
// Log every 5 seconds (approx 5 * expected FPS frames)
// Use a simple frame counter to avoid diag_tickTime overhead in the perf monitor itself
if (isNil QGVAR(perfLogCounter)) then { GVAR(perfLogCounter) = 0 };
GVAR(perfLogCounter) = GVAR(perfLogCounter) + 1;
if (GVAR(perfLogCounter) >= (5 * diag_fps)) then {
    GVAR(perfLogCounter) = 0;
    if (_total > 0) then {
        DEBUG_1("Frame overhead: %1ms",_total * 1000);
    };
};
#endif
