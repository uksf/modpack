class CfgVehicles {
    class I_Soldier_base_F;
    class I_Soldier_F;
    class GVAR(Soldier_Underwear) : I_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "Zir Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = GVAR(U_Base);
        weapons[] = {
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "Throw",
            "Put"
        };
        magazines[] = {};
        respawnMagazines[] = {};
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
    };
    class GVAR(soldier_Base) : I_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = QUOTE(ADDON);
        displayName = "Zgf Base";
        nakedUniform = GVAR(U_Base);
        uniformClass = "CUP_U_B_BDUv2_desert";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguagePER_F", "Head_TK" };
        genericNames = "ZgfMen";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
        accuracy = 2.3;
        camouflage = 1.2;
        cost = 90000;
        threat[] = { 1, 0.1, 0.1 };
        class Wounds {
            tex[] = {};
            mat[] = {
                "A3\Characters_F\BLUFOR\Data\clothing1.rvmat",
                "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
                "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat",
                "A3\Characters_F\Common\Data\basicbody.rvmat",
                "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
                "A3\Characters_F\Common\Data\basicbody_injury.rvmat",
                "A3\Characters_F\Common\Data\coveralls.rvmat",
                "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
                "A3\Characters_F\Common\Data\coveralls_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
                "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_old.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
                "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
                "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
            };
        };
    };

    class B_FieldPack_cbr;
    class GVAR(Machine_Gunner_pack) : B_FieldPack_cbr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Red_M,4);
        };
    };

    class CUP_B_RPGPack_Khaki;
    class GVAR(lat_pack) : CUP_B_RPGPack_Khaki {
        scope = 1;
        displayName = "RPG Backpack";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_PG7V_M,3);
        };
    };

    #include "units\CfgUnitsSoldiers.hpp"
    #include "vehicles\CfgTigrs.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgTrucks.hpp"
};
