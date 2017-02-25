class CfgVehicles {
    class Ares_Spawn_Module_Base;
    class UKSF_Module_SmallExplosion: Ares_Spawn_Module_Base {
        scopeCurator = 2;
        displayName = "Small Explosion";
        function = QFUNC(explosionSmall);
    };        
    class UKSF_Module_LargeExplosion: Ares_Spawn_Module_Base {
        scopeCurator = 2;
        displayName = "Large Explosion";
        function = QFUNC(explosionLarge);
    };
    class Ares_Zeus_Module_Base;
    class UKSF_Module_AddAllObjects: Ares_Zeus_Module_Base {
        scopeCurator = 2;
        displayName = "Add all objects";
        function = QFUNC(addAllObjects);
        icon = "\achilles\data_f_achilles\icons\icon_position.paa";
        portrait = "\achilles\data_f_achilles\icons\icon_position.paa";
    };
    class Ares_Module_Zeus_Visibility: Ares_Zeus_Module_Base {
        displayName = "Toggle Zeus Visibility";
        function = QFUNC(toggleZeusVisibility);
    };
    class UKSF_Module_TeleportZeus: Ares_Zeus_Module_Base {
        scopeCurator = 2;
        displayName = "Teleport Zeus";
        function = QFUNC(teleportZeus);
        icon = "\achilles\data_f_ares\icons\icon_default.paa";
        portrait = "\achilles\data_f_ares\icons\icon_default.paa";
    };
};
