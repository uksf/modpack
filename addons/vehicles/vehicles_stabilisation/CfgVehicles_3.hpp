class CUP_nM1025_Mk19_Base : CUP_nHMMWV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_nM1025_SOV_Base : CUP_nHMMWV_Base {
    class NewTurret;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_nM1036_TOW_Base : CUP_nHMMWV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Ridgback_Base : Wheeled_APC_F {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Tigr_M_KORD_Base : CUP_Tigr_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Tigr_M_PK_Base : CUP_Tigr_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Tigr_STS_PK_Base : CUP_Tigr_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_Armed_Base : CUP_UAZ_Base {
    class Turrets;
};
class CUP_Ural_BaseTurret : Truck_F {
    class Turrets {
        class MainTurret;
    };
};
class CUP_Wolfhound_Base : Wheeled_APC_F {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_01_armed_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_01_AT_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_02_armed_base_F : LSV_02_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class LSV_02_armed762_base_F : LSV_02_base_F {
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
class B_LSV_01_armed_G_noMMG : LSV_01_armed_base_F {
    class Turrets : Turrets {
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class B_LSV_01_armed_G_noMMG_noBoxes : LSV_01_armed_base_F {
    class Turrets : Turrets {
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class B_LSV_01_AT_G_noMMG : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class B_LSV_01_AT_G_noMMG_noBoxes : LSV_01_AT_base_F {
    class Turrets : Turrets {
        class TopTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_LR_Special_CZ_W : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {};
    };
};
class CUP_B_LR_Special_Des_CZ_D : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {};
    };
};
class CUP_B_Mastiff_GMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Mastiff_GMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Mastiff_LMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Mastiff_LMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Ridgback_GMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Ridgback_GMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Ridgback_LMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Ridgback_LMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Wolfhound_GMG_GB_D : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Wolfhound_GMG_GB_W : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
