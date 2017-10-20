#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Enable/Disable Collision Lights
["UKSF", QGVAR(collisionLights), "Collision Lights",
{
    (vehicle ace_player) setCollisionLight !(isCollisionLightOn (vehicle ace_player));
},
{false},
[0, [false, false, false]]] call CBA_fnc_addKeybind;

// Release cargo
["UKSF", QGVAR(releaseCargoAll), "Release Cargo (All)", {false}, {["All"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoFront), "Release Cargo (Front)", {false}, {["Front"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoCenter), "Release Cargo (Center)", {false}, {["Center"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoRear), "Release Cargo (Rear)", {false}, {["Rear"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
