class MRAP_03_base_F : Car_F {
    class Turrets;
};
class MRAP_03_hmg_base_F : MRAP_03_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
    };
};
class CUP_Tigr_Base : Car_F {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
        class hide_gear_1 {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_gear_2 {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_gear_3 {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_roofcarrier {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_Tigr_SPM_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
    };
};
class CUP_Tigr_STS_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
        class hide_gunnerplatform {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_pkm_shield {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_Tigr_M_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class HitGlass10 {
            hitpoint = "HitGlass10";
        };
        class hide_gunnerplatform {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
        class hide_pkm_shield {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 0;
        };
        class mainturret {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_M1240_Base : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
    };
    class NewTurret;
};
class CUP_M1240_M134_Base : CUP_M1240_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_M134_veh";
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class Turret_Commander;
    };
};
class CUP_M1240A1_M134_Base : CUP_M1240_M134_Base {};
class CUP_M1240_M240_Base : CUP_M1240_Base {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class Turret_Commander;
    };
};
class CUP_M1240_M2_Base : CUP_M1240_Base {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class Turret_Commander;
    };
};
class CUP_M1240_Mk19_Base : CUP_M1240_Base {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
        class Turret_Commander;
    };
};
class CUP_M1240_OGPK_M240_Base : CUP_M1240_M240_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_M240_veh";
        };
    };
};
class CUP_M1240A1_OGPK_M240_Base : CUP_M1240_OGPK_M240_Base {};
class CUP_M1240_OGPK_M2_Base : CUP_M1240_M2_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vhmg_M2_HMMWV_veh";
        };
    };
};
class CUP_M1240A1_OGPK_M2_Base : CUP_M1240_OGPK_M2_Base {};
class CUP_M1240_OGPK_Mk19_Base : CUP_M1240_Mk19_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vgmg_MK19_veh";
        };
    };
};
class CUP_M1277_Base : CUP_M1240_Base {
    class AnimationSources : AnimationSources {
        class muzzle_source_rot {
            source = "ammorandom";
            weapon = "CUP_Vhmg_M2_CROWS_veh";
        };
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vhmg_M2_CROWS_veh";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_Vhmg_M2_CROWS_veh";
        };
    };
};
class CUP_M1277_M134_Base : CUP_M1277_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_Vlmg_M134_veh";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class Turret_Commander;
    };
};
class CUP_M1277_Mk19_Base : CUP_M1277_Base {
    class AnimationSources : AnimationSources {
        class muzzle_source_rot {
            source = "ammorandom";
            weapon = "CUP_Vgmg_MK19_crows_veh";
        };
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vgmg_MK19_crows_veh";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_Vgmg_MK19_crows_veh";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class Turret_Commander;
    };
};
class CUP_RG31_BASE : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_RG31_Mk19 : CUP_RG31_BASE {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Vgmg_MK19_veh";
        };
    };
};
class CUP_Tigr_M_KORD_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_KORD_Base : CUP_Tigr_M_KORD_Base {};
class CUP_Tigr_M_PK_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233114_PK_Base : CUP_Tigr_M_PK_Base {};
class CUP_Tigr_STS_PK_Base : CUP_Tigr_Base {
    class AnimationSources : AnimationSources {
        class hide_gunnerplatform {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
        class MainTurretTurnIn;
    };
};
class CUP_Tigr_233014_PK_Base : CUP_Tigr_STS_PK_Base {};
class CUP_B_Tigr_233014_PK_AFU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_233014_PK_CDF : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_233014_PK_GREEN_AFU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_M_233114_KORD_AFU : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_M_233114_KORD_GREEN_AFU : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_M_233114_PK_AFU : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_Tigr_M_233114_PK_GREEN_AFU : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_FENNEK_HMG_ION : MRAP_03_hmg_base_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class HitPoints {};
        };
        class CommanderTurret : CommanderTurret {};
    };
};
class CUP_M1240_Unarmed_Base : CUP_M1240_Base {
    class Turrets : Turrets {
        class MainTurretFFV;
        class MainTurretTurnIn;
        class Turret_Commander;
    };
};
class CUP_M1240A1_Unarmed_Base : CUP_M1240_Unarmed_Base {};
class CUP_I_M1240_ION : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_I_M1240_ION_WIN : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_I_M1240_M134_ION : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_I_M1240_M134_ION_WIN : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_I_Tigr_233014_PK_UN : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_Tigr_M_233114_KORD_ION : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_Tigr_M_233114_KORD_ION_WIN : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_Tigr_M_233114_PK_ION : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_I_Tigr_M_233114_PK_ION_WIN : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1240_AFU : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_M134_AFU : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_M134_NATO : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_M134_NATO_T : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_M134_USA_Desert : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_M134_USA_WDL : CUP_M1240_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_NATO : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_NATO_T : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_AFU : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_NATO : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_NATO_T : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_RACS : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_USA_Desert : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M240_USA_WDL : CUP_M1240_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_AFU : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_NATO : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_NATO_T : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_RACS : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_USA_Desert : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_M2_USA_WDL : CUP_M1240_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_Mk19_AFU : CUP_M1240_OGPK_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_Mk19_NATO : CUP_M1240_OGPK_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_Mk19_NATO_T : CUP_M1240_OGPK_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_Mk19_USA_Desert : CUP_M1240_OGPK_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_OGPK_Mk19_USA_WDL : CUP_M1240_OGPK_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_RACS : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_USA_Desert : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240_USA_WDL : CUP_M1240_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_AFU : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_LDF : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_NATO : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_NATO_T : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_USA_Desert : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1240A1_USA_WDL : CUP_M1240A1_Unarmed_Base {
    class Turrets : Turrets {
        class MainTurretFFV : MainTurretFFV {};
        class MainTurretTurnIn : MainTurretTurnIn {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Base : CUP_M1240_Base {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_M1245_CROWS_Base : CUP_M1245_Base {
    class AnimationSources;
    class Turrets;
};
class CUP_M1245_CROWS_M134_Base : CUP_M1245_CROWS_Base {
    class AnimationSources : AnimationSources {
        class muzzle_source_rot_3 {
            source = "ammorandom";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class reloadanim_2 {
            source = "reload";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class reloadmagazine_2 {
            source = "reloadmagazine";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_Vlmg_M134_veh";
        };
        class revolving_3 {
            source = "revolving";
            weapon = "CUP_Vlmg_M134_veh";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class Turret_Observer;
        class MainTurretRear04TurnIn;
        class MainTurretRear05TurnIn;
    };
};
class CUP_M1245_CROWS_M134_AFU : CUP_M1245_CROWS_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Observer : Turret_Observer {
            class HitPoints {};
        };
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M134_USA_Desert : CUP_M1245_CROWS_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Observer : Turret_Observer {
            class HitPoints {};
        };
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M134_USA_WDL : CUP_M1245_CROWS_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Observer : Turret_Observer {
            class HitPoints {};
        };
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
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
class CUP_M1245_CROWS_M2_AFU : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M2_Arid_CTRG : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M2_CTRG : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M2_Urban_CTRG : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M2_USA_Desert : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_M2_USA_WDL : CUP_M1245_CROWS_M2_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_Base : CUP_M1245_CROWS_Base {
    class Turrets : Turrets {
        class Turret_Observer;
        class MainTurretRear04TurnIn;
        class MainTurretRear05TurnIn;
        class RearM240Turret;
        class MainTurret;
    };
};
class CUP_M1245_CROWS_Mk19_AFU : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_Arid_CTRG : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_CTRG : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_Urban_CTRG : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_USA_Desert : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_CROWS_Mk19_USA_WDL : CUP_M1245_CROWS_Mk19_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_Base : CUP_M1245_Base {
    class Turrets : Turrets {
        class Turret_Observer;
        class MainTurretRear04TurnIn;
        class MainTurretRear05TurnIn;
        class RearM240Turret : MainTurret {
            stabilizedInAxes = 3;
        };
        class RearM134Turret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M1245_RearM240_AFU : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_Arid_CTRG : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_CTRG : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_RACS : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_Urban_CTRG : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_USA_Desert : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_RearM240_USA_WDL : CUP_M1245_RearM240_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
        class RearM240Turret : RearM240Turret {
            class HitPoints {};
        };
        class RearM134Turret : RearM134Turret {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_Base : CUP_M1245_Base {
    class Turrets : Turrets {
        class Turret_Observer;
        class MainTurretRear04TurnIn;
        class MainTurretRear05TurnIn;
    };
};
class CUP_M1245_Unarmed_AFU : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_Arid_CTRG : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_CTRG : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_RACS : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_Urban_CTRG : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_USA_Desert : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1245_Unarmed_USA_WDL : CUP_M1245_Unarmed_Base {
    class Turrets : Turrets {
        class Turret_Observer : Turret_Observer {};
        class MainTurretRear04TurnIn : MainTurretRear04TurnIn {
            class HitPoints {};
        };
        class MainTurretRear05TurnIn : MainTurretRear05TurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M134_AFU : CUP_M1277_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M134_USA_Desert : CUP_M1277_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M134_USA_WDL : CUP_M1277_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M2_Base : CUP_M1277_Base {
    class Turrets : Turrets {
        class MainTurret;
        class Turret_Commander;
    };
};
class CUP_M1277_M2_AFU : CUP_M1277_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M2_LDF : CUP_M1277_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M2_USA_Desert : CUP_M1277_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_M2_USA_WDL : CUP_M1277_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_Mk19_AFU : CUP_M1277_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_Mk19_LDFt : CUP_M1277_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_Mk19_USA_Desert : CUP_M1277_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_M1277_Mk19_USA_WDL : CUP_M1277_Mk19_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_DESERT_PK_RU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_GREEN_PK_RU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_PK_CHDKZ : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_PK_RU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_PK_SLA : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_PK_TKA : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_233014_WINTER_PK_RU : CUP_Tigr_233014_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_DESERT_KORD_RU : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_DESERT_PK_RU : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_GREEN_KORD_RU : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_GREEN_PK_RU : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_KORD_CSAT : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_KORD_CSAT_T : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_KORD_TKA : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_PK_CSAT : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_PK_CSAT_T : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_PK_TKA : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_WINTER_KORD_RU : CUP_Tigr_233114_KORD_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_O_Tigr_M_233114_WINTER_PK_RU : CUP_Tigr_233114_PK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_Tigr_233011_Base : CUP_Tigr_Base {
    class Turrets {
        class MainTurretTurnIn;
        class MainTurretFFV;
        class SecTurretTurnIn : NewTurret {
            class HitPoints {};
        };
        class SecTurretFFV;
    };
};
class CUP_Tigr_233034_Base : CUP_Tigr_SPM_Base {
    class Turrets {
        class MainTurretTurnIn;
        class MainTurretFFV;
        class SecTurretTurnIn : NewTurret {
            class HitPoints {};
        };
        class SecTurretFFV;
    };
};
class M1240A1_M134_AFU : CUP_M1240A1_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_M134_NATO : CUP_M1240A1_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_M134_NATO_T : CUP_M1240A1_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_M134_USA_Desert : CUP_M1240A1_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_M134_USA_WDL : CUP_M1240A1_M134_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M240_AFU : CUP_M1240A1_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M240_NATO : CUP_M1240A1_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M240_NATO_T : CUP_M1240A1_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M240_USA_Desert : CUP_M1240A1_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M240_USA_WDL : CUP_M1240A1_OGPK_M240_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M2_AFU : CUP_M1240A1_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M2_NATO : CUP_M1240A1_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M2_NATO_T : CUP_M1240A1_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M2_USA_Desert : CUP_M1240A1_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
class M1240A1_OGPK_M2_USA_WDL : CUP_M1240A1_OGPK_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
        class Turret_Commander : Turret_Commander {
            class HitPoints {};
        };
    };
};
