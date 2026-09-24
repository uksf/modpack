class CUP_B_Wolfhound_LMG_GB_D : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_B_Wolfhound_LMG_GB_W : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_BMP2_base : CUP_BMP1_base {
    class NewTurret;
    class Turrets;
};
class CUP_BRDM2_HQ_Base : CUP_BRDM2_Base {
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_GAZ_Vodnik_AGS_Base : CUP_GAZ_Vodnik_Base {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_I_LR_SF_GMG_AAF : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_I_LR_SF_HMG_AAF : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_LR_AA_Base : CUP_LR_SPG9_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M1245_CROWS_Base : CUP_M1245_Base {
    class Turrets;
};
class CUP_M1245_RearM240_Base : CUP_M1245_Base {
    class Turrets : Turrets {
        class RearM240Turret : MainTurret {
            stabilizedInAxes = 3;
        };
        class RearM134Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M1A2Abrams_TUSK_II_Base : CUP_M1A2Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_M1Abrams_A2_TUSK_Base : CUP_M1Abrams_A2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_M1Abrams_M1A1FEP_F_TUSK_Base : CUP_M1Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_nM1025_M2_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_nM1025_M240_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_nM1025_Mk19_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_nM1025_SOV_M2_Base : CUP_nM1025_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class SideTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_nM1025_SOV_Mk19_Base : CUP_nM1025_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class SideTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AA_Base : CUP_UAZ_Armed_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AGS30_Base : CUP_UAZ_Armed_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_METIS_Base : CUP_UAZ_Armed_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_MG_Base : CUP_UAZ_Armed_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_SPG9_Base : CUP_UAZ_Armed_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
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
class CUP_BMP2_HQ_Base : CUP_BMP2_base {
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M1245_CROWS_M2_Base : CUP_M1245_CROWS_Base {
    class Turrets : Turrets {
        class Turret_Observer;
        class MainTurretRear04TurnIn;
        class MainTurretRear05TurnIn;
        class RearM134Turret;
        class MainTurret;
    };
};
