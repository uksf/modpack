class All {
    class AnimationSources;
};
class Thing : All {};
class ThingX : Thing {};
class ace_rearm_defaultCarriedObject : ThingX {
    class AnimationSources : AnimationSources {
        class ammo_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class ammoord_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class grenades_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class support_source {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
