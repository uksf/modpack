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
class SmokeShell;
class GVAR(105mm_smoke_shell) : SmokeShell {
    simulation = "shotSmokeX";
    model = "\A3\Weapons_F\explosives\mine_AP_bouncing";
    airFriction = -2;
    explosionTime = 0;
    deflecting = 45;
    deflectionSlowDown = 0.1;
    deflectionDirDistribution = 0.1;
    timeToLive = 90;
    effectsSmoke = QGVAR(SmokeMortarEffect);
};
class tbd_mortars_105mm_shell_ammo_smoke : SubmunitionCore {
    hit = 100;
    indirectHit = 1;
    indirectHitRange = 1;
    explosive = 0.01;
    submunitionAmmo = QGVAR(105mm_smoke_shell);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionConeAngle = 5;
    submunitionConeType[] = { "poissondisc", 3 };
    submunitionInitialOffset[] = { 0, 0, 0 };
    deleteParentWhenTriggered = 0;
    submunitionParentSpeedCoef = 0.5;
    submunitionInitSpeed = 0;
    triggerOnImpact = 1;
    explosionEffects = "";
};
class GVAR(105mm_shell_smoke_empty) : tbd_mortars_105mm_shell_ammo_smoke {
    hit = 100;
    indirectHit = 1;
    indirectHitRange = 1;
    explosive = 0.01;
    submunitionAmmo = "";
    explosionEffectsRadius = 0.5;
    explosionForceCoef = 0.2;
    explosionEffects = "GrenadeExplosion";
    CraterEffects = "ExploAmmoCrater";
    CraterWaterEffects = "ImpactEffectsWaterHE";
    SoundSetExplosion[] = { "jsrs_2025_shell_blunt_hit_soundset", "jsrs_2025_debris_small_soundset" };
    class HitEffects {
        hitVirtual = "ImpactMetalSabotSmall";
        HitMetal = "ImpactMetalSabotSmall";
        HitMetalPlate = "ImpactMetalSabotSmall";
        hitBuilding = "BCImpactConcrete_30mm";
        hitConcrete = "BCImpactConcrete_30mm";
        hitGroundSoft = "BCImpactDirt_120mm";
        hitGroundHard = "BCImpactDirt_120mm";
        default_mat = "BCImpactDirt_30mm";
        Hit_Foliage_green = "BCImpactDirt_30mm";
        Hit_Foliage_Dead = "BCImpactDirt_30mm";
        Hit_Foliage_Green_big = "BCImpactDirt_30mm";
        Hit_Foliage_Palm = "BCImpactDirt_30mm";
        Hit_Foliage_Pine = "BCImpactDirt_30mm";
        hitWood = "ImpactWood_Big";
        hitWater = "ImpactEffectsWater";
    };
};
