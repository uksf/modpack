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
class MRAP_01_base_F : Car_F {
    class Turrets;
};
class UK3CB_BAF_Jackal_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
        class L7A2_1_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_LandRover_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class UK3CB_BAF_RHIB_Base : Boat_Armed_01_base_F {
    class NewTurret;
    class Turrets;
};
class UK3CB_BAF_Coyote_L111A1_Base : UK3CB_BAF_Jackal_Base {
    class Turrets : Turrets {
        class L111A1_MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_Coyote_L134A1_Base : UK3CB_BAF_Jackal_Base {
    class Turrets : Turrets {
        class L134A1_MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_Husky_Base : MRAP_01_base_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class UK3CB_BAF_LandRover_WMIK_Base : UK3CB_BAF_LandRover_Base {
    class Turrets : Turrets {
        class MainTurret;
        class GPMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_RHIB_GPMG : UK3CB_BAF_RHIB_Base {
    class Turrets : Turrets {
        class L7A2_1_Turret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
};
class UK3CB_BAF_RHIB_HMG : UK3CB_BAF_RHIB_Base {
    class Turrets : Turrets {
        class L111A1_1_Turret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
};
class UK3CB_BAF_Husky_GMG_Base : UK3CB_BAF_Husky_Base {
    class Turrets : Turrets {
        class L134A1_1_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_Husky_GPMG_Base : UK3CB_BAF_Husky_Base {
    class Turrets : Turrets {
        class L7A2_1_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_Husky_HMG_Base : UK3CB_BAF_Husky_Base {
    class Turrets : Turrets {
        class L111A1_1_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_LandRover_WMIK_GMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class GMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_LandRover_WMIK_GPMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class GPMG_2_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_LandRover_WMIK_HMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class HMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class UK3CB_BAF_LandRover_WMIK_Milan_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class Milan_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
