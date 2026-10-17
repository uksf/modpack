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
class APC_Tracked_01_base_F : Tank_F {
    class AnimationSources;
};
class B_APC_Tracked_01_base_F : APC_Tracked_01_base_F {};
class APC_Tracked_02_base_F : Tank_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "autocannon_30mm_CTWS";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class O_APC_Tracked_02_base_F : APC_Tracked_02_base_F {};
class LT_01_base_F : Tank_F {
    class AnimationSources;
};
class LT_01_cannon_base_F : LT_01_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "ACE_cannon_20mm_Rh202";
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
class O_APC_Tracked_02_AA_F : O_APC_Tracked_02_base_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon {
            source = "reload";
            weapon = "autocannon_35mm";
        };
    };
};
