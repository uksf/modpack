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
class HAFM_052C : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_B_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 6000;
};
class HAFM_ABurke : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_B_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 9000;
};
class HAFM_Admiral : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_L_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_R_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 250000;
};
class HAFM_BUYAN : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class FiglaTurret : WeaponsTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class BiglaTurret : WeaponsTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 50000;
};
class HAFM_CB90 : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class mainTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class MisTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
            stabilizedInAxes = 4;
        };
    };
    ace_refuel_fuelCapacity = 6500;
};
class HAFM_FREMM : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_L_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_R_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 700000;
};
class HAFM_GunBoat : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class RearTurret : FrontTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 5000;
};
class HAFM_MEKO_TN : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_L_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_R_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 700000;
};
class HAFM_Replenishment : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class obsTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 5000000;
};
class HAFM_Russen : Ship_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class RAM_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class BTurretR : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class BTurretL : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
    ace_refuel_fuelCapacity = 250000;
};
class HAFM_052D : HAFM_052C {
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class RAM_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
};
class HAFM_MEKO_HN : HAFM_MEKO_TN {
    class Turrets : Turrets {
        class FrontTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_B_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
};
class HAFM_Replenishment_OPF : HAFM_Replenishment {
    class Turrets : Turrets {
        class obsTurret;
        class WeaponsTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class SonarTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CaptainTurret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
        class CIWS_F2_Turret : NewTurret {
            class HitPoints {
                delete HitGun;
                delete HitTurret;
            };
        };
    };
};
class HAFM_RHIB : Boat_F {
    ace_refuel_fuelCapacity = 200;
};
