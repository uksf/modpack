#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops statistics collection. Removes sync PFHs and provider event handlers.
        Note: CBA class event handlers (used by hits provider) cannot be removed,
        but the addEvent function checks the killswitch so events are silently dropped.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_stopCollection
*/
if (GVAR(clientSyncPFH) != -1) then {
    [GVAR(clientSyncPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(clientSyncPFH) = -1;
};

// Remove provider event handlers
if (!isNil QGVAR(firedManEHId) && {hasInterface}) then {
    player removeEventHandler ["FiredMan", GVAR(firedManEHId)];
    GVAR(firedManEHId) = nil;
};

if (GVAR(performancePFH) != -1) then {
    [GVAR(performancePFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(performancePFH) = -1;
};

if (isServer && {GVAR(serverSyncPFH) != -1}) then {
    [GVAR(serverSyncPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(serverSyncPFH) = -1;
};

INFO("Statistics collection stopped");
