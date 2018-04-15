#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "Inegal_F",
            "Inegal_C",
            "Inegal_O",
            "Inegal_MED",
            "Inegal_MG",
            "Inegal_Mark",
            "Inegal_AA",
            "Inegal_ATE",
            "Inegal_ATJ",
            "Inegal_Sniper",
            "Inegal_FAC",
            "Inegal_FDF_S",
            "Inegal_FDF_V",
            "Inegal_FDF_B",
            "Inegal_FDF_Sh",
            "Inegal_FDF_A",
            "Inegal_FDF_Se",
            "Inegal_Diablerie_S",
            "Inegal_Diablerie_C",
            "Inegal_Diablerie_G",
            "Inegal_Diablerie_Su",
            "Inegal_Diablerie_B",
            "Inegal_Diablerie_Sh",
            "Inegal_Diablerie_A",
            "Inegal_Diablerie_Se",
            "Inegal_Diablerie_As",
            "Inegal_Recrues_C",
            "Inegal_Recrues_L",
            "Inegal_Recrues_R",
            "Inegal_Crew_HP",
            "Inegal_Crew_HC",
            "Inegal_Crew_C",
            "Inegal_Crew_P",

            "Inegal_LandRover_Unarmed",
            "Inegal_LandRover_MG",
            "Inegal_LandRover_GL",
            "Inegal_LandRover_FDF_Unarmed",
            "Inegal_LandRover_FDF_MG",
            "Inegal_LandRover_FDF_GL",
            "Inegal_VAB_Unarmed",
            "Inegal_VAB_HMG",
            "Inegal_VAB_GMG",
            "Inegal_VAB_D_Unarmed",
            "Inegal_VAB_D_HMG",
            "Inegal_VAB_D_GMG",
            "Inegal_APC_VBCI",
            "Inegal_TRM_Covered",
            "Inegal_TRM_Open",
            "Inegal_TRM_D_Covered",
            "Inegal_TRM_D_Open",
            "Inegal_TRM_R_Covered",
            "Inegal_TRM_R_Open",
            "Inegal_TRM_Ammo",
            "Inegal_TRM_Repair",
            "Inegal_TRM_Fuel",
            "Inegal_Tank_Leclerc",
            "Inegal_Heli_AW101",
            "Inegal_Heli_AH6",
            "Inegal_Heli_MH6",
            "Inegal_Heli_FDF_MH6",
            "Inegal_Heli_D_MH6",
            "Inegal_Jet_A149",
            "Inegal_Static_HMG",
            "Inegal_Static_GMG",
            "Inegal_Static_Mortar",

            "Inegal_B_F",
            "Inegal_B_C",
            "Inegal_B_Med",
            "Inegal_B_MG",
            "Inegal_B_Mark",
            "Inegal_B_AT_AT13",
            "Inegal_B_Sniper",
            "Inegal_B_FAC",
            "Inegal_B_FDF_B",
            "Inegal_B_FDF_A",
            "Inegal_B_D_Specialist",
            "Inegal_B_D_Commander",
            "Inegal_B_D_Surgeon",
            "Inegal_B_D_Brute",
            "Inegal_B_D_Sharpshooter",
            "Inegal_B_D_Arsonist",
            "Inegal_B_D_Sentinel",
            "Inegal_B_D_Assassin",
            "Inegal_B_R_C",
            "Inegal_B_R_L",
            "Inegal_B_R_R"
        };
        weapons[] = {
            "CUP_arifle_Mk16_STD_FG_black",
            "CUP_arifle_Mk16_STD_EGLM_black_Aimpoint",
            "CUP_arifle_Mk16_CQC_EGLM_black_Aimpoint",
            "CUP_arifle_Mk16_STD_black_Aimpoint",
            "CUP_lmg_Mk48_des_Aimpoint",
            "CUP_srifle_M110_Leupold",
            "srifle_DMR_02_F_PMII",
            "CUP_srifle_M107_Base_PMII",
            "arifle_SPAR_01_blk_F_eotech_lamp_bipod",
            "arifle_SPAR_01_GL_blk_F_eotech",
            "arifle_SPAR_03_blk_F_dms_bipod",
            "arifle_SPAR_01_blk_F_erco_laser_bipod_suppressor",
            "arifle_SPAR_01_GL_blk_F_erco_laser_suppressor",
            "arifle_SPAR_03_blk_F_dms_bipod_suppressor_laser",
            "CUP_arifle_Mk16_CQC_EGLM_black_Eotech",
            "CUP_arifle_Mk16_CQC_black_Eotech",
            "SMG_05_F_Aco",
            "Inegal_Diablerie_Vest",
            "Inegal_Diablerie_Helmet"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"

class CfgWorlds {
    class GenericNames {
        class FrenchMen {
            class FirstNames {
                Nathan = "Nathan";
                Lucas = "Lucas";
                Leo = "Léo";
                Enzo = "Enzo";
                Louis = "Louis";
                Gabriel = "Gabriel";
                Jules = "Jules";
                Timeo = "Timéo";
                Hugo = "Hugo";
                Arthur = "Arthur";
                Ethan = "Ethan";
                Raphael = "Raphaël";
                Mael = "Maël";
                Tom = "Tom";
                Noah = "Noah";
                Mathis = "Mathis";
                Theo = "Théo";
                Adam = "Adam";
                Nolan = "Nolan";
                Clement = "Clément";
                Nicolas = "Nicolas";
                Pierre = "Pierre";
                David = "David";
                Sebastien = "Sébastien";
                Thomas = "Thomas";
                Alexandre = "Alexandre";
                Vincent = "Vincent";
                Romain = "Romain";
                Antoine = "Antoine";
                Kevin = "Kévin";
                Mathieu = "Mathieu";
                Arnaud = "Arnaud";
                Paul = "Paul";
                Florian = "Florian";
                Alexis = "Alexis";
                Quentin = "Quentin";
                Loic = "Loïc";
                Valentin = "Valentin";
                Matthieu = "Matthieu";
                Adrien = "Adrien";
                Julien = "Julien";
                Anthony = "Anthony";
                Come = "Côme";
                Jacques = "Jacques";
                Ludovic = "Ludovic";
                Benoit = "Benoît";
                Jonathan = "Jonathan";
                Pierre_olivier = "Pierre-Olivier";
                Pierre_nicolas = "Pierre-Nicolas";
            };
            class LastNames {
                Martin = "Martin";
                Bernard = "Bernard";
                Dubois = "Dubois";
                Robert = "Robert";
                Richard = "Richard";
                Petit = "Petit";
                Durand = "Durand";
                Leroy = "Leroy";
                Moreau = "Moreau";
                Simon = "Simon";
                Laurent = "Laurent";
                Lefebvre = "Lefebvre";
                Michel = "Michel";
                Garcia = "Garcia";
                Bertrand = "Bertrand";
                Roux = "Roux";
                Fournier = "Fournier";
                Morel = "Morel";
                Girard = "Girard";
                Andre = "Andre";
                Lefevre = "Lefevre";
                Mercier = "Mercier";
                Dupont = "Dupont";
                Lambert = "Lambert";
                Bonnet = "Bonnet";
                Martinez = "Martinez";
                Legrand = "Legrand";
                Garnier = "Garnier";
                Faure = "Faure";
                Rousseau = "Rousseau";
                Blanc = "Blanc";
                Guerin = "Guerin";
                Muller = "Muller";
                Henry = "Henry";
                Roussel = "Roussel";
                Perrin = "Perrin";
                Morin = "Morin";
                Gauthier = "Gauthier";
                Dumont = "Dumont";
                Lopez = "Lopez";
                Fontaine = "Fontaine";
                Chevalier = "Chevalier";
                Robin = "Robin";
                Masson = "Masson";
                Sanchez = "Sanchez";
                Gerard = "Gerard";
                Boyer = "Boyer";
                Lemaire = "Lemaire";
                Benoist = "Benoist";
            };
        };
    };
};
