class CfgCloudlets {
    class Default;
    class SmokeShellWhite : Default {
        particleEffects = "";
    };
    class fxp_smokeshelLinkl;
    class SmokeShellWhite3 : fxp_smokeshelLinkl {
        interval = 0.3;
        colorCoef[] = { "colorR", "colorG", "colorB", "colorA" };
    };
};
class SmokeShellWhiteEffect {
    class SmokeShell {
        simulation = "particles";
        type = "SmokeShellWhite";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
    class SmokeShell2 {
        simulation = "particles";
        type = "SmokeShellWhite2";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
    class SmokeShell3 {
        simulation = "particles";
        type = "SmokeShellWhite3";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
    class SmokeShellUW {
        simulation = "particles";
        type = "SmokeShellWhiteUW";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
    class SmokeShell2UW {
        simulation = "particles";
        type = "SmokeShellWhite2UW";
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
    };
};
class SmokeShellRedEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class SmokeShellGreenEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class SmokeShellYellowEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class SmokeShellPurpleEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class SmokeShellBlueEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class SmokeShellOrangeEffect : SmokeShellWhiteEffect {
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellWhiteEffect : SmokeShellWhiteEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellRedEffect : SmokeShellRedEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellGreenEffect : SmokeShellGreenEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellYellowEffect : SmokeShellYellowEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellPurpleEffect : SmokeShellPurpleEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellBlueEffect : SmokeShellBlueEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
class UK3CB_SmokeShellOrangeEffect : SmokeShellOrangeEffect {
    class SmokeShell : SmokeShell {
        type = "SmokeShellWhite";
    };
    class SmokeShell2 : SmokeShell2 {
        type = "SmokeShellWhite2";
    };
    class SmokeShell3 : SmokeShell3 {};
};
