#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Soldier_Underwear),
            QGVAR(Soldier_Base),
            QGVAR(Rifleman),
            QGVAR(Squad_Leader),
            QGVAR(sf_autorifleman),
            QGVAR(Rifleman_LAT),
            QGVAR(Sharpshooter),
            QGVAR(Machine_Gunner),
            QGVAR(Rifleman_HAT),
            QGVAR(Officer),
            QGVAR(sf_sfc),
            QGVAR(Heli_Pilot),
            QGVAR(Sniper),
            QGVAR(Crewman),
            QGVAR(Rifleman_AA),
            QGVAR(sf_operator),
            QGVAR(sf_grenadier),
            QGVAR(sf_LAT),
            QGVAR(Officer_HQ),
            QGVAR(Signaller),

            // Vehicles
            QGVAR(MTVR),
            QGVAR(MTVR_Ammo),
            QGVAR(MTVR_Refuel),
            QGVAR(MTVR_Repair),
            QGVAR(Leopard2A6),
            QGVAR(T55),
            QGVAR(Boxer_HMG),
            QGVAR(Boxer_GMG),
            QGVAR(Boxer_Empty),
            QGVAR(MBT_Arty),
            QGVAR(APC_AA),
            QGVAR(Heli_Light_Dynamic),
            QGVAR(Heli_Light),
            QGVAR(AW159),
            QGVAR(AW159_Unarmed),
            QGVAR(CH_54_Armed),
            QGVAR(CH_54_Transport),
            QGVAR(CH47F),
            QGVAR(JAS39),
            QGVAR(C130J),
            QGVAR(LSV_01_unarmed_SF),
            QGVAR(LSV_01_armed_SF),
            QGVAR(M1025_M2),
            QGVAR(M1025_M240),
            QGVAR(M1025_Mk19),
            QGVAR(M1036_TOW),

            // statics
            QGVAR(Mini_Radar_Dish),
            QGVAR(rugged_radar_small),
            QGVAR(rugged_radar_large),
            QGVAR(SAM_System),
            QGVAR(Ship_MRLS),
            QGVAR(ZU23),
            QGVAR(L134A1),
            QGVAR(M252),
            QGVAR(M119),
            QGVAR(Dragon),
            QGVAR(HMG_02),
            QGVAR(HMG_02_high),
            QGVAR(RBS70),
            QGVAR(auto_hmg),
            QGVAR(Radar_System),

        };
        weapons[] = {
            QGVAR(arifle_SPAR_03_blk_F_optic_AMS),
            QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight),
            QGVAR(CUP_arifle_G36C_VFG_ACE_optic_MRCO_2D_acc_flashlight_suppressed),
            QGVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed),
            QGVAR(CUP_arifle_G36K_RIS_AG36_ACE_optic_MRCO_2D_acc_flashlight),
            QGVAR(CUP_arifle_MG36_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed),
            QGVAR(srifle_DMR_02_camo_F_optic_KHS_old)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_common", "uksf_eug"};
        author = QUOTE(UKSF);
        authors[] = {"Bridgford.A"};
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgWorlds {
    class GenericNames {
        class FrenchMen {
            class FirstNames {
                firstName1 = "Jean";
                firstName2 = "Pierre";
                firstName3 = "Michel";
                firstName4 = "André";
                firstName5 = "Philippe";
                firstName6 = "René";
                firstName7 = "Louis";
                firstName8 = "Jacques";
                firstName9 = "François";
                firstName10 = "Alain";
                firstName11 = "Nicolas";
                firstName12 = "Patrick";
                firstName13 = "Christian";
                firstName14 = "Daniel";
                firstName15 = "Paul";
                firstName16 = "Marc";
                firstName17 = "Bernard";
                firstName18 = "Yves";
                firstName19 = "Roger";
                firstName20 = "Robert";
            };
            class LastNames {
                lastName1 = "Dubois";
                lastName2 = "Durand";
                lastName3 = "Lefebvre";
                lastName4 = "Moreau";
                lastName5 = "Simon";
                lastName6 = "Laurent";
                lastName7 = "Michel";
                lastName8 = "Thomas";
                lastName9 = "Robert";
                lastName10 = "Petit";
                lastName11 = "Girard";
                lastName12 = "André";
                lastName13 = "Lefèvre";
                lastName14 = "Roux";
                lastName15 = "Fournier";
                lastName16 = "Morel";
                lastName17 = "Dupont";
                lastName18 = "Lambert";
                lastName19 = "Bonnet";
                lastName20 = "François";
            };
        };
    };
};

#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

