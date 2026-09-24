class Offroad_01_base_F;
class Ship;
class LandVehicle;
class CUP_BMP1_base;
class CUP_UAZ_Base;
class Truck_F;
class Ship_F : Ship {
    class NewTurret;
    class Turrets;
};
class Boat_F : Ship_F {
    class Turrets;
};
class Car : LandVehicle {
    class Turrets;
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
};
class CUP_RHIB_Base : Ship_F {
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
};
class HAFM_CB90 : Ship_F {
    class Turrets : Turrets {
        class mainTurret : NewTurret {
            stabilizedInAxes = 4;
        };
        class MisTurret : NewTurret {
            stabilizedInAxes = 4;
        };
    };
};
class Tank : LandVehicle {
    class NewTurret;
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
class Car_F : Car {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_RHIB2Turret_Base : CUP_RHIB_Base {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret : MainTurret {
            stabilizedInAxes = 4;
        };
    };
};
class Tank_F : Tank {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            class Turrets;
        };
    };
};
class CUP_BAF_Jackal2_BASE_D : Car_F {
    class Turrets : Turrets {
        class MainTurret;
        class M240_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Challenger2_base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_Datsun_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_ECVHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_Hilux_Base : Car_F {
    class Turrets;
};
class CUP_HMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Leopard2_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_LR_Base : Car_F {
    class Turrets;
};
class CUP_M1_Abrams_base : Tank_F {
    class NewTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets;
        };
    };
};
class CUP_M1240_Base : Car_F {
    class NewTurret;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_M151_base : Car_F {
    class Turrets;
};
class CUP_M1A2Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_M1Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_nHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_RG31_BASE : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_SUV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_T34_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret;
        class FrontGunner : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Tigr_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_UpHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_01_base_F : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class LSV_02_base_F : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class MRAP_01_base_F : Car_F {
    class Turrets;
};
class Offroad_02_base_F : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class RHICC_MAIN : Boat_Armed_01_base_F {
    class Turrets : Turrets {
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
class Wheeled_APC_F : Car_F {
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class CUP_BAF_Jackal2_GMG_D : CUP_BAF_Jackal2_BASE_D {
    class Turrets : Turrets {
        class GMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
