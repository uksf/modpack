#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Damage received provider setup. No-op — the ace_medical_woundReceived handler
        is consolidated into fnc_providerCombatDamage to avoid duplicate event handlers.
        This provider is kept for registry compatibility but does nothing.

    Parameters:
        None

    Return Value:
        None
*/
