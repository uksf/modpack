class CfgCloudlets {
    class Default;

    // WarFXPE/fxp_* overrides — fix extra ) in colorCoef expressions
    class ExhaustSmoke1HeliHP: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (engineDamage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1PlaneBig: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,3.5])"};
    };
    class ExhaustSmoke1Plane: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1PlaneHP: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (engineDamage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1Jet: Default {
        colorCoef[] = {"15", "15", "15", "1.2 * intensity * (damage interpolate [0.3,1,1,5])"};
    };
    class ExhaustSmoke1JetM: Default {
        colorCoef[] = {"15", "15", "15", "1.8 * intensity * (damage interpolate [0.3,1,1,5])"};
    };
    class ExhaustSmoke1JetL: Default {
        colorCoef[] = {"15", "15", "15", "2.4 * intensity * (damage interpolate [0.3,1,1,5])"};
    };

    // AVDAVFX overrides — fix extra ) in colorCoef expressions
    class ExhaustSmoke1PlaneSmall: Default {
        colorCoef[] = {"15", "15", "15", "intensity/1.5 * (damage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1PlaneSmallHP: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (engineDamage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1VTOL: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke1VTOLHP: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (engineDamage interpolate [0.3,0.4,1,6])"};
    };
    class ExhaustSmoke2VTOL: Default {
        colorCoef[] = {"15", "15", "15", "intensity/2 * (damage interpolate [0.3,0.4,1,6])"};
    };
};
