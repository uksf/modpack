class CUP_UAZ_Armed_Base : CUP_UAZ_Base {
    class AnimationSources;
    class Turrets;
};
class CUP_UAZ_METIS_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_MG_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_SPG9_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AA_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_UAZ_AGS30_Base : CUP_UAZ_Armed_Base {
    class AnimationSources : AnimationSources {
        class hide_lower_tarp {
            source = "user";
            animPeriod = 0.1;
        };
        class hide_upper_tarp {
            source = "user";
            animPeriod = 0.1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M151_base : Car_F {
    aggregateReflectors[] = {{"LightCarHeadL01",  "LightCarHeadR01"}};
    class Turrets;
};
class CUP_Datsun_Base : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_LR_Base : Car_F {
    class AnimationSources : AnimationSources {
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class Turrets;
};
class CUP_LR_MG_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_LR_SPG9_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_LR_Special_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret;
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_T810_Base : Car_F {
    class AnimationSources;
};
class CUP_T810_Unarmed_Base : CUP_T810_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_Datsun_AA_Base : CUP_Datsun_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Igla_twice_W";
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_I_LR_SF_GMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_hide_gmg {
            source = "reload";
            weapon = "CUP_Vgmg_MK19_veh";
        };
        class muzzle_rot_gmg {
            source = "ammorandom";
            weapon = "CUP_Vgmg_MK19_veh";
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_I_LR_SF_HMG_AAF : CUP_LR_Special_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_m2 {
            source = "ammorandom";
            weapon = "CUP_Vhmg_M2_static";
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class PK_Turret : PK_Turret {
            stabilizedInAxes = 3;
        };
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_LR_AA_Base : CUP_LR_SPG9_Base {
    class AnimationSources : AnimationSources {
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_LR_Ambulance_Base : CUP_LR_Base {
    class AnimationSources : AnimationSources {
        class selection_antenna_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class selection_box {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class selection_rear {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_roll {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_tarp {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class selection_wheels {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
    };
};
class CUP_T810_Reammo_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_T810_Refuel_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
};
class CUP_T810_Repair_Base : CUP_T810_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class select_plachta {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
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
class CUP_BAF_Jackal2_GMG_D : CUP_BAF_Jackal2_BASE_D {
    class Turrets : Turrets {
        class M240_Turret;
        class GMG_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
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
class CUP_BAF_Jackal2_GMG_W : CUP_BAF_Jackal2_GMG_D {};
class CUP_B_Jackal2_GMG_FIA : CUP_BAF_Jackal2_GMG_W {
    class Turrets : Turrets {
        class M240_Turret : M240_Turret {};
        class GMG_Turret : GMG_Turret {
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
class CUP_BAF_Jackal2_L2A1_D : CUP_BAF_Jackal2_BASE_D {
    class Turrets : Turrets {
        class M240_Turret;
        class M2_Turret : MainTurret {
            stabilizedInAxes = 3;
        };
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
class CUP_BAF_Jackal2_L2A1_W : CUP_BAF_Jackal2_L2A1_D {};
class CUP_B_Jackal2_L2A1_FIA : CUP_BAF_Jackal2_L2A1_W {
    class Turrets : Turrets {
        class M240_Turret : M240_Turret {};
        class M2_Turret : M2_Turret {
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
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_Hilux_Base : Car_F {
    class Turrets;
};
class CUP_Hilux_M2_Base : CUP_Hilux_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_M2_veh";
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_armored_M2_Base : CUP_Hilux_M2_Base {
    class AnimationSources : AnimationSources {
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_M2_veh";
        };
    };
};
class CUP_Hilux_btr60_base : CUP_Hilux_Base {
    class AnimationSources {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_igla_Base : CUP_Hilux_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Igla_twice_W";
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_podnos_Base : CUP_Hilux_Base {
    class AnimationSources : AnimationSources {
        class reloadanim {
            source = "reload";
            weapon = "CUP_mortar_82mm_veh";
        };
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_mortar_82mm_veh";
        };
    };
};
class CUP_Hilux_zu23_Base : CUP_Hilux_Base {
    class AnimationSources {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
    };
};
class CUP_Hilux_BMP1_base : CUP_Hilux_Base {
    class AnimationSources {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_noeject";
        };
    };
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_armored_BMP1_Base : CUP_Hilux_BMP1_base {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
        class muzzle_rot_mg {
            source = "ammorandom";
            weapon = "CUP_Vhmg_PKT_veh_noeject";
        };
    };
};
class CUP_Hilux_armored_BTR60_Base : CUP_Hilux_btr60_base {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
        };
    };
};
class CUP_Hilux_armored_igla_Base : CUP_Hilux_igla_Base {
    class AnimationSources : AnimationSources {
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_Igla_twice_W";
        };
    };
};
class CUP_Hilux_armored_podnos_Base : CUP_Hilux_podnos_Base {
    class AnimationSources : AnimationSources {
        class reloadanim {
            source = "reload";
            weapon = "CUP_mortar_82mm_veh";
        };
        class reloadmagazine {
            source = "reloadmagazine";
            weapon = "CUP_mortar_82mm_veh";
        };
    };
};
class CUP_Hilux_armored_zu23_Base : CUP_Hilux_zu23_Base {
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
        class hitglass5 {
            source = "Hit";
            hitpoint = "HitGlass5";
            raw = 1;
        };
        class hitlbwheel {
            source = "Hit";
            hitpoint = "HitLF2Wheel";
            raw = 1;
        };
        class hitlf2wheel {
            source = "Hit";
            hitpoint = "HitLBWheel";
            raw = 1;
        };
        class hitlfwheel {
            source = "Hit";
            hitpoint = "HitLFWheel";
            raw = 1;
        };
        class hitlmwheel {
            source = "Hit";
            hitpoint = "HitLMWheel";
            raw = 1;
        };
        class hitrbwheel {
            source = "Hit";
            hitpoint = "HitRF2Wheel";
            raw = 1;
        };
        class hitrf2wheel {
            source = "Hit";
            hitpoint = "HitRBWheel";
            raw = 1;
        };
        class hitrfwheel {
            source = "Hit";
            hitpoint = "HitRFWheel";
            raw = 1;
        };
        class hitrmwheel {
            source = "Hit";
            hitpoint = "HitRMWheel";
            raw = 1;
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
class CUP_Datsun_PK_Base : CUP_Datsun_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_AGS30_Base : CUP_Hilux_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_DSHKM_Base : CUP_Hilux_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_metis_Base : CUP_Hilux_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_Hilux_SPG9_Base : CUP_Hilux_Base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_M151_M2_Base : CUP_M151_base {
    class MainTurret;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
