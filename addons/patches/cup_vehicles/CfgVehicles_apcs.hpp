class CUP_Boxer_Base_HMG : CUP_Boxer_Base {
    class Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_Boxer_Base_GMG : CUP_Boxer_Base_HMG {
    class Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_Boxer_GMG_GER_DES : CUP_Boxer_Base_GMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class CUP_B_Boxer_GMG_GER_WDL : CUP_Boxer_Base_GMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class CUP_B_Boxer_HMG_GER_DES : CUP_Boxer_Base_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class CUP_B_Boxer_HMG_GER_WDL : CUP_Boxer_Base_HMG {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class CargoTurret_03 : CargoTurret_03 {
            class HitPoints {};
        };
        class CargoTurret_04 : CargoTurret_04 {
            class HitPoints {};
        };
    };
};
class Wheeled_APC_F : Car_F {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class CUP_BRDM2_Base : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class NewTurret;
    class Turrets;
};
class CUP_BRDM2_HQ_Base : CUP_BRDM2_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_BTR40_MG_Base : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_BTR80_Common_Base : Wheeled_APC_F {
    class AnimationSources;
    class Turrets;
};
class CUP_BTR90_Base : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR90_HQ_Base : CUP_BTR90_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_GAZ_Vodnik_Base : Wheeled_APC_F {
    class AnimationSources : AnimationSources {
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_GAZ_Vodnik_MedEvac_Base : CUP_GAZ_Vodnik_Base {
    class AnimationSources : AnimationSources {
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
    };
    class Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_GAZ_Vodnik_Unarmed_base : CUP_GAZ_Vodnik_Base {
    class AnimationSources : AnimationSources {
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
    };
    class Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_StrykerBase : Wheeled_APC_F {
    class AnimationSources;
    class Turrets;
};
class CUP_BRDM2_ATGM_Base : CUP_BRDM2_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR40_Base : CUP_BTR40_MG_Base {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR80A_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_pkt {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
        class muzzle_rot_pkt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class CUP_O_BTR80A_GREEN_RU : CUP_BTR80A_Base {};
class CUP_BTR80_Base : CUP_BTR80_Common_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_kpvt {
            source = "reload";
            weapon = "CUP_Vhmg_KPVT_veh";
        };
        class muzzle_hide_pkt {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
        class muzzle_rot_kpvt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_KPVT_veh";
        };
        class muzzle_rot_pkt {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_Noeject";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoTurret_07;
        class CargoTurret_08;
    };
};
class CUP_O_BTR80_GREEN_RU : CUP_BTR80_Base {};
class CUP_B_M1128_MGS_Desert : CUP_StrykerBase {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class CommanderOptics : NewTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_M1135_ATGMV_Desert : CUP_StrykerBase {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_M1126_ICV_BASE : CUP_StrykerBase {
    class AnimationSources;
    class Turrets;
};
class CUP_B_M1126_ICV_M2_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1126_ICV_MK19_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class ObsTurret;
        class CargoTurret_01;
    };
};
class CUP_B_M1129_MC_MK19_Desert : CUP_B_M1126_ICV_MK19_Desert {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class ObsTurret : ObsTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
    };
};
class CUP_B_M1130_CV_M2_Desert : CUP_B_M1126_ICV_M2_Desert {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_B_M1133_MEV_Desert : CUP_M1126_ICV_BASE {
    class AnimationSources : AnimationSources {
        class hitglass1 {
            source = "Hit";
            hitpoint = "HitGlass1";
            raw = 1;
        };
        class hitglass2 {
            source = "Hit";
            hitpoint = "HitGlass2";
            raw = 1;
        };
        class hitglass3 {
            source = "Hit";
            hitpoint = "HitGlass3";
            raw = 1;
        };
        class hitglass4 {
            source = "Hit";
            hitpoint = "HitGlass4";
            raw = 1;
        };
    };
};
class CUP_BTR60_Base : Wheeled_APC_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_06;
        class CargoGunner_1;
        class CargoGunner_2;
    };
};
class CUP_B_BTR60_AFU : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_BTR60_CDF : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_BTR60_FIA : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_BTR80_CDF : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_B_BTR80_FIA : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_B_BTR80A_CDF : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_B_BTR80A_FIA : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_LAV25_Base : Wheeled_APC_F {
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1;
        class CargoGunner_2;
    };
};
class CUP_B_LAV25_USMC : CUP_LAV25_Base {
    class AnimationSources;
};
class CUP_B_LAV25_HQ_USMC : CUP_B_LAV25_USMC {
    class AnimationSources : AnimationSources {
        class maingun {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CommanderOptics;
        class CargoGunner_1 : NewTurret {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_3 : NewTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25_desert_USMC : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25_green : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_B_LAV25M240_USMC : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_Mastiff_Base : Wheeled_APC_F {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class commanderoptics;
    };
};
class CUP_B_Mastiff_GMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_GMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_HMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_HMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_LMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Mastiff_LMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_Ridgback_Base : Wheeled_APC_F {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_B_Ridgback_GMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Ridgback_GMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Ridgback_HMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Ridgback_HMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Ridgback_LMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_B_Ridgback_LMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_Wolfhound_Base : Wheeled_APC_F {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class CommanderTurret;
        class commanderoptics;
    };
};
class CUP_B_Wolfhound_HMG_GB_D : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_B_Wolfhound_HMG_GB_W : CUP_Wolfhound_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class commanderoptics : commanderoptics {
            class HitPoints {};
        };
    };
};
class CUP_GAZ_Vodnik_AGS_Base : CUP_GAZ_Vodnik_Base {
    class Turrets : Turrets {
        class MainTurret;
        class BackTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_GAZ_Vodnik_BPPU_Base : CUP_GAZ_Vodnik_Base {
    class Turrets {
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_GAZ_Vodnik_KPVT_Base : CUP_GAZ_Vodnik_Base {
    class Turrets {
        class MainTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_I_BTR60_UN : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_I_BTR80_ION : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_I_BTR80A_ION : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_I_LAV25_RACS : CUP_B_LAV25_USMC {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_CHDKZ : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_CSAT : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_Green_RU : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_RU : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_SLA : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_TK : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR60_Winter_RU : CUP_BTR60_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoGunner_1 : CargoGunner_1 {};
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
    };
};
class CUP_O_BTR80_CAMO_RU : CUP_O_BTR80_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_CHDKZ : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_CSAT : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_CSAT_T : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_DESERT_RU : CUP_O_BTR80_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_SLA : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_TK : CUP_BTR80_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80_WINTER_RU : CUP_O_BTR80_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_CAMO_RU : CUP_O_BTR80A_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_CHDKZ : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_CSAT_T : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_DESERT_RU : CUP_O_BTR80A_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_SLA : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_TK : CUP_BTR80A_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_BTR80A_WINTER_RU : CUP_O_BTR80A_GREEN_RU {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {};
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_07 : CargoTurret_07 {};
        class CargoTurret_08 : CargoTurret_08 {};
    };
};
class CUP_O_GAZ_Vodnik_AGS_RU : CUP_GAZ_Vodnik_AGS_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_O_GAZ_Vodnik_BPPU_RU : CUP_GAZ_Vodnik_BPPU_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_O_GAZ_Vodnik_KPVT_RU : CUP_GAZ_Vodnik_KPVT_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_O_GAZ_Vodnik_MedEvac_RU : CUP_GAZ_Vodnik_MedEvac_Base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_O_GAZ_Vodnik_PK_RU : CUP_GAZ_Vodnik_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class BackTurret : BackTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {
            class HitPoints {};
        };
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
        };
    };
};
class CUP_O_GAZ_Vodnik_Unarmed_RU : CUP_GAZ_Vodnik_Unarmed_base {
    class Turrets : Turrets {
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {
            class HitPoints {};
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
