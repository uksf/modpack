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
class uksf_cdf_Praetorian : B_AAA_System_01_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
