class CfgVehicles {
    class O_Soldier_base_F;
    class O_Soldier_F;
    class GVAR(Soldier_Underwear) : O_Soldier_F {
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
    class GVAR(Soldier_Base) : O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = QUOTE(ADDON);
        displayName = "Zir Base";
        nakedUniform = GVAR(U_Base);
        uniformClass = "CUP_O_TKI_Khet_Partug_06";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguagePER_F", "PersianHead_A3" };
        genericNames = "ZirMen";
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

    // militia
    class CUP_B_AlicePack_Khaki;
    class GVAR(Machine_Gunner_pack) : CUP_B_AlicePack_Khaki {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Yellow_M,5);
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

    #include "units\CfgUnitsMilitia.hpp"
    // #include "vehicles\CfgAntiAir.hpp"
    // #include "vehicles\CfgArtillery.hpp"
    // #include "vehicles\CfgMTLB.hpp"
    // #include "vehicles\CfgBTR.hpp"
    // #include "vehicles\CfgBuran.hpp"
    // #include "vehicles\CfgRG31.hpp"
    // #include "vehicles\CfgHeli.hpp"
    // #include "vehicles\CfgJet.hpp"
    // #include "vehicles\CfgStatic.hpp"
    // #include "vehicles\CfgT55.hpp"
    // #include "vehicles\CfgHEMTT.hpp"
    // #include "vehicles\CfgWiesel.hpp"
};
