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
