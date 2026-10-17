class StaticWeapon : LandVehicle {
    class Turrets;
};
class StaticMGWeapon : StaticWeapon {
    class Turrets : Turrets {
        delete ViewOptics;
    };
};
class Radar_System_02_base_F : StaticMGWeapon {
    class AnimationSources;
};
class AAA_System_01_base_F : StaticMGWeapon {
    class Turrets : Turrets {
        class MainTurret;
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
