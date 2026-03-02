#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops statistics collection. Removes sync PFHs and provider event handlers.

    Parameters:
        None

    Return Value:
        None
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

if (isServer && {GVAR(serverSyncPFH) != -1}) then {
    [GVAR(serverSyncPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(serverSyncPFH) = -1;
};

INFO("Statistics collection stopped");
