class CUP_Tigr_Base : Car_F {
    class AnimationSources : AnimationSources {
        class HitGlass10;
        class hide_gear_1;
        class hide_gear_2;
        class hide_gear_3;
        class hide_roofcarrier;
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_Tigr_M_PK_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform;
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_PK_Base : CUP_Tigr_M_PK_Base {};
class CUP_O_Tigr_M_233114_PK_RU : CUP_Tigr_233114_PK_Base {};
class CUP_Tigr_M_KORD_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform;
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_KORD_Base : CUP_Tigr_M_KORD_Base {};
class CUP_O_Tigr_M_233114_KORD_RU : CUP_Tigr_233114_KORD_Base {};
class CUP_nHMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_nHMMWV_DF_Base : CUP_nHMMWV_Base {
    class Turrets;
};
class CUP_nM1025_Mk19_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_Mk19_DF_NATO_T : CUP_nM1025_Mk19_DF_Base {};
class CUP_nM1025_M240_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M240_DF_NATO_T : CUP_nM1025_M240_DF_Base {};
class CUP_nM1025_M2_DF_Base : CUP_nHMMWV_DF_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn;
    };
};
class CUP_B_nM1025_M2_DF_NATO_T : CUP_nM1025_M2_DF_Base {};
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
        class TopTurret : MainTurret {};
    };
};
class B_T_LSV_01_armed_F : LSV_01_armed_base_F {};
class MRAP_03_base_F : Car_F {
    class Turrets;
};
class MRAP_03_hmg_base_F : MRAP_03_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
    };
};
class I_MRAP_03_hmg_F : MRAP_03_hmg_base_F {};
class Inegal_VAB_HMG : I_MRAP_03_hmg_F {};
class CUP_LR_Base : Car_F {
    class AnimationSources : AnimationSources {
        class selection_wheels;
    };
    class Turrets;
};
class CUP_LR_Special_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class MainTurret;
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret : MainTurret {};
    };
};
class CUP_I_LR_SF_HMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_m2;
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class CUP_I_LR_SF_GMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_gmg;
        class muzzle_rot_gmg;
        class selection_rear;
        class selection_roll;
        class selection_tarp;
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class CUP_B_LR_Special_CZ_W : CUP_LR_Special_Base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {};
    };
};
class Inegal_LandRover_GL : CUP_B_LR_Special_CZ_W {};
class Inegal_LandRover_FDF_GL : Inegal_LandRover_GL {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class Inegal_VAB_D_HMG : Inegal_VAB_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CommanderTurret : CommanderTurret {};
    };
};
class uksf_aug_landrover_gmg : CUP_I_LR_SF_GMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_aug_landrover_mg : CUP_I_LR_SF_HMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cartel_commando_LR_GMG : CUP_B_LR_Special_CZ_W {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_cartel_commando_LR_MG : CUP_I_LR_SF_HMG_AAF {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class PK_Turret : PK_Turret {};
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class uksf_vaf_LSV_01_armed_SF : B_T_LSV_01_armed_F {
    class Turrets : Turrets {
        class TopTurret : TopTurret {};
        class CodRiverTurret : CodRiverTurret {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
    };
};
class uksf_vaf_M1025_M2 : CUP_B_nM1025_M2_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_vaf_M1025_M240 : CUP_B_nM1025_M240_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_vaf_M1025_Mk19 : CUP_B_nM1025_Mk19_DF_NATO_T {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_zgf_tigr_kord : CUP_O_Tigr_M_233114_KORD_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class uksf_zgf_tigr_pk : CUP_O_Tigr_M_233114_PK_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
