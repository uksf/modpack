#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Records the execution time of a provider handler for the current frame.
        Called by provider event handlers after they complete their work.

    Parameters:
        0: Provider key <STRING>
        1: Start time from diag_tickTime <NUMBER>

    Return Value:
        None
*/
params ["_providerKey", "_startTime"];

private _elapsed = diag_tickTime - _startTime;
GVAR(frameTimings) set [_providerKey, (GVAR(frameTimings) getOrDefault [_providerKey, 0]) + _elapsed];
