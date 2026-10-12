class All {
    class AnimationSources;
};
class AllVehicles : All {
    class NewTurret;
};
class Ship : AllVehicles {};
class Ship_F : Ship {
    class Turrets;
    class NewTurret;
};
class Boat_F : Ship_F {
    class Turrets;
};
class Boat_Armed_01_base_F : Boat_F {
    class NewTurret;
    class Turrets : Turrets {
        class FrontTurret;
        class RearTurret : FrontTurret {};
    };
};
class RHICC_MAIN : Boat_Armed_01_base_F {
    class Turrets {
        class CommanderTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class TopTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class CodRiverTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class CodRiver1Turret : NewTurret {
            stabilizedInAxes = 4;
        };
        class MinigunLeft : NewTurret {
            stabilizedInAxes = 4;
        };
        class MinigunRight : NewTurret {
            stabilizedInAxes = 4;
        };
    };
};
