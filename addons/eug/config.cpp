#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Rifleman),
            QGVAR(Squad_Leader),
            QGVAR(Officer),
            QGVAR(LMG_Gunner),
            QGVAR(HMG_Gunner),
            QGVAR(Rifleman_Light_AT),
            QGVAR(Rifleman_Heavy_AT),
            QGVAR(Rifleman_AA),
            QGVAR(Radio_Operator),
            QGVAR(Combat_Medic),
            QGVAR(SF_Rifleman),
            QGVAR(SF_Teamlead),
            QGVAR(SF_Medic),
            QGVAR(SF_AT),
            QGVAR(SF_LMG),
            QGVAR(SF_Comms),
            QGVAR(SF_Sniper),
            QGVAR(SF_Rifleman_Para),
            QGVAR(SF_Teamlead_Para),
            QGVAR(SF_AT_Para),
            QGVAR(SF_LMG_Para),
            QGVAR(Tank_Crew),
            QGVAR(Vehicle_Crew),
            QGVAR(Heli_Crew),
            QGVAR(Jet_Pilot),

            QGVAR(Pantsir),
            QGVAR(ZSU_23_4),
            QGVAR(UAZ_AA),
            QGVAR(Bardelas),
            QGVAR(Ural_Radar),
            QGVAR(SON_9A_Radar),
            QGVAR(Buran_APC),
            QGVAR(BTR_80A),
            QGVAR(BTR_90),
            QGVAR(BTR_90HQ),
            QGVAR(BMP3),
            QGVAR(Humvee_AGS),
            QGVAR(Humvee_Dshkm),
            QGVAR(MTVR_Transport),
            QGVAR(MTVR_Ammo),
            QGVAR(MTVR_Fuel),
            QGVAR(MTVR_Repair),
            QGVAR(T_90A),
            QGVAR(T72),
            QGVAR(T55),
            QGVAR(T_14_Armata),
            QGVAR(Namer),
            QGVAR(Podnos),
            QGVAR(Dshkm),
            QGVAR(Dshkm_Mini),
            QGVAR(AGS_30),
            QGVAR(Kornet),
            QGVAR(Zu_23),
            QGVAR(Igla_Pod),
            QGVAR(D_30),

            QGVAR(Mi_28N),
            QGVAR(Mi_24_Superhind),
            QGVAR(Kasatka_Unarmed),
            QGVAR(Gripen),
            QGVAR(Shikra),
            QGVAR(Shikra_Stealth),
            QGVAR(Li_2)
        };
        weapons[] = {
            QGVAR(CUP_arifle_M16A4_GL_SSQN_AR_ACOG),
            QGVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG2),
            QGVAR(CUP_arifle_M16A4_Base_CUP_optic_ACOG_TA01B_Black),
            QGVAR(CUP_arifle_Colt727_M203_CUP_optic_ACOG_TA01B_RMR_Black),
            QGVAR(CUP_arifle_Colt727),
            QGVAR(LMG_Mk200_black_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),
            QGVAR(MMG_01_tan_F_CUP_optic_ACOG_TA01B_RMR_Blackbipod_02_F_blk),
            QGVAR(CUP_arifle_AKMN_railed_desert_CUP_muzzle_snds_KZRZP_AK762_desertCUP_optic_HensoldtZO_low_RDS_desert),
            QGVAR(CUP_arifle_AKS74U_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),
            QGVAR(CUP_launch_MAAWS_CUP_optic_MAAWS_Scope),
            QGVAR(CUP_arifle_RPK74M_railed_CUP_muzzle_TGPACUP_optic_HensoldtZO_low_RDS),
            QGVAR(srifle_DMR_05_tan_f_muzzle_snds_93mmg_tanACE_optic_LRPS_2Dbipod_02_F_arid)
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

#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
