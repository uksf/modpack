#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {
            "UK3CB_BAF_LLM_Flashlight_Far_Black",
            "ACE_NVG_Pilot",
            "UK3CB_BAF_L85A2_RIS_Elcan",
            "UK3CB_BAF_L22A2_Elcan",
            "UK3CB_BAF_L85A2_UGL_Elcan",
            "UK3CB_BAF_L110A3_Elcan",
            "UK3CB_BAF_L129A1_Grippod_Acog",
            "UK3CB_BAF_L115A3_LRPS",
            "UK3CB_BAF_L115A3_DE_LRPS",
            "UK3CB_BAF_L135A1_LRPS",
            "CUP_arifle_M4A1_Acog",
            "CUP_lmg_M240_LDS",
            "CUP_launch_Mk153Mod0_Rubber",
            "CUP_launch_FIM92Stinger_Rubber",
            "CUP_AGM114L_Hellfire_II_Launcher_W",
            "CUP_AGM114N_Hellfire_II_Launcher_W",
            "UK3CB_BAF_Javelin_CLU"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "cba_jr",
            "ace_chemlights",
            "UK3CB_BAF_Equipment",
            "UK3CB_BAF_Equipment_ACRE_compatibility",
            "UK3CB_BAF_Weapons",
            "UK3CB_BAF_Weapons_Ammo",
            "UK3CB_BAF_Weapons_L110",
            "UK3CB_BAF_Weapons_L115",
            "UK3CB_BAF_Weapons_L119",
            "UK3CB_BAF_Weapons_L1A1",
            "UK3CB_BAF_Weapons_Launchers",
            "UK3CB_BAF_Weapons_SmallArms",
            "UK3CB_BAF_Weapons_Static",
            "UK3CB_BAF_Weapons_Accessories",
            "UK3CB_BAF_Weapons_ACE",
            "CUP_Weapons_Stinger",
            "CUP_Weapons_Curator",
            "CUP_Weapons_Ammunition",
            "CUP_Weapons_VehicleWeapons",
            "CUP_Creatures_StaticWeapons",
            "CUP_Weapons_DynamicLoadout",
            "CUP_Weapons_AK",
            "CUP_Weapons_M16",
            "CUP_Weapons_M240",
            "CUP_Weapons_SMAW",
            "DynaSound_DS_w_MINIGUN762",
            "DynaSound_DS_w_HMG",
            "DynaSound_DS_w_GMG",
            "DynaSound_DS_w_CoaxMG",
            "DynaSound_DS_w_LRR",
            "DynaSound_DS_w_Zafir",
            "acre_sys_prc117f",
            "JSRS_SOUNDMOD_Explosions",
            "3CB_L7A2",
            "3CB_L135A1"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
#include "CfgAmmo.hpp"
#include "CfgEffects.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFunctions.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
