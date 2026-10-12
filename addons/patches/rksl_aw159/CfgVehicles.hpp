class All {
    class AnimationSources;
};
class AllVehicles : All {
    class NewTurret;
};
class Air : AllVehicles {
    class AnimationSources;
};
class Helicopter : Air {
    class AnimationSources;
};
class Helicopter_Base_F : Helicopter {
    class Turrets;
};
class rksla3_aw159_base : Helicopter_Base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
