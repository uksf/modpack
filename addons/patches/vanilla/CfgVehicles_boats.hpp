class B_Boat_Transport_01_F : Rubber_duck_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class I_Boat_Transport_01_F : Rubber_duck_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class I_G_Boat_Transport_01_F : Rubber_duck_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class O_Boat_Transport_01_F : Rubber_duck_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Rescue_duck_base_F : Rubber_duck_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
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
        class RearTurret : FrontTurret {
            stabilizedInAxes = 4;
        };
    };
};
class Boat_Transport_02_base_F : Boat_F {
    ace_refuel_fuelCapacity = 200;
};
class SDV_01_base_F : Boat_F {
    ace_refuel_fuelCapacity = 120;
};
