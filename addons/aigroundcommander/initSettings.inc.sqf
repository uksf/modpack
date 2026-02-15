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

[
    QGVAR(groupLimit),
    "SLIDER",
    ["Group Limit", "Maximum number of active groups allowed"],
    COMPONENT_NAME,
    [1, 15, 10, 0],
    1
] call CBA_settings_fnc_init;
