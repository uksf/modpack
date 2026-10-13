class Truck_F : Car_F {};
class CUP_Ural_BaseTurret : Truck_F {
    class Turrets {
        class MainTurret;
    };
};
class CUP_BM21_Base : CUP_Ural_BaseTurret {
    class Turrets;
};
class CUP_B_RM70_Base : CUP_BM21_Base {
    class Turrets : Turrets {
        class MainTurret;
        class UkTurret : NewTurret {
            class HitPoints {};
        };
    };
};
class CUP_Ural_ZU23_Base : CUP_Ural_BaseTurret {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
