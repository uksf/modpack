#define DENSITY_GATE "density interpolate [0.98,0.981,-1,1]"
#define WATER_DIRT_GATE "(isWaterSurface * (distToSurface interpolate [1.5,1.51,1,1]))"
#define OFF(NAME) class NAME { enabled = "-1"; }
#define ON(NAME) class NAME { enabled = "1"; }

class RocketBackEffectsRPG {
    class RocketFrontsmoke { enabled = DENSITY_GATE; };
    OFF(RocketFrontDust);
    OFF(RocketBackDust);
    OFF(LauSparkBack);
    OFF(LauSparkFront);
    OFF(Dirt);
    OFF(HeatHazeBig);
    OFF(HeatHazeBigFront);
};
class RocketBackEffectsNLAW {
    OFF(RocketBackDust);
    OFF(Dirt);
    OFF(LauSparkFront);
    OFF(LauSparkBack);
    OFF(HeatHazeBig);
    OFF(HeatHazeBigFront);
};
class RocketBackEffectsStaticRPG {
    OFF(RocketFrontDust);
    OFF(RocketBackDust);
    OFF(Dirt);
    OFF(LauSparkBack);
    OFF(LauSparkFront);
    OFF(HeatHazeBig);
    OFF(HeatHazeBigFront);
};

class RocketBackEffectsRPGNT {
    ON(LauSparkBack);
    ON(LauSparkFront);
    class Dirt { enabled = WATER_DIRT_GATE; };
};
class RocketBackEffectsNLAWNT {
    ON(LauSparkBack);
    ON(LauSparkFront);
    class Dirt { enabled = WATER_DIRT_GATE; };
};
class RHS_RocketBackEffectsRPGNT {
    ON(RocketBackfire1);
    ON(RocketBacksmoke2);
    ON(RocketFrontsmoke);
    ON(LauSparkBack);
    ON(LauSparkFront);
    class Dirt { enabled = WATER_DIRT_GATE; };
};
