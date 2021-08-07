// [
//     QGVAR(enabled),
//     "CHECKBOX",
//     ["Cleanup", "Enables cleanup of dead units/vehicles"],
//     ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
//     false,
//     1,
//     {
//         params ["_value"];

//         if (isServer && _value) then {
//             [{call FUNC(cleanupCheck)}, [], 0] call CBA_fnc_waitAndExecute;
//         };
//     }
// ] call CBA_settings_fnc_init;

// [
//     QGVAR(delay),
//     "SLIDER",
//     ["Cleanup Delay", "Delay in seconds between death and cleanup"],
//     ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
//     [5, 600, 300, 0],
//     1
// ] call CBA_settings_fnc_init;
