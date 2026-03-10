class CfgExplosionEffects {
    class GVAR(SmokeMortarEffect) {
        class SmokePillar {
            simulation = "particles";
            type = QGVAR(SmokeMortarPillar);
            position[] = { 0, 0, 0 };
            intensity = 1;
            interval = 1;
        };
        class SmokeBase {
            simulation = "particles";
            type = QGVAR(SmokeMortarBase);
            position[] = { 0, 0, 0 };
            intensity = 1;
            interval = 1;
        };
    };
};
