#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the performance log on a machine without an interface (the server or a headless client).
        Every 10 s it writes one RPT line with fps, slow-frame counts, local AI and script counts.
        It writes a separate line for each frame of 250 ms or more.
        Does nothing when the performance log setting is off.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_common_fnc_perfLogStart
*/
if (hasInterface || {!GVAR(perfLogEnabled)} || {!isNil QGVAR(perfLogPFH)}) exitWith {};

GVAR(perfLogMachine) = ["hc", "server"] select isServer;
GVAR(perfLogLastFrameAt) = diag_tickTime;
GVAR(perfLogWindowStart) = diag_tickTime;
GVAR(perfLogFrames) = 0;
GVAR(perfLogSlowCounts) = [0, 0, 0];
GVAR(perfLogMaxMs) = 0;

GVAR(perfLogPFH) = [FUNC(perfLogTick), 0, []] call CBA_fnc_addPerFrameHandler;
INFO_1("Performance log started on %1",GVAR(perfLogMachine));
