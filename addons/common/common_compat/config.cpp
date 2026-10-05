#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common",
            "Alpine_Vests_Config",
            "Black_Vests_Config",
            "G_Headbands",
            "greenmag_main",
            "EAWS_EF2000",
            "mbg_killhouses_a3",
            "HAFM_Navy_Core",
            "ffaa_casas_af",
            "HAFM_Navy_Config",
            "A3_Data_F_ParticleEffects",
            "Blastcore_VEP",
            "CUP_WheeledVehicles_LR",
            "rksla3_cvwp",
            "gx_drones_compat_rksl_cvwp",
            "CUP_AirVehciles_MH47E",
            "CUP_CAMisc_ACR_Dog",
            "A3_Props_F_Globe_Military_Ammo",
            "A3_Dubbing_Radio_F",
            "A3_Dubbing_Radio_F_EXP",
            "A3_Dubbing_Radio_F_Enoch",
            "CUP_Dubbing_Radio_CZ_ACR_c",
            "CUP_Dubbing_Radio_CZ_c",
            "CUP_Dubbing_Radio_EN_c",
            "CUP_Dubbing_Radio_EN_BAF_c",
            "CUP_Dubbing_Radio_EN_PMC_c",
            "CUP_Dubbing_Radio_RU_c",
            "CUP_Dubbing_Radio_TK_c",
            "A3_Animals_F_Snakes",
            "A3_Boat_F_Beta_Boat_Transport_01",
            "A3_Boat_F_Boat_Transport_01",
            "A3_Boat_F_Gamma_Boat_Transport_01",
            "A3_Characters_expEden_Loyalists",
            "A3_Characters_expEden_proAAF",
            "A3_expEden",
            "A3_expEden_characters",
            "A3_Props_F_Enoch_Military_Equipment",
            "A3_Props_F_Globe_Civilian_Gallery",
            "A3_Props_F_Globe_Civilian_InfoBoards",
            "A3_Props_F_Globe_Items",
            "A3_Props_F_Globe_Items_Decorative",
            "A3_Props_F_Globe_Items_Documents",
            "A3_Props_F_Globe_Military_Camps",
            "A3_Props_F_Globe_Military_Equipment",
            "A3_Structures_F_EPB_Civ_Camping",
            "A3_Structures_F_Globe_Infrastructure",
            "A3_Structures_F_Globe_Items_Electronics",
            "A3_Weapons_F_Globe_Items",
            "A400M",
            "ace_medical_engine",
            "acre_sys_gestures",
            "Air_Globe_UAV_02",
            "cba_xeh",
            "dagger_island_summer",
            "HAFM_EC635",
            "HAFM_Navy_Config",
            "Jbad_ConstructionCrane",
            "Jbad_Misc_Powerline",
            "Missiles",
            "PaddleMod",
            "Props_Globe_Civilian_Camping",
            "Props_Globe_Humanitarian_Camps",
            "Props_Globe_Humanitarian_Supplies",
            "Props_Globe_Items_Electronics",
            "Props_Globe_Items_Tools",
            "Props_Globe_Particles",
            "rksla3_aw159",
            "rnc_misc",
            "Structures_Globe_Civilian_Constructions",
            "Structures_Globe_Industrial_PowerLines",
            "Structures_Globe_Industrial_Tanks",
            "Structures_Globe_Items_Airport",
            "Structures_Globe_Items_Sport",
            "Structures_Globe_Signs_City_Road",
            "Structures_Globe_Training_SkeetMachine",
            "UK3CB_BAF_Weapons_Accessories"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

// Third-party classes that declare EventHandlers without inheritance drop CBA XEH (and the ACE inits it carries).
class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class Animal_Base_F;
    class B_crew_F;
    class B_CTRG_soldier_M_medic_F;
    class B_G_Soldier_F;
    class B_G_Soldier_GL_F;
    class B_officer_F;
    class B_recon_TL_F;
    class B_Soldier_03_f;
    class B_Soldier_SL_F;
    class B_Soldier_TL_F;
    class B_W_Soldier_F;
    class Book_01_F;
    class Book_01_large;
    class Book_01_small;
    class Book_02_F;
    class C_man_hunter_1_F;
    class CombatBoot_base;
    class FloatingStructure_F;
    class FlowerBouquet_base_F;
    class Furniture_Residental_base_F;
    class GalleryDioramaUnit_01_base_F;
    class GasTank_01_base_F;
    class Helicopter_Base_F;
    class HelicopterWreck;
    class I_Soldier_base_F;
    class I_soldier_F;
    class Infostand_base_F;
    class Items_base_F;
    class Land_AirHorn_01_F;
    class Land_Balloon_01_air_F;
    class Land_Balloon_01_water_F;
    class Land_CampingChair_V2_F;
    class Land_Chemlight_Blue_noLight;
    class Land_Chemlight_Green_noLight;
    class Land_Chemlight_Red_noLight;
    class Land_Chemlight_Yellow_noLight;
    class Land_FMradio_F;
    class Land_IntravenStand_01_base_F;
    class Land_Jbad_PowLines_Conc2L;
    class Land_Laptop_02_unfolded_F;
    class Land_Laptop_03_base_F;
    class Land_Laptop_03_black_F;
    class Land_Laptop_03_black_NATO_F;
    class Land_Laptop_03_sand_F;
    class Land_Laptop_03_sand_NATO_F;
    class Land_MapBoard_01_Wall_Orange_F;
    class Land_MultiScreenComputer_01_base_F;
    class Land_Orange_01_F;
    class Land_PCSet_01_screen_EdenEditor_F;
    class Land_Photoframe_01_broken_F;
    class Land_Photoframe_01_F;
    class Land_Photos_V3_F;
    class Land_Photos_V4_F;
    class Land_Portable_generator_F;
    class Land_PortableHelipadLight_01_F;
    class Land_PortableLongRangeRadio_F;
    class Land_PortableLongRangeRadioMilitary_F;
    class Land_PowerLine_01_pole_transformer_F;
    class Land_powerline_02_pole_junction_nest_a_f;
    class Land_PowLines_Transformer_F;
    class Land_Pumpkin_01_F;
    class Land_SurvivalRadio_F;
    class Land_TripodScreen_01_large_F;
    class Land_WhiteBoard_Orange_F;
    class Lantern_01_base_F;
    class Laptop_CTRG_01;
    class Leaflet_05_F;
    class Leaflet_05_New_F;
    class Leaflet_05_Old_F;
    class Logic;
    class O_T_Soldier_F;
    class Photoframe_icon;
    class PlaneWreck;
    class PortableHelipadLight_01_blue_F;
    class PortableHelipadLight_01_green_F;
    class PortableHelipadLight_01_red_F;
    class PortableHelipadLight_01_white_F;
    class PortableHelipadLight_01_yellow_F;
    class PowerLines_Small_base_F;
    class RoadBarrier_small_F;
    class RoadBarrier_small_v2;
    class RoadCone_L_F;
    class RoadCone_L_v2;
    class Rubber_duck_base_F;
    class Ship_F;
    class Tank_F;
    class Thing;
    class TripodScreen_CTRG_large_01;
    class UAV_02_base_F;
    class C_man_1;
    class C_man_w_worker_F_dgtl;
    class I_E_Helipilot_F;
    class I_E_Man_Base_F;
    class O_Soldier_base_F;
    class A400M_wreck_F : PlaneWreck {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class AirHorn_01_klaxon : Land_AirHorn_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_L_Soldier_Base_F : B_G_Soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_crew_F : B_crew_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_engineer_Future_G : B_Soldier_03_f {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_medic_F : B_CTRG_soldier_M_medic_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_officer_F : B_officer_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_recon_TL_F : B_recon_TL_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_ScottAlsworth : B_officer_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_Soldier_SL_01_F : B_Soldier_SL_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_Soldier_SL_02_F : B_Soldier_SL_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_Story_Soldier_TL_01_F : B_Soldier_TL_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_UAV_02_LM_G : UAV_02_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class B_W_Story_Protagonist_01_F : B_W_Soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Book_01_random : Book_01_small {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Book_01_random_F : Book_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Book_02_random : Book_01_large {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Book_02_random_F : Book_02_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class C_Story_Oldman_01_F : C_man_hunter_1_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class CanisterFuel_Full : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Chemlight_Blue_light : Land_Chemlight_Blue_noLight {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Chemlight_Green_light : Land_Chemlight_Green_noLight {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Chemlight_Red_light : Land_Chemlight_Red_noLight {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Chemlight_Yellow_light : Land_Chemlight_Yellow_noLight {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class CombatBoot_random : CombatBoot_base {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class DiaryImages_Altis_random : Land_Photos_V3_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class DiaryImages_AltisStratis_random : Land_Photos_V3_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class DiaryImages_Stratis_random : Land_Photos_V3_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class FireExtinguisher_Full : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class FlowerBouquet_random : FlowerBouquet_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class FMradio_sportGame_01 : Land_FMradio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class GalleryDioramaUnit_01_IDAP_Doggo : GalleryDioramaUnit_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class GalleryDioramaUnit_01_IDAP_UAV : GalleryDioramaUnit_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class GasTank_01_full_base_G : GasTank_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_052C : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_ABurke : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_Admiral : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_BUYAN : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_CB90 : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_EC635Wreck : HelicopterWreck {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_FREMM : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_GunBoat : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_MEKO_TN : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_Replenishment : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class HAFM_Russen : Ship_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_C_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_G_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_P_Soldier_base_F : I_Soldier_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_Story_Soldier_01_F : I_soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class I_Story_Soldier_GL_01_F : B_G_Soldier_GL_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class IntravenStand_01_randomBag : Land_IntravenStand_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Jbad_CraneCon : Tank_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Jbad_Lamps_base_powerline : PowerLines_Small_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Balloon_01_air_blue : Land_Balloon_01_air_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Balloon_01_water_blue : Land_Balloon_01_water_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Camping_Light_F : FloatingStructure_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_InfoStand_V2_IDAP_random_F : Infostand_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_IPPhone_01_base_F : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Jbad_Pole_1 : Jbad_Lamps_base_powerline {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Jbad_Pole_Speaker : Land_Jbad_PowLines_Conc2L {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Jbad_Pole_withlight : Land_Jbad_PowLines_Conc2L {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Jbad_PowLineB : Jbad_Lamps_base_powerline {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Laptop_03_black_NATO_random_F : Land_Laptop_03_black_NATO_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Laptop_03_sand_NATO_random_F : Land_Laptop_03_sand_NATO_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Laptop_unfolded_AAN_01_F : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Laptop_unfolded_AAN_02_F : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Leaflet_NorthenBala_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Leaflet_Balavu_F : Land_Leaflet_NorthenBala_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Leaflet_Central_tanoa_F : Land_Leaflet_NorthenBala_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Leaflet_Lijn_Islands_F : Land_Leaflet_NorthenBala_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Leaflet_North_Tanoa_F : Land_Leaflet_NorthenBala_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_MapBoard_01_Wall_Orange_random_F : Land_MapBoard_01_Wall_Orange_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_PCSet_01_screen_random_F : Land_PCSet_01_screen_EdenEditor_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Photoframe_01_broken_random_F : Land_Photoframe_01_broken_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_Photoframe_01_random_F : Land_Photoframe_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_PortableHelipadLight_01_off : Land_PortableHelipadLight_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_powerline_02_pole_junction_nest_a_bird : Land_powerline_02_pole_junction_nest_a_f {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_TripodScreen_01_large_VIDEO_F : Land_TripodScreen_01_large_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Land_WhiteBoard_Orange_random_F : Land_WhiteBoard_Orange_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_black_empty : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_black_off : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_blue_empty : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_blue_off : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_green_empty : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_green_off : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_random : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_random_empty : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_random_off : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_red_empty : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Lantern_01_red_off : Lantern_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_02_unfolded_ofp_video : Land_Laptop_02_unfolded_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_03_black_StaticNoise : Land_Laptop_03_black_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_03_G_DiaryImagesAltis_random : Land_Laptop_03_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_03_G_DiaryImagesAltisStratis_random : Land_Laptop_03_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_03_G_DiaryImagesStratis_random : Land_Laptop_03_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_03_sand_StaticNoise : Land_Laptop_03_sand_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Laptop_CTRG_04 : Laptop_CTRG_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_AccommodationCentralTanoa_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_AccommodationDutchIsland_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_AccommodationNorthernBalavu_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_AccommodationNorthernTanoa_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_AccommodationSouthernBalavu_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_announcements_01_random_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_ChildDrawings_radnom_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_civilian_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Crime_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_CSAT_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Drawings_radnom_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_FIA_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_IDAP_IHL_radnom_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_NATO_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_AccommodationCentralTanoa_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_AccommodationDutchIsland_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_AccommodationNorthernBalavu_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_AccommodationNorthernTanoa_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_AccommodationSouthernBalavu_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_announcements_01_random_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_ChildDrawings_radnom_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_civilian_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_Crime_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_CSAT_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_Drawings_radnom_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_FIA_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_IDAP_IHL_radnom_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_NATO_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_realityCheck : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_New_SuicideNote_F : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_AccommodationCentralTanoa_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_AccommodationDutchIsland_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_AccommodationNorthernBalavu_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_AccommodationNorthernTanoa_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_AccommodationSouthernBalavu_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_announcements_01_random_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_ChildDrawings_radnom_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_civilian_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_Crime_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_CSAT_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_Drawings_radnom_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_FIA_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_IDAP_IHL_radnom_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_NATO_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_realityCheck : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_Old_SuicideNote_F : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_realityCheck : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_05_SuicideNote_F : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_New_random_01 : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_New_childDrawings_01_F : Leaflet_New_random_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_New_random_02 : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Leaflet_New_Drawings_01_F : Leaflet_New_random_02 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Logic_attachSynchronizedObjects : Logic {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class MissilePropBase_F : Land_CampingChair_V2_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class MultiScreenComputer_01_G_DiaryImagesAltis_random : Land_MultiScreenComputer_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class MultiScreenComputer_01_G_DiaryImagesAltisStratis_random : Land_MultiScreenComputer_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class MultiScreenComputer_01_G_DiaryImagesStratis_random : Land_MultiScreenComputer_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class O_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class O_T_Boat_Transport_01_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class O_T_Scientist_F : O_T_Soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class O_T_Scientist_Unarmed_F : O_T_Soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class O_T_Soldier_CBRN_F : O_T_Soldier_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Orange_01_part : Land_Orange_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Particle_Base_F : Thing {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Particle_Bubbles_F : Thing {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Particle_BigFire1_F : Particle_Bubbles_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Particle_Smoke_F : Particle_Bubbles_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Photoframe_broken_random : Photoframe_icon {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Photoframe_random : Photoframe_icon {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Photos_V4_scenarios_random : Land_Photos_V4_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class piano : Furniture_Residental_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Portable_generator_enabled : Land_Portable_generator_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_blue_off : PortableHelipadLight_01_blue_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_blue_constant : PortableHelipadLight_01_blue_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_constant : Land_PortableHelipadLight_01_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_green_off : PortableHelipadLight_01_green_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_green_constant : PortableHelipadLight_01_green_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_red_off : PortableHelipadLight_01_red_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_red_constant : PortableHelipadLight_01_red_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_white_off : PortableHelipadLight_01_white_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_white_constant : PortableHelipadLight_01_white_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_yellow_off : PortableHelipadLight_01_yellow_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableHelipadLight_01_yellow_constant : PortableHelipadLight_01_yellow_off {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadio_EmptyAir : Land_PortableLongRangeRadio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadio_RadioChatEngC_01_G : Land_PortableLongRangeRadio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadio_RadioChatEngF : Land_PortableLongRangeRadio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadio_RadioChatEngFCiv_01_G : Land_PortableLongRangeRadio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadioMilitary_EmptyAir : Land_PortableLongRangeRadioMilitary_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadioMilitary_RadioChatEng : Land_PortableLongRangeRadioMilitary_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PortableLongRangeRadioMilitary_RadioChatEngA_01_G : Land_PortableLongRangeRadioMilitary_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PowerLine_01_pole_transformer_G_on : Land_PowerLine_01_pole_transformer_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PowLines_Transformer_G_on : Land_PowLines_Transformer_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Pumpkin_01_part : Land_Pumpkin_01_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class PylonPod_Searchlight_01_G_base : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Rescue_duck_base_F : Rubber_duck_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class rksla3_aw159_base : Helicopter_Base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Rnc_Particle_BigFire_F : Thing {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class RoadBarrier_small_off : RoadBarrier_small_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class RoadBarrier_small_v2_off : RoadBarrier_small_v2 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class RoadCone_L_off : RoadCone_L_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class RoadCone_L_v2_off : RoadCone_L_v2 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Skeet_Clay_white : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Snake_random_F : Animal_Base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class SurvivalRadio_G_on : Land_SurvivalRadio_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Tablet_02_G_DiaryImagesAltis_random : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Tablet_02_G_DiaryImagesAltisStratis_random : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class Tablet_02_G_DiaryImagesStratis_random : Items_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class treeNote_random : Leaflet_05_New_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class treeNote_random_a : Leaflet_05_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class treeNote_random_b : Leaflet_05_Old_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class TripodScreen_01_large_VIDEO_placeholder : Land_TripodScreen_01_large_VIDEO_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };
    class TripodScreen_CTRG_large_04 : TripodScreen_CTRG_large_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
    };

    // Uniform units that redefine HitPoints without the ACE limb hitpoints.
    class Protagonist_VR_01 : C_man_1 {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };
    class O_Soldier_diver_noFins_base : O_Soldier_base_F {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };
    class I_Uniform_01_coveralls_G_gloves : I_E_Man_Base_F {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };
    class I_E_Helipilot_noGloves : I_E_Helipilot_F {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };
    class C_man_w_worker_F_Contact : C_man_w_worker_F_dgtl {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };
    class B_Uniform_01_coveralls_G_gloves : I_E_Man_Base_F {
        class HitPoints {
            class HitHands;
            class HitLegs;
            // ACE ADD_ACE_HITPOINTS
            class HitLeftArm : HitHands {
                material = -1;
                name = "hand_l";
                radius = 0.08;
                visual = "injury_hands";
                minimalHit = 0.01;
            };
            class HitRightArm : HitLeftArm {
                name = "hand_r";
            };
            class HitLeftLeg : HitLegs {
                material = -1;
                name = "leg_l";
                radius = 0.1;
                visual = "injury_legs";
                minimalHit = 0.01;
            };
            class HitRightLeg : HitLeftLeg {
                name = "leg_r";
            };
        };
    };

    // Static fuel props: CBA disables XEH on Static, ACE refuel needs it to init placed objects.
    class House_Small_F;
    class Strategic;
    class Land_TrailerCistern_wreck_G_fuel : House_Small_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class Land_Tank_rust_G_fuel : House_Small_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class Bomb : Strategic {
        ace_refuel_fuelCargo = -1; // Internal vanilla class, not a fuel source
    };
#include "CfgVehiclesNoModel.hpp"
#include "CfgVehiclesFixes.hpp"
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgCloudlets.hpp"
#include "CfgMoves.hpp"
#include "CfgSurfaces.hpp"
#include "CfgVoiceTypes.hpp"
