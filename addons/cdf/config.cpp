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

            QGVAR(T55),
            QGVAR(BTR80A),
            QGVAR(BTR80),
            QGVAR(MTLB),
            QGVAR(Buran_Transporter),
            QGVAR(Buran_Medical),
            QGVAR(Buran_Cargo),
            QGVAR(RG31_HMG),
            QGVAR(RG31_GMG),
            QGVAR(RG31_Tpt),
            QGVAR(HEMTT_Ammo),
            QGVAR(HEMTT_Transport),
            QGVAR(HEMTT_Fuel),
            QGVAR(HEMTT_Repair),
            QGVAR(M777),
            QGVAR(SMERCH),
            QGVAR(2S7M),

            QGVAR(Patriot),
            QGVAR(Patriot_Radar),
            QGVAR(Wiesel_AA),
            QGVAR(Wiesel_Radar),
            QGVAR(Shilka),

            GVAR(Wiesel_MK20),
            GVAR(Wiesel_AT),

            QGVAR(Gripen),
            QGVAR(TU16),

            QGVAR(CH146_Tpt),
            QGVAR(CH146_AT),
            QGVAR(CH146_Armed),
            QGVAR(Li2),

            QGVAR(MK6),
            QGVAR(M134A),
            QGVAR(SPG9),
            QGVAR(RBS70),
            QGVAR(ZU23),
            QGVAR(Praetorian),
            QGVAR(Searchlight)
        };
        weapons[] = {
            QGVAR(CUP_arifle_M4A1_MOE_winter_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_arifle_M4A1_BUIS_GL_CUP_acc_Flashlight_CUP_optic_HensoldtZO_RDS),
            QGVAR(LMG_Zafir_F_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_srifle_M14_DMR_CUP_optic_HensoldtZO_RDS),
            QGVAR(CUP_srifle_G22_blk_ACE_optic_LRPS_2D),
            QGVAR(CUP_arifle_HK_M27_VFG_CUP_optic_HensoldtZO_RDS_muzzle_snds_M)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common",
            "ace_medical_treatment",
            "CUP_Weapons_LoadOrder",
            "CUP_Creatures_People_LoadOrder"
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

