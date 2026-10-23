#define NT_LIGHT_SOURCE(NUM) \
    class light_##NUM##_source { \
        source = "MarkerLight"; \
        markerLight = QUOTE(Light_##NUM); \
    }

#define NT_LIGHT(NUM,R,G,B,AR,AG,AB,INTENSITY,QUADRATIC,LIMIT_START,LIMIT_END) \
    class Light_##NUM { \
        color[] = {R, G, B}; \
        ambient[] = {AR, AG, AB}; \
        name = QUOTE(Light_##NUM##_pos); \
        intensity = INTENSITY; \
        drawLight = 1; \
        drawLightSize = 0.5; \
        drawLightCenterSize = 0.2; \
        flaresize = 0.5; \
        activeLight = 1; \
        blinking = 0; \
        dayLight = 0; \
        useFlare = 1; \
        brightness = 1; \
        class Attenuation { \
            start = 0; \
            constant = 0; \
            linear = 1; \
            quadratic = QUADRATIC; \
            hardLimitStart = LIMIT_START; \
            hardLimitEnd = LIMIT_END; \
        }; \
    }

#define NT_FLUSH_LIGHT(R,G,B,AR,AG,AB) \
    class AnimationSources : AnimationSources { \
        NT_LIGHT_SOURCE(1); \
    }; \
    class MarkerLights { \
        NT_LIGHT(1,R,G,B,AR,AG,AB,35,2,0,100); \
    }

#define NT_EDGE_LIGHT(R,G,B) \
    class AnimationSources : AnimationSources { \
        NT_LIGHT_SOURCE(1); \
    }; \
    class MarkerLights { \
        NT_LIGHT(1,R,G,B,R,G,B,70,2,2,200); \
    }

class All {
    class AnimationSources;
};
class Static : All {};
class NT_Misc_EdgeLight : Static {
    NT_EDGE_LIGHT(2,1.9,1.7);
};
class NT_Misc_EdgeLightBlue : Static {
    NT_EDGE_LIGHT(0.2,0.2,1.3);
};
class NT_Misc_FlushLight_1 : Static {
    NT_FLUSH_LIGHT(0.85,0.85,0.05,0.85,0.85,0.05);
};
class NT_Misc_FlushLight_2 : Static {
    NT_FLUSH_LIGHT(5,0,0,0.1,0,0);
};
class NT_Misc_FlushLight_3 : Static {
    NT_FLUSH_LIGHT(0.05,0.65,0.05,0.05,0.65,0.05);
};
class NT_Misc_NaviLight_1 : Static {
    class AnimationSources : AnimationSources {
        NT_LIGHT_SOURCE(1);
    };
    class MarkerLights {
        NT_LIGHT(1,0.95,0.85,0.15,0.95,0.85,0.15,70,0.5,100,1000);
    };
};
class NT_Misc_NaviLight_2 : Static {
    class AnimationSources : AnimationSources {
        NT_LIGHT_SOURCE(1);
        NT_LIGHT_SOURCE(2);
        NT_LIGHT_SOURCE(3);
    };
    class MarkerLights {
        NT_LIGHT(1,0.9,0,0,0.09,0,0,70,0.5,100,1000);
        NT_LIGHT(2,0.9,0,0,0.09,0,0,70,0.5,100,1000);
        NT_LIGHT(3,0.9,0,0,0.09,0,0,70,0.5,100,1000);
    };
};
