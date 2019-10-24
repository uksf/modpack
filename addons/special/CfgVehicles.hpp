class CfgVehicles {
    class CUP_O_TK_INS_Soldier;
    class UKSF_O_TK_INS_Suicide_Driver: CUP_O_TK_INS_Soldier {
        author = "UKSF";
        scope = 2;
        scopeCurator = 2;
        displayName = "Suicide Driver";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_O_TK_INS_Suicide.jpg);
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
    };
    class UKSF_O_TK_INS_Suicide_Deadman: UKSF_O_TK_INS_Suicide_Driver {
        displayName = "Suicide Bomber (Deadman)";
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

    class TargetP_Inf_F;
    class UKSF_Target_Nopopup: TargetP_Inf_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Figure 11 Target - No Popup";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_Target_Nopopup.jpg);
        class EventHandlers {
            hitPart = "";
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
    class Sign_sphere10cm_EP1;
    class UKSF_Target_Moving: Sign_sphere10cm_EP1 {
        scope = 2;
        scopeCurator = 2;
        displayName = "Movable Figure 11 Target";
        editorCategory = "EdCat_Things";
        editorSubcategory = "EdSubcat_Targets";
        editorPreview = QPATHTOEF(common,data\previews\UKSF_Target_Nopopup.jpg);
        model = "\A3\Structures_F\Training\Target_PopUp_F.p3d";
        icon = "iconObject_5x4";
        class DestructionEffects {
        };
        class AnimationSources {
            class Terc {
                animPeriod = 0.35;
            };
        };
        hiddenSelections[] = { "camo", "target2", "target3" };
        hiddenSelectionsTextures[] = { "a3\structures_f\training\data\target_inf_co", "#(argb,8,8,3)color(0,0,0,0,ca)", "#(argb,8,8,3)color(0,0,0,0,ca)" };
        mapSize = 0.72;
        class SimpleObject {
            eden = 0;
            animate[] = {{"terc", 0}};
            hide[] = {};
            verticalOffset = 0.858;
            verticalOffsetWorld = 0;
            init = "''";
        };
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
            hitPart = "_this select 0 execVM '\A3\Structures_F\Training\data\scripts\TargetP_Inf_F_hitPart.sqf';";
        };
    };
};
