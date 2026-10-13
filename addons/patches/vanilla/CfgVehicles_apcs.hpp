class Wheeled_APC_F : Car_F {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
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
class APC_Wheeled_02_base_F : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitengine_src {
            source = "Hit";
            hitpoint = "HitEngine";
            raw = 1;
        };
        class hitfuel_src {
            source = "Hit";
            hitpoint = "HitFuel";
            raw = 1;
        };
        class hithull_src {
            source = "Hit";
            hitpoint = "HitHull";
            raw = 1;
        };
        class hitmaingun_src {
            source = "Hit";
            hitpoint = "HitGun";
            raw = 1;
        };
        class hitslat_back_src {
            source = "Hit";
            hitpoint = "HitSLAT_back";
            raw = 1;
        };
        class hitslat_front_src {
            source = "Hit";
            hitpoint = "HitSLAT_front";
            raw = 1;
        };
        class hitslat_left_1_src {
            source = "Hit";
            hitpoint = "HitSLAT_Left_1";
            raw = 1;
        };
        class hitslat_left_2_src {
            source = "Hit";
            hitpoint = "HitSLAT_Left_2";
            raw = 1;
        };
        class hitslat_left_3_src {
            source = "Hit";
            hitpoint = "HitSLAT_Left_3";
            raw = 1;
        };
        class hitslat_right_1_src {
            source = "Hit";
            hitpoint = "HitSLAT_Right_1";
            raw = 1;
        };
        class hitslat_right_2_src {
            source = "Hit";
            hitpoint = "HitSLAT_Right_2";
            raw = 1;
        };
        class hitslat_right_3_src {
            source = "Hit";
            hitpoint = "HitSLAT_Right_3";
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
    class Turrets : Turrets {
        class MainTurret;
        class CommanderOptics;
    };
};
class O_APC_Wheeled_02_base_F : APC_Wheeled_02_base_F {};
class O_APC_Wheeled_02_rcws_F : O_APC_Wheeled_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
    };
};
class O_T_APC_Wheeled_02_rcws_ghex_F : O_APC_Wheeled_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderOptics : CommanderOptics {
            class HitPoints {};
        };
    };
};
