class CfgSounds {
    class GVAR(ejection) {
        sound[] = {"A3\sounds_f\weapons\launcher\nlaw_final_2", db10, 1, 1000};
        name = QGVAR(ejection);
        titles[] = {};
        duration = 3;
    };
    class GVAR(sonicBoom) {
        sound[] = { QPATHTOF(data\sound\sonicboom.ogg), 50, 1, 10000 };
        name = QGVAR(sonicBoom);
        titles[] = {};
    };
};
