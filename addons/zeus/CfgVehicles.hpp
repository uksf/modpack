class CfgVehicles {
    class Module_F;
    class ModuleCurator_F: Module_F {
        function = QFUNC(moduleCurator);
    };
    
    class ModuleMine_APERSTripMine_F;
    class ModuleMine_FlareTripMine_F: ModuleMine_APERSTripMine_F {
        _generalMacro = "ModuleMine_FlareTripMine_F";
        displayName = "Tripwire Flare";
        explosive = "ACE_FlareTripMine_Wire_Ammo";
    };
    
    class EGVAR(common,moduleBase);
    class GVAR(moduleAddAllObjects): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Add all objects";
        function = QFUNC(moduleAddAllObjects);
        icon = "\achilles\data_f_achilles\icons\icon_position.paa";
    };
    class GVAR(moduleDelete): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Force Delete";
        function = QFUNC(moduleDelete);
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Settings_ca.paa";
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
    class GVAR(moduleHaloHaho): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = "HALO/HAHO Units";
        function = QFUNC(moduleHaloHaho);
        icon = "\achilles\data_f_achilles\icons\icon_dropzone.paa";
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
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Blufor/Opfor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {west, east};
        icon = QPATHTOF(UI\Icon_Module_ToggleBluforOpfor_ca.paa);
    };
    class GVAR(moduleToggleIndepBlufor): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Indep/Blufor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {independent, west};
        icon = QPATHTOF(UI\Icon_Module_ToggleIndepBlufor_ca.paa);
    };
    class GVAR(moduleToggleIndepOpfor): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = QEGVAR(common,zeus_uksf_side);
        displayName = "Toggle Indep/Opfor Relations";
        function = QFUNC(moduleToggleSideRelations);
        GVAR(sides)[] = {independent, east};
        icon = QPATHTOF(UI\Icon_Module_ToggleIndepOpfor_ca.paa);
    };
    class GVAR(moduleToggleFps): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Toggle FPS";
        function = QFUNC(moduleToggleFps);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
        portrait = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class GVAR(moduleToggleHasRadio): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        displayName = "Toggle Unit Support";
        function = QFUNC(moduleToggleHasRadio);
    };

    class ace_zeus_moduleBase;
    class ace_zeus_AddFullArsenal: ace_zeus_moduleBase {
        scopeCurator = 0;
    };
    class ace_zeus_RemoveFullArsenal: ace_zeus_moduleBase {
        scopeCurator = 0;
    };
    class ace_zeus_AddFullAceArsenal: ace_zeus_moduleBase {
        function = QFUNC(moduleAddAceArsenal);
    };
    class ace_zeus_RemoveFullAceArsenal: ace_zeus_moduleBase {
        function = QFUNC(moduleRemoveAceArsenal);
    };

    class Ares_Zeus_Module_Base;
    class Ares_Module_Zeus_Visibility: Ares_Zeus_Module_Base {
        curatorCanAttach = 1;
        displayName = "Toggle Zeus Visibility";
        function = QFUNC(moduleToggleZeusVisibility);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
        portrait = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class Achilles_Module_Base;
    class Achilles_ACE_Module_Base: Achilles_Module_Base {
        curatorCanAttach = 1;
        category = "ace_zeus_Medical";
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Medic_ca.paa";
        portrait = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Medic_ca.paa";
    };
    class Achilles_ACE_Heal_Module: Achilles_ACE_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Arsenal_Module_Base;
    class Achilles_Module_Arsenal_AddFull: Achilles_Arsenal_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Module_Arsenal_CreateCustom: Achilles_Arsenal_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Module_Arsenal_CopyToClipboard: Achilles_Arsenal_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Module_Arsenal_Paste: Achilles_Arsenal_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Module_Arsenal_Remove: Achilles_Arsenal_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Behaviours_Module_Base;
    class Ares_Module_Bahaviour_SurrenderUnit: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Bahaviour_Garrison_Nearest: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Bahaviour_UnGarrison: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Behaviour_Search_Nearby_Building: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Behaviour_Search_Nearby_And_Garrison: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Behaviour_Patrol: Ares_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Player_Module_Base;
    class Ares_Module_Player_Change_Player_Side: Ares_Player_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Player_Teleport: Ares_Player_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Player_Module_Base;
    class Achilles_Module_Player_Set_Frequencies: Achilles_Player_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Equipment_Module_Base;
    class Ares_Module_Equipment_Flashlight_IR_ON_OFF: Ares_Equipment_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Equipment_NVD_TACLIGHT_IR: Ares_Equipment_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Zeus_Add_Remove_Editable_Objects: Ares_Zeus_Module_Base {
        scopeCurator = 0;
    };
    class Ares_Module_Zeus_Switch_Side: Ares_Zeus_Module_Base {
        scopeCurator = 0;
    };
    class Enyo_Behaviours_Module_Base;
    class Achilles_SuicideBomber_Module: Enyo_Behaviours_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_FireSupport_ModuleBase;
    class Achilles_Suppressive_Fire_Module: Achilles_FireSupport_ModuleBase {
        scopeCurator = 0;
    };
    class Achilles_Create_Suppression_Target_Module: Achilles_FireSupport_ModuleBase {
        scopeCurator = 0;
    };
    class Achilles_Objects_Module_Base;
    class Achilles_Toggle_Simulation_Module: Achilles_Objects_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Zeus_Module_Base;
    class Achilles_Module_Zeus_SwitchUnit: Achilles_Zeus_Module_Base {
        scopeCurator = 0;
    };
    class Achilles_Module_Zeus_AssignZeus: Achilles_Zeus_Module_Base {
        scopeCurator = 0;
    };
    class ModuleArsenal_F: Module_F {
        scopeCurator = 0;
    };
};
