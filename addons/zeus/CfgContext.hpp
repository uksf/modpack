class zen_context_menu_actions {
    class HealUnits {
        condition = QUOTE([ARR_2(_objects,_args)] call zen_context_actions_fnc_canHealUnits);
        statement = QUOTE([ARR_2(_objects,_args)] call zen_context_actions_fnc_healUnits);
        args = 0;
    };
    class Loadout {
        statement = QUOTE([_hoveredEntity] call FUNC(openArsenal));
    };
    class EditableObjects {
        class Add {
            class All {
                displayName = "All";
                statement = QUOTE([ARR_3(allMissionObjects 'All',true,getAssignedCuratorLogic player)] call zen_common_fnc_updateEditableObjects);
                icon = "\x\zen\addons\context_actions\ui\add_ca.paa";
                priority = 100;
            };
        };
    };
    class TeleportPlayers {
        statement = QUOTE(_objects call FUNC(teleportPlayers));
    };
    class TeleportZeus {
        priority = -950;
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
