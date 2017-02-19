class CfgVehicles {    
    class O_Soldier_base_F;
    class O_Soldier_F;
    class Inegal_Soldier_Underwear: O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "Inegal Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = "Inegal_U_Base";
        weapons[] = {
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "Throw",
            "Put"
        };
        magazines[]={};
        respawnMagazines[] = {};
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
    };
    class Inegal_Soldier_Base: O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_Inegal";
        displayName = "Inegal Base";
        nakedUniform = "Inegal_U_Base";
        uniformClass = "U_B_CTRG_Soldier_urb_3_F";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguageENGFRE_F", "Head_Euro" };
        genericNames = "FrenchMen";
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

    #include "units\CfgCombattants.hpp"
    #include "units\CfgFDF.hpp"
    #include "units\CfgDiablerie.hpp"
    #include "units\CfgRecrues.hpp"
    #include "units\CfgCrew.hpp"

    #include "vehicles\CfgLandRover.hpp"
    #include "vehicles\CfgVAB.hpp"
    #include "vehicles\CfgTRM.hpp"
    #include "vehicles\CfgVBCI.hpp"
    #include "vehicles\CfgLeclerc.hpp"
    #include "vehicles\CfgHeli.hpp"
    #include "vehicles\CfgJet.hpp"
    #include "vehicles\CfgStatic.hpp"    

    class B_FieldPack_oli;
    class Inegal_B_F: B_FieldPack_oli {
        scope = 1;
        author = "UKSF";
        displayName = "Fusilier Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_R3F_30Rnd_556x45_FAMAS {
                magazine = "R3F_30Rnd_556x45_FAMAS";
                count = 10;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
        class TransportBackpacks {};
    };
    class Inegal_B_C: Inegal_B_F {
        scope = 1;
        author = "UKSF";
        displayName = "Commander Pack";
        class TransportMagazines: TransportMagazines {
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 10;
            };
            class _xx_R3F_30Rnd_556x45_FAMAS {
                magazine = "R3F_30Rnd_556x45_FAMAS";
                count = 10;
            };
        };
    };
    class B_TacticalPack_oli;
    class Inegal_B_Med: B_TacticalPack_oli {
        scope = 1;
        author = "UKSF";
        displayName = "Medical Pack";
        class TransportWeapons {};
        class TransportMagazines {};
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 50;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 50;
            };
            class _xx_ACE_tourniquet {
                name = "ACE_tourniquet";
                count = 5;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 6;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 6;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 25;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 25;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 5;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 5;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
        class TransportBackpacks {};
    };
    class Inegal_B_MG: Inegal_B_F {
        scope = 1;
        author = "UKSF";
        displayName = "MG Pack";
        class TransportMagazines {
            class _xx_R3F_100Rnd_762x51_MINIMI {
                magazine = "R3F_100Rnd_762x51_MINIMI";
                count = 4;
            };
        };
        class TransportItems {};
    };
    class Inegal_B_Mark: Inegal_B_F {
        scope = 1;
        author = "UKSF";
        displayName = "Marksman Pack";
        class TransportMagazines {
            class _xx_R3F_10Rnd_762x51_FRF2 {
                magazine = "R3F_10Rnd_762x51_FRF2";
                count = 10;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_EntrenchingTool {
                name = "ACE_EntrenchingTool";
                count = 1;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
    };
    class Inegal_B_AA: Inegal_B_Med {
        scope = 1;
        author = "UKSF";
        displayName = "AA Pack";
        class TransportMagazines {
            class _xx_R3F_STINGER_mag {
                magazine = "R3F_STINGER_mag";
                count = 2;
            };
        };
        class TransportItems {};
    };
    class Inegal_B_AT_Eryx: Inegal_B_AA {
        scope = 1;
        author = "UKSF";
        displayName = "AT Eryx Pack";
        class TransportMagazines {
            class _xx_R3F_ERYX_Mag {
                magazine = "R3F_ERYX_Mag";
                count = 2;
            };
        };
    };
    class Inegal_B_Sniper: Inegal_B_Mark {
        scope = 1;
        author = "UKSF";
        displayName = "Sniper Pack";
        class TransportMagazines {
            class _xx_R3F_7Rnd_127x99_PGM {
                magazine = "R3F_7Rnd_127x99_PGM";
                count = 10;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_EntrenchingTool {
                name = "ACE_EntrenchingTool";
                count = 1;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_JTAC_H_A;
    class Inegal_B_FAC: UK3CB_BAF_B_Bergen_MTP_JTAC_H_A {
        scope = 1;
        author = "UKSF";
        displayName = "FAC Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_R3F_30Rnd_556x45_FAMAS {
                magazine = "R3F_30Rnd_556x45_FAMAS";
                count = 10;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
        class TransportBackpacks {};
    };
    class B_Carryall_cbr;
    class Inegal_B_FDF_B: B_Carryall_cbr {
        scope = 1;
        author = "UKSF";
        displayName = "FDF Brute Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_R3F_100Rnd_762x51_MINIMI {
                magazine = "R3F_100Rnd_762x51_MINIMI";
                count = 6;
            };
        };
        class TransportItems {};
        class TransportBackpacks {};
    };
    class Inegal_B_FDF_A: Inegal_B_FDF_B {
        scope = 1;
        author = "UKSF";
        displayName = "FDF Arsonist Pack";
        class TransportMagazines {
            class _xx_R3F_AT4CS_Mag {
                magazine = "R3F_AT4CS_Mag";
                count = 4;
            };
        };
    };
    class Inegal_B_D_Specialist: SP_Carryall_ATacsFG {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Specialist Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
                magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
                count = 16;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSBoundingMine_Range_Mag {
                magazine = "APERSBoundingMine_Range_Mag";
                count = 2;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
        class TransportBackpacks {};
    };
    class Inegal_B_D_Commander: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Commander Pack";
        class TransportMagazines {
            class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
                magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
                count = 10;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 10;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSBoundingMine_Range_Mag {
                magazine = "APERSBoundingMine_Range_Mag";
                count = 2;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 2;
            };
        };
    };
    class Inegal_B_D_Surgeon: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Surgeon Pack";
        class TransportMagazines {
            class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
                magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
                count = 16;
            };
        };
        class TransportItems {
            class _xx_ACE_packingBandage {
                name = "ACE_packingBandage";
                count = 30;
            };
            class _xx_ACE_elasticBandage {
                name = "ACE_elasticBandage";
                count = 30;
            };
            class _xx_ACE_tourniquet {
                name = "ACE_tourniquet";
                count = 5;
            };
            class _xx_ACE_ACE_atropine {
                name = "ACE_atropine";
                count = 5;
            };
            class _xx_ACE_ACE_adenosinee {
                name = "ACE_adenosine";
                count = 5;
            };
            class _xx_ACE_morphine {
                name = "ACE_morphine";
                count = 20;
            };
            class _xx_ACE_epinephrine {
                name = "ACE_epinephrine";
                count = 20;
            };
            class _xx_ACE_bloodIV_500 {
                name = "ACE_bloodIV_500";
                count = 5;
            };
            class _xx_ACE_bloodIV {
                name = "ACE_bloodIV";
                count = 5;
            };
            class _xx_ACE_personalAidKit {
                name = "ACE_personalAidKit";
                count = 1;
            };
            class _xx_ACE_surgicalKit {
                name = "ACE_surgicalKit";
                count = 1;
            };
        };
    };
    class Inegal_B_D_Brute: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Brute Pack";
        class TransportMagazines {
            class _xx_R3F_100Rnd_762x51_MINIMI {
                magazine = "R3F_100Rnd_762x51_MINIMI";
                count = 6;
            };
        };
        class TransportItems {};
    };
    class Inegal_B_D_Sharpshooter: SP_Carryall_ATacsFG {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Sharpshooter Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_ACE_20Rnd_762x51_Mk316_Mod_0_Mag {
                magazine = "ACE_20Rnd_762x51_Mk316_Mod_0_Mag";
                count = 8;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSBoundingMine_Range_Mag {
                magazine = "APERSBoundingMine_Range_Mag";
                count = 2;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
        class TransportBackpacks {};
    };
    class Inegal_B_D_Arsonist: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Arsonist Pack";
        class TransportMagazines {
            class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
                magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
                count = 10;
            };
            class _xx_R3F_AT4CS_Mag {
                magazine = "R3F_AT4CS_Mag";
                count = 4;
            };
        };
        class TransportItems {};
    };
    class Inegal_B_D_Sentinel: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Sentinel Pack";
        class TransportMagazines {
            class _xx_ACE_30Rnd_556x45_Stanag_Mk262_mag {
                magazine = "ACE_30Rnd_556x45_Stanag_Mk262_mag";
                count = 16;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSBoundingMine_Range_Mag {
                magazine = "APERSBoundingMine_Range_Mag";
                count = 2;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
    };
    class Inegal_B_D_Assassin: Inegal_B_D_Specialist {
        scope = 1;
        author = "UKSF";
        displayName = "Diablerie Assassin Pack";
        class TransportMagazines {
            class _xx_R3F_7Rnd_127x99_PEI_PGM {
                magazine = "R3F_7Rnd_127x99_PEI_PGM";
                count = 12;
            };
            class _xx_ClaymoreDirectionalMine_Remote_Mag {
                magazine = "ClaymoreDirectionalMine_Remote_Mag";
                count = 2;
            };
            class _xx_APERSMine_Range_Mag {
                magazine = "APERSMine_Range_Mag";
                count = 2;
            };
            class _xx_APERSTripMine_Wire_Mag {
                magazine = "APERSTripMine_Wire_Mag";
                count = 2;
            };
            class _xx_APERSBoundingMine_Range_Mag {
                magazine = "APERSBoundingMine_Range_Mag";
                count = 2;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 2;
            };
        };
        class TransportItems {
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker";
                count = 1;
            };
            class _xx_ACE_Cellphone {
                name = "ACE_Cellphone";
                count = 1;
            };
            class _xx_ACE_CableTie {
                name = "ACE_CableTie";
                count = 4;
            };
            class _xx_ACE_DefusalKit {
                name = "ACE_DefusalKit";
                count = 1;
            };
        };
    };
    class Inegal_B_R_C: B_FieldPack_oli {
        scope = 1;
        author = "UKSF";
        displayName = "Recrues Conscript Pack";
        class TransportWeapons {};
        class TransportMagazines {
            class _xx_R3F_30Rnd_556x45_FAMAS {
                magazine = "R3F_30Rnd_556x45_FAMAS";
                count = 4;
            };
            class _xx_R3F_25Rnd_556x45_FAMAS {
                magazine = "R3F_25Rnd_556x45_FAMAS";
                count = 3;
            };
            class _xx_R3F_25Rnd_556x45_TRACER_FAMAS {
                magazine = "R3F_25Rnd_556x45_TRACER_FAMAS";
                count = 2;
            };
        };
        class TransportItems {};
        class TransportBackpacks {};
    };
    class Inegal_B_R_L: Inegal_B_R_C {
        scope = 1;
        author = "UKSF";
        displayName = "Recrues Leader Pack";
        class TransportMagazines {
            class _xx_R3F_30Rnd_556x45_FAMAS {
                magazine = "R3F_30Rnd_556x45_FAMAS";
                count = 8;
            };
            class _xx_1Rnd_HE_Grenade_shell {
                magazine = "1Rnd_HE_Grenade_shell";
                count = 5;
            };
        };
    };
    class Inegal_B_R_R: Inegal_B_R_C {
        scope = 1;
        author = "UKSF";
        displayName = "Recrues Recruit Pack";
        class TransportMagazines {
            class _xx_R3F_25Rnd_556x45_FAMAS {
                magazine = "R3F_25Rnd_556x45_FAMAS";
                count = 5;
            };
            class _xx_R3F_25Rnd_556x45_TRACER_FAMAS {
                magazine = "R3F_25Rnd_556x45_TRACER_FAMAS";
                count = 5;
            };
        };
    };
};