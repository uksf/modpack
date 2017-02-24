class CfgVehicles {
    class CUP_O_TK_INS_Soldier;
    class UKSF_O_TK_INS_Suicide_Driver: CUP_O_TK_INS_Soldier {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "Suicide Driver";
        //editorPreview = QPATHTOEF(common,data\previews\UKSF_O_TK_INS_Suicide_Driver.jpg);
        uniformClass = "CUP_O_TKI_Khet_Partug_04";
        weapons[] = { "Throw", "Put" };
        respawnWeapons[] = { "Throw", "Put" };
        magazines[] = {};
        respawnMagazines[] = {};
        linkedItems[] = { "CUP_H_TKI_Pakol_2_01", "CUP_V_OI_TKI_Jacket1_03", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio" };
        respawnLinkedItems[] = { "CUP_H_TKI_Pakol_2_01", "CUP_V_OI_TKI_Jacket1_03", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio" };
    };
    class UKSF_O_TK_INS_Suicide: UKSF_O_TK_INS_Suicide_Driver {
        author = "UKSF";
        displayName = "Suicide Bomber";
        //editorPreview = QPATHTOEF(common,data\previews\UKSF_O_TK_INS_Suicide.jpg);
    };
    class UKSF_O_TK_INS_Suicide_Deadman: UKSF_O_TK_INS_Suicide_Driver {
        displayName = "Suicide Bomber (Deadman)";
        //editorPreview = QPATHTOEF(common,data\previews\UKSF_O_TK_INS_Suicide_Deadman.jpg);
    };

    class CUP_C_Skoda_White_CIV;
    class UKSF_O_Skoda_Base: CUP_C_Skoda_White_CIV {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        side = 0;
        faction = "CUP_O_TK_MILITIA";
        displayName = "Car Bomb";
        crew = "UKSF_O_TK_INS_Suicide_Driver";
		typicalCargo[] = { "UKSF_O_TK_INS_Suicide_Driver" };
        class TextureSources {
            class White {
                displayName = "White";
                author = "UKSF";
                textures[] = { "\CUP\WheeledVehicles\CUP_WheeledVehicles_Skoda\data\skodovka_bila_co.paa" };
                factions[] = {};
            };
            class Red {
                displayName = "Red";
                author = "UKSF";
                textures[] = { "\CUP\WheeledVehicles\CUP_WheeledVehicles_Skoda\data\skodovka_cervena_co.paa" };
                factions[] = {};
            };
            class Blue {
                displayName = "Blue";
                author = "UKSF";
                textures[] = { "\CUP\WheeledVehicles\CUP_WheeledVehicles_Skoda\data\skodovka_modra_co.paa" };
                factions[] = {};
            };
            class Green {
                displayName = "Green";
                author = "UKSF";
                textures[] = { "\CUP\WheeledVehicles\CUP_WheeledVehicles_Skoda\data\skodovka_zelena_co.paa" };
                factions[] = {};
            };
        };
    };
    class UKSF_O_Skoda_CarBomb: UKSF_O_Skoda_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Car Bomb";
    };
    class UKSF_O_Skoda_CarBomb_Deadman: UKSF_O_Skoda_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Car Bomb (Deadman)";
    };
    class UKSF_O_Skoda_CarBomb_Empty: UKSF_O_Skoda_Base {
        scope = 2;
        scopeCurator = 2;
        displayName = "Car Bomb (Empty)";
        crew = "";
		typicalCargo[] = { "" };
    };

    class EGVAR(common,moduleBase);
    class GVAR(moduleMakeSuicideBomber): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        scopeCurator = 2;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = QUOTE(Make Suicide Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = "\z\ace\addons\explosives\UI\Icon_Module_Explosives_ca.paa";
    };
    class GVAR(moduleMakeSuicideBomberDeadman): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        scopeCurator = 2;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = QUOTE(Make Deadman Suicide Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = "\z\ace\addons\explosives\UI\Icon_Module_Explosives_ca.paa";
    };
    class GVAR(moduleMakeCarBomber): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        scopeCurator = 2;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = QUOTE(Make Car Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = "\z\ace\addons\explosives\UI\Icon_Module_Explosives_ca.paa";
    };
    class GVAR(moduleMakeCarBomberDeadman): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        scopeCurator = 2;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = QUOTE(Make Deadman Car Bomber);
        function = QFUNC(moduleMakeBomb);
        icon = "\z\ace\addons\explosives\UI\Icon_Module_Explosives_ca.paa";
    };
    class GVAR(moduleMakeCarBomb): EGVAR(common,moduleBase) {
        curatorCanAttach = 1;
        scopeCurator = 2;
        category = QEGVAR(common,zeus_uksf_special);
        displayName = QUOTE(Make Car Bomb);
        function = QFUNC(moduleMakeBomb);
        icon = "\z\ace\addons\explosives\UI\Icon_Module_Explosives_ca.paa";
    };
};
