class CfgAmmo{
    class B_762x51_Ball;
    class UK3CB_BAF_762_Ball: B_762x51_Ball {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class B_762x51_Tracer_Red;
    class UK3CB_BAF_762_Ball_Tracer_Red: B_762x51_Tracer_Red {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class UK3CB_BAF_762_Ball_EL: UK3CB_BAF_762_Ball {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class UK3CB_BAF_762_Ball_Tracer_Red_EL: UK3CB_BAF_762_Ball_Tracer_Red {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class BulletBase;
    class UK3CB_BAF_B_12Gauge_Pellets: BulletBase {
        hit = 5; //Increased from 2, 4, 10
    };
    class B_556x45_Ball;
    class B_556x45_Ball_Rubber: B_556x45_Ball {
        hit = 0.25;
        cost = 1;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    };
    class CUP_B_762x51_Tracer_White;
    class CUP_B_762x51_Tracer_White_Rubber: CUP_B_762x51_Tracer_White {
        hit = 0.25;
        cost = 1;
    };
    class B_127x99_Ball_Tracer_Red;
    class B_127x99_Ball_Tracer_White_Rubber: B_127x99_Ball_Tracer_Red {
        hit = 0.25;
        cost = 1;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
    };
    class CUP_R_SMAW_HEAA_N;
    class CUP_R_SMAW_HEAT_N_Rubber: CUP_R_SMAW_HEAA_N {
        hit = 0.5;
        indirecthit = 0;
        indirecthitrange = 0;
        cost = 1;
        ace_frag_enabled = 0;
        mass = 20;
    };
    class CUP_M_Stinger_AA;
    class CUP_M_Stinger_AA_Rubber: CUP_M_Stinger_AA {
        hit = 31;
        indirecthit = 10;
        indirecthitrange = 1;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class Sh_120mm_APFSDS;
    class Sh_120mm_APFSDS_Tracer_White_Rubber: Sh_120mm_APFSDS {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = 0;
        cost = 1;
    };
    class Sh_120mm_HE;
    class Sh_120mm_HE_Tracer_White_Rubber: Sh_120mm_HE {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        dangerRadiusHit = 0;
        suppressionRadiusHit = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class CUP_B_25mm_HE_White_Tracer;
    class CUP_B_25mm_HE_White_Tracer_Rubber: CUP_B_25mm_HE_White_Tracer {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };
    class CUP_B_25mm_APFSDS_White_Tracer;
    class CUP_B_25mm_APFSDS_White_Tracer_Rubber: CUP_B_25mm_APFSDS_White_Tracer {
        hit = 0.5;
        indirectHit = 0;
        indirectHitRange = 0;
        cost = 1;
        ace_frag_enabled = 0;
    };

    class MissileBase;
    class CUP_M_AGM_114K_Hellfire_II_AT: MissileBase {
        model = QPATHTOF(data\AGM114\AGM114Hellfire.p3d);
        proxyShape = QPATHTOF(data\AGM114\AGM114Hellfire_proxy.p3d);
        CraterEffects = "ATRocketCrater";
        explosionEffects = "ATRocketExplosion";
        class Hiteffects {
            hitWater = "ImpactEffectsWaterBig";
        };
        hit = 1400;
        indirectHit = 50;
        indirectHitRange = 4;
        irLock = 0;
        laserLock = 1;
        weaponLockSystem = 4;
        maxSpeed = 475;
        ace_frag_enabled = 1;
        ace_frag_classes[] = { "ACE_frag_medium", "ACE_frag_medium_HD" };
        ace_frag_metal = 8000;
        ace_frag_charge = 2400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
        //SoundSetExplosion[] = { "DS_Ex_rocket_big_SoundSet","DS_exploBig_Tail_placeholder_SoundSet" };
    };
    class CUP_M_AGM_114L_Hellfire_II_AT: MissileBase {
        model = QPATHTOF(data\AGM114\AGM114Hellfire.p3d);
        proxyShape = QPATHTOF(data\AGM114\AGM114Hellfire_proxy.p3d);
        CraterEffects = "ATRocketCrater";
        explosionEffects = "ATRocketExplosion";
        class Hiteffects {
            hitWater = "ImpactEffectsWaterBig";
        };
        //SoundSetExplosion[] = { "DS_Ex_rocket_big_SoundSet","DS_exploBig_Tail_placeholder_SoundSet" };
    };
    class CUP_M_AGM_114N_Hellfire_II_AT: CUP_M_AGM_114K_Hellfire_II_AT {
        hit = 1100;
        indirectHit = 200;
        indirectHitRange = 7;
        explosionEffects = "BombExplosion";
        aiAmmoUsageFlags = "64 + 128";
        ace_frag_metal = 4000;
        ace_frag_charge = 1500;
        ace_frag_gurney_c = 1800;
    };
    class CUP_R_70mm_Hydra_HE;
    class CUP_R_CRV7_FAT: CUP_R_70mm_Hydra_HE {
        hit = 800;
        indirectHit = 8;
        indirectHitRange = 3;
        maxSpeed = 975;
        thrustTime = 0.93;
        thrust = 1150;
        aiAmmoUsageFlags = "128 + 256";
        ace_frag_enabled = 0;
        CraterEffects = "ATRocketCrater";
        explosionEffects = "ATRocketExplosion";
        class HitEffects {
            hitWater = "ImpactEffectsWaterBig";
        };
        //SoundSetExplosion[] = { "DS_Ex_rocket_small_SoundSet","DS_exploBig_Tail_placeholder_SoundSet" };
    };
    class CUP_R_CRV7_HEISAP: CUP_R_CRV7_FAT {
        hit = 400;
        indirectHit = 60;
        indirectHitRange = 15;
        aiAmmoUsageFlags = "64 + 128";
        ace_frag_enabled = 1;
        ace_frag_classes[] = { "ACE_frag_medium", "ACE_frag_medium_HD" };
        ace_frag_metal = 3850;
        ace_frag_charge = 1040;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
        CraterEffects = "HERocketCrater";
        explosionEffects = "HERocketExplosion";
        class HitEffects {
            hitWater = "ImpactEffectsWaterBig";
        };
    };
    class CUP_B_30x113mm_M789_HEDP_Red_Tracer: BulletBase {
        //SoundSetExplosion[] = { "DS_Ex_small_impact_SoundSet", "DS_exploSmall_Tail_placeholder_SoundSet", "Explosion_Debris_SoundSet" };
        CraterEffects = "ExploAmmoCrater";
        explosionEffects = "ExploAmmoExplosion";
        class HitEffects {
            hitWater = "ImpactEffectsWater";
        };
        hit = 105;
        indirectHit = 15;
        indirectHitRange = 4;
        tracerEndTime = 30;
        caliber = 4.2;
    };
    class M_Titan_AA;
    class UKSF_Dummy_Missile: M_Titan_AA {
        indirectHitRange = 1;
        fusedistance = 0.01;
        inittime = 0.01;
        timetolive = 0.01;        
        ace_frag_enabled = 1;
        ace_frag_classes[] = { "ACE_frag_medium", "ACE_frag_medium_HD" };
        ace_frag_metal = 8000;
        ace_frag_charge = 2400;
        ace_frag_gurney_c = 2700;
        ace_frag_gurney_k = "1/2";
    };
};
