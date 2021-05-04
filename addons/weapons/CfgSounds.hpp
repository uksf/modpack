class CfgSoundSets {
    class L119A2_ShotSD_SoundSet {
        soundShaders[] = { "L119A2_shot_SoundShader" };
        volumeFactor = 1;
        volumeCurve = "3CB_BAF_silencedSoundCurve";
        sound3DProcessingType = "WeaponMediumShot3DProcessingType";
        distanceFilter = "3CB_BAF_defaultDistanceFilter";
        occlusionFactor = 0.5;
        obstructionFactor = 0.3;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
};
class CfgSoundShaders {
    class L119A2_shot_SoundShader {
        samples[] = { { "\L911A2\sounds\m4sd_s1", 1 }, { "\L911A2\sounds\m4sd_s2", 1 }, { "\L911A2\sounds\m4sd_s3", 1 } };
        volume = 0.75;
        range = 240;
        rangeCurve[] = { { 0, 1 }, { 240, 0 } };
    };
};
