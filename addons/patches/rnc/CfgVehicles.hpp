class rnc_house_base;
class All {
    class AnimationSources;
};
class Thing : All {};
class Rnc_Particle_BigFire_F : Thing {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_rnc_apt_v1_c9_c1_f6 : rnc_house_base {
    class AnimationSources;
};
class Land_rnc_apt_v1_c9_c2_f3 : Land_rnc_apt_v1_c9_c1_f6 {
    class AnimationSources : AnimationSources {
        class door_3_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
class Land_rnc_apt_v1_c9_c2_f5 : Land_rnc_apt_v1_c9_c1_f6 {
    class AnimationSources : AnimationSources {
        class door_3_source {
            source = "user";
            animPeriod = 1;
            initPhase = 0;
        };
    };
};
