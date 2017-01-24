class CBA_Extended_EventHandlers;
class CfgVehicles {    
    class O_Soldier_base_F;
    class O_Soldier_F;
    class GENFOR_Soldier_Underwear: O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "GENFOR Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = "GENFOR_U_Base";
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
    class GENFOR_Soldier_Base: O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_Genfor";
        displayName = "Genfor Base";
        nakedUniform = "GENFOR_U_Base";
        uniformClass = "SP_0000_Standard_FieldUniform_Hunter2";
        model = "\A3\Characters_F\OPFOR\o_soldier_01.p3d";
        weapons[] = {
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "Throw",
            "Put"
        };
        magazines[] = {
            "rhs_mag_rdg2_white"
        };
        respawnMagazines[] = {
            "rhs_mag_rdg2_white"
        };
        Items[] = {
            "ACE_EarPlugs",
            "ACE_MapTools",
            "ACE_Morphine",
            "ACE_Morphine",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot"
        };
        respawnItems[] = {
            "ACE_EarPlugs",
            "ACE_MapTools",
            "ACE_Morphine",
            "ACE_Morphine",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot",
            "ACE_quikClot"
        };
        respawnLinkedItems[] = {
            "ItemMap",
            "ItemCompass",
            "ItemWatch"
        };
        linkedItems[] = {
            "ItemMap",
            "ItemCompass",
            "ItemWatch"
        };
        accuracy = 2.3;
        camouflage = 1.2;
        cost = 90000;
        threat[] = {1,0.1,0.1};
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
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

    #include "units\CfgReg.hpp"
    #include "units\CfgPara.hpp"
    #include "units\CfgSF.hpp"
    #include "units\CfgRes.hpp"
    #include "units\CfgVeh.hpp"

    #include "vehicles\CfgApc.hpp"
    #include "vehicles\CfgBrdm.hpp"
    #include "vehicles\CfgHilux.hpp"
    #include "vehicles\CfgHmmwv.hpp"
    #include "vehicles\CfgLandRover.hpp"
    #include "vehicles\CfgUaz.hpp"
    #include "vehicles\CfgUral.hpp"
    #include "vehicles\CfgTank.hpp"
    #include "vehicles\CfgHeli.hpp"
    #include "vehicles\CfgJet.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgScopeZero.hpp"

    class B_AssaultPack_rgr;
    class GENFOR_B_R: B_AssaultPack_rgr {
        scope = 1;
        author = "UKSF";
        displayName = "Standard Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_RNOMAG: GENFOR_B_R {
        displayName = "Light Pack";
        class TransportMagazines {
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_Mark: GENFOR_B_R {
        displayName = "Marksman Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_762x39mm_tracer {
                magazine = "rhs_30Rnd_762x39mm_tracer";
                count = 6;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_Med: UKSF_B_Medic {
        scope = 1;
        displayName = "Genfor Medic Pack";
        class TransportMagazines {};
    };
    class GENFOR_B_MG: GENFOR_B_R {
        displayName = "MG Pack";
        class TransportMagazines {
            class _xx_rhs_100Rnd_762x54mmR_green {
                magazine = "rhs_100Rnd_762x54mmR_green";
                count = 5;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class SP_Carryall_Hunter2;
    class GENFOR_B_AA: SP_Carryall_Hunter2 {
        scope = 1;
        author = "UKSF";
        displayName = "AA Pack";
        class TransportMagazines {
            class _xx_rhs_mag_9k38_rocket {
                magazine = "rhs_mag_9k38_rocket";
                count = 4;
            };
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_AT7: GENFOR_B_AA {
        displayName = "RPG Pack";
        class TransportMagazines {
            class _xx_rhs_rpg7_PG7VL_mag {
                magazine = "rhs_rpg7_PG7VL_mag";
                count = 6;
            };
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_AT: GENFOR_B_AA {
        displayName = "AT Pack";
        class TransportMagazines {
            class _xx_Titan_AT {
                magazine = "Titan_AT";
                count = 2;
            };
            class _xx_Titan_AP {
                magazine = "Titan_AP";
                count = 2;
            };
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_Sl: GENFOR_B_R {
        displayName = "Section Leader Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
            class _xx_rhs_VOG25 {
                magazine = "rhs_VOG25";
                count = 10;
            };
        };
    };
    class UK3CB_BAF_B_Bergen_MTP_JTAC_L_A;
    class GENFOR_B_Radio: UK3CB_BAF_B_Bergen_MTP_JTAC_L_A {
        scope = 1;
        displayName = "Radio Pack";
        class eventhandlers {
            init = "this addItemCargoGlobal [""ACRE_PRC117F"", 2]";
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };

    class GENFOR_B_P_R: SP_Carryall_Hunter2 {
        scope = 1;
        author = "UKSF";
        displayName = "Para Standard Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_P_RNOMAG: SP_Carryall_Hunter2 {
        scope = 1;
        author = "UKSF";
        displayName = "Para Light Pack";
        class TransportMagazines {
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_P_B: GENFOR_B_P_R {
        displayName = "Para Breacher Pack";
        class TransportMagazines {
            class _xx_UK3CB_BAF_12G_Pellets {
                magazine = "UK3CB_BAF_12G_Pellets";
                count = 5;
            };
            class _xx_UK3CB_BAF_12G_Slugs {
                magazine = "UK3CB_BAF_12G_Slugs";
                count = 5;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
            class _xx_DemoCharge_Remote_Mag {
                magazine = "DemoCharge_Remote_Mag";
                count = 4;
            };
        };
    };
    class GENFOR_B_P_MG: SP_Carryall_Hunter2 {
        scope = 1;
        displayName = "Para MG Pack";
        class TransportMagazines {
            class _xx_200Rnd_65x39_cased_Box_Tracer {
                magazine = "200Rnd_65x39_cased_Box_Tracer";
                count = 5;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_P_AT: GENFOR_B_P_MG {
        displayName = "Para AT Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_rpg7_PG7VL_mag {
                magazine = "rhs_rpg7_PG7VL_mag";
                count = 6;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_P_AA: GENFOR_B_P_MG {
        displayName = "Para AA Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_9k32_rocket {
                magazine = "rhs_mag_9k32_rocket";
                count = 4;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };

    class GENFOR_B_SF_R: GENFOR_B_R {
        displayName = "SF Standard Pack";
        class TransportMagazines {
            class _xx_30Rnd_556x45_Stanag {
                magazine = "30Rnd_556x45_Stanag";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_SF_RNOMAG: GENFOR_B_SF_R {
        displayName = "SF Light Pack";
        class TransportMagazines {
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_SF_MG: GENFOR_B_SF_R {
        displayName = "SF MG Pack";
        class TransportMagazines {
            class _xx_200Rnd_65x39_cased_Box_Tracer {
                magazine = "200Rnd_65x39_cased_Box_Tracer";
                count = 4;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class GENFOR_B_SF_AT: GENFOR_B_SF_R {
        displayName = "SF AT Pack";
        class TransportMagazines {
            class _xx_30Rnd_556x45_Stanag {
                magazine = "30Rnd_556x45_Stanag";
                count = 10;
            };
            class _xx_RPG32_F {
                magazine = "RPG32_F";
                count = 3;
            };
            class _xx_RPG32_HE_F {
                magazine = "RPG32_HE_F";
                count = 3;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
    class SP_Carryall_ATacsFG;
    class GENFOR_B_SF_P: SP_Carryall_ATacsFG {
        scope = 1;
        author = "UKSF";
        displayName = "SF Patrol Pack";
        class TransportMagazines {
            class _xx_rhs_30Rnd_545x39_AK {
                magazine = "rhs_30Rnd_545x39_AK";
                count = 10;
            };
            class _xx_rhs_mag_rgd5 {
                magazine = "rhs_mag_rgd5";
                count = 5;
            };
            class _xx_rhs_mag_rdg2_white {
                magazine = "rhs_mag_rdg2_white";
                count = 5;
            };
        };
    };
};