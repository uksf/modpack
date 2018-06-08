class CfgSoundSets {
    class GVAR(soundSet_sonicBoom) {
        soundShaders[] = {QGVAR(soundShader_sonicBoom)};
        volumeFactor = 4; // 2
        spatial = 1;
        loop = 0;
        speedOfSound = 0;
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
    };
    class GVAR(soundSet_engineLowExt) {
        soundShaders[] = {QGVAR(soundShader_engineLowExt)};
        volumeFactor = 1.7; // 1.2
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
    };
    class GVAR(soundSet_engineHighExt) {
        soundShaders[] = {QGVAR(soundShader_engineHighExt)};
        volumeFactor = 1.7; // 1.2
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(soundSet_forsageExt) {
        soundShaders[] = {QGVAR(soundShader_forsageExt)};
        volumeFactor = 1.75; // 1.25
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class GVAR(soundSet_engineLowInt) {
        soundShaders[] = {QGVAR(soundShader_engineLowInt)};
        volumeFactor = 1.5; // 1.4
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class GVAR(soundSet_engineHighInt) {
        soundShaders[] = {QGVAR(soundShader_engineHighInt)};
        volumeFactor = 1.4; // 1.3
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class GVAR(soundSet_forsageInt) {
        soundShaders[] = {QGVAR(soundShader_forsageInt)};
        volumeFactor = 1.45; // 1.35
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
};
