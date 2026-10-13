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
