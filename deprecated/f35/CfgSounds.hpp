class CfgSounds {
    class GVAR(ejection) {
        sound[] = { "A3\sounds_f\weapons\launcher\nlaw_final_2", db10, 1, 1000};
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
class CfgSoundSets {
    class Plane_Fighter_SonicBoom_SoundSet {
        soundShaders[] = {"Plane_Fighter_SonicBoom_SoundShader"};
        volumeFactor = 3;
        spatial = 1;
        loop = 0;
        speedOfSound = 0;
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
    };
    class Plane_Fighter_01_EngineLowExt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineLowExt_SoundShader"};
        volumeFactor = 1.5;
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
    };
    class Plane_Fighter_01_EngineHighExt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineHighExt_SoundShader"};
        volumeFactor = 1.5;
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class Plane_Fighter_01_ForsageExt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_ForsageExt_SoundShader"};
        volumeFactor = 1.75;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
        occlusionFactor = 0.45;
        obstructionFactor = 0.35;
    };
    class Plane_Fighter_01_WindNoiseExt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_WindNoiseExt_SoundShader"};
        volumeFactor = 1;
        spatial = 1;
        loop = 1;
        sound3DProcessingType = "JetExt_Close_3DProcessingType";
    };
    class Plane_Fighter_01_EngineExt_Middle_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineExt_Middle_SoundShader"};
        volumeFactor = 2;
        spatial = 1;
        loop = 1;
        shape = "FrontSemispace10";
        volumeCurve = "InverseSquare3Curve";
        sound3DProcessingType = "JetExt_Middle_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
    class Plane_Fighter_01_EngineExt_Dist_Front_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineExt_Dist_Front_SoundShader"};
        volumeFactor = 1.8;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare3Curve";
        shape = "FrontSemispace60";
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
    class Plane_Fighter_01_EngineExt_Dist_Rear_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineExt_Dist_Rear_SoundShader"};
        volumeFactor = 2.5;
        spatial = 1;
        loop = 1;
        volumeCurve = "InverseSquare1Curve";
        shape = "RearSemispace20";
        sound3DProcessingType = "JetExt_Distant_3DProcessingType";
        occlusionFactor = 0.5;
        obstructionFactor = 0;
    };
    class Plane_Fighter_01_EngineLowInt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineLowInt_SoundShader"};
        volumeFactor = 1.9;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class Plane_Fighter_01_EngineHighInt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_EngineHighInt_SoundShader"};
        volumeFactor = 2;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
    class Plane_Fighter_01_ForsageInt_SoundSet {
        soundShaders[] = {"Plane_Fighter_01_ForsageInt_SoundShader"};
        volumeFactor = 1.35;
        spatial = 0;
        loop = 1;
        sound3DProcessingType = "VehicleInt_Back_3DProcessingType";
    };
};
class CfgSoundShaders {
    class Plane_Fighter_SonicBoom_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_sonicboom", 1}};
        frequency = 1;
        volume = 1;
        range = 5000;
    };
    class Plane_Fighter_01_EngineLowExt_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_low_ext", 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0, 1])";
        volume = "0.7 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0.75, 0])";
        range = 1500;
    };
    class Plane_Fighter_01_EngineHighExt_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_high_ext", 1}};
        frequency = "1.0 min (rpm + 0.5)*(rpm factor[0.5, 1.1])";
        volume = "0.7 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0, 0.75])";
        range = 2000;
    };
    class Plane_Fighter_01_ForsageExt_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_forsage_ext", 1}};
        frequency = 1.1;
        volume = "0.7 * machcone*engineOn*camPos*(thrust factor[0.6, 1.0])";
        range = 2000;
        rangeCurve[] = {{0, 1}, {200, 0.75}, {1000, 0.25}, {1500, 0}};
    };
    class Plane_Fighter_01_EngineExt_Middle_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_middle", 1}};
        frequency = 1;
        volume = "0.7 * machcone*camPos*(rpm factor[0.5, 1])";
        range = 5000;
        rangeCurve[] = {{0, 0}, {50, 1}, {5000, 1}};
    };
    class Plane_Fighter_01_EngineExt_Dist_Front_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_front", 1}};
        frequency = 1;
        volume = "0.7 * machcone*camPos*(rpm factor[0.5, 1])";
        range = 5000;
        rangeCurve[] = {{0, 0}, {50, 1}, {5000, 1}};
    };
    class Plane_Fighter_01_EngineExt_Dist_Rear_SoundShader {
        samples[] = {{"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_back", 1}};
        frequency = 1;
        volume = "0.7 * machcone*camPos*(rpm factor[0.5, 1])";
        range = 7000;
        rangeCurve[] = {{0, 0}, {50, 1}, {7000, 1}};
    };
};
