#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Release slung cargo
["UKSF", QGVAR(releaseCargoAll), "Release Cargo (All)", {false}, {["All"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoFront), "Release Cargo (Front)", {false}, {["Front"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoCenter), "Release Cargo (Center)", {false}, {["Center"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoRear), "Release Cargo (Rear)", {false}, {["Rear"] call FUNC(releaseCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Open Ramp
["UKSF", QGVAR(ramp), "Open/Close Ramp", {false}, {call FUNC(ramp)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;

// Paradrop internal cargo (Only works with C-130)
["UKSF", QGVAR(dropCargoSingle), "Drop Cargo (Single)", {false}, {[0] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(dropCargoAll), "Drop Cargo (All)", {false}, {[1] call FUNC(paradropCargo)}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
