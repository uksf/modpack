#include "script_component.hpp"

GVAR(active) = false;

["UKSF", QGVAR(screenshotToggle), "Toggle Screenshot Mode", {false}, {
    GVAR(active) = !GVAR(active);
    [!GVAR(active)] call FUNC(toggle);
}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
