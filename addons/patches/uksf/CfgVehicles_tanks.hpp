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
