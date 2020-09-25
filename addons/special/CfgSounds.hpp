class CfgSounds {
    class GVAR(suicide) {
        name = QGVAR(suicide);
        sound[] = { QPATHTOF(data\sounds\suicide), 10, 1, 150 };
        titles[] = {};
    };
    class GVAR(trigger) {
        name = QGVAR(trigger);
        sound[] = { "A3\Sounds_F\weapons\mines\mech_trigger_2", 10, 1, 100 };
        titles[] = {};
    };
    class GVAR(alarm) {
        name = QGVAR(alarm);
        sound[] = { QPATHTOF(data\sounds\alarm), 20, 1, 200 };
        titles[] = {};
    };
    class GVAR(nokia) {
        name = QGVAR(nokia);
        sound[] = { QPATHTOF(data\sounds\nokia), 20, 1, 200 };
        titles[] = {};
    };
};
