[
    QGVAR(mainOp),
    "CHECKBOX",
    ["Main Op", "Determines if this op is a main op"],
    ["UKSF", QUOTE(COMPONENT_BEAUTIFIED)],
    false,
    1
] call CBA_settings_fnc_init;

[
    "diwako_dui_main_hide_ui_by_default",
    "CHECKBOX",
    [localize "STR_dui_hide_ui_by_default", localize "STR_dui_hide_ui_by_default_desc"],
    [(format ["%1 - %2",localize "STR_dui_mod", localize "STR_dui_addon_main"]), localize "STR_dui_cat_general"],
    true,
    false,
    {
        params ["_value"];
        diwako_dui_main_toggled_off = _value;
        ["diwako_dui_main_hudToggled", [diwako_dui_main_toggled_off]] call CBA_fnc_localEvent;
    }
] call CBA_Settings_fnc_init;

[
    "diwako_dui_ace_hide_interaction",
    "CHECKBOX",
    [localize "STR_dui_ace_hide_interaction", localize "STR_dui_ace_hide_interaction_desc"],
    [(format ["%1 - %2",localize "STR_dui_mod", localize "STR_dui_addon_main"]), localize "STR_dui_cat_general"],
    false,
    false
] call CBA_Settings_fnc_init;
