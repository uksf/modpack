class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateActiveRadar;

class CfgAmmo {
    class B_762x51_Ball;
    class UK3CB_BAF_762_Ball : B_762x51_Ball {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class B_762x51_Tracer_Red;
    class UK3CB_BAF_762_Ball_Tracer_Red : B_762x51_Tracer_Red {
        ACE_bulletMass = 10.0438;
        hit = 14;
        caliber = 1.6;
    };
    class UK3CB_BAF_762_Ball_EL : UK3CB_BAF_762_Ball {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class UK3CB_BAF_762_Ball_Tracer_Red_EL : UK3CB_BAF_762_Ball_Tracer_Red {
        hit = 12;
        tracerEndTime = 4.15957;
    };
    class BulletBase;
    class UK3CB_BAF_B_12Gauge_Pellets : BulletBase {
        hit = 5;  // Increased from 2, 4, 10
    };
    class B_408_Ball;
    class UK3CB_BAF_338_Ball_Tracer_Red : B_408_Ball {
        tracerEndTime = 3;  // 1
    };
    class UK3CB_BAF_B_127x99_Ball;
    class UK3CB_BAF_B_127x99_T : UK3CB_BAF_B_127x99_Ball {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class Flare_82mm_AMOS_White;
    class UK3CB_BAF_Flare_81mm_AMOS_White : Flare_82mm_AMOS_White {
        deflecting = 30;
        useFlare = 1;
        lightColor[] = { 0.5, 0.5, 0.5, 0.5 };
        smokeColor[] = { 1, 1, 1, 0.5 };
        brightness = 12000000;
        intensity = 8000000;
        size = 1;
        flareSize = 24;
    };
    class UK3CB_BAF_Flare_60mm_AMOS_White : UK3CB_BAF_Flare_81mm_AMOS_White {
        brightness = 9000000;
        intensity = 6000000;
        flareSize = 18;
    };
    class UK3CB_BAF_Sh_60mm_AMOS_AB;
    class UK3CB_BAF_Sh_60mm_AMOS_AB_helper : UK3CB_BAF_Sh_60mm_AMOS_AB {
        indirectHitRange = 10;  // 21
    };
    class UK3CB_BAF_Sh_81mm_AMOS_AB;
    class UK3CB_BAF_Sh_81mm_AMOS_AB_helper : UK3CB_BAF_Sh_81mm_AMOS_AB {
        indirectHitRange = 18;  // 32
    };

    class Chemlight_red;
    class ACE_G_Chemlight_HiRed : Chemlight_red {
        timeToLive = 3600;
    };
    class Chemlight_yellow;
    class ACE_G_Chemlight_HiYellow : Chemlight_yellow {
        timeToLive = 3600;
    };
    class ACE_G_Chemlight_White;
    class ACE_G_Chemlight_HiWhite : ACE_G_Chemlight_White {
        timeToLive = 3600;
    };
    class Chemlight_Blue;
    class ACE_G_Chemlight_HiBlue : Chemlight_Blue {
        timeToLive = 3600;
    };
    class Chemlight_Green;
    class ACE_G_Chemlight_HiGreen : Chemlight_Green {
        timeToLive = 3600;
    };

    class DemoCharge_Remote_Ammo;
    class BreachCharge_Remote_Ammo : DemoCharge_Remote_Ammo {
        hit = 200;
        indirectHit = 200;
        indirectHitRange = 1;
        defaultMagazine = "BreachCharge_Remote_Mag";
        mineInconspicuousness = 4;
        mineTrigger = "RemoteTrigger";
        explosionEffectsRadius = 5;
        CraterEffects = "GrenadeCrater";
        CraterWaterEffects = "ImpactEffectsWaterExplosion";
        explosionEffects = "GrenadeExplosion";
        SoundSetExplosion[] = { "JPEX_GRENADE_EXPLOSION_SoundSet", "JPEX_GRENADE_REFLECTOR_SoundSet", "JPEX_Medium_Debris_SoundSet" };
        ace_explosives_magazine = "BreachCharge_Remote_Mag";
        ace_explosives_Explosive = "BreachCharge_Remote_Ammo_Scripted";
    };
    class BreachCharge_Remote_Ammo_Scripted : BreachCharge_Remote_Ammo {};
};
