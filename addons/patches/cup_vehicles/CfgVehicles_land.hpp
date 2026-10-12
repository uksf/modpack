class CUP_UAZ_Armed_Base : CUP_UAZ_Base {
    class AnimationSources;
    class Turrets;
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
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
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
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
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
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AA_Base : CUP_UAZ_Armed_Base {
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
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AGS30_Base : CUP_UAZ_Armed_Base {
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
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
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
class CUP_B_Boxer_GMG_GER_WDL : CUP_Boxer_Base_GMG {
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
class CUP_B_Boxer_HMG_GER_DES : CUP_Boxer_Base_HMG {
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
class CUP_B_Boxer_HMG_GER_WDL : CUP_Boxer_Base_HMG {
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
