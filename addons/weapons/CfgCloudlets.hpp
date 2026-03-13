class GVAR(SmokeMortarEffect) {
    class SmokePillar {
        simulation = "particles";
        type = "UK3CB_SmokeShellMortarWhitePillar";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
    class SmokeBase {
        simulation = "particles";
        type = "UK3CB_SmokeShellMortarWhiteBase";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
};
