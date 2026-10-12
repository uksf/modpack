class CUP_Boxer_Base;
class CUP_Boxer_Base_HMG : CUP_Boxer_Base {
    class Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Boxer_HMG_HIL : CUP_Boxer_Base_HMG {};
class CUP_Boxer_Base_GMG : CUP_Boxer_Base_HMG {
    class Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Boxer_GMG_HIL : CUP_Boxer_Base_GMG {};
class All {
    class AnimationSources;
};
class AllVehicles : All {
    class NewTurret;
};
class Air : AllVehicles {
    class AnimationSources;
};
class Helicopter : Air {
    class AnimationSources;
};
class Helicopter_Base_F : Helicopter {
    class Turrets;
};
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources : AnimationSources {
        class HitEngine2;
    };
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class CUP_412_01_base_F : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1;
        class inspect_panel2_1;
    };
    class Turrets;
};
class CUP_412_Military_Armed_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_Military_Armed_AT_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_B_412_Military_Armed_AT_HIL : CUP_412_Military_Armed_AT_Base_F {};
class CUP_I_412_Military_Armed_AT_PMC : CUP_412_Military_Armed_AT_Base_F {};
class uksf_cdf_CH146_AT : CUP_I_412_Military_Armed_AT_PMC {};
class CUP_I_412_Military_Armed_PMC : CUP_412_Military_Armed_Base_F {};
class uksf_cdf_CH146_Armed : CUP_I_412_Military_Armed_PMC {};
class CUP_Mi8_base : Helicopter_Base_H {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret;
        class CopilotTurret;
    };
};
class CUP_Mi171Sh_Base : CUP_Mi8_base {
    class Turrets : Turrets {
        class LeftTurret;
        class BackTurret;
        class RightTurret;
        class CopilotTurret;
    };
};
class CUP_Mi171Sh_Unarmed_Base : CUP_Mi171Sh_Base {};
class CUP_B_Mi171Sh_Unarmed_ACR : CUP_Mi171Sh_Unarmed_Base {};
class Land : AllVehicles {};
class LandVehicle : Land {};
class Tank : LandVehicle {
    class NewTurret;
};
class Tank_F : Tank {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            class Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_M1Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurret {};
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abrams_M1A1FEP_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {};
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1FEP_Woodland_USMC : CUP_M1Abrams_M1A1FEP_Base {};
class CUP_Leopard2_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret : NewTurret {};
            };
        };
    };
};
class CUP_B_Leopard2A6_HIL : CUP_Leopard2_Base {};
class CUP_B_Leopard2A6_GER : CUP_Leopard2_Base {};
class CUP_BMP3_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
        class LeftTurret;
        class RightTurret;
    };
};
class CUP_O_BMP3_RU : CUP_BMP3_Base {};
class CUP_T55_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
    };
};
class CUP_O_T55_CHDKZ : CUP_T55_Base {};
class uksf_eug_T55 : CUP_O_T55_CHDKZ {};
class CUP_O_T55_SLA : CUP_T55_Base {};
class uksf_cdf_T55 : CUP_O_T55_SLA {};
class CUP_ZSU23_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_B_ZSU23_CDF : CUP_ZSU23_Base {};
class CUP_O_ZSU23_ChDKZ : CUP_ZSU23_Base {};
class CUP_O_ZSU23_SLA : CUP_ZSU23_Base {};
class uksf_cdf_Shilka : CUP_O_ZSU23_SLA {};
class CUP_T72_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
    };
};
class CUP_O_T72_RU : CUP_T72_Base {};
class CUP_O_T72_SLA : CUP_T72_Base {};
class APC_Tracked_02_base_F : Tank_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon;
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_BMP1_base : APC_Tracked_02_base_F {
    class Turrets : Turrets {
        class CommanderOptics;
        class MainTurret : MainTurret {
            class Turrets;
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class CUP_BMP2_base : CUP_BMP1_base {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_07;
    };
    class NewTurret;
};
class CUP_B_BMP2_CZ : CUP_BMP2_base {};
class Car : LandVehicle {
    class Turrets;
};
class Car_F : Car {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class CUP_Tigr_Base : Car_F {
    class AnimationSources : AnimationSources {
        class HitGlass10;
        class hide_gear_1;
        class hide_gear_2;
        class hide_gear_3;
        class hide_roofcarrier;
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_Tigr_M_PK_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform;
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_PK_Base : CUP_Tigr_M_PK_Base {};
class CUP_O_Tigr_M_233114_PK_RU : CUP_Tigr_233114_PK_Base {};
class CUP_Tigr_M_KORD_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform;
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_KORD_Base : CUP_Tigr_M_KORD_Base {};
class CUP_O_Tigr_M_233114_KORD_RU : CUP_Tigr_233114_KORD_Base {};
class CUP_nHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_nHMMWV_DF_Base : CUP_nHMMWV_Base {
    class Turrets;
};
class CUP_nM1025_Mk19_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_Mk19_DF_NATO_T : CUP_nM1025_Mk19_DF_Base {};
class CUP_nM1025_M240_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M240_DF_NATO_T : CUP_nM1025_M240_DF_Base {};
class CUP_nM1025_M2_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M2_DF_NATO_T : CUP_nM1025_M2_DF_Base {};
class LSV_01_base_F : Car_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
    };
};
class LSV_01_armed_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
        class TopTurret : MainTurret {};
    };
};
class B_T_LSV_01_armed_F : LSV_01_armed_base_F {};
class Wheeled_APC_F : Car_F {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class CUP_BTR80_Common_Base : Wheeled_APC_F {
    class AnimationSources;
    class Turrets;
};
class CUP_BTR80A_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_pkt;
        class muzzle_rot_pkt;
    };
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class CUP_O_BTR80A_CSAT : CUP_BTR80A_Base {};
class CUP_O_BTR80A_GREEN_RU : CUP_BTR80A_Base {};
class CUP_I_BTR80A_UN : CUP_BTR80A_Base {};
class CUP_BTR80_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_kpvt;
        class muzzle_hide_pkt;
        class muzzle_rot_kpvt;
        class muzzle_rot_pkt;
    };
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class CUP_O_BTR80_GREEN_RU : CUP_BTR80_Base {};
class CUP_I_BTR80_UN : CUP_BTR80_Base {};
class MRAP_03_base_F : Car_F {
    class Turrets;
};
class MRAP_03_hmg_base_F : MRAP_03_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
    };
};
class I_MRAP_03_hmg_F : MRAP_03_hmg_base_F {};
class Inegal_VAB_HMG : I_MRAP_03_hmg_F {};
class CUP_LR_Base : Car_F {
    class AnimationSources : AnimationSources {
        class selection_wheels;
    };
    class Turrets;
};
class CUP_LR_Special_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class MainTurret;
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret : MainTurret {};
    };
};
class CUP_I_LR_SF_HMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_m2;
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class CUP_I_LR_SF_GMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_gmg;
        class muzzle_rot_gmg;
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class CUP_B_LR_Special_CZ_W : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class Inegal_LandRover_GL : CUP_B_LR_Special_CZ_W {};
class StaticWeapon : LandVehicle {
    class Turrets;
};
class StaticMGWeapon : StaticWeapon {
    class Turrets : Turrets {};
};
class AAA_System_01_base_F : StaticMGWeapon {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class B_AAA_System_01_F : AAA_System_01_base_F {};
class Radar_System_02_base_F : StaticMGWeapon {
    class AnimationSources;
};
class O_Radar_System_02_F : Radar_System_02_base_F {};
class uksf_vaf_Mini_Radar_Dish : O_Radar_System_02_F {
    class AnimationSources : AnimationSources {
        class tripod_hide_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 0;
        };
        class wall_mount_hide_source {
            source = "user";
            animPeriod = 0.1;
            initPhase = 1;
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
class Inegal_LandRover_FDF_GL : Inegal_LandRover_GL {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class Inegal_VAB_D_HMG : Inegal_VAB_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CommanderTurret : CommanderTurret {};
    };
};
class uksf_acr_BVP : CUP_B_BMP2_CZ {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
    };
};
class uksf_acr_Mi17 : CUP_B_Mi171Sh_Unarmed_ACR {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
    };
};
class uksf_acr_T72 : CUP_O_T72_SLA {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
    };
};
class uksf_aug_landrover_gmg : CUP_I_LR_SF_GMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_aug_landrover_mg : CUP_I_LR_SF_HMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cartel_commando_LR_GMG : CUP_B_LR_Special_CZ_W {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cartel_commando_LR_MG : CUP_I_LR_SF_HMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cdf_BTR80 : CUP_I_BTR80_UN {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class uksf_cdf_BTR80_Woodland : CUP_O_BTR80_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class uksf_cdf_BTR80A : CUP_I_BTR80A_UN {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class uksf_cdf_BTR80A_Woodland : CUP_O_BTR80A_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class uksf_cdf_CH146_Armed_Woodland : uksf_cdf_CH146_Armed {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class uksf_cdf_CH146_AT_Woodland : uksf_cdf_CH146_AT {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class uksf_cdf_Praetorian : B_AAA_System_01_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cdf_Shilka_Woodland : uksf_cdf_Shilka {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_cdf_T55_Woodland : uksf_cdf_T55 {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
    };
};
class uksf_eug_BMP3 : CUP_O_BMP3_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
    };
};
class uksf_eug_BTR_80A : CUP_O_BTR80A_CSAT {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class uksf_eug_T72 : CUP_O_T72_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
    };
};
class uksf_eug_ZSU_23_4 : CUP_O_ZSU23_ChDKZ {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_saf_leopard2A6 : CUP_B_Leopard2A6_GER {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_saf_m1a1 : CUP_B_M1A1FEP_Woodland_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_saf_zsu23 : CUP_B_ZSU23_CDF {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_vaf_Boxer_GMG : CUP_B_Boxer_GMG_HIL {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class uksf_vaf_Boxer_HMG : CUP_B_Boxer_HMG_HIL {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class uksf_vaf_CH_54_Armed : CUP_B_412_Military_Armed_AT_HIL {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class uksf_vaf_Leopard2A6 : CUP_B_Leopard2A6_HIL {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class uksf_vaf_LSV_01_armed_SF : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class uksf_vaf_M1025_M2 : CUP_B_nM1025_M2_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_vaf_M1025_M240 : CUP_B_nM1025_M240_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_vaf_M1025_Mk19 : CUP_B_nM1025_Mk19_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_vaf_T55 : uksf_eug_T55 {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
    };
};
class uksf_zgf_tigr_kord : CUP_O_Tigr_M_233114_KORD_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_zgf_tigr_pk : CUP_O_Tigr_M_233114_PK_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
