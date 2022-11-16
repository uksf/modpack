#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Rifleman),
            QGVAR(Squad_Leader),
            GVAR(Autorifleman),
            QGVAR(Rifleman_LAT),
            QGVAR(Sharpshooter),
            QGVAR(Armour_Crewman),
            QGVAR(Officer),
            QGVAR(Signaller),
            QGVAR(Heli_Pilot),
            QGVAR(Sniper),
            QGVAR(Crewman),
            QGVAR(Jet_Pilot),
            QGVAR(Rifleman_AA),
            QGVAR(Paratrooper),
            QGVAR(Machine_Gunner),
            QGVAR(Rifleman_HAT),

            QGVAR(Operator),

            QGVAR(T72),
            QGVAR(Pandur2),
            QGVAR(BVP),
            QGVAR(Buran_Transporter),
            QGVAR(Buran_Medical),
            QGVAR(Buran_Cargo),
            QGVAR(Dingo_Mg),
            QGVAR(Dingo_GL),
            QGVAR(Tatra_Ammo),
            QGVAR(Tatra_Transport),
            QGVAR(Tatra_Fuel),
            QGVAR(Tatra_MG),
            QGVAR(Tatra_Repair),
            QGVAR(RM_70),
            QGVAR(Sholef),
            QGVAR(Wiesel_AA),
            QGVAR(Wiesel_Radar),

            QGVAR(f35),
            QGVAR(Gripen),
            QGVAR(Mi35),
            QGVAR(AH1Z),
            QGVAR(Yabhon),
            QGVAR(Li2),
            QGVAR(Mi17),

            QGVAR(Podnos),
            QGVAR(ags),
            QGVAR(M2_Raised),
            QGVAR(M2_Low),
            QGVAR(TOW)
        };
        weapons[] = {
            QGVAR(CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D),
            QGVAR(CUP_arifle_ACRC_EGLM_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D),
            QGVAR(LMG_03_F_CUP_acc_FlashlightACE_optic_MRCO_2D),
            QGVAR(CUP_srifle_SVD_wdl_CUP_optic_PSO_1_1_open),
            QGVAR(CUP_arifle_ACRC_blk_556),
            QGVAR(CUP_arifle_ACRC_blk_556_ACE_optic_MRCO_2D),
            QGVAR(CUP_srifle_M2010_blk_ACE_optic_LRPS_2D),
            QGVAR(UKSF_ACR_ACR_CUP_arifle_ACRC_blk_556_CUP_acc_FlashlightACE_optic_MRCO_2D_CUP_acc_FlashlightACE_optic_MRCO_2D),
            QGVAR(CUP_lmg_MG3_rail_ACE_optic_MRCO_2D)
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
