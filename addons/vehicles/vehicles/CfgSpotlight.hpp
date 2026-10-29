    class Reflector_Cone_01_base_F;
    class GVAR(spotlight) : Reflector_Cone_01_base_F {
        scope = 1;
        scopeCurator = 0;
        displayName = "Weapon Spotlight";
        class Reflectors {
            class Light_1 {
                color[] = {1, 1, 1};
                ambient[] = {1, 1, 1};
                intensity = 2500;
                size = 1;
                innerAngle = 10;
                outerAngle = 38;
                coneFadeCoef = 6;
                position = "Light_1_pos";
                direction = "Light_1_dir";
                hitpoint = "Light_1_hitpoint";
                hitpointClass = "Hit_Light_1";
                selection = "Light_1_hide";
                useFlare = 0;
                irLight = 0;
                class Attenuation {
                    start = 0;
                    constant = 0;
                    linear = 0;
                    quadratic = 0.01;
                    hardLimitStart = 150;
                    hardLimitEnd = 270;
                };
            };
            class Light_1_Flare : Light_1 {
                hitpointClass = "Hit_Light_1_Flare";
                outerAngle = 178;
                useFlare = 1;
                flareSize = 0.9;
                flareMaxDistance = 450;
            };
        };
    };
    class GVAR(spotlightIR) : GVAR(spotlight) {
        displayName = "Weapon Spotlight (IR)";
        class Reflectors : Reflectors {
            class Light_1 : Light_1 {
                irLight = 1;
            };
            class Light_1_Flare : Light_1_Flare {
                irLight = 1;
            };
        };
    };
