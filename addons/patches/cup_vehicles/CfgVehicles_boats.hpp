class Ship : AllVehicles {};
class Ship_F : Ship {
    class Turrets;
    class NewTurret;
};
class CUP_Frigate_Base : Ship_F {
    class HitPoints {
        delete HitTurret;
    };
    class Turrets : Turrets {
        class FrontTurret;
        class CommanderTurret : FrontTurret {
            class HitPoints {};
        };
        class CIWS : FrontTurret {
            class HitPoints {};
        };
        class VLSGunner : FrontTurret {
            class HitPoints {};
        };
    };
    ace_refuel_fuelCapacity = 700000;
};
class CUP_LCVP_Base : Ship_F {
    class Turrets : Turrets {
        class LeftTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class RightTurret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
    ace_refuel_fuelCapacity = 800;
};
class CUP_LCVP_VIV_Base : CUP_LCVP_Base {};
class CUP_I_LCVP_RACS : CUP_LCVP_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class RightTurret : RightTurret {
            class HitPoints {};
        };
    };
};
class CUP_I_LCVP_VIV_RACS : CUP_LCVP_VIV_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class RightTurret : RightTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_LCVP_SLA : CUP_LCVP_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class RightTurret : RightTurret {
            class HitPoints {};
        };
    };
};
class CUP_O_LCVP_VIV_SLA : CUP_LCVP_VIV_Base {
    class Turrets : Turrets {
        class LeftTurret : LeftTurret {};
        class RightTurret : RightTurret {
            class HitPoints {};
        };
    };
};
class CUP_RHIB_Base : Ship_F {
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
    ace_refuel_fuelCapacity = 200;
};
class CUP_RHIB2Turret_Base : CUP_RHIB_Base {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret : MainTurret {
            stabilizedInAxes = 4;
        };
    };
};
class CUP_LCU1600_Base : Ship_F {
    ace_refuel_fuelCapacity = 9500;
};
class CUP_ZUBR_Base : Ship_F {
    ace_refuel_fuelCapacity = 56000;
};
class CUP_MK10_Base : Ship_F {
    ace_refuel_fuelCapacity = 1500;
};
class CUP_Seafox_Base : Ship_F {
    ace_refuel_fuelCapacity = 600;
};
class CUP_Fishing_Boat_Base : Ship_F {
    ace_refuel_fuelCapacity = 800;
};
class CUP_Hovercraft_Base : Ship_F {
    ace_refuel_fuelCapacity = 1200;
};
