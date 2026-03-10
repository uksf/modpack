class CfgCloudlets {
    class SmokeShellWhite;

    // Dense smoke cloud - matches 3CB CloudSmallLight1
    class GVAR(SmokeMortarCloud) : SmokeShellWhite {
        interval = 0.003;
        particleShape = "warfxWeps\ParticleEffects\Universal\smoke_02";
        particleFSNtieth = 1;
        particleFSIndex = 0;
        particleFSFrameCount = 1;
        particleFSLoop = 1;
        moveVelocity[] = { 0, 0.5, 0 };
        moveVelocityVar[] = { 3.5, 3.5, 3.5 };
        positionVar[] = { 0.5, 0.5, 0.5 };
        size[] = { 2, 4, 5, 6 };
        sizeVar = 0.4;
        color[] = {
            { 0.005, 0.005, 0.005, 0.22 },
            { 0.01, 0.01, 0.01, 0.18 },
            { 0.05, 0.05, 0.05, 0.15 },
            { 0.1, 0.1, 0.1, 0.1 },
            { 0.15, 0.15, 0.15, 0.05 },
            { 0.2, 0.2, 0.2, 0 }
        };
        animationSpeed[] = { 1.5, 0.5, 0.3, 0.25, 0.25 };
        lifeTime = 22;
        lifeTimeVar = 4;
        weight = 0.52;
        volume = 0.4;
        rubbing = 0.4;
        angleVar = 1;
        rotationVelocityVar = 10;
        randomDirectionPeriod = 0.2;
        randomDirectionIntensity = 0.1;
        blockAIVisibility = 1;
    };

    // WP trail splatter - matches 3CB UK3CB_WPTrails
    class GVAR(SmokeMortarTrail) : SmokeShellWhite {
        interval = 0.01;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleFSNtieth = 16;
        particleFSIndex = 13;
        particleFSFrameCount = 2;
        particleFSLoop = 0;
        lifeTime = 5;
        lifeTimeVar = 1;
        moveVelocity[] = { 0, 6, 0 };
        moveVelocityVar[] = { 10, 5, 10 };
        positionVar[] = { 2, 2, 2 };
        size[] = { 0.5 };
        sizeVar = 0;
        color[] = { { 1, 1, 1, 1 } };
        animationSpeed[] = { 1000 };
        weight = 15;
        volume = 7.9;
        rubbing = 0.1;
        timerPeriod = 0.07;
        angleVar = 1;
        rotationVelocityVar = 20;
        randomDirectionPeriod = 1;
        randomDirectionIntensity = 0;
        particleEffects = QGVAR(SmokeMortarTrailSubEffect);
    };

    // Nested trail particle - matches 3CB WPTrailEffect
    class GVAR(SmokeMortarTrailSub) : SmokeShellWhite {
        interval = 0.07;
        particleShape = "warfxWeps\ParticleEffects\Universal\smoke_02";
        particleFSNtieth = 1;
        particleFSIndex = 0;
        particleFSFrameCount = 1;
        particleFSLoop = 1;
        lifeTime = 5;
        lifeTimeVar = 0.3;
        moveVelocity[] = { 0, 0, 0 };
        moveVelocityVar[] = { 0, 0, 0 };
        positionVar[] = { 0, 0, 0 };
        size[] = { 0.75, 1.75 };
        sizeVar = 0.25;
        color[] = {
            { 0.05, 0.05, 0.05, 0.3 },
            { 0.1, 0.1, 0.1, 0.175 },
            { 0.15, 0.15, 0.15, 0.09 },
            { 0.2, 0.2, 0.2, 0.025 },
            { 0.25, 0.25, 0.25, 0 }
        };
        animationSpeed[] = { 1 };
        weight = 10;
        volume = 7.9;
        rubbing = 0.075;
        angleVar = 1;
        randomDirectionPeriod = 1;
        randomDirectionIntensity = 0;
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
