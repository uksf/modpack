#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_weapons"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

// https://github.com/nk3nny/LambsMods/blob/master/addons/rpg/config.cpp
class Mode_SemiAuto;
class CfgWeapons {
    class Launcher_Base_F;
    class Launch_RPG7_F : Launcher_Base_F {
        primary = 11;
        class Single : Mode_SemiAuto {
            aiDispersionCoefX = 1.7;
            aiDispersionCoefY = 2.2;
            aiRateOfFire = 10;
            aiRateOfFireDistance = 300;
            aiRateOfFireDispersion = 10;
            minRange = 5;
            minRangeProbab = 0.56;
            midRange = 250;
            midRangeProbab = 0.9;
            maxRange = 500;
            maxRangeProbab = 0.4;
            recoil = "recoil_single_law";
            sounds[] = {"StandardSound"};
        };
    };
    class launch_RPG32_F : Launcher_Base_F {
        class Single : Mode_SemiAuto {
            aiDispersionCoefX = 1.7;
            aiDispersionCoefY = 2.2;
            aiRateOfFire = 12;
            aiRateOfFireDistance = 400;
            aiRateOfFireDispersion = 3;
            minRange = 10;
            minRangeProbab = 0.3;
            midRange = 200;
            midRangeProbab = 0.85;
            maxRange = 600;
            maxRangeProbab = 0.85;
            recoil = "recoil_single_law";
            sounds[] = {"StandardSound"};
        };
    };
};

class CfgAmmo {
    class BulletBase;
    class B_19mm_HE : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class B_30mm_HE : B_19mm_HE {
        AMMO_USAGE_INFVEHAIR;
    };
    class B_20mm : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class B_25mm : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class B_20mm_AP : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class B_30mm_AP : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class Gatling_30mm_HE_Plane_CAS_01_F : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_19mm_HE : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_20mm_AP_Tracer_Red : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_20mm_APHE_Tracer_Red : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_20mm_API_Tracer_Red : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_20mm_AA : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_23mm_APHE_Tracer_Green : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_23mm_AA : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_23mm_APHE_No_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_23mm_APHE_Green_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_30x113mm_M789_HEDP_Red_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_30mm_CAS_Red_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_25mm_HE_White_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_B_25mm_APFSDS_White_Tracer : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_R_57mm_HE : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class ammo_Gun20mmAABase : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class ammo_Gun30mmAABase : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class ammo_Gun35mmAABase : BulletBase {
        AMMO_USAGE_INFVEHAIR;
    };
    class CUP_Sh_PG9_AT : BulletBase {
        AMMO_USAGE_INFVEHAIRARM;
    };

    class Default;
    class BombCore : Default {
        AMMO_USAGE_INFVEHARM;
    };
    class LaserBombCore;
    class ammo_Bomb_LaserGuidedBase : LaserBombCore {
        AMMO_USAGE_INFVEHARM;
    };

    class RocketBase;
    class R_PG32V_F : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class R_TBG32V_F : R_PG32V_F {
        AMMO_USAGE_INFVEHAIR;
        AMMO_USAGE_BUFF;
    };
    class R_PG7_F : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_PG7V_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_PG7VM_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_PG7VL_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_PG7VR_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_TBG7V_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_OG7_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_70mm_Hydra_HE : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_RPG18_AT : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_SMAW_HEDP : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class CUP_R_SMAW_HEDP_N : RocketBase {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };
    class R_MRAAWS_HEAT_F;
    class R_MRAAWS_HE_F : R_MRAAWS_HEAT_F {
        AMMO_USAGE_INFVEHAIRARM;
        AMMO_USAGE_BUFF;
    };

    class MissileBase;
    class M_Titan_AT : MissileBase {
        AMMO_USAGE_INFVEHARM;
    };
    class Missile_AGM_02_F : MissileBase {
        AMMO_USAGE_INFVEHARM;
    };
    class Rocket_04_HE_F : MissileBase {
        AMMO_USAGE_INFVEHAIRARM;
    };
    class CUP_AGM65pod_AT : MissileBase {
        AMMO_USAGE_INFVEHARM;
    };
    class M_Vorona_HEAT;
    class M_Vorona_HE : M_Vorona_HEAT {
        AMMO_USAGE_INFVEHARM;
    };
    class CUP_R_TOW_AT : M_Titan_AT {
        airLock = 0;
    };

    class ShellBase;
    class CUP_Sh_PG15V : ShellBase {
        AMMO_USAGE_INFVEHARM;
    };
};
