class LSV_01_base_F : Car_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
    };
};
class LSV_01_armed_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class B_T_LSV_01_armed_F : LSV_01_armed_base_F {};
class B_LSV_01_armed_F : LSV_01_armed_base_F {};
class B_LSV_01_armed_black_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_LSV_01_armed_olive_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_LSV_01_armed_sand_F : B_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class LSV_01_AT_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class B_LSV_01_AT_F : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_T_LSV_01_armed_black_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_T_LSV_01_armed_CTRG_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
        class TopTurret;
        class CodRiverTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class B_T_LSV_01_armed_olive_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_T_LSV_01_armed_sand_F : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class B_T_LSV_01_AT_F : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class MRAP_03_base_F : Car_F {
    class Turrets;
};
class MRAP_03_hmg_base_F : MRAP_03_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
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
class LSV_02_armed_base_F : LSV_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_02_AT_base_F : LSV_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class Offroad_01_military_base_F : Offroad_01_base_F {
    class Turrets;
};
class Offroad_02_AT_base_F : Offroad_02_base_F {
    class Turrets : Turrets {
        class AT_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class Offroad_02_LMG_base_F : Offroad_02_base_F {
    class Turrets : Turrets {
        class LMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class Offroad_01_armed_base_F : Offroad_01_military_base_F {
    class MainTurret;
    class Turrets : Turrets {
        class M2_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class Offroad_01_AT_base_F : Offroad_01_military_base_F {
    class MainTurret;
    class Turrets : Turrets {
        class AT_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
