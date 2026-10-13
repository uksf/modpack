class CUP_ECVHMMWV_Base : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_ECVHMMWV_m240_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_ECVHMMWV_m2_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_ECVHMMWV_mk19_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_running_boards {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_HMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_HMMWV_SOV_M2_Base : CUP_HMMWV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class SideTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_HMMWV_SOV_M2_NATO_T : CUP_HMMWV_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_HMMWV_SOV_M2_USA : CUP_HMMWV_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_HMMWV_SOV_Base : CUP_HMMWV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class SideTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_HMMWV_SOV_NATO_T : CUP_HMMWV_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_HMMWV_SOV_USA : CUP_HMMWV_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_nHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_nM1025_SOV_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
    class Turrets : Turrets {
        class MainTurret;
    };
    class NewTurret;
};
class CUP_nM1025_SOV_Mk19_Base : CUP_nM1025_SOV_Base {
    class AnimationSources : AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class SideTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_nM1036_TOW_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_nM1036_TOW_DF_Base : CUP_nM1036_TOW_Base {};
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
class CUP_nM1038_4s_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
        class hide_ammo_cans {
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
class CUP_nM1097_Avenger_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
class CUP_nM997_amb_Base : CUP_nHMMWV_Base {
    class AnimationSources {
        class hide_ammo_cans {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
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
        class hide_spare_wheel_mount {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
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
class CUP_nM1025_M240_Base : CUP_nHMMWV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M240_NATO : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_NATO_T : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_USA_DES : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_USA_WDL : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_USMC_DES : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_USMC_WDL : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_nM1025_M2_Base : CUP_nHMMWV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M2_NATO : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_NATO_T : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_USA_DES : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_USA_WDL : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_USMC_DES : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_USMC_WDL : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_nM1025_Mk19_Base : CUP_nHMMWV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_Mk19_NATO : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_NATO_T : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_USA_DES : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_USA_WDL : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_USMC_DES : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_USMC_WDL : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_nM1025_SOV_M2_Base : CUP_nM1025_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class SideTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_nM1025_SOV_M2_ION : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_ION_WIN : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_NATO : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_NATO_T : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_USA_DES : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_USA_WDL : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_USMC_DES : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_M2_USMC_WDL : CUP_nM1025_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_ION : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_ION_WIN : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_NATO : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_NATO_T : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_USA_DES : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_USA_WDL : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_USMC_DES : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1025_SOV_Mk19_USMC_WDL : CUP_nM1025_SOV_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_nM1036_TOW_DF_NATO : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_DF_NATO_T : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_DF_USA_DES : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_DF_USA_WDL : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_DF_USMC_DES : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_DF_USMC_WDL : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_NATO : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_NATO_T : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_USA_DES : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_USA_WDL : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_USMC_DES : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1036_TOW_USMC_WDL : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret;
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M240_ION : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M240_ION_WIN : CUP_nM1025_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M2_ION : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M2_ION_WIN : CUP_nM1025_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_Mk19_ION : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_Mk19_ION_WIN : CUP_nM1025_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1036_TOW_DF_ION : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1036_TOW_DF_ION_WIN : CUP_nM1036_TOW_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1036_TOW_ION : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1036_TOW_ION_WIN : CUP_nM1036_TOW_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_UpHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
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
class CUP_nHMMWV_DF_Base : CUP_nHMMWV_Base {
    class Turrets;
};
class CUP_nM1025_M240_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M240_DF_NATO : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_DF_USA_DES : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_DF_USA_WDL : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_DF_USMC_DES : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M240_DF_USMC_WDL : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_nM1025_M2_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M2_DF_NATO : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_DF_USA_DES : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_DF_USA_WDL : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_DF_USMC_DES : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_M2_DF_USMC_WDL : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_nM1025_Mk19_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_Mk19_DF_NATO : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_DF_USA_DES : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_DF_USA_WDL : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_DF_USMC_DES : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_nM1025_Mk19_DF_USMC_WDL : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M240_DF_ION : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M240_DF_ION_WIN : CUP_nM1025_M240_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M2_DF_ION : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_M2_DF_ION_WIN : CUP_nM1025_M2_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_Mk19_DF_ION : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_nM1025_Mk19_DF_ION_WIN : CUP_nM1025_Mk19_DF_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
