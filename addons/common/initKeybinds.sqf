#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Release slung cargo
["UKSF", QGVAR(releaseCargoAll), "DEPRECATED - Release Cargo (All)", {false}, {["All"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoFront), "DEPRECATED - Release Cargo (Front)", {false}, {["Front"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoCenter), "DEPRECATED - Release Cargo (Center)", {false}, {["Center"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoRear), "DEPRECATED - Release Cargo (Rear)", {false}, {["Rear"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Open Ramp
["UKSF", QGVAR(ramp), "DEPRECATED - Open/Close Ramp", {false}, {call FUNC(ramp)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Paradrop internal cargo (Only works with C-130)
["UKSF", QGVAR(dropCargoSingle), "DEPRECATED - Drop Cargo (Single)", {false}, {[0] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(dropCargoAll), "DEPRECATED - Drop Cargo (All)", {false}, {[1] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
