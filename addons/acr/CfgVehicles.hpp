class CfgVehicles {
    class O_Soldier_base_F;
    class O_Soldier_F;
    class UKSF_ACR_Soldier_Underwear: O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "ACR Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = "ACR_U_Base";
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
    class UKSF_ACR_Soldier_Base: O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_ACR";
        displayName = "ACR Base";
        nakedUniform = "ACR_U_Base";
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
    class UKSF_ACR_Squad_Leader_pack: CUP_B_Kombat_Radio_Olive
    {
        scope = 1;
        class TransportMagazines
        {
            class _xx_1Rnd_HE_Grenade_shell {count = 11;magazine = "1Rnd_HE_Grenade_shell";};
        };
        class TransportItems{};
        class TransportWeapons{};
    };
    class CUP_B_ACRPara_m95;
    class UKSF_ACR_Autorifleman_pack: CUP_B_ACRPara_m95
    {
        scope = 1;
        class TransportMagazines
        {
            class _xx_CUP_100Rnd_TE4_Green_Tracer_556x45_M249 {count = 5;magazine = "CUP_100Rnd_TE4_Green_Tracer_556x45_M249";};
        };
        class TransportItems{};
        class TransportWeapons{};
    };
    class UKSF_ACR_Rifleman_LAT_pack: CUP_B_ACRPara_m95
    {
        scope = 1;
        class TransportMagazines
        {
            class _xx_CUP_OG7_M {count = 1;magazine = "CUP_OG7_M";};
            class _xx_CUP_PG7V_M {count = 2;magazine = "CUP_PG7V_M";};
        };
        class TransportItems{};
        class TransportWeapons{};
    };
    class CUP_B_GER_Medic_Flecktarn;
    class UKSF_ACR_Sharpshooter_pack: CUP_B_GER_Medic_Flecktarn
    {
        scope = 1;
        class TransportMagazines{};
        class TransportItems{};
        class TransportWeapons{};
    };
    class B_RadioBag_01_wdl_F;
    class UKSF_ACR_Signaller_pack: B_RadioBag_01_wdl_F
    {
        scope = 1;
        displayName = "Radio Backpack";
        class TransportMagazines
        {
            class _xx_SmokeShellOrange {count = 2;magazine = "SmokeShellOrange";};
            class _xx_SmokeShellPurple {count = 2;magazine = "SmokeShellPurple";};
            class _xx_SmokeShell {count = 3;magazine = "SmokeShell";};
            class _xx_CUP_HandGrenade_RGD5 {count = 2;magazine = "CUP_HandGrenade_RGD5";};
        };
        class TransportItems{};
        class TransportWeapons{};
    };
    class UKSF_ACR_Machine_Gunner_pack: CUP_B_ACRPara_m95
    {
        scope = 1;
        class TransportMagazines
        {
            class _xx_CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M {count = 4;magazine = "CUP_120Rnd_TE4_LRT4_Green_Tracer_762x51_Belt_M";};
        };
        class TransportItems{};
        class TransportWeapons{};
    };
    class UKSF_ACR_Rifleman_HAT_pack: CUP_B_ACRPara_m95
    {
        scope = 1;
        class TransportMagazines {};
    };
    class CUP_B_ACRScout_m95;
    class UKSF_ACR_Operator_Pack: CUP_B_ACRScout_m95
    {
        scope = 1;
        class TransportMagazines
        {
            class _xx_APERSMine_Range_Mag {count = 2;magazine = "APERSMine_Range_Mag";};
        };
    };
};
