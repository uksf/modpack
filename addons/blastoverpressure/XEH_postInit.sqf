#include "script_component.hpp"

["CBA_settingsInitialized", {
    [{
        params ["_projectile", "_positionASL"];

        // Skip if projectile won't inflict damage (avoids duplicate events from tracers)
        if !(_projectile getShotInfo 5) exitWith {};

        [_projectile, _positionASL] call FUNC(explosionHandler);
    }] call EFUNC(common,addExplosionEventHandler);
}] call CBA_fnc_addEventHandler;
