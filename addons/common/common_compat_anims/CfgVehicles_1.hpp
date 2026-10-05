class CUP_BMP1_base;
class CUP_LAV25_Base;
class CUP_M1245_Base;
class CUP_UAZ_Base;
class Car;
class Plane_Base_F;
class StaticMGWeapon;
class rnc_house_base;
class All {
    class AnimationSources;
};
class AllVehicles : All {};
class Buoy_base_F;
class CUP_BMP2_base : CUP_BMP1_base {
    class AnimationSources;
};
class CUP_B_LAV25_USMC : CUP_LAV25_Base {
    class AnimationSources;
};
class CUP_B_MV22_USMC : Plane_Base_F {
    class AnimationSources;
};
class CUP_B_MV22_USMC_RAMPGUN : CUP_B_MV22_USMC {
    class AnimationSources : AnimationSources {
        class gatling_2 {
            source = "revolving";
            weapon = "CUP_Vlmg_M240_veh";
        };
        class gatling_2_muzzle_rot {
            source = "ammorandom";
            weapon = "CUP_Vlmg_M240_veh";
        };
    };
};
class CUP_M1245_CROWS_Base : CUP_M1245_Base {
    class AnimationSources;
};
class CUP_M1245_CROWS_M134_Base : CUP_M1245_CROWS_Base {
    class AnimationSources : AnimationSources {
        class muzzle_source_rot_3 {
            source = "ammorandom";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class reloadanim_2 {
            source = "reload";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class revolving_3 {
            source = "revolving";
            weapon = "CUP_Vlmg_M134_veh";
        };
    };
};
class CUP_UAZ_Armed_Base : CUP_UAZ_Base {
    class AnimationSources;
};
class CUP_UAZ_METIS_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
};
class CUP_UAZ_MG_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
};
class CUP_UAZ_SPG9_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
};
class CUP_nHMMWV_Base;
class CUP_nM1037sc_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_door_rear_left {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_door_rear_right {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_front_left_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_front_right_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_nM1038_4s_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_front_left_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_front_right_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class unhide_deployment_1 {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class unhide_deployment_2 {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_nM1038_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_door_rear_left {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_door_rear_right {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_front_left_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_front_right_antenna {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_nM997_amb_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_blue_force_tracker {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_door_rear_left {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_door_rear_right {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_jerrycans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_spare_wheel {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 1;
        };
    };
};
class Car_F : Car {
    class AnimationSources;
};
class Helicopter_Base_F;
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources;
};
class House_EP1;
class LSV_01_base_F : Car_F {
    class AnimationSources : AnimationSources {
        class maingun {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class LSV_02_base_F : Car_F {
    class AnimationSources : AnimationSources {
        class maingun {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class Land : AllVehicles {};
class LandVehicle : Land {};
class Land_BagFence_End_F;
class Land_BuoyBig_F : Buoy_base_F {
    class AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class Land_Mil_Guardhouse_EP1 : House_EP1 {
    class AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_rnc_apt_v1_c9_c1_f6 : rnc_house_base {
    class AnimationSources;
};
class Land_rnc_apt_v1_c9_c2_f3 : Land_rnc_apt_v1_c9_c1_f6 {
    class AnimationSources : AnimationSources {
        class door_3_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_rnc_apt_v1_c9_c2_f5 : Land_rnc_apt_v1_c9_c1_f6 {
    class AnimationSources : AnimationSources {
        class door_3_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Radar_System_02_base_F : StaticMGWeapon {
    class AnimationSources;
};
class Static : All {};
class StaticShip;
class Tank : LandVehicle {};
class Tank_F : Tank {};
class Thing : All {};
class ThingX : Thing {};
class Truck_F : Car_F {};
class Van_02_base_F : Truck_F {};
class Van_02_service_base_F : Van_02_base_F {
    class AnimationSources : AnimationSources {
        class enable_cargo {
            source = "user";
            animPeriod = 0.0002;
        };
    };
};
class Wall_F;
class Wheeled_APC_F : Car_F {
    class AnimationSources;
};
class Wrecks_Globe_base : ThingX {};
class ace_rearm_defaultCarriedObject : ThingX {
    class AnimationSources : AnimationSources {
        class ammo_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class ammoord_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class grenades_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class support_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class AFV_Wheeled_01_base_F : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hideturret {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class AFV_Wheeled_01_up_base_F : AFV_Wheeled_01_base_F {
    class AnimationSources : AnimationSources {
        class hideturret {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class APC_Tracked_01_base_F : Tank_F {
    class AnimationSources;
};
class APC_Tracked_02_base_F : Tank_F {
    class AnimationSources;
};
class APC_Wheeled_02_base_F : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitmaingun_src {
            source = "Hit";
            hitpoint = "HitGun";
            raw = 1;
        };
        class hitturret_src {
            source = "Hit";
            hitpoint = "HitTurret";
            raw = 1;
        };
        class revolving_gmg {
            source = "revolving";
            weapon = "GMG_40mm";
        };
        class showbags {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcamonethull {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcanisters {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showslathull {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showtools {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class Air : AllVehicles {
    class AnimationSources;
};
class B_APC_Tracked_01_base_F : APC_Tracked_01_base_F {};
class BagFence_couple : Land_BagFence_End_F {
    class AnimationSources {
        class helmet_x {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class helmet_y {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class helmet_z {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_x {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_y {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_z {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
    };
};
class Building : Static {};
class CUP_412_01_base_F : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Civ_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Luxury_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Medic_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Transport_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Utility_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Military_Radar_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Police_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_A1_BaseObject : Static {};
class CUP_A1_Buildings : CUP_A1_BaseObject {};
class CUP_A1_Cihlovej_dum_in : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Cihlovej_dum_mini : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Dum_mesto2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Hlidac_budka : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Kbud : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Plot_Wood1_door : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Plot_Wood_door : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Ryb_domek : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_SS_hangar : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_11_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_SS_hangarD : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_11_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Sara_domek_sedy : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Sara_domek_zluty : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Sara_zluty_statek_in : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_Statek_brana_open : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_ammostore2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class lid_1_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_army_hut2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_army_hut2_int : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_army_hut3_long : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_army_hut3_long_int : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_army_hut_int : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_benzina_schnell : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_brana02 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_budova3 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_budova4_in : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_garaz : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_garaz_bez_tanku : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_garaz_mala : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_garaz_s_tankem : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_hangar_2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_hospoda_mesto : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_house_y : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_kulna : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_pletivo_wired_branaL : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_pletivo_wired_branaL_civil : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_pletivo_wired_branaP : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_green_branka : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_green_vrat_l : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_green_vrat_r : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_green_vrata : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_rust_branka : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_rust_vrat_l : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_rust_vrat_r : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_plot_rust_vrata : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_pumpa : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class handle_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_runway_edgelight : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class CUP_A1_stodola_open : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_strazni_vez : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_tovarna2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_zavora : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A1_zavora_2 : CUP_A1_Buildings {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_Baseclass : Static {};
class CUP_A2_Cargo : CUP_A2_Baseclass {};
class CUP_A2_Civilian : CUP_A2_Baseclass {};
class CUP_A2_Fences : CUP_A2_Baseclass {};
class CUP_A2_Industry : CUP_A2_Baseclass {};
class CUP_A2_Military : CUP_A2_Baseclass {};
class CUP_A2_Pier : CUP_A2_Baseclass {};
class CUP_A2_Rails : CUP_A2_Baseclass {};
class CUP_A2_Ruins : CUP_A2_Baseclass {};
class CUP_A2_Runway : CUP_A2_Baseclass {};
class CUP_A2_Various : CUP_A2_Baseclass {};
class CUP_A2_Walls : CUP_A2_Baseclass {};
class CUP_A2_Wrecks : CUP_A2_Baseclass {};
class CUP_A2_a_tvtower_base : CUP_A2_Various {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barn_metal : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barn_metal_dam : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barn_w_01 : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barn_w_01_dam : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barn_w_02 : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barrack2_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barracks : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barracks_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barracks_i : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_barracks_i_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_budova4_in : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_cargo1ao : CUP_A2_Cargo {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_cargo1bo : CUP_A2_Cargo {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_church_03 : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_church_03_dam : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_cihlovej_dum_in : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_coltan_main_ep1 : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_controltower : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_controltower_dam : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_controltower_dam_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_controltower_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_dum_mesto2 : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_farm_cowshed_a : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_farm_cowshed_a_dam : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_farm_cowshed_c : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_farm_cowshed_c_dam : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_fuelstation_build : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_fuelstation_build_ep1 : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_fuelstation_build_pmc : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_garage01 : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_garage01_ep1 : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_garaz : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_garaz_mala : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind1_l : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind1_r : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2a_l : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2a_r : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2b_l : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2b_r : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2rail_l : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_ind2rail_r : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_indvar2_5 : CUP_A2_Walls {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_village : CUP_A2_Fences {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_wood1 : CUP_A2_Fences {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_wood1_5 : CUP_A2_Fences {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_gate_wood2_5 : CUP_A2_Fences {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_generalstore_01 : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_generalstore_01_dam : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_generalstore_01a : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_generalstore_01a_dam : CUP_A2_Industry {
    class AnimationSources : AnimationSources {
        class door_10_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_7_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_8_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_9_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_guardhouse : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_guardhouse_ep1 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_nosound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_hangar_2 : CUP_A2_Military {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_2_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_3_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_4_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_5_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
        class door_6_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_hlidac_budka : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class CUP_A2_hlidac_budka_ep1 : CUP_A2_Civilian {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
