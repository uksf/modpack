class CfgCloudlets {
    class SmokeShellWhite;

    // Dense smoke cloud - matches 3CB CloudSmallLight1 behaviour
    class GVAR(SmokeMortarCloud) : SmokeShellWhite {
        interval = 0.003;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        particleFSLoop = 0;
        colorCoef[] = { 1, 1, 1, 1 };
        rubbing = 0.4;
        moveVelocity[] = { 0, 0.5, 0 };
        moveVelocityVar[] = { 1, 0.3, 1 };
        size[] = { 2, 4, 6 };
        sizeVar = 1;
        color[] = { { 0.8, 0.8, 0.8, 0.3 }, { 0.8, 0.8, 0.8, 0.15 }, { 0.8, 0.8, 0.8, 0 } };
        lifeTime = 30;
        lifeTimeVar = 3;
        weight = 0.52;
        volume = 0.4;
        blockAIVisibility = 1;
    };

    // WP trail splatter - matches 3CB UK3CB_WPTrails behaviour
    class GVAR(SmokeMortarTrail) : SmokeShellWhite {
        interval = 0.01;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 13;
        particleFSFrameCount = 2;
        particleFSLoop = 0;
        lifeTime = 5;
        moveVelocity[] = { 0, 6, 0 };
        moveVelocityVar[] = { 10, 5, 10 };
        positionVar[] = { 2, 2, 2 };
        size[] = { 0.5 };
        sizeVar = 0.25;
        color[] = { { 1, 1, 1, 1 } };
        weight = 15;
        volume = 7.9;
        rubbing = 0.1;
        particleEffects = QGVAR(SmokeMortarTrailSubEffect);
    };

    // Nested trail particle - matches 3CB WPTrailEffect behaviour
    class GVAR(SmokeMortarTrailSub) : SmokeShellWhite {
        interval = 0.07;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 12;
        particleFSFrameCount = 8;
        particleFSLoop = 0;
        lifeTime = 5;
        lifeTimeVar = 2;
        moveVelocity[] = { 0, 0.2, 0 };
        moveVelocityVar[] = { 0.5, 0.3, 0.5 };
        size[] = { 0.75, 1.25, 1.75 };
        sizeVar = 0.5;
        color[] = { { 0.6, 0.6, 0.6, 0.3 }, { 0.6, 0.6, 0.6, 0.15 }, { 0.6, 0.6, 0.6, 0 } };
        weight = 10;
        volume = 7.9;
        rubbing = 0.075;
    };
};

// effectsSmoke on shotSmokeX resolves from root config
class GVAR(SmokeMortarEffect) {
    class SmokeCloud {
        simulation = "particles";
        type = QGVAR(SmokeMortarCloud);
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
    class SmokeTrails {
        simulation = "particles";
        type = QGVAR(SmokeMortarTrail);
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};

// particleEffects on CfgCloudlets entries resolves from root config
class GVAR(SmokeMortarTrailSubEffect) {
    class SmokeTrailSub {
        simulation = "particles";
        type = QGVAR(SmokeMortarTrailSub);
        position[] = { 0, 0, 0 };
        intensity = 1;
        interval = 1;
        lifeTime = 1;
    };
};
