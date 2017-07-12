class CfgVehicles {
    class Module_F;
    class ModuleCurator_F: Module_F {
        function = QFUNC(moduleCurator);
    };
    
    class EGVAR(common,moduleBase);
    class GVAR(moduleAddAllObjects): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Add all objects";
        function = QFUNC(moduleAddAllObjects);
        icon = "\achilles\data_f_achilles\icons\icon_position.paa";
    };
    class GVAR(moduleExplosionLarge): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Spawn";
        displayName = "Large Explosion";
        function = QFUNC(moduleExplosionLarge);
        icon = QPATHTOF(UI\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleExplosionSmall): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Spawn";
        displayName = "Small Explosion";
        function = QFUNC(moduleExplosionSmall);
        icon = QPATHTOF(UI\Icon_Module_Explosion_Small_ca.paa);
    };
    class GVAR(moduleLoadoutCopy): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Equipment";
        displayName = "Loadout Copy";
        function = QFUNC(moduleLoadoutCopy);
        icon = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
        portrait = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
    };
    class GVAR(moduleLoadoutPaste): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Equipment";
        displayName = "Loadout Paste";
        function = QFUNC(moduleLoadoutPaste);
        icon = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
        portrait = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
    };
    class GVAR(moduleSetEngineer): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "ace_zeus_Repair";
        displayName = "Assign Engineer";
        function = QFUNC(moduleSetEngineer);
        icon = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
        portrait = "\achilles\data_f_achilles\icons\icon_default_unit.paa";
    };
    class GVAR(moduleTeleportZeus): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Teleport Zeus";
        function = QFUNC(moduleTeleportZeus);
        icon = "\achilles\data_f_achilles\icons\icon_position.paa";
    };
    class GVAR(moduleToggleAllowUnconcious): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "ace_zeus_Medical";
        displayName = "Toggle Allow Unconcious";
        function = QFUNC(moduleToggleAllowUnconcious);
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Unconscious_ca.paa";
    };
    class GVAR(moduleToggleBluforOpfor): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        isGlobal = 0;
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Blufor/Opfor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {west, east};
        icon = QPATHTOF(UI\Icon_Module_ToggleBluforOpfor_ca.paa);
    };
    class GVAR(moduleToggleIndepBlufor): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        isGlobal = 0;
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Indep/Blufor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {independent, west};
        icon = QPATHTOF(UI\Icon_Module_ToggleIndepBlufor_ca.paa);
    };
    class GVAR(moduleToggleIndepOpfor): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        isGlobal = 0;
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Indep/Opfor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {independent, east};
        icon = QPATHTOF(UI\Icon_Module_ToggleIndepOpfor_ca.paa);
    };

    class Ares_Zeus_Module_Base;
    class Ares_Module_Zeus_Visibility: Ares_Zeus_Module_Base {
        displayName = "Toggle Zeus Visibility";
        function = QFUNC(moduleToggleZeusVisibility);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
        portrait = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class Achilles_Module_Base;
    class Achilles_ACE_Module_Base: Achilles_Module_Base {
        category = "ace_zeus_Medical";
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Medic_ca.paa";
        portrait = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Medic_ca.paa";
    };
    class Achilles_ACE_Heal_Module: Achilles_ACE_Module_Base {
        function = QFUNC(moduleFullHeal);
    };
};
