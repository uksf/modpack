#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops statistics collection. Removes sync PFHs.
        CBA event handlers persist for mission lifetime and are cleaned up on mission end.
        Projectile event handlers are cleaned up when projectiles are deleted.

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

// CBA event handlers registered by providers persist for mission lifetime
// and are cleaned up on mission end. No manual removal needed.

if (GVAR(performancePFH) != -1) then {
    [GVAR(performancePFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(performancePFH) = -1;
};

if (GVAR(samplerPFH) != -1) then {
    [GVAR(samplerPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(samplerPFH) = -1;
};

if (isServer && {GVAR(serverSyncPFH) != -1}) then {
    [GVAR(serverSyncPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(serverSyncPFH) = -1;
};

GVAR(collectionStarted) = false;
INFO("Statistics collection stopped");
