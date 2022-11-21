class CfgVehicles {
    class O_Soldier_base_F;
    class O_Soldier_F;
    class GVAR(Soldier_Underwear): O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "ACR Underwear";
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
    class GVAR(Soldier_Base): O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = QUOTE(ADDON);
        displayName = "ACR Base";
        nakedUniform = GVAR(U_Base);
        uniformClass = "CUP_U_B_CZ_WDL_NoKneepads";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] =  { "LanguagePOL_F", "Head_Euro" };
        genericNames = "CzechMen";
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
        threat[] = {1,0.1,0.1};
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

    #include "vehicles\CfgAntiAir.hpp"
    #include "vehicles\CfgArtillery.hpp"
    #include "vehicles\CfgBuran.hpp"
    #include "vehicles\CfgBVP.hpp"
    #include "vehicles\CfgDingo.hpp"
    #include "vehicles\CfgDrone.hpp"
    #include "vehicles\CfgHeli.hpp"
    #include "vehicles\CfgJet.hpp"
    #include "vehicles\CfgPandur.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgT72.hpp"
    #include "vehicles\CfgTatra.hpp"
    #include "units\CfgUnits.hpp"

    class CUP_B_Kombat_Radio_Olive;
    class GVAR(Squad_Leader_pack): CUP_B_Kombat_Radio_Olive {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,11);
        };
    };
    class CUP_B_ACRPara_m95;
    class GVAR(Autorifleman_pack): CUP_B_ACRPara_m95 {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_100Rnd_TE4_Green_Tracer_556x45_M249,5);
        };
    };
    class GVAR(Rifleman_LAT_pack): CUP_B_ACRPara_m95 {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_OG7_M,1);
            MACRO_ADDMAGAZINE(CUP_PG7V_M,2);
        };
    };
    class CUP_B_GER_Medic_Flecktarn;
    class GVAR(Sharpshooter_pack): CUP_B_GER_Medic_Flecktarn {
        scope = 1;
    };
    class B_RadioBag_01_wdl_F;
    class GVAR(Signaller_pack): B_RadioBag_01_wdl_F {
        scope = 1;
        displayName = "Radio Backpack";
        class TransportMagazines {
            MACRO_ADDMAGAZINE(SmokeShellOrange,2);
            MACRO_ADDMAGAZINE(SmokeShellPurple,2);
            MACRO_ADDMAGAZINE(SmokeShell,3);
            MACRO_ADDMAGAZINE(CUP_HandGrenade_RGD5,2);
        };
    };
    class GVAR(Machine_Gunner_pack): CUP_B_ACRPara_m95 {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M,4);
        };
    };
    class GVAR(Rifleman_HAT_pack): CUP_B_ACRPara_m95 {
        scope = 1;
        class TransportMagazines {};
    };
    class CUP_B_ACRScout_m95;
    class GVAR(Operator_Pack): CUP_B_ACRScout_m95 {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(APERSMine_Range_Mag,2);
        };
    };
};
