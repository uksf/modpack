class CfgVehicles {
    class O_Soldier_F;
    class PROR_Soldier_Underwear : O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "PROR Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = "PROR_U_Base";
        weapons[] = { "Throw", "Put" };
        respawnWeapons[] = { "Throw", "Put" };
        magazines[] = {};
        respawnMagazines[] = {};
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
    };
    class O_Soldier_base_F;
    class PROR_Soldier_Base : O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_PROR";
        displayName = "PROR Base";
        nakedUniform = "PROR_U_Base";
        uniformClass = "CFP_U_FieldUniform_M81light";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguageENGFRE_F", "Head_Euro" };
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

#include "units\CfgInfantry.hpp"
#include "units\CfgCrew.hpp"
#include "units\CfgParas.hpp"
#include "units\CfgSF.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgLAV.hpp"
#include "vehicles\CfgM60.hpp"
#include "vehicles\CfgMRAP.hpp"
#include "vehicles\CfgPolaris.hpp"
#include "vehicles\CfgStatic.hpp"
#include "vehicles\CfgStriker.hpp"
#include "vehicles\CfgTRM.hpp"
#include "vehicles\CfgWiesel.hpp"

    class UK3CB_BAF_B_Carryall_OLI;
    class PROR_B_MG_Carryall : UK3CB_BAF_B_Carryall_OLI {
        scope = 1;
        author = "UKSF";
        displayName = "PROR MG Carryall";
        class TransportMagazines {
            class _xx_130Rnd_338_Mag {
                magazine = "130Rnd_338_Mag";
                count = 4;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 5;
            };
        };
    };
    class PROR_B_ATL_Carryall : UK3CB_BAF_B_Carryall_OLI {
        scope = 1;
        author = "UKSF";
        displayName = "PROR AT-L Carryall";
        class TransportMagazines {
            class _xx_MRAWS_HE_F {
                magazine = "MRAWS_HE_F";
                count = 2;
            };
            class _xx_MRAWS_HEAT_F {
                magazine = "MRAWS_HEAT_F";
                count = 2;
            };
        };
    };
    class PROR_B_ATH_Carryall : UK3CB_BAF_B_Carryall_OLI {
        scope = 1;
        author = "UKSF";
        displayName = "PROR AT-H Carryall";
        class TransportMagazines {
            class _xx_Vorona_HEAT {
                magazine = "Vorona_HEAT";
                count = 3;
            };
        };
    };
    class PROR_B_AA_Carryall : UK3CB_BAF_B_Carryall_OLI {
        scope = 1;
        author = "UKSF";
        displayName = "PROR AA Carryall";
        class TransportMagazines {
            class _xx_Titan_AA {
                magazine = "Titan_AA";
                count = 2;
            };
        };
    };

    class CFP_AssaultPack_M81;
    class PROR_B_SF_AssPack : CFP_AssaultPack_M81 {
        scope = 1;
        author = "UKSF";
        displayName = "PROR SF Ass Pack";
        class TransportMagazines {
            class _xx_9Rnd_45ACP_Mag {
                magazine = "9Rnd_45ACP_Mag";
                count = 3;
            };
            class _xx_CUP_30Rnd_556x45_Emag_Tracer_Yellow {
                magazine = "CUP_30Rnd_556x45_Emag_Tracer_Yellow";
                count = 4;
            };
            class _xx_ACE_M14 {
                magazine = "ACE_M14";
                count = 2;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 3;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 2;
            };
        };
    };
    class PROR_B_SF_TL_AssPack : PROR_B_SF_AssPack {
        scope = 1;
        author = "UKSF";
        displayName = "PROR SF Ass Pack (TL)";
        class TransportMagazines {
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 5;
            };
            class _xx_UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell {
                magazine = "UK3CB_BAF_1Rnd_SmokeRed_Grenade_shell";
                count = 3;
            };
            class _xx_9Rnd_45ACP_Mag {
                magazine = "9Rnd_45ACP_Mag";
                count = 3;
            };
            class _xx_CUP_30Rnd_556x45_Emag_Tracer_Yellow {
                magazine = "CUP_30Rnd_556x45_Emag_Tracer_Yellow";
                count = 4;
            };
            class _xx_ACE_M14 {
                magazine = "ACE_M14";
                count = 2;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 3;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 2;
            };
        };
    };
    class CFP_Kitbag_M81;
    class PROR_B_SF_Kitbag_AR : CFP_Kitbag_M81 {
        scope = 1;
        author = "UKSF";
        displayName = "PROR SF Kitbag (AR)";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_9Rnd_45ACP_Mag {
                magazine = "9Rnd_45ACP_Mag";
                count = 3;
            };
            class _xx_CUP_200Rnd_TE4_Yellow_Tracer_556x45_L110A1 {
                magazine = "CUP_200Rnd_TE4_Yellow_Tracer_556x45_L110A1";
                count = 2;
            };
            class _xx_ACE_M14 {
                magazine = "ACE_M14";
                count = 2;
            };
            class _xx_SmokeShell {
                magazine = "SmokeShell";
                count = 3;
            };
            class _xx_HandGrenade {
                magazine = "HandGrenade";
                count = 2;
            };
        };
    };
    class PROR_B_SF_MedicBag : CFP_Kitbag_M81 {
        scope = 1;
        author = "UKSF";
        displayName = "PROR SF Medic bag";
        class TransportItems {
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 50;
            };
            class _xx_ACE_bloodIV_250 {
                name = "ACE_bloodIV_250";
                count = 3;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 2;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 3;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 15;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 15;
            };
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 50;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
    };
};
