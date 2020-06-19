class zen_context_menu_actions {
    class HealUnits {
        condition = QUOTE([ARR_2(_objects,_args)] call zen_context_actions_fnc_canHealUnits);
        statement = QUOTE([ARR_2(_objects,_args)] call zen_context_actions_fnc_healUnits);
        args = 0;
    };
    class Loadout {
        statement = QUOTE([_hoveredEntity] call FUNC(openArsenal));
    };
    class TeleportZeus {
        priority = -490;
    };
    class lambs_wp {
        priority = 95;
    };
    class lambs_wp_Search {
        priority = 96;
    };
    class lambs_danger {
        priority = 97;
    };
};
