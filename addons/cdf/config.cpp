#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Rifleman),
            QGVAR(Squad_Leader),
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
            QGVAR(Machine_Gunner),
            QGVAR(Rifleman_HAT),
            QGVAR(Operator),

            QGVAR(Rifleman_Woodland),
            QGVAR(Squad_Leader_Woodland),
            QGVAR(Rifleman_LAT_Woodland),
            QGVAR(Sharpshooter_Woodland),
            QGVAR(Armour_Crewman_Woodland),
            QGVAR(Officer_Woodland),
            QGVAR(Signaller_Woodland),
            QGVAR(Heli_Pilot_Woodland),
            QGVAR(Sniper_Woodland),
            QGVAR(Crewman_Woodland),
            QGVAR(Rifleman_AA_Woodland),
            QGVAR(Machine_Gunner_Woodland),
            QGVAR(Rifleman_HAT_Woodland),
            QGVAR(Operator_Woodland),

            QGVAR(T55),
            QGVAR(BTR80A),
            QGVAR(BTR80A_Woodland),
            QGVAR(BTR80),
            QGVAR(BTR80_Woodland),
            QGVAR(MTLB),
            QGVAR(MTLB_Woodland),
            QGVAR(Buran_Transporter),
            QGVAR(Buran_Transporter_Woodland),
            QGVAR(Buran_Medical),
            QGVAR(Buran_Medical_Woodland),
            QGVAR(Buran_Cargo),
            QGVAR(Buran_Cargo_Woodland),
            QGVAR(RG31_HMG),
            QGVAR(RG31_HMG_Woodland),
            QGVAR(RG31_GMG),
            QGVAR(RG31_GMG_Woodland),
            QGVAR(RG31_Tpt),
            QGVAR(RG31_Tpt_Woodland),
            QGVAR(HEMTT_Ammo),
            QGVAR(HEMTT_Ammo_Woodland),
            QGVAR(HEMTT_Transport),
            QGVAR(HEMTT_Transport_Woodland),
            QGVAR(HEMTT_Fuel),
            QGVAR(HEMTT_Fuel_Woodland),
            QGVAR(HEMTT_Repair),
            QGVAR(HEMTT_Repair_Woodland),
            QGVAR(M777),
            QGVAR(SMERCH),
            QGVAR(2S7M),
            QGVAR(M777_Woodland),
            QGVAR(SMERCH_Woodland),
            QGVAR(2S7M_Woodland),

            QGVAR(Patriot),
            QGVAR(Patriot_Radar),
            QGVAR(Wiesel_AA),
            QGVAR(Wiesel_Radar),
            QGVAR(Shilka),
            QGVAR(Shilka_Woodland),
            QGVAR(Wiesel_AA_Woodland),
            QGVAR(Wiesel_Radar_Woodland),

            QGVAR(Wiesel_MK20),
            QGVAR(Wiesel_MK20_Woodland),
            QGVAR(Wiesel_AT),
            QGVAR(Wiesel_AT_Woodland),

            QGVAR(Gripen),
            QGVAR(Gripen_Woodland),
            QGVAR(TU16),
            QGVAR(TU16_Woodland),

            QGVAR(CH146_Tpt),
            QGVAR(CH146_Tpt_Woodland),
            QGVAR(CH146_AT),
            QGVAR(CH146_AT_Woodland),
            QGVAR(CH146_Armed),
            QGVAR(CH146_Armed_Woodland),
            QGVAR(Li2),
            QGVAR(Li2_Woodland),

            QGVAR(MK6),
            QGVAR(MK6_Woodland),
            QGVAR(M134A),
            QGVAR(M134A_Woodland),
            QGVAR(SPG9),
            QGVAR(SPG9_Woodland),
            QGVAR(RBS70),
            QGVAR(RBS70_Woodland),
            QGVAR(ZU23),
            QGVAR(ZU23_Woodland),
            QGVAR(Praetorian),
            QGVAR(Searchlight),
            QGVAR(Searchlight_Woodland)
        };
        weapons[] = {
            // alphine
            QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_arifle_M4A1_BUIS_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),
            QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),
            QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M),

            // woodland
            QGVAR(CUP_arifle_M4A3_woodland_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_arifle_M4A1_BUIS_camo_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

class CfgWorlds {
    class GenericNames {
        class ChernoMen {
            class FirstNames {
                Ante = "Ante";
                Branimir = "Branimir";
                Davorin = "Davorin";
                Dinko = "Dinko";
                Dragan = "Dragan";
                Drazen = "Dražen";
                Eduard = "Eduard";
                Emil = "Emil";
                Franjo = "Franjo";
                Goran = "Goran";
                Hrvoje = "Hrvoje";
                Igor = "Igor";
                Ivan = "Ivan";
                Jakov = "Jakov";
                Josip = "Josip";
                Juraj = "Juraj";
                Kresimir = "Kresimir";
                Luka = "Luka";
                Mario = "Mario";
                Nikola = "Nikola";
                Ognjen = "Ognjen";
                Pero = "Pero";
                Roko = "Roko";
                Stjepan = "Stjepan";
                Tomislav = "Tomislav";
                Uros = "Uros";
                Vedran = "Vedran";
                Zoran = "Zoran";
            };
            class LastNames {
                Abramovic = "Abramovic";
                Babic = "Babic";
                Cavlovic = "Cavlovic";
                Delic = "Delic";
                Erceg = "Erceg";
                Frljic = "Frljic";
                Grgic = "Grgic";
                Horvat = "Horvat";
                Ivanovic = "Ivanovic";
                Juric = "Juristic";
                Kovacevic = "Kovacevic";
                Ljubic = "Ljubic";
                Milic = "Milic";
                Nikolic = "Nikolic";
                Oreskovic = "Oreskovic";
                Pavic = "Pavic";
                Radosevic = "Radosevic";
                Saric = "Saric";
                Tomic = "Tomic";
                Uzelac = "Uzelac";
                Vlahovic = "Vlahovic";
                Zoric = "Zoric";
            };
        };
    };
};

