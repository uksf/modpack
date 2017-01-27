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
        hit = 2; //Reduced from 10, 4
    };
    class MissileBase;
    class CUP_M_AGM_114K_Hellfire_II_AT : MissileBase {
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
};