class Land_TinWall_01_m_gate_v2_closed_F : Wall_F {
    class AnimationSources {
        class door_1_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
        class door_2_locked_source {
            source = "user";
            animPeriod = 0.8;
            initPhase = 0;
        };
    };
};
class Lexx_ContainerShip_Base_H : StaticShip {
    class AnimationSources {
        class addcargo {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
};
class MBT_01_wreck : Heli_Light_02_wreck {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class hatchdriver {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
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
        class recoil_source {
            source = "user";
            animPeriod = 5;
            initPhase = 0;
        };
        class showcamonethull {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcamonetplates1 {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcamonetplates2 {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class MBT_04_base_F : Tank_F {
    class AnimationSources : AnimationSources {
        class hidehull {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
        class hideturret {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class MBT_04_command_base_F : MBT_04_base_F {
    class AnimationSources : AnimationSources {
        class hidehull {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
        class hideturret {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
    };
};
class Mea_Hoist_Hook : Items_base_F {
    class AnimationSources : AnimationSources {
        class collisionlightred_source {
            source = "MarkerLight";
        };
        class collisionlightwhite_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_EdgeLight : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_EdgeLightBlue : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_FlushLight_1 : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_FlushLight_2 : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_FlushLight_3 : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_NaviLight_1 : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
    };
};
class NT_Misc_NaviLight_2 : Static {
    class AnimationSources : AnimationSources {
        class light_1_source {
            source = "MarkerLight";
        };
        class light_2_source {
            source = "MarkerLight";
        };
        class light_3_source {
            source = "MarkerLight";
        };
    };
};
class NonStrategic : Building {};
class O_APC_Tracked_02_base_F : APC_Tracked_02_base_F {};
class O_Radar_System_02_F : Radar_System_02_base_F {};
class Plane : Air {};
class Plane_Base_F : Plane {
    class AnimationSources;
};
class Plane_Civil_01_base_F : Plane_Base_F {
    class AnimationSources : AnimationSources {
        class hitengine {
            source = "Hit";
            hitpoint = "HitEngine";
            raw = 1;
        };
    };
};
class ReammoBox_F : ThingX {};
class Truck_01_base_F : Truck_F {};
class UAV : Plane {};
class UAV_02_base_F : UAV {
    class AnimationSources : AnimationSources {
        class hideweapons {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 1;
        };
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
class UK3CB_BAF_Apache_base : Heli_Attack_01_base_F {
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
class uksf_vaf_Mini_Radar_Dish : O_Radar_System_02_F {
    class AnimationSources : AnimationSources {
        class tripod_hide_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 0;
        };
    };
};
class uksf_vaf_rugged_radar_large : O_Radar_System_02_F {
    class AnimationSources : AnimationSources {
        class progress_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 0;
        };
        class terminal_source {
            source = "user";
            animPeriod = 0.07;
            initPhase = 0;
        };
        class terminal_source_sound_case_01 {
            source = "user";
            animPeriod = 0.15;
            initPhase = 0;
        };
        class terminal_source_sound_case_02 {
            source = "user";
            animPeriod = 0.15;
            initPhase = 0;
        };
    };
};
class uksf_vaf_rugged_radar_small : O_Radar_System_02_F {
    class AnimationSources : AnimationSources {
        class progress_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 0;
        };
        class satellite_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 0;
        };
        class terminal_source {
            source = "user";
            animPeriod = 0.07;
            initPhase = 0;
        };
        class terminal_source_sound {
            source = "user";
            animPeriod = 0.07;
            initPhase = 0;
        };
    };
};
class 14_pier_14_lighthouse : CUP_A2_Pier {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class 14_pier_14_lighthouse2 : CUP_A2_Pier {
    class AnimationSources : AnimationSources {
        class door_1_sound_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class 14_pier_14_nav_boathouse : CUP_A2_Pier {
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
class B_APC_Tracked_01_AA_F : B_APC_Tracked_01_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "autocannon_35mm";
        };
    };
};
class B_APC_Tracked_01_CRV_F : B_APC_Tracked_01_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "HMG_127_APC";
        };
    };
};
class B_Truck_01_transport_F : Truck_01_base_F {};
class Box_Ammo_F : ReammoBox_F {
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
class CUP_BRDM2_ATGM_Base : CUP_BRDM2_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR40_Base : CUP_BTR40_MG_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR80A_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_pkt {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
        class muzzle_rot_pkt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
    };
};
class CUP_BTR80_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_kpvt {
            source = "reload";
            weapon = "CUP_Vhmg_KPVT_veh";
        };
        class muzzle_hide_pkt {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
        class muzzle_rot_kpvt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_KPVT_veh";
        };
        class muzzle_rot_pkt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
    };
};
class CUP_B_M1128_MGS_Desert : CUP_StrykerBase {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1135_ATGMV_Desert : CUP_StrykerBase {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_MH47E_USA : CUP_MH47E_base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitglass6 {
            source = "Hit";
            hitpoint = "HitGlass6";
            raw = 1;
        };
    };
};
class CUP_B_MH6J_OBS_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6J_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6M_OBS_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6M_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
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
class CUP_B_Merlin_HC3_GB : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_CIV_Rescue : CUP_Merlin_Rescue_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_IDAP_Rescue : CUP_Merlin_Rescue_Base {
    class AnimationSources : AnimationSources {
        class flir_gun {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class flir_turret {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Datsun_AA_Base : CUP_Datsun_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Igla_twice_W";
        };
    };
};
class CUP_Hilux_BMP1_base : CUP_Hilux_Base {
    class AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_noeject";
        };
    };
};
class CUP_Hilux_armored_BMP1_Base : CUP_Hilux_BMP1_base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_noeject";
        };
    };
};
class CUP_Hilux_armored_BTR60_Base : CUP_Hilux_btr60_base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
    };
};
class CUP_Hilux_armored_igla_Base : CUP_Hilux_igla_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Igla_twice_W";
        };
    };
};
class CUP_Hilux_armored_podnos_Base : CUP_Hilux_podnos_Base {
    class AnimationSources : AnimationSources {
        class reloadanim {
            source = "reload";
            weapon = "CUP_mortar_82mm_veh";
        };
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_mortar_82mm_veh";
        };
    };
};
class CUP_Hilux_armored_zu23_Base : CUP_Hilux_zu23_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
    };
};
class CUP_I_LR_SF_GMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_gmg {
            source = "reload";
            weapon = "CUP_Vgmg_MK19_veh";
        };
        class muzzle_rot_gmg {
            source = "ammorandom";
            weapon = "CUP_Vgmg_MK19_veh";
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
};
class CUP_I_LR_SF_HMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_m2 {
            source = "ammorandom";
            weapon = "CUP_Vhmg_M2_static";
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
};
class CUP_LR_AA_Base : CUP_LR_SPG9_Base {
    class AnimationSources : AnimationSources {
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
};
class CUP_LR_Ambulance_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_antenna_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class selection_box {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
};
class CUP_M1126_ICV_BASE : CUP_StrykerBase {
    class AnimationSources;
};
class CUP_M113A1_HQ_Base : CUP_M113New_HQ_Base {
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
class CUP_M113A1_Med_Base : CUP_M113New_Med_Base {
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
class CUP_M113A3_Reammo_Base : CUP_M113New_HQ_Base {
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
class CUP_M113A3_Repair_Base : CUP_M113New_HQ_Base {
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
class CUP_M1151_Mk19_BASE : CUP_UpHMMWV_Base {
    class AnimationSources : AnimationSources {
        class detailhide {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_M1151_Unarmed_BASE : CUP_UpHMMWV_Base {
    class AnimationSources : AnimationSources {
        class detailhide {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_M1152_BASE : CUP_UpHMMWV_Base {
    class AnimationSources : AnimationSources {
        class detailhide {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_M1167_BASE : CUP_UpHMMWV_Base {
    class AnimationSources : AnimationSources {
        class detailhide {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_Merlin_HC3A_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_T810_Reammo_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_T810_Refuel_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_T810_Repair_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_T90MS_Base : CUP_T90M_Base {
    class AnimationSources : AnimationSources {
        class coax_muzzlehide {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_T90M";
        };
        class muzzleflash_cannon_rot {
            source = "ammorandom";
            weapon = "CUP_Vcannon_2A46_Txx";
        };
    };
};
class CUP_UH60_Unarmed_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_Uh60S_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class pylons_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_Uh60_Unarmed_FFV_Base : CUP_UH60_Unarmed_Base {
    class AnimationSources;
};
class CombatBoot_base : Items_base_F {
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
class HouseBase : NonStrategic {};
class LT_01_AA_base_F : LT_01_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "HMG_127";
        };
    };
};
class LT_01_AT_base_F : LT_01_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "HMG_127";
        };
    };
};
class Land_Box_AmmoOld_F : ReammoBox_F {
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
class O_APC_Tracked_02_AA_F : O_APC_Tracked_02_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "autocannon_35mm";
        };
    };
};
class B_Truck_01_medical_F : B_Truck_01_transport_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_mover_F : B_Truck_01_transport_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class CUP_B_M1126_ICV_M2_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1126_ICV_MK19_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1129_MC_MK19_Desert : CUP_B_M1126_ICV_MK19_Desert {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1130_CV_M2_Desert : CUP_B_M1126_ICV_M2_Desert {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1133_MEV_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_MH60S_Unarmed_FFV_Base : CUP_Uh60_Unarmed_FFV_Base {};
class CUP_MH60S_Unarmed_FFV_USN : CUP_MH60S_Unarmed_FFV_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_MH60S_Unarmed_USN : CUP_UH60_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class House : HouseBase {};
class Land_Ind_Mlyn_03 : House {
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
        class glass_1_source {
            source = "Hit";
            hitpoint = "Glass_1_hitpoint";
            raw = 1;
        };
        class glass_2_source {
            source = "Hit";
            hitpoint = "Glass_2_hitpoint";
            raw = 1;
        };
        class glass_3_source {
            source = "Hit";
            hitpoint = "Glass_3_hitpoint";
            raw = 1;
        };
    };
};
class B_Truck_01_Repair_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_ammo_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_box_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
class B_Truck_01_fuel_F : B_Truck_01_mover_F {
    class AnimationSources : AnimationSources {
        class mirror_l_hide {
            source = "user";
            animPeriod = 0.01;
            initPhase = 0;
        };
    };
};
