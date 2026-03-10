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
    submunitionConeType[] = { "poissondisc", 4 };  // 20
    submunitionConeAngle = 10;
    submunitionConeAngleHorizontal = 360;
    submunitionInitialOffset[] = { 0, 0, -50 };
    submunitionInitSpeed = 12;
    submunitionParentSpeedCoef = 0;
    deleteParentWhenTriggered = 0;
    triggerOnImpact = 0;
    triggerDistance = 50;
};
