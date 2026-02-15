class CfgVehicles {
    class O_Soldier_base_F;
    class O_Soldier_F;
    class GVAR(Soldier_Underwear) : O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        displayName = "Cartel Underwear";
        model = "\A3\Characters_F\Common\basicbody";
        uniformClass = QGVAR(U_Base);
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
        displayName = "ACR Base";
        nakedUniform = QGVAR(U_Base);
        uniformClass = "U_I_C_Soldier_Bandit_2_F";
        model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
        identityTypes[] = { "LanguageFRE_F", "Head_Euro" };
        genericNames = "SpanishMen";
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

    class B_Messenger_Olive_F;
    class GVAR(Autorifleman_pack) : B_Messenger_Olive_F {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_60Rnd_TE1_Green_Tracer_545x39_AK74M_M,8);
        };
    };

    class CUP_B_RPGPack_Khaki;
    class GVAR(LAT_pack) : CUP_B_RPGPack_Khaki {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_OG7_M,1);
            MACRO_ADDMAGAZINE(CUP_PG7V_M,2);
        };
    };

    class GVAR(GL_pack) : B_Messenger_Olive_F {
        scope = 1;
        class TransportMagazines {
            MACRO_ADDMAGAZINE(CUP_1Rnd_HE_GP25_M,10);
        };
    };

#include "units\CfgArmedCivs.hpp"
#include "units\CfgCommandos.hpp"
#include "units\CfgCouriers.hpp"
#include "units\CfgMilitia.hpp"
#include "vehicles\CfgMilitiaVehicles.hpp"
#include "vehicles\CfgCommandoVehicles.hpp"
};
