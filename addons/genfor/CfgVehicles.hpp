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
};