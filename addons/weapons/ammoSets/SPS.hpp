class B_SPS_338_ball_HAPI : B_SPS_338_ball_API526 {
    timeToLive = 10;
    caliber = 2.8;
    deflecting = 10;
    hit = 30; // 16
    indirectHit = 4;
    indirectHitRange = 0.2;
    explosive = 0.1;
    class CamShakeExplode {
        power = 4;
        duration = 0.8;
        frequency = 20;
        distance = 75.7771;
    };
    class CamShakeHit {
        power = 20;
        duration = 0.4;
        frequency = 20;
        distance = 1;
    };
    explosionEffects = "CUP_AA12AmmoExplosion";
    craterEffects = "CUP_AA12AmmoImpact";
    class HitEffects {
        hitWater = "ImpactEffectsWater";
    };
    SoundSetExplosion[] = {
        "JPEX_20mm_EXPLOSION_SoundSet", "JPEX_20mm_REFLECTOR_SoundSet"
    };
    ace_vehicle_damage_incendiary = 0.1;
};
