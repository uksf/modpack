class CfgVehicles {
    class O_Soldier_base_F;
    class O_Soldier_F;
    class GVAR(Soldier_Underwear) : O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "CDF Underwear";
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
        displayName = "CDF Base";
        nakedUniform = GVAR(U_Base);
        uniformClass = "CUP_U_B_BDUv2_gloves_dirty_Winter";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguageRUS_F", "Head_Euro" };
        genericNames = "ChernoMen";
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

    class GVAR(Soldier_Base_Woodland) : GVAR(Soldier_Base) {
        editorSubcategory = QGVAR(men_woodland);
        uniformClass = "CUP_U_B_BDUv2_gloves_Tigerstripe";
    };

    // alpine
    class Alpine_Backpack_Compact;
    class GVAR(Squad_Leader_pack) : Alpine_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,10);
            MACRO_ADDMAGAZINE(UGL_FlareYellow_F,5);
            MACRO_ADDMAGAZINE(1Rnd_Smoke_Grenade_shell,5);
        };
    };
    class GVAR(Machine_Gunner_pack) : Alpine_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(150Rnd_762x54_Box,3);
        };
    };
    class tfw_ilbe_blade_b;
    class GVAR(Signaller_pack) : tfw_ilbe_blade_b {
        scope = 1;
        displayName = "Radio Backpack";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SmokeShellOrange,2);
            MACRO_ADDMAGAZINE(SmokeShellPurple,2);
            MACRO_ADDMAGAZINE(SmokeShell,3);
        };
    };
    class GVAR(Operator_Pack) : Alpine_Backpack_Compact {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(APERSTripMine_Wire_Mag,2);
        };
    };

    // woodland
    class CUP_B_Kombat_Radio_Olive;
    class GVAR(Squad_Leader_pack_Woodland) : CUP_B_Kombat_Radio_Olive {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,10);
            MACRO_ADDMAGAZINE(UGL_FlareYellow_F,5);
            MACRO_ADDMAGAZINE(1Rnd_Smoke_Grenade_shell,5);
        };
    };
    class CUP_O_RUS_Patrol_bag_Green;
    class GVAR(Machine_Gunner_pack_Woodland) : CUP_O_RUS_Patrol_bag_Green {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(150Rnd_762x54_Box,3);
        };
    };
    class B_RadioBag_01_wdl_F;
    class GVAR(Signaller_pack_Woodland) : B_RadioBag_01_wdl_F {
        scope = 1;
        displayName = "Radio Backpack";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SmokeShellOrange,2);
            MACRO_ADDMAGAZINE(SmokeShellPurple,2);
            MACRO_ADDMAGAZINE(SmokeShell,3);
        };
    };
    class B_AssaultPack_rgr;
    class GVAR(Operator_Pack_Woodland) : B_AssaultPack_rgr {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(APERSTripMine_Wire_Mag,2);
        };
    };

#include "units\CfgUnitsAlpine.hpp"
#include "units\CfgUnitsWoodland.hpp"
#include "vehicles\CfgAntiAir.hpp"
#include "vehicles\CfgArtillery.hpp"
#include "vehicles\CfgMTLB.hpp"
#include "vehicles\CfgBTR.hpp"
#include "vehicles\CfgBuran.hpp"
#include "vehicles\CfgRG31.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgStatic.hpp"
#include "vehicles\CfgT55.hpp"
#include "vehicles\CfgHEMTT.hpp"
#include "vehicles\CfgWiesel.hpp"
};
