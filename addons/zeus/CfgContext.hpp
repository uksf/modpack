class zen_context_menu_actions {
    class Loadout {
        statement = QUOTE([_hoveredEntity] call FUNC(openArsenal));
    };
    class AI {
        displayName = "Ai";
        class Caching {
            displayName = "$STR_A3_RscAttributeUnitPos_Up_tooltip";
            icon = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
            statement = QUOTE([ARR_2(_selectedObjects,'UP')] call FUNC(setStance));
        };
    };
    class Object {
        displayName = "Object";
        // Cleanup
    };
};
