class CfgCloudlets {
    class Default;
    class MK82_Explosion_01: Default {
        moveVelocity[] = {0, 0, 0};
    };
    class MK82_Explosion_02: Default {
        moveVelocity[] = {0, 0, 0};
    };
    class ImpactEffectsWater1: Default {
        interval = "0.03+(0.2/(hit interpolate [0.1,40,0.1,40]))";
    };
    class ImpactEffectsWater1Med: Default {
        interval = "0.06+(0.4/(hit interpolate [0.1,40,0.1,40]))";
    };
    class ImpactEffectsWater2: Default {
        interval = "0.018/(hit interpolate [0.1,40,0.1,40])";
    };
    class ImpactEffectsWater2Med: Default {
        interval = "0.03/(hit interpolate [0.1,40,0.1,40])";
    };
    class ImpactEffectsWater3: Default {
        interval = "0.0008 + 0.003/(hit interpolate [0.1,40,0.1,40])";
    };
    class ImpactEffectsWater3Med: Default {
        interval = "0.0016 + 0.006/(hit interpolate [0.1,40,0.1,40])";
    };
    class ImpactEffectsWater4: Default {
        interval = "0.0014 + (0.00007/(hit interpolate [0.1,40,0.1,40]))";
    };
    class ImpactEffectsWater4Med: Default {
        interval = "0.0028 + (0.00014/(hit interpolate [0.1,40,0.1,40]))";
    };
    class ImpactEffectsWater5: Default {
        interval = "0.0005+(0.004/(hit interpolate [0.1,40,0.1,40]))";
    };
    class ImpactConcreteWall2: Default {
        interval = "(0.06 + (0.1/hit)) + ((randomValue * 0.1)/hit)";
    };
    class ExhaustSmoke1PlaneBig: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,3.5])"};
    };
    class ExhaustSmoke1Plane: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,6])"};
    };
};
