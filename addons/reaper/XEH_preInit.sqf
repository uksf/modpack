#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(droneKilled), {
    if (!alive (getConnectedUAV ACE_player) && {!isNil QGVAR(handlerCompass)}) then {
        [GVAR(handlerCompass)] call CBA_fnc_removePerFrameHandler;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
