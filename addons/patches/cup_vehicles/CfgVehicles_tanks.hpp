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
class APC_Tracked_02_base_F : Tank_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon;
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_M113New_Base : Tank_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1;
        class CargoGunner_2;
        class MainTurretTurnIn;
    };
};
class CUP_M113A3_Base : CUP_M113New_Base {};
class CUP_M113A1_Base : CUP_M113New_Base {};
class CUP_M113New_HQ_Base : CUP_M113New_Base {
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
class CUP_M113New_Med_Base : CUP_M113New_Base {
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
class CUP_T90M_Base : Tank_F {
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
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : NewTurret {
                    class HitPoints {};
                };
                class CommanderPeriscope : NewTurret {
                    class HitPoints {};
                };
            };
        };
    };
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
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
class CUP_BMP2_Ambul_Base : CUP_BMP2_base {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
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
    };
};
class CUP_BMP2_HQ_Base : CUP_BMP2_base {
    class AnimationSources {
        class hatchc {
            source = "door";
            animPeriod = 0.8;
        };
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class hatchd {
            source = "door";
            animPeriod = 0.8;
        };
        class hatchg {
            source = "door";
            animPeriod = 0.8;
        };
    };
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_BMP2_ZU_base : CUP_BMP2_base {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
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
class CUP_B_BMP2_CZ_Des : CUP_B_BMP2_CZ {
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
class CUP_Leopard2_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_Leopard2_ERA_Base : CUP_Leopard2_Base {};
class CUP_B_Leopard2A6_UA : CUP_Leopard2_ERA_Base {
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
class CUP_B_Leopard2A6DST_GER : CUP_Leopard2_Base {
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
class CUP_B_Leopard2A6Green_UA : CUP_Leopard2_ERA_Base {
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
class CUP_B_M113A1_desert_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
class CUP_B_M113A3_desert_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
        class MainTurret : MainTurret {};
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
                class LoaderTurretMG : LoaderTurret {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abramcs_M1A1SA_Base : CUP_M1Abrams_Base {};
class CUP_B_M1A1_AFU : CUP_M1Abramcs_M1A1SA_Base {
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
class CUP_M1Abrams_TUSK_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abrams_M1A1SA_TUSK_Base : CUP_M1Abrams_TUSK_Base {};
class CUP_B_M1A1_TUSK_AFU : CUP_M1Abrams_M1A1SA_TUSK_Base {
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
class CUP_M1Abrams_M1A1FEP_F_TUSK_Base : CUP_M1Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1EP_TUSK_OD_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
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
class CUP_B_M1A1EP_TUSK_Woodland_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
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
class CUP_M1Abrams_M1A1FEP_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1FEP_Desert_USMC : CUP_M1Abrams_M1A1FEP_Base {
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
class CUP_B_M1A1FEP_OD_USMC : CUP_M1Abrams_M1A1FEP_Base {
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
class CUP_B_M1A1FEP_TUSK_Desert_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
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
class CUP_B_M1A1SA_Desert_TUSK_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
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
class CUP_B_M1A1SA_Desert_US_Army : CUP_M1Abramcs_M1A1SA_Base {
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
class CUP_B_M1A1SA_OD_US_Army : CUP_M1Abramcs_M1A1SA_Base {
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
class CUP_B_M1A1SA_TUSK_OD_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
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
class CUP_B_M1A1SA_TUSK_Woodland_US_Army : CUP_M1Abrams_M1A1SA_TUSK_Base {
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
class CUP_B_M1A1SA_Woodland_US_Army : CUP_M1Abramcs_M1A1SA_Base {
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
class CUP_M1A2Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurret {
                    stabilizedInAxes = 3;
                };
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_LDF : CUP_M1A2Abrams_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_NATO : CUP_M1A2Abrams_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_NATO_T : CUP_M1A2Abrams_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_OD_US_Army : CUP_M1A2Abrams_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
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
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
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
                class CommanderMGOptics : CommanderMGOptics {};
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
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_LDF : CUP_M1A2Abrams_TUSK_II_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_NATO : CUP_M1A2Abrams_TUSK_II_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_NATO_T : CUP_M1A2Abrams_TUSK_II_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_OD_US_Army : CUP_M1A2Abrams_TUSK_II_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_II_Woodland_US_Army : CUP_M1A2Abrams_TUSK_II_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_LDF : CUP_M1A2Abrams_TUSK_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_NATO : CUP_M1A2Abrams_TUSK_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_NATO_T : CUP_M1A2Abrams_TUSK_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_OD_US_Army : CUP_M1A2Abrams_TUSK_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_TUSK_Woodland_US_Army : CUP_M1A2Abrams_TUSK_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
            };
        };
    };
};
class CUP_B_M1A2C_Woodland_US_Army : CUP_M1A2Abrams_Base {
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
                class CommanderMGOptics : CommanderMGOptics {};
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
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
                class CommanderMG;
            };
        };
    };
};
class CUP_M1Abrams_M1A2SEP_Base : CUP_M1Abrams_A2_Base {};
class CUP_B_M1A2SEP_Desert_US_Army : CUP_M1Abrams_M1A2SEP_Base {
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
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
                class CommanderMG;
            };
        };
    };
};
class CUP_M1Abrams_M1A2SEP_TUSK_Base : CUP_M1Abrams_A2_TUSK_Base {};
class CUP_B_M1A2SEP_TUSK_Desert_US_Army : CUP_M1Abrams_M1A2SEP_TUSK_Base {
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
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
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
        class MainTurret : MainTurret {};
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
class CUP_B_T72_CDF : CUP_T72_Base {
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
class CUP_T72_ACR_Base : CUP_T72_Base {
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
class CUP_B_T72_CZ : CUP_T72_ACR_Base {
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
class CUP_ZSU23_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_ZSU23_Afghan_Base : CUP_ZSU23_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_B_ZSU23_Afghan_CDF : CUP_ZSU23_Afghan_Base {
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
class CUP_BMP1P_base : CUP_BMP1_base {
    class Turrets : Turrets {
        class CommanderOptics;
        class MainTurret;
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
class CUP_I_AAV_RACS : CUP_AAV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_I_BMP1_TK_GUE : CUP_BMP1_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_I_BMP2_NAPA : CUP_BMP2_base {
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
class CUP_I_BMP2_UN : CUP_BMP2_base {
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
class CUP_I_M113A1_RACS : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_I_M113A1_RACS_URB : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_I_M113A3_AAF : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_I_M113A3_UN : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_I_M270_DPICM_AAF : CUP_M270_DPICM_Base {
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
class CUP_I_M270_DPICM_RACS : CUP_M270_DPICM_Base {
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
class CUP_I_M270_HE_AAF : CUP_M270_HE_Base {
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
class CUP_I_M270_HE_RACS : CUP_M270_HE_Base {
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
class CUP_I_T55_NAPA : CUP_T55_Base {
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
class CUP_I_T55_TK_GUE : CUP_T55_Base {
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
class CUP_I_T72_NAPA : CUP_T72_Base {
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
class CUP_I_T72_RACS : CUP_T72_Base {
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
class CUP_I_ZSU23_AAF : CUP_ZSU23_Base {
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
class CUP_I_ZSU23_Afghan_AAF : CUP_ZSU23_Afghan_Base {
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
class CUP_O_2S6_RU : CUP_2S6_Base {
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
class CUP_O_2S6M_RU : CUP_2S6M_Base {
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
class CUP_O_BMP1_CSAT : CUP_BMP1_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP1_CSAT_T : CUP_BMP1_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP1_TKA : CUP_BMP1_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP1P_CSAT : CUP_BMP1P_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP1P_CSAT_T : CUP_BMP1P_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP1P_TKA : CUP_BMP1P_base {
    class Turrets : Turrets {
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
        class CargoTurret_08 : CargoTurret_08 {
            class HitPoints {};
        };
    };
};
class CUP_O_BMP2_CHDKZ : CUP_BMP2_base {
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
class CUP_O_BMP2_CSAT : CUP_BMP2_base {
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
class CUP_O_BMP2_CSAT_T : CUP_BMP2_base {
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
class CUP_O_BMP2_RU : CUP_BMP2_base {
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
class CUP_O_BMP2_SLA : CUP_BMP2_base {
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
class CUP_O_BMP2_TKA : CUP_BMP2_base {
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
class CUP_O_BMP3_CSAT_T : CUP_BMP3_Base {
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
class CUP_O_M113A3_TKA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
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
class CUP_O_T55_CSAT : CUP_T55_Base {
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
class CUP_O_T55_CSAT_T : CUP_T55_Base {
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
class CUP_O_T55_TK : CUP_T55_Base {
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
class CUP_O_T72_CHDKZ : CUP_T72_Base {
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
class CUP_O_T72_CSAT : CUP_T72_Base {
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
class CUP_O_T72_CSAT_T : CUP_T72_Base {
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
class CUP_O_T72_TKA : CUP_T72_Base {
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
class CUP_O_ZSU23_Afghan_ChDKZ : CUP_ZSU23_Afghan_Base {
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
class CUP_O_ZSU23_Afghan_CSAT : CUP_ZSU23_Afghan_Base {
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
class CUP_O_ZSU23_Afghan_SLA : CUP_ZSU23_Afghan_Base {
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
class CUP_O_ZSU23_Afghan_TK : CUP_ZSU23_Afghan_Base {
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
class CUP_O_ZSU23_CSAT : CUP_ZSU23_Base {
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
class CUP_O_ZSU23_TK : CUP_ZSU23_Base {
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
class CUP_T34_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class FrontGunner : MainTurret {
            stabilizedInAxes = 3;
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
class CUP_T90_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : NewTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_Challenger2_base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_M1_Abrams_base : Tank_F {
    class NewTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets;
        };
    };
};
class CUP_M1A2_TUSK_base : CUP_M1_Abrams_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
