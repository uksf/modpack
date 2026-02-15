class CfgVehicles {
    class O_Soldier_F;
    class GVAR(Soldier_Underwear) : O_Soldier_F {
        author = "UKSF";
        scope = 1;
        scopeCurator = 0;
        side = 2;
        displayName = "EUG Underwear";
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
    class O_Soldier_base_F;
    class GVAR(Soldier_Base) : O_Soldier_base_F {
        author = "UKSF";
        scope = 0;
        side = 2;
        faction = QUOTE(ADDON);
        displayName = "EUG Base";
        nakedUniform = QGVAR(U_Base);
        uniformClass = "CUP_U_B_BDUv2_gloves_desert";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USArmy\CUP_U_BDUv2_gloves.p3d";
        // identityTypes[] = { "LanguagePOL_F", "Head_Euro" };
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

    #include "units\CfgUnits.hpp"

    #include "vehicles\CfgAntiAir.hpp"
    #include "vehicles\CfgAPC.hpp"
    #include "vehicles\CfgHeli.hpp"
    #include "vehicles\CfgHumvee.hpp"
    #include "vehicles\CfgJet.hpp"
    #include "vehicles\CfgMtvr.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgTank.hpp"

    class B_Kitbag_cbr;
    class GVAR(Rifleman_Light_AT_pack): B_Kitbag_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_RPG32_F {
                count = 3;
                magazine = "RPG32_F";
            };
            class _xx_RPG32_HE_F {
                count = 2;
                magazine = "RPG32_HE_F";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(Rifleman_Heavy_AT_pack): B_Kitbag_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_Vorona_HEAT {
                count = 1;
                magazine = "Vorona_HEAT";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(LMG_Gunner_pack): B_Kitbag_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_200Rnd_65x39_cased_Box {
                count = 3;
                magazine = "200Rnd_65x39_cased_Box";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(HMG_Gunner_pack): B_Kitbag_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_150Rnd_93x64_Mag {
                count = 4;
                magazine = "150Rnd_93x64_Mag";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };

    class CUP_B_GER_Medic_Desert;
    class GVAR(Combat_Medic_pack): CUP_B_GER_Medic_Desert {
        scope = 1;
        class TransportMagazines {};
        class TransportItems {
            class _xx_ACE_elasticBandage {
                count = 20;
                name = "ACE_elasticBandage";
            };
            class _xx_ACE_packingBandage {
                count = 20;
                name = "ACE_packingBandage";
            };
            class _xx_ACE_epinephrine {
                count = 5;
                name = "ACE_epinephrine";
            };
            class _xx_ACE_morphine {
                count = 5;
                name = "ACE_morphine";
            };
            class _xx_ACE_splint {
                count = 5;
                name = "ACE_splint";
            };
            class _xx_ACE_tourniquet {
                count = 5;
                name = "ACE_tourniquet";
            };
            class _xx_ACE_surgicalKit {
                count = 1;
                name = "ACE_surgicalKit";
            };
            class _xx_ACE_salineIV_500 {
                count = 4;
                name = "ACE_salineIV_500";
            };
            class _xx_ACE_salineIV_250 {
                count = 4;
                name = "ACE_salineIV_250";
            };
            class _xx_ACE_salineIV {
                count = 2;
                name = "ACE_salineIV";
            };
        };
        class TransportWeapons {};
    };

    class B_AssaultPack_cbr;
    class GVAR(SF_Medic_pack): B_AssaultPack_cbr {
        scope = 1;
        class TransportMagazines {};
        class TransportItems {
            class _xx_ACE_elasticBandage {
                count = 20;
                name = "ACE_elasticBandage";
            };
            class _xx_ACE_packingBandage {
                count = 20;
                name = "ACE_packingBandage";
            };
            class _xx_ACE_epinephrine {
                count = 5;
                name = "ACE_epinephrine";
            };
            class _xx_ACE_morphine {
                count = 5;
                name = "ACE_morphine";
            };
            class _xx_ACE_splint {
                count = 5;
                name = "ACE_splint";
            };
            class _xx_ACE_tourniquet {
                count = 5;
                name = "ACE_tourniquet";
            };
        };
        class TransportWeapons {};
    };
    class GVAR(SF_AT_pack): B_AssaultPack_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_MAAWS_HEDP_M {
                count = 2;
                magazine = "CUP_MAAWS_HEDP_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(SF_LMG_pack): B_AssaultPack_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_CUP_60Rnd_545x39_AK74M_M {
                count = 10;
                magazine = "CUP_60Rnd_545x39_AK74M_M";
            };
        };
        class TransportItems {};
        class TransportWeapons {};
    };
    class GVAR(SF_Sniper_pack): B_AssaultPack_cbr {
        scope = 1;
        class TransportMagazines {
            class _xx_10Rnd_93x64_DMR_05_Mag {
                count = 4;
                magazine = "10Rnd_93x64_DMR_05_Mag";
            };
        };
        class TransportItems {
            class _xx_ACE_elasticBandage {
                count = 10;
                name = "ACE_elasticBandage";
            };
        };
        class TransportWeapons {};
    };

    class UK3CB_BAF_B_Bergen_TAN_JTAC_H_A;
    class GVAR(SF_Comms_pack): UK3CB_BAF_B_Bergen_TAN_JTAC_H_A {
        scope = 1;
        class TransportMagazines {};
        class TransportItems {};
        class TransportWeapons {};
    };
};
