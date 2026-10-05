class All;
class AllVehicles : All {
    class NewTurret;
};
class Land : AllVehicles {
};
class LandVehicle : Land {
};
class StaticWeapon;
class StaticMGWeapon : StaticWeapon {
    class Turrets;
};
class AAA_System_01_base_F : StaticMGWeapon {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class Tank : LandVehicle {
};
class Tank_F : Tank {
    class Turrets {
        class MainTurret : NewTurret {
            class Turrets {
                class CommanderOptics;
            };
        };
    };
};
class APC_Tracked_02_base_F : Tank_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class Car;
class Car_F : Car {
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class Wheeled_APC_F : Car_F {
    class NewTurret;
    class Turrets;
};
class APC_Wheeled_02_base_F : Wheeled_APC_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderOptics;
    };
};
class B_AAA_System_01_F : AAA_System_01_base_F {
};
class Helicopter;
class Helicopter_Base_F : Helicopter {
    class Turrets;
};
class Helicopter_Base_H : Helicopter_Base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class Heli_Transport_03_base_F : Helicopter_Base_H {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class B_Heli_Transport_03_F : Heli_Transport_03_base_F {
};
class B_Heli_Transport_03_black_F : B_Heli_Transport_03_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
    };
};
class Heli_Transport_03_unarmed_base_F : Heli_Transport_03_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class B_Heli_Transport_03_unarmed_F : Heli_Transport_03_unarmed_base_F {
};
class B_Heli_Transport_03_unarmed_green_F : B_Heli_Transport_03_unarmed_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class RightDoorGun : RightDoorGun {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
    };
};
class LSV_01_base_F : Car_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
    };
};
class LSV_01_armed_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class TopTurret;
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
    };
};
class B_LSV_01_armed_F : LSV_01_armed_base_F {
};
class B_LSV_01_armed_black_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class B_LSV_01_armed_olive_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class B_LSV_01_armed_sand_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class LSV_01_AT_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class TopTurret;
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
    };
};
class B_LSV_01_AT_F : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class SAM_System_01_base_F : StaticMGWeapon {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class B_SAM_System_01_F : SAM_System_01_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class SAM_System_02_base_F : StaticMGWeapon {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class B_SAM_System_02_F : SAM_System_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class B_T_LSV_01_armed_F : LSV_01_armed_base_F {
};
class B_T_LSV_01_armed_black_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class B_T_LSV_01_armed_CTRG_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
        class TopTurret;
        class CodRiverTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class B_T_LSV_01_armed_olive_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class B_T_LSV_01_armed_sand_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class B_T_LSV_01_AT_F : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {
        };
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
    };
};
class Plane;
class Plane_Base_F : Plane {
    class Turrets;
};
class VTOL_Base_F;
class VTOL_01_base_F : VTOL_Base_F {
    class Turrets;
};
class VTOL_01_armed_base_F : VTOL_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class GunnerTurret_01;
        class GunnerTurret_02;
    };
};
class B_T_VTOL_01_armed_F : VTOL_01_armed_base_F {
};
class B_T_VTOL_01_armed_blue_F : B_T_VTOL_01_armed_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class GunnerTurret_01 : GunnerTurret_01 {
            class HitPoints {};
        };
        class GunnerTurret_02 : GunnerTurret_02 {
            class HitPoints {};
        };
    };
};
class B_T_VTOL_01_armed_olive_F : B_T_VTOL_01_armed_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class GunnerTurret_01 : GunnerTurret_01 {
            class HitPoints {};
        };
        class GunnerTurret_02 : GunnerTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_2S6_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_2S6M_Base : CUP_2S6_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
    };
};
class CUP_412_01_base_F : Helicopter_Base_H {
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
class CUP_412_dynamicLoadout_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_Mil_Utility_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
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
class CUP_412_Military_Radar_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Police_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_AAV_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoGunner_1;
        class CargoGunner_2;
        class CargoGunner_3;
        class CargoGunner_4;
        class CargoGunner_5;
        class CargoGunner_6;
    };
};
class CUP_B_412_dynamicLoadout_HIL : CUP_412_dynamicLoadout_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_B_412_Mil_Utility_HIL : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_412_Military_Armed_AT_HIL : CUP_412_Military_Armed_AT_Base_F {
};
class CUP_B_412_Military_Armed_HIL : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_B_412_Military_Radar_HIL : CUP_412_Military_Radar_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_AAV_Unarmed_USMC : CUP_AAV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class CargoGunner_3 : CargoGunner_3 {
            class HitPoints {};
        };
        class CargoGunner_4 : CargoGunner_4 {
            class HitPoints {};
        };
        class CargoGunner_5 : CargoGunner_5 {
            class HitPoints {};
        };
        class CargoGunner_6 : CargoGunner_6 {
            class HitPoints {};
        };
    };
};
class CUP_B_AAV_USMC : CUP_AAV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class CargoGunner_3 : CargoGunner_3 {
            class HitPoints {};
        };
        class CargoGunner_4 : CargoGunner_4 {
            class HitPoints {};
        };
        class CargoGunner_5 : CargoGunner_5 {
            class HitPoints {};
        };
        class CargoGunner_6 : CargoGunner_6 {
            class HitPoints {};
        };
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
};
class CUP_B_BMP2_CDF : CUP_BMP2_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
    };
};
class CUP_B_BMP2_CZ : CUP_BMP2_base {
};
class CUP_B_BMP2_CZ_Des : CUP_B_BMP2_CZ {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
    };
};
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
class CUP_B_Boxer_GMG_GER_DES : CUP_Boxer_Base_GMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
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
class CUP_B_Boxer_GMG_GER_WDL : CUP_Boxer_Base_GMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
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
class CUP_B_Boxer_GMG_HIL : CUP_Boxer_Base_GMG {
};
class CUP_B_Boxer_HMG_GER_DES : CUP_Boxer_Base_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
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
class CUP_B_Boxer_HMG_GER_WDL : CUP_Boxer_Base_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
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
class CUP_B_Boxer_HMG_HIL : CUP_Boxer_Base_HMG {
};
class CUP_BTR60_Base : Wheeled_APC_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoGunner_1;
        class CargoGunner_2;
    };
};
class CUP_B_BTR60_AFU : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoGunner_1 : CargoGunner_1 {
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_BTR60_CDF : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoGunner_1 : CargoGunner_1 {
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_BTR60_FIA : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoGunner_1 : CargoGunner_1 {
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_BTR80_Common_Base : Wheeled_APC_F {
    class Turrets;
};
class CUP_BTR80_Base : CUP_BTR80_Common_Base {
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
class CUP_B_BTR80_CDF : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_B_BTR80_FIA : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_BTR80A_Base : CUP_BTR80_Common_Base {
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
class CUP_B_BTR80A_CDF : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_B_BTR80A_FIA : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_HMMWV_Base : Car_F {
    class Turrets;
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
        class MainTurret : MainTurret {
        };
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_B_HMMWV_SOV_M2_USA : CUP_HMMWV_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
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
        class MainTurret : MainTurret {
        };
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_B_HMMWV_SOV_USA : CUP_HMMWV_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_BAF_Jackal2_BASE_D : Car_F {
    class Turrets;
};
class CUP_BAF_Jackal2_GMG_D : CUP_BAF_Jackal2_BASE_D {
    class Turrets : Turrets {
        class M240_Turret;
        class GMG_Turret;
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
class CUP_BAF_Jackal2_GMG_W : CUP_BAF_Jackal2_GMG_D {
};
class CUP_B_Jackal2_GMG_FIA : CUP_BAF_Jackal2_GMG_W {
    class Turrets : Turrets {
        class M240_Turret : M240_Turret {
        };
        class GMG_Turret : GMG_Turret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_BAF_Jackal2_L2A1_D : CUP_BAF_Jackal2_BASE_D {
    class Turrets : Turrets {
        class M240_Turret;
        class M2_Turret;
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
class CUP_BAF_Jackal2_L2A1_W : CUP_BAF_Jackal2_L2A1_D {
};
class CUP_B_Jackal2_L2A1_FIA : CUP_BAF_Jackal2_L2A1_W {
    class Turrets : Turrets {
        class M240_Turret : M240_Turret {
        };
        class M2_Turret : M2_Turret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
        class CargoTurret_05 : CargoTurret_05 {
        };
        class CargoTurret_06 : CargoTurret_06 {
        };
        class CargoTurret_07 : CargoTurret_07 {
        };
        class CargoTurret_08 : CargoTurret_08 {
        };
    };
};
class CUP_LAV25_Base : Wheeled_APC_F {
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1;
        class CargoGunner_2;
    };
};
class CUP_B_LAV25_USMC : CUP_LAV25_Base {
};
class CUP_B_LAV25_desert_USMC : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25_green : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25_HQ_USMC : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class CommanderOptics;
        class CargoGunner_1 : NewTurret {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_3 : NewTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25M240_USMC : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_Leopard2_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
            };
        };
    };
};
class CUP_B_Leopard2A6_GER : CUP_Leopard2_Base {
};
class CUP_B_Leopard2A6_HIL : CUP_Leopard2_Base {
};
class CUP_Leopard2_ERA_Base : CUP_Leopard2_Base {
};
class CUP_B_Leopard2A6_UA : CUP_Leopard2_ERA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_Leopard2A6DST_GER : CUP_Leopard2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_Leopard2A6Green_UA : CUP_Leopard2_ERA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_LR_Base : Car_F {
};
class CUP_LR_Special_Base : CUP_LR_Base {
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret;
    };
};
class CUP_B_LR_Special_CZ_W : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret;
    };
};
class CUP_B_LR_Special_Des_CZ_D : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_StrykerBase : Wheeled_APC_F {
    class Turrets;
};
class CUP_M1126_ICV_BASE : CUP_StrykerBase {
    class Turrets;
};
class CUP_B_M1126_ICV_MK19_Desert : CUP_M1126_ICV_BASE {
    class Turrets : Turrets {
        class ObsTurret;
        class CargoTurret_01;
    };
};
class CUP_B_M1128_MGS_Desert : CUP_StrykerBase {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderOptics : NewTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_M1129_MC_MK19_Desert : CUP_B_M1126_ICV_MK19_Desert {
    class Turrets : Turrets {
        class MainTurret;
        class ObsTurret : ObsTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
    };
};
class CUP_M113New_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1;
        class CargoGunner_2;
        class MainTurretTurnIn;
    };
};
class CUP_M113A1_Base : CUP_M113New_Base {
};
class CUP_B_M113A1_desert_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A1_olive_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A1_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M113A3_Base : CUP_M113New_Base {
};
class CUP_B_M113A3_desert_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_GER : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_olive_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abramcs_M1A1SA_Base : CUP_M1Abrams_Base {
};
class CUP_B_M1A1_AFU : CUP_M1Abramcs_M1A1SA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_M1Abrams_TUSK_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abrams_M1A1SA_TUSK_Base : CUP_M1Abrams_TUSK_Base {
};
class CUP_B_M1A1_TUSK_AFU : CUP_M1Abrams_M1A1SA_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_M1Abrams_M1A1FEP_F_TUSK_Base : CUP_M1Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1EP_TUSK_OD_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1EP_TUSK_Woodland_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_M1Abrams_M1A1FEP_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1FEP_Desert_USMC : CUP_M1Abrams_M1A1FEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1FEP_OD_USMC : CUP_M1Abrams_M1A1FEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1FEP_TUSK_Desert_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1FEP_Woodland_USMC : CUP_M1Abrams_M1A1FEP_Base {
};
class CUP_B_M1A1SA_Desert_TUSK_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1SA_Desert_US_Army : CUP_M1Abramcs_M1A1SA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1SA_OD_US_Army : CUP_M1Abramcs_M1A1SA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1SA_TUSK_OD_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1SA_TUSK_Woodland_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_B_M1A1SA_Woodland_US_Army : CUP_M1Abramcs_M1A1SA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
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
class CUP_M1A2Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMGOptics;
            };
        };
    };
};
class CUP_B_M1A2C_Desert_US_Army : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_LDF : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_NATO : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_NATO_T : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_OD_US_Army : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_M1A2Abrams_TUSK_Base : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMGOptics;
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_Desert_US_Army : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_M1A2Abrams_TUSK_II_Base : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMGOptics;
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_Desert_US_Army : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_LDF : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_NATO : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_NATO_T : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_OD_US_Army : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_Woodland_US_Army : CUP_M1A2Abrams_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_LDF : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_NATO : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_NATO_T : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_OD_US_Army : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_Woodland_US_Army : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_B_M1A2C_Woodland_US_Army : CUP_M1A2Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMGOptics : CommanderMGOptics {
                };
            };
        };
    };
};
class CUP_M1Abrams_A2_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMG;
            };
        };
    };
};
class CUP_M1Abrams_M1A2SEP_Base : CUP_M1Abrams_A2_Base {
};
class CUP_B_M1A2SEP_Desert_US_Army : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_NATO : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_NATO_T : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_OD_US_Army : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_RACS : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M1Abrams_A2_TUSK_Base : CUP_M1Abrams_A2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMG;
            };
        };
    };
};
class CUP_M1Abrams_M1A2SEP_TUSK_Base : CUP_M1Abrams_A2_TUSK_Base {
};
class CUP_B_M1A2SEP_TUSK_Desert_US_Army : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M1Abrams_A2_TUSK_II_Base : CUP_M1Abrams_A2_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG;
                class CommanderOpticsGPSE;
                class CommanderMG;
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_II_Desert_US_Army : CUP_M1Abrams_A2_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_II_NATO : CUP_M1Abrams_A2_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_II_NATO_T : CUP_M1Abrams_A2_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_II_OD_US_Army : CUP_M1Abrams_A2_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_II_Woodland_US_Army : CUP_M1Abrams_A2_TUSK_II_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_NATO : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_NATO_T : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_OD_US_Army : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_RACS : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_TUSK_Woodland_US_Army : CUP_M1Abrams_M1A2SEP_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A2SEP_Woodland_US_Army : CUP_M1Abrams_M1A2SEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                };
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
                class CommanderMG : CommanderMG {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M270_HE_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_M270_DPICM_Base : CUP_M270_HE_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
    };
};
class CUP_B_M270_DPICM_BAF_DES : CUP_M270_DPICM_Base {
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
class CUP_B_M270_DPICM_BAF_WOOD : CUP_M270_DPICM_Base {
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
class CUP_B_M270_DPICM_HIL : CUP_M270_DPICM_Base {
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
class CUP_B_M270_DPICM_USA : CUP_M270_DPICM_Base {
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
class CUP_B_M270_DPICM_USMC : CUP_M270_DPICM_Base {
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
class CUP_B_M270_HE_BAF_DES : CUP_M270_HE_Base {
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
class CUP_B_M270_HE_BAF_WOOD : CUP_M270_HE_Base {
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
class CUP_B_M270_HE_HIL : CUP_M270_HE_Base {
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
class CUP_B_M270_HE_USA : CUP_M270_HE_Base {
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
class CUP_B_M270_HE_USMC : CUP_M270_HE_Base {
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
class CUP_Mastiff_Base : Wheeled_APC_F {
    class Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class commanderoptics;
    };
};
class CUP_B_Mastiff_GMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_GMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_HMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_HMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
        };
        class CommanderTurret : CommanderTurret {
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_LMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret;
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_LMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret;
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_Merlin_HC3_Base;
class CUP_Merlin_HC3_Armed_Base : CUP_Merlin_HC3_Base {
    class Turrets;
};
class CUP_B_Merlin_HC3_Armed_GB : CUP_Merlin_HC3_Armed_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Merlin_HC3_GB_Armed : CUP_B_Merlin_HC3_Armed_GB {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
class CUP_Merlin_HC3A_Armed_Base : CUP_Merlin_HC3_Armed_Base {
};
class CUP_B_Merlin_HC3A_Armed_GB : CUP_Merlin_HC3A_Armed_Base {
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Merlin_HC3A_GB_Armed : CUP_B_Merlin_HC3A_Armed_GB {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
        };
        class CargoTurret_02 : CargoTurret_02 {
        };
        class CargoTurret_03 : CargoTurret_03 {
        };
        class CargoTurret_04 : CargoTurret_04 {
        };
    };
};
