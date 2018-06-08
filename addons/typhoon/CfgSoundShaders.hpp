class CfgSoundShaders {
    class GVAR(soundShader_sonicBoom) {
        samples[] = {{QPATHTOF(data\sounds\sonicboom), 1}};
        frequency = 1;
        volume = 2; // 1
        range = 3000; // 1000
    };
    class GVAR(soundShader_engineLowExt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_low_ext), 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0, 1])";
        volume = "0.6 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0.75, 0])";
        range = 1200;
    };
    class GVAR(soundShader_engineHighExt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_high_ext), 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0.5, 1.1])";
        volume = "0.6 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0, 0.75])";
        range = 1300;
    };
    class GVAR(soundShader_forsageExt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_forsage_ext), 1}};
        frequency = 1.1;
        volume = "0.6 * machcone*engineOn*camPos*(thrust factor[0.6, 1.0])";
        range = 1500;
        rangeCurve[] = {{0, 1}, {200, 0.75}, {1000, 0.25}, {1500, 0}};
    };
    class GVAR(soundShader_engineLowInt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_high_ext), 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0, 1])";
        volume = "1 * engineOn*(1-camPos)*(rpm factor[0.5, 1])";
    };
    class GVAR(soundShader_engineHighInt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_high_int), 1}};
        frequency = "1.0 min (rpm + 0.25)*(rpm factor[0.25, 1.1])";
        volume = "1 * engineOn*(1-camPos)*(rpm factor[0, 1])";
    };
    class GVAR(soundShader_forsageInt) {
        samples[] = {{QPATHTOF(data\sounds\typhoon_engine_forsage_int), 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0, 1])";
        volume = "1 * engineOn*(1-camPos)*(rpm factor[0.5, 1])*(thrust factor[0.5, 1.0])";
    };
};
