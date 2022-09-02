#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Paradrop internal cargo (Only works with C-130)
["UKSF", QGVAR(dropCargoSingle), "DEPRECATED - Drop Cargo (Single)", {false}, {[0] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(dropCargoAll), "DEPRECATED - Drop Cargo (All)", {false}, {[1] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
