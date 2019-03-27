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
#include "vehicles\CfgVAB.hpp"
    // #include "vehicles\CfgTRM.hpp"
    // #include "vehicles\CfgVBCI.hpp"
    // #include "vehicles\CfgLeclerc.hpp"
    // #include "vehicles\CfgHeli.hpp"
    // #include "vehicles\CfgJet.hpp"
    // #include "vehicles\CfgStatic.hpp"

    class B_FieldPack_oli; // Base class
    class PROR_B_R : B_FieldPack_oli { // Custom class, inheriting from base. Custom class needs to be in units[] array in config.cpp
        scope = 1;
        author = "UKSF";
        displayName = "Rifleman Pack";
        class TransportWeapons {}; // Weapons
        class TransportMagazines { // Magazines
            class _xx_30Rnd_556x45_Stanag { // Classname is irrelevant, but must be unique to the others. Naming convention is _xx_<magazine class name>
                magazine = "30Rnd_556x45_Stanag"; // Exact classname of the magazine (note property name is magazine)
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
        class TransportItems { // Items
            class _xx_ACE_M26_Clacker {
                name = "ACE_M26_Clacker"; // Exact classname of the item (note property name is name)
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
    // class Inegal_B_C : Inegal_B_F {
    //     displayName = "Commander Pack";
    //     class TransportMagazines : TransportMagazines {
    //         class _xx_1Rnd_HE_Grenade_shell {
    //             magazine = "1Rnd_HE_Grenade_shell";
    //             count = 10;
    //         };
    //         class _xx_30Rnd_556x45_Stanag {
    //             magazine = "30Rnd_556x45_Stanag";
    //             count = 10;
    //         };
    //     };
    // };
    // class B_TacticalPack_oli;
    // class Inegal_B_Med : B_TacticalPack_oli {
    //     scope = 1;
    //     author = "UKSF";
    //     displayName = "Medical Pack";
    //     class TransportWeapons {};
    //     class TransportMagazines {};
    //     class TransportItems {
    //         class _xx_ACE_packingBandage {
    //             name = "ACE_packingBandage";
    //             count = 50;
    //         };
    //         class _xx_ACE_elasticBandage {
    //             name = "ACE_elasticBandage";
    //             count = 50;
    //         };
    //         class _xx_ACE_tourniquet {
    //             name = "ACE_tourniquet";
    //             count = 5;
    //         };
    //         class _xx_ACE_ACE_atropine {
    //             name = "ACE_atropine";
    //             count = 6;
    //         };
    //         class _xx_ACE_ACE_adenosinee {
    //             name = "ACE_adenosine";
    //             count = 6;
    //         };
    //         class _xx_ACE_morphine {
    //             name = "ACE_morphine";
    //             count = 25;
    //         };
    //         class _xx_ACE_epinephrine {
    //             name = "ACE_epinephrine";
    //             count = 25;
    //         };
    //         class _xx_ACE_bloodIV_500 {
    //             name = "ACE_bloodIV_500";
    //             count = 5;
    //         };
    //         class _xx_ACE_bloodIV {
    //             name = "ACE_bloodIV";
    //             count = 5;
    //         };
    //         class _xx_ACE_personalAidKit {
    //             name = "ACE_personalAidKit";
    //             count = 1;
    //         };
    //         class _xx_ACE_surgicalKit {
    //             name = "ACE_surgicalKit";
    //             count = 1;
    //         };
    //     };
    //     class TransportBackpacks {};
    // };
};
