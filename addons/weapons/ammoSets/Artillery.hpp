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
    model = "\A3\weapons_f\ammo\shell_smoke";
    explosionTime = 0;
    deflecting = 10;
    timeToLive = 90;
    effectsSmoke = QGVAR(SmokeMortarEffect);
};
class tbd_mortars_105mm_shell_ammo_smoke : SubmunitionCore {
    hit = 100;
    indirectHit = 0;
    indirectHitRange = 4;
    submunitionAmmo = QGVAR(105mm_smoke_shell);
    submunitionDirectionType = "SubmunitionModelDirection";
    submunitionConeType[] = { "poissondisc", 3 };  // 20
    submunitionConeAngle = 10;
    submunitionConeAngleHorizontal = 10;
    submunitionInitialOffset[] = { 0, 0, -0.2 };
    deleteParentWhenTriggered = 0;
    triggerSpeedCoef[] = { 0.9, 0.95 };
    triggerOnImpact = 0;
    triggerDistance = 100;
    explosionEffectsRadius = 0.5;
    explosionForceCoef = 0.2;
    explosionEffects = "GrenadeExplosion";
    CraterEffects = "ExploAmmoCrater";
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
