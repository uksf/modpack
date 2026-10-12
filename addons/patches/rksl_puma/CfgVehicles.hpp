class All {
    class AnimationSources;
};
class AllVehicles : All {
    class NewTurret;
};
class Air : AllVehicles {
    class AnimationSources;
};
class Helicopter : Air {
    class AnimationSources;
};
class Helicopter_Base_F : Helicopter {
    class Turrets;
};
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources : AnimationSources {
        class HitEngine2;
    };
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class rksla3_pumahc_base : Helicopter_Base_H {
    class Turrets : Turrets {
        class CopilotTurret;
    };
};
class rksla3_puma_hc1_1gpmg : rksla3_pumahc_base {
    class Turrets : Turrets {
        class CopilotTurret;
        class RH_Turret : MainTurret {
            class HitPoints {};
        };
    };
};
class rksla3_puma_hc1_2gpmg : rksla3_pumahc_base {
    class Turrets : Turrets {
        class CopilotTurret;
        class RH_Turret : MainTurret {
            class HitPoints {};
        };
        class LH_Turret : RH_Turret {
            class HitPoints {};
        };
    };
};
