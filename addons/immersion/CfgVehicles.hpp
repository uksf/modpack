class CfgVehicles {
    class Reflector_Cone_01_base_F;
    class Reflector_Cone_01_long_base_F: Reflector_Cone_01_base_F {
        class Reflectors;
    };

    class TracerR: Reflector_Cone_01_long_base_F {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };

    class TracerR_50: TracerR {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerR_10: TracerR_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                intensity = 200; // 300
                class Attenuation: Attenuation {
                    hardLimitStart = 2;  // 100 * 0.7
                    hardLimitEnd = 20;   // 100
                };
            };
        };
    };

    class TracerG: TracerR {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerG_10: TracerG {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                intensity = 200; // 300
                class Attenuation: Attenuation {
                    hardLimitStart = 2;  // 100 * 0.7
                    hardLimitEnd = 20;   // 100
                };
            };
        };
    };

    class TracerY: TracerR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerY_50: TracerY {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerY_10: TracerY_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                intensity = 200; // 300
                class Attenuation: Attenuation {
                    hardLimitStart = 2;  // 100 * 0.7
                    hardLimitEnd = 20;   // 100
                };
            };
        };
    };

    class TracerW: TracerR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerW_50: TracerW {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerW_10: TracerW_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                intensity = 200; // 300
                class Attenuation: Attenuation {
                    hardLimitStart = 2;  // 100 * 0.7
                    hardLimitEnd = 20;   // 100
                };
            };
        };
    };

    class TracerTR: TracerR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerTR_50: TracerTR {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerTR_10: TracerTR_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation: Attenuation {
                    hardLimitStart = 1;  // 100 * 0.7
                    hardLimitEnd = 10;   // 100
                };
            };
        };
    };

    class TracerTG: TracerTR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerTG_50: TracerTG {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerTG_10: TracerTG_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation: Attenuation {
                    hardLimitStart = 1;  // 100 * 0.7
                    hardLimitEnd = 10;   // 100
                };
            };
        };
    };

    class TracerTY: TracerTR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerTY_50: TracerTY {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerTY_10: TracerTY_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation: Attenuation {
                    hardLimitStart = 1;  // 100 * 0.7
                    hardLimitEnd = 10;   // 100
                };
            };
        };
    };

    class TracerTW: TracerTR {
        class Reflectors: Reflectors {
            class Light_1;
        };
    };
    class TracerTW_50: TracerTW {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation;
            };
        };
    };
    class TracerTW_10: TracerTW_50 {
        class Reflectors: Reflectors {
            class Light_1: Light_1 {
                class Attenuation: Attenuation {
                    hardLimitStart = 1;  // 100 * 0.7
                    hardLimitEnd = 10;   // 100
                };
            };
        };
    };
};
