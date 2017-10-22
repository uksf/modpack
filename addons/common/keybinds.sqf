#include "\a3\editor_f\Data\Scripts\dikCodes.h"

// Enable/Disable Collision Lights
// Remove once added with next ACE update
["UKSF", QGVAR(collisionLights), "Collision Lights", {
    if (!([ACE_player, vehicle ACE_player, []] call EFUNC(common,canInteractWith))) exitWith {false};
    if ((ACE_player isEqualTo (vehicle ACE_player)) || {ACE_player != (driver (vehicle ACE_player))}) exitWith {false};
    (vehicle ACE_player) setCollisionLight !(isCollisionLightOn (vehicle ACE_player));
    true
},
{false},
[0, [false, false, false]]] call CBA_fnc_addKeybind;

// Release cargo
["UKSF", QGVAR(releaseCargoAll), "Release Cargo (All)", {false}, {["All"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoFront), "Release Cargo (Front)", {false}, {["Front"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoCenter), "Release Cargo (Center)", {false}, {["Center"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
["UKSF", QGVAR(releaseCargoRear), "Release Cargo (Rear)", {false}, {["Rear"] call FUNC(releaseCargo);}, [0, [false, false, false]]] call CBA_fnc_addKeybind;
