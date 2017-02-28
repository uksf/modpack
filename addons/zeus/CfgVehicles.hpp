class CfgVehicles {
    class Ares_Spawn_Module_Base;
    class UKSF_Module_SmallExplosion: Ares_Spawn_Module_Base {
        scopeCurator = 2;
        displayName = "Small Explosion";
        function = QFUNC(moduleExplosionSmall);
        icon = QPATHTOF(UI\Icon_Module_Explosion_Small_ca.paa);
    };        
    class UKSF_Module_LargeExplosion: Ares_Spawn_Module_Base {
        scopeCurator = 2;
        displayName = "Large Explosion";
        function = QFUNC(moduleExplosionLarge);
        icon = QPATHTOF(UI\Icon_Module_Explosion_Large_ca.paa);
    };
    class Ares_Zeus_Module_Base;
    class UKSF_Module_AddAllObjects: Ares_Zeus_Module_Base {
        scopeCurator = 2;
        displayName = "Add all objects";
        function = QFUNC(moduleAddAllObjects);
        icon = "\achilles\data_f_achilles\icons\icon_position.paa";
    };
    class Ares_Module_Zeus_Visibility: Ares_Zeus_Module_Base {
        displayName = "Toggle Zeus Visibility";
        function = QFUNC(moduleToggleZeusVisibility);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class UKSF_Module_TeleportZeus: Ares_Zeus_Module_Base {
        scopeCurator = 2;
        displayName = "Teleport Zeus";
        function = QFUNC(moduleTeleportZeus);
        icon = QPATHTOF(UI\Icon_Module_Explosion_ca.paa);
    };
    class Achilles_Module_Base;
    class Achilles_ACE_Module_Base: Achilles_Module_Base {
        category = "ace_zeus_Medical";
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Medic_ca.paa";
    };
    class Achilles_ACE_Heal_Module: Achilles_ACE_Module_Base {
        function = QFUNC(moduleFullHeal);
    };
    class UKSF_Module_ToggleAllowUnconcious: Achilles_ACE_Module_Base {
        scopeCurator = 2;
        displayName = "Toggle Allow Unconcious";
        function = QFUNC(moduleToggleAllowUnconcious);
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Unconscious_ca.paa";
    };
};
