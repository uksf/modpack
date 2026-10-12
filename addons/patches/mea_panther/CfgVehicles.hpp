class All {
    class AnimationSources;
};
class Thing : All {};
class ThingX : Thing {};
class Items_base_F : ThingX {};
class Mea_Hoist_Hook : Items_base_F {
    class AnimationSources : AnimationSources {
        class collisionlightred_source {
            source = "MarkerLight";
        };
        class collisionlightwhite_source {
            source = "MarkerLight";
        };
    };
};
