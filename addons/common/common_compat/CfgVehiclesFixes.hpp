// MBG's sound sources have no parent, so they lack every base vehicle entry and have no simulation.
class Sound;
class MBG_SndSrc_DoorOpen : Sound {};
// Two FFAA buildings list a ladder whose start1/end1 points their models do not have.
class ffaa_casa_af_base;
class land_ffaa_casa_urbana_8 : ffaa_casa_af_base {
    ladders[] = {};
};
class land_ffaa_casa_hangar_2 : ffaa_casa_af_base {
    ladders[] = {};
};
// Expeden's ScopeShieldDeMount declares ViewOptics directly in StaticMGWeapon's Turrets, so every static MG
// that inherits that list (Fort_Nest_M240) gets an empty second turret.
class LandVehicle;
class StaticWeapon : LandVehicle {
    class Turrets;
};
class StaticMGWeapon : StaticWeapon {
    class Turrets : Turrets {
        delete ViewOptics;
    };
};
// aggregateReflectors is a list of groups; CUP gives the M151 headlights as one flat list.
class Car;
class Car_F : Car {
    class AnimationSources;
};
class CUP_M151_base : Car_F {
    aggregateReflectors[] = { { "LightCarHeadL01", "LightCarHeadR01" } };
};
// 3CB's CW DPM smock unit names its uniform with a trailing space, so the two never resolve to each other.
class UK3CB_BAF_Soldier_Smock_Base;
class UK3CB_BAF_Soldier_Smock_CW_DPM_Base : UK3CB_BAF_Soldier_Smock_Base {
    uniformClass = "UK3CB_BAF_U_Smock_CW_DPM";
};
// Vanilla's HitEngine2 damage source names hitpoint Engine2; every helicopter's hitpoint is HitEngine2.
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources : AnimationSources {
        class HitEngine2 {
            hitpoint = "HitEngine2";
        };
    };
};
// CUP's Tigr HitGlass10 damage source names hitpoint HitGlas104.
class CUP_Tigr_Base : Car_F {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_SPM_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_STS_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_M_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
