#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_ACR_Rifleman",
            "UKSF_ACR_Squad_Leader",
            "UKSF_Autorifleman",
            "UKSF_ACR_Rifleman_LAT",
            "UKSF_ACR_Sharpshooter",
            "UKSF_ACR_Armour_Crewman",
            "UKSF_ACR_Officer",
            "UKSF_ACR_Signaller",
            "UKSF_ACR_Heli_Pilot",
            "UKSF_ACR_Sniper",
            "UKSF_ACR_Crewman",
            "UKSF_ACR_Jet_Pilot",
            "UKSF_ACR_Rifleman_AA",
            "UKSF_ACR_Paratrooper",
            "UKSF_ACR_Machine_Gunner",
            "UKSF_ACR_Rifleman_HAT",

            "UKSF_ACR_Operator",

            "UKSF_ACR_T72",
            "UKSF_ACR_Pandur2",
            "UKSF_ACR_BVP",
            "UKSF_ACR_Buran_Transporter",
            "UKSF_ACR_Buran_Medical",
            "UKSF_ACR_Buran_Cargo",
            "UKSF_ACR_Dingo_Mg",
            "UKSF_ACR_Dingo_GL",
            "UKSF_ACR_Tatra_Ammo",
            "UKSF_ACR_Tatra_Transport",
            "UKSF_ACR_Tatra_Fuel",
            "UKSF_ACR_Tatra_MG",
            "UKSF_ACR_Tatra_Repair",
            "UKSF_ACR_RM_70",
            "UKSF_ACR_Sholef",
            "UKSF_ACR_Wiesel_AA",
            "UKSF_ACR_Wiesel_Radar",

            "UKSF_ACR_f35",
            "UKSF_ACR_Gripen",
            "UKSF_ACR_Mi35",
            "UKSF_ACR_AH1Z",
            "UKSF_ACR_Yabhon",
            "UKSF_ACR_Li2",
            "UKSF_ACR_Mi17",

            "UKSF_ACR_Podnos",
            "UKSF_ACR_ags",
            "UKSF_ACR_M2_Raised",
            "UKSF_ACR_M2_Low",
            "UKSF_ACR_TOW"
        };
        weapons[] = {
            "UKSF_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D",
            "UKSF_ACR_CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D",
            "UKSF_ACR_LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D",
            // "UKSF_ACR_CUP_launch_RPG7V",
            "UKSF_ACR_CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open",
            "UKSF_ACR_CUP_arifle_ACRC_blk_556",
            "UKSF_ACR_CUP_arifle_ACRC_blk_556_ACE_optic_MRCO_2D",
            // "UKSF_ACR_CUP_hgun_CZ75",
            "UKSF_ACR_CUP_srifle_M2010_blk_ACE_optic_LRPS_2D",
            "UKSF_ACR_UKSF_ACR_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D_CUP_acc_FlashlightACE_optic_MRCO_2D",
            // "UKSF_ACR_CUP_launch_FIM92Stinger_Loaded",
            "UKSF_ACR_CUP_lmg_MG3_rail_ACE_optic_MRCO_2D"
            // "UKSF_ACR_launch_I_Titan_short_F"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common",

            // not sure if these are needed??
            "ace_medical_treatment",
            "A3_Weapons_F",
            "CUP_Weapons_ACR",
            "CUP_Creatures_Military_ACR",
            "A3_Characters_F",
            "CuratorOnly_Characters_F_OPFOR",
            "CUP_Weapons_RPG7",
            "CUP_Weapons_SVD",
            "A3_Characters_F_Tank_Headgear",
            "CUP_Weapons_CZ75",
            "CUP_Weapons_M2010",
            "CUP_Weapons_Stinger",
            "CUP_Weapons_MG3"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

class CfgWorlds {
    class GenericNames {
        class CzechMen {
            class FirstNames {
                Ales = "Ales";
                Alexandr = "Alexandr";
                Alexej = "Alexej";
                Alojz = "Alojz";
                Andel = "Andel";
                Andrej = "Andrej";
                Anton = "Anton";
                Antonin = "Antonin";
                Arnost = "Arnost";
                Augustin = "Augustin";
                Bartolomej = "Bartolomej";
                Beda = "Beda";
                Bedrich = "Bedrich";
                Benes = "Benes";
                Blazej = "Blazej";
                Bohdan = "Bohdan";
                Bohumil = "Bohumil";
                Bohumir = "Bohumir";
                Bohuslav = "Bohuslav";
                Bonifac = "Bonifac";
                Bozidar = "Bozidar";
                Branislav = "Branislav";
                Bronislav = "Bronislav";
                Cenek = "Cenek";
                Cernobog = "Cernobog";
            };
            class LastNames {
                Novakova = "Novakova";
                Novak = "Novak";
                Svobodova = "Svobodova";
                Svoboda = "Svoboda";
                Novotna = "Novotna";
                Novotny = "Novotny";
                Dvorakova = "Dvorakova";
                Dvorak = "Dvorak";
                Cerna = "Cerna";
                Cerny = "Cerny";
                Prochazkova = "Prochazkova";
                Prochazka = "Prochazka";
                Kucera = "Kucera";
                Kucerova = "Kucerova";
                Vesela = "Vesela";
                Horakova = "Horakova";
                Vesely = "Vesely";
                Horak = "Horak";
                Krejci = "Krejci";
                Marek = "Marek";
                Pospisilova = "Pospisilova";
                Pokorna = "Pokorna";
                Markova = "Markova";
                Pokorny = "Pokorny";
                Pospisil = "Pospisil";
            };
        };
    };
};
