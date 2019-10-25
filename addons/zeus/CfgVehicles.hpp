class CfgVehicles {
    // Edit vanilla modules
    class ModuleMine_APERSTripMine_F;
    class ModuleMine_FlareTripMine_F: ModuleMine_APERSTripMine_F {
        _generalMacro = "ModuleMine_FlareTripMine_F";
        displayName = "Tripwire Flare";
        explosive = "ACE_FlareTripMine_Wire_Ammo";
    };

    // Edit zen modules
    class zen_modules_moduleBase;
    class zen_modules_moduleArsenal: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleAddFullArsenal: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleRemoveArsenal: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleAssignZeus: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleAttachFlag: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleHideZeus: zen_modules_moduleBase {
        scopeCurator = 1;
    };
    class zen_modules_moduleHeal: zen_modules_moduleBase {
        scopeCurator = 1;
    };

    // Edit ace modules
    class ace_zeus_moduleBase;
    class ace_zeus_AddFullAceArsenal: ace_zeus_moduleBase {
        function = QFUNC(moduleAddAceArsenal);
    };
    class ace_zeus_RemoveFullAceArsenal: ace_zeus_moduleBase {
        function = QFUNC(moduleRemoveAceArsenal);
    };
    class ace_zeus_AddFullArsenal: ace_zeus_moduleBase {
        scopeCurator = 1;
    };
    class ace_zeus_RemoveFullArsenal: ace_zeus_moduleBase {
        scopeCurator = 1;
    };
    class ace_zeus_moduleEditableObjects: ace_zeus_moduleBase {
        scopeCurator = 1;
    };

    // Custom modules
    class Module_F;
    class GVAR(moduleBase): Module_F {
        author = QUOTE(UKSF);
        category = QGVAR(uksf);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        scope = 1;
        scopeCurator = 2;
    };
    class GVAR(moduleAddAllObjects): GVAR(moduleBase) {
        category = "Curator";
        displayName = "Add all objects";
        function = QFUNC(moduleAddAllObjects);
        icon = "\x\zen\addons\modules\ui\edit_obj_ca.paa";
    };
    class GVAR(moduleToggleZeusVisibility): GVAR(moduleBase) {
        category = "Curator";
        displayName = "Toggle Zeus Visibility";
        function = QFUNC(moduleToggleZeusVisibility);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class GVAR(moduleDelete): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "Curator";
        displayName = "Force Delete";
        function = QFUNC(moduleDelete);
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Settings_ca.paa";
    };
    class GVAR(moduleExplosionLarge): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "Spawn";
        displayName = "Large Explosion";
        function = QFUNC(moduleExplosionLarge);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleExplosionSmall): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "Spawn";
        displayName = "Small Explosion";
        function = QFUNC(moduleExplosionSmall);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Small_ca.paa);
    };
    class GVAR(moduleToggleAllowUnconcious): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "ace_zeus_Medical";
        displayName = "Toggle Allow Unconcious";
        function = QFUNC(moduleToggleAllowUnconcious);
        icon = "\z\ace\addons\zeus\ui\Icon_Module_Zeus_Unconscious_ca.paa";
    };
    class GVAR(moduleToggleFps): GVAR(moduleBase) {
        category = "Curator";
        displayName = "Toggle FPS";
        function = QFUNC(moduleToggleFps);
        icon = "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa";
    };
    class GVAR(moduleToggleHasRadio): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "zen_modules_AI";
        displayName = "Toggle Unit Support";
        function = QFUNC(moduleToggleHasRadio);
    };
    class GVAR(moduleToggleCaching): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "zen_modules_AI";
        displayName = QUOTE(Caching Toggle);
        function = QFUNC(moduleToggleCaching);
        icon = QPATHTOF(ui\Icon_Module_Caching_ca.paa);
    };
    class GVAR(moduleToggleCleanup): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = "zen_modules_AI";
        displayName = QUOTE(Cleanup Toggle);
        function = QFUNC(moduleToggleCleanup);
        icon = QPATHTOF(ui\Icon_Module_Cleanup_ca.paa);
    };
    class GVAR(moduleParadrop): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = QGVAR(special);
        displayName = "Paradrop Units";
        function = QFUNC(moduleParadrop);
        icon = QPATHTOF(ui\Icon_Module_Dropzone.paa);
    };
    class GVAR(moduleMakeSuicideBomber): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = GVAR(special);
        displayName = QUOTE(Make Suicide Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleMakeSuicideBomberDeadman): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = GVAR(special);
        displayName = QUOTE(Make Deadman Suicide Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleMakeCarBomber): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = GVAR(special);
        displayName = QUOTE(Make Car Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleMakeCarBomberDeadman): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = GVAR(special);
        displayName = QUOTE(Make Deadman Car Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
    class GVAR(moduleMakeCarBomb): GVAR(moduleBase) {
        curatorCanAttach = 1;
        category = GVAR(special);
        displayName = QUOTE(Make Car Bomb);
        function = QFUNC(moduleMakeBomb);
        icon = QPATHTOF(ui\Icon_Module_Explosion_Large_ca.paa);
    };
};
