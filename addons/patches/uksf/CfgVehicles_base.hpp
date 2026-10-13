class CUP_Boxer_Base;
class All {
    class AnimationSources;
};
class AllVehicles : All {
    class NewTurret;
};
class Land : AllVehicles {};
class LandVehicle : Land {};
class Car : LandVehicle {
    class Turrets;
};
class Car_F : Car {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
