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
class Air : AllVehicles {
    class AnimationSources;
};
class Plane : Air {};
class Plane_Base_F : Plane {
    class AnimationSources;
    class Turrets;
};
class Helicopter : Air {
    class AnimationSources;
};
class Helicopter_Base_F : Helicopter {
    class Turrets;
};
class Helicopter_Base_H : Helicopter_Base_F {
    class AnimationSources : AnimationSources {
        class HitEngine2;
    };
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class Land : AllVehicles {};
class LandVehicle : Land {};
class Tank : LandVehicle {
    class NewTurret;
};
class Tank_F : Tank {
    class NewTurret;
    class Turrets {
        class MainTurret : NewTurret {
            class Turrets {
                class CommanderOptics;
            };
        };
    };
};
class APC_Tracked_02_base_F : Tank_F {
    class AnimationSources : AnimationSources {
        class muzzle_hide_cannon;
    };
    class Turrets : Turrets {
        class MainTurret;
    };
};
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
class Truck_F : Car_F {};
class MRAP_03_base_F : Car_F {
    class Turrets;
};
class MRAP_03_hmg_base_F : MRAP_03_base_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
    };
};
class Wheeled_APC_F : Car_F {
    class AnimationSources;
    class NewTurret;
    class Turrets {
        class MainTurret;
    };
};
class CUP_M151_base : Car_F {
    aggregateReflectors[] = {{"LightCarHeadL01",  "LightCarHeadR01"}};
    class Turrets;
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
class CUP_MH47E_base : Helicopter_Base_H {
    scope = 0;
    class AnimationSources;
};
class CUP_412_01_base_F : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets;
};
class CUP_412_Civ_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Luxury_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Medic_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Transport_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_412_Mil_Utility_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Military_Radar_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_412_Police_Base_F : CUP_412_01_base_F {
    class AnimationSources : AnimationSources {
        class inspect_panel1_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class inspect_panel2_1 {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret;
    };
};
class CUP_AH6_BASE : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_MH6_TRANSPORT : CUP_AH6_BASE {};
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
class CUP_B_AH6X_USA : CUP_AH6_BASE {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_Datsun_Base : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_ECVHMMWV_Base : Car_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
    };
};
class CUP_ECVHMMWV_m240_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_ECVHMMWV_m2_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_ECVHMMWV_mk19_Base : CUP_ECVHMMWV_Base {
    class AnimationSources : AnimationSources {
        class hide_overhead_protection {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 0;
        };
        class hide_running_boards {
            source = "user";
            animPeriod = 1e-07;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
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
class CUP_Ka60_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class reloadanim {
            source = "reload";
            weapon = "CUP_M32_heli";
        };
        class revolving {
            source = "revolving";
            weapon = "CUP_M32_heli";
        };
    };
    class Turrets : Turrets {
        class MainTurret;
        class CopilotTurret;
    };
};
class CUP_Ka60_GL_BASE : CUP_Ka60_Base {};
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
class CUP_M113New_Base : Tank_F {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret;
        class CargoGunner_1;
        class CargoGunner_2;
        class MainTurretTurnIn;
    };
};
class CUP_M113A3_Base : CUP_M113New_Base {};
class CUP_M113A1_Base : CUP_M113New_Base {};
class CUP_M113New_HQ_Base : CUP_M113New_Base {
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
};
class CUP_M113New_Med_Base : CUP_M113New_Base {
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
class CUP_MH60S_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Merlin_HC3_Base : Helicopter_Base_H {
    class AnimationSources;
};
class CUP_Merlin_HC3_Lux_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class addgunholder {
            source = "user";
            animPeriod = 1e-06;
            initPhase = 0;
        };
        class dvere_l {
            source = "door";
            animPeriod = 1.3;
            initPhase = 0;
        };
        class dvere_p {
            source = "door";
            animPeriod = 1.3;
            initPhase = 0;
        };
        class hide_radar {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class hidepipmfdco {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class hidepipmfdpi {
            source = "user";
            animPeriod = 0;
            initPhase = 0;
        };
        class rampa {
            source = "door";
            animPeriod = 6;
            initPhase = 0;
        };
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class winchsection2 {
            source = "user";
            initPhase = 0;
        };
    };
};
class CUP_Merlin_HC3_VIV_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_HM2_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_Merlin_Rescue_Base : Helicopter_Base_H {
    class AnimationSources;
    class Turrets : Turrets {
        class CopilotTurret;
        class FLIRTurret : MainTurret {
            class HitPoints {};
        };
        class LoadmasterTurret : MainTurret {
            class HitPoints {};
        };
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
class CUP_StrykerBase : Wheeled_APC_F {
    class AnimationSources;
    class Turrets;
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
class CUP_T90M_Base : Tank_F {
    class AnimationSources : AnimationSources {
        class coax_muzzlehide {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_T90M";
        };
        class muzzleflash_cannon_rot {
            source = "ammorandom";
            weapon = "CUP_Vcannon_2A46_Txx";
        };
    };
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : NewTurret {
                    class HitPoints {};
                };
                class CommanderPeriscope : NewTurret {
                    class HitPoints {};
                };
            };
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
class CUP_UH1H_base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class side_door_extension_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class RightDoorGun;
        class LeftDoorGun;
        class CopilotTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_UH1H_gunship_base : CUP_UH1H_base {};
class CUP_O_UH1H_gunship_TKA : CUP_UH1H_gunship_base {};
class CUP_UH1H_armed_base : CUP_UH1H_base {};
class CUP_Uh60_Base : Helicopter_Base_H {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class pylons_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Uh60L_Base : CUP_Uh60_Base {};
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
class CUP_B_MH47E_USA : CUP_MH47E_base {
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
        class hitglass6 {
            source = "Hit";
            hitpoint = "HitGlass6";
            raw = 1;
        };
    };
};
class CUP_B_MH6J_OBS_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6J_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6M_OBS_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MH6M_USA : CUP_MH6_TRANSPORT {
    class AnimationSources : AnimationSources {
        class hidegaul {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidegaur {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134l {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
        class hidem134r {
            source = "user";
            animPeriod = 1e-05;
            initPhase = 0;
        };
    };
};
class CUP_B_MV22_USMC : Plane_Base_F {
    class AnimationSources;
    class Turrets : Turrets {
        class CopilotTurret;
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_B_MV22_USMC_RAMPGUN : CUP_B_MV22_USMC {
    class AnimationSources : AnimationSources {
        class gatling_2 {
            source = "revolving";
            weapon = "CUP_Vlmg_M240_veh";
        };
        class gatling_2_muzzle_rot {
            source = "ammorandom";
            weapon = "CUP_Vlmg_M240_veh";
        };
    };
    class Turrets : Turrets {
        class RightDoorGun;
        class CopilotTurret : CopilotTurret {
            class HitPoints {};
        };
        class CargoTurret_01;
        class CargoTurret_02;
    };
};
class CUP_B_Merlin_HC3_GB : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_CIV_Rescue : CUP_Merlin_Rescue_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
    };
};
class CUP_C_Merlin_HC3_IDAP_Rescue : CUP_Merlin_Rescue_Base {
    class AnimationSources : AnimationSources {
        class flir_gun {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class flir_turret {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
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
class CUP_M1126_ICV_BASE : CUP_StrykerBase {
    class AnimationSources;
    class Turrets;
};
class CUP_M113A1_HQ_Base : CUP_M113New_HQ_Base {
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
};
class CUP_M113A1_Med_Base : CUP_M113New_Med_Base {
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
};
class CUP_M113A3_Reammo_Base : CUP_M113New_HQ_Base {
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
};
class CUP_M113A3_Repair_Base : CUP_M113New_HQ_Base {
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
};
class CUP_Merlin_HC3A_Base : CUP_Merlin_HC3_Base {
    class AnimationSources : AnimationSources {
        class rampa_hide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
        };
        class rampa_unhide {
            source = "user";
            animPeriod = 0;
            initPhase = 1;
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
class CUP_T90MS_Base : CUP_T90M_Base {
    class AnimationSources : AnimationSources {
        class coax_muzzlehide {
            source = "reload";
            weapon = "CUP_Vhmg_PKT_T90M";
        };
        class muzzleflash_cannon_rot {
            source = "ammorandom";
            weapon = "CUP_Vcannon_2A46_Txx";
        };
    };
};
class CUP_UH60_Unarmed_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_Uh60S_Base : CUP_Uh60_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class pylons_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
    class Turrets : Turrets {
        class CopilotTurret;
        class MainTurret;
        class RightDoorGun;
    };
};
class CUP_Uh60_Unarmed_FFV_Base : CUP_UH60_Unarmed_Base {
    class AnimationSources;
};
class CUP_MH60S_Unarmed_FFV_Base : CUP_Uh60_Unarmed_FFV_Base {};
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
class CUP_MH60S_Unarmed_FFV_USN : CUP_MH60S_Unarmed_FFV_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_MH60S_Unarmed_USN : CUP_UH60_Unarmed_Base {
    class AnimationSources : AnimationSources {
        class miniguns_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
        class seats_hide {
            source = "user";
            animPeriod = 1;
            initPhase = 1;
        };
    };
};
class CUP_2S6_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
    };
};
class CUP_2S6M_Base : CUP_2S6_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
    };
};
class CUP_412_Military_Armed_Base_F : CUP_412_01_base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_dynamicLoadout_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_412_Military_Armed_AT_Base_F : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret;
        class LeftTurret;
        class RightTurret;
        class FLIRTurret;
        class CargoTurret_06;
        class CargoTurret_04;
    };
};
class CUP_AAV_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret;
        class CargoGunner_1;
        class CargoGunner_2;
        class CargoGunner_3;
        class CargoGunner_4;
        class CargoGunner_5;
        class CargoGunner_6;
    };
};
class CUP_B_412_dynamicLoadout_HIL : CUP_412_dynamicLoadout_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_412_Mil_Utility_HIL : CUP_412_Mil_Utility_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_412_Military_Armed_HIL : CUP_412_Military_Armed_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class LeftTurret : LeftTurret {
            class HitPoints {};
        };
        class RightTurret : RightTurret {
            class HitPoints {};
        };
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
        class CargoTurret_06 : CargoTurret_06 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_412_Military_Radar_HIL : CUP_412_Military_Radar_Base_F {
    class Turrets : Turrets {
        class CopilotTurret : CopilotTurret {};
        class FLIRTurret : FLIRTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_AAV_Unarmed_USMC : CUP_AAV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class CargoGunner_3 : CargoGunner_3 {
            class HitPoints {};
        };
        class CargoGunner_4 : CargoGunner_4 {
            class HitPoints {};
        };
        class CargoGunner_5 : CargoGunner_5 {
            class HitPoints {};
        };
        class CargoGunner_6 : CargoGunner_6 {
            class HitPoints {};
        };
    };
};
class CUP_B_AAV_USMC : CUP_AAV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CommanderTurret : CommanderTurret {
            class HitPoints {};
        };
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class CargoGunner_3 : CargoGunner_3 {
            class HitPoints {};
        };
        class CargoGunner_4 : CargoGunner_4 {
            class HitPoints {};
        };
        class CargoGunner_5 : CargoGunner_5 {
            class HitPoints {};
        };
        class CargoGunner_6 : CargoGunner_6 {
            class HitPoints {};
        };
    };
};
class CUP_BMP1_base : APC_Tracked_02_base_F {
    class Turrets : Turrets {
        class CommanderOptics;
        class MainTurret : MainTurret {
            class Turrets;
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
class CUP_BMP2_base : CUP_BMP1_base {
    class AnimationSources;
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
            };
        };
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
        class CargoTurret_05;
        class CargoTurret_07;
    };
    class NewTurret;
};
class CUP_B_BMP2_CZ : CUP_BMP2_base {};
class CUP_BMP2_Ambul_Base : CUP_BMP2_base {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
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
};
class CUP_BMP2_HQ_Base : CUP_BMP2_base {
    class AnimationSources {
        class hatchc {
            source = "door";
            animPeriod = 0.8;
        };
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class hatchd {
            source = "door";
            animPeriod = 0.8;
        };
        class hatchg {
            source = "door";
            animPeriod = 0.8;
        };
    };
    class Turrets : Turrets {
        class MainTurret : NewTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_BMP2_ZU_base : CUP_BMP2_base {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
    };
};
class CUP_B_BMP2_CDF : CUP_BMP2_base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
        };
    };
};
class CUP_B_BMP2_CZ_Des : CUP_B_BMP2_CZ {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {
                    class HitPoints {};
                };
            };
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
        class CargoTurret_05 : CargoTurret_05 {
            class HitPoints {};
        };
        class CargoTurret_07 : CargoTurret_07 {
            class HitPoints {};
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
class CUP_HMMWV_Base : Car_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            stabilizedInAxes = 3;
        };
    };
};
class CUP_HMMWV_SOV_M2_Base : CUP_HMMWV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class SideTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_HMMWV_SOV_M2_NATO_T : CUP_HMMWV_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_HMMWV_SOV_M2_USA : CUP_HMMWV_SOV_M2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_HMMWV_SOV_Base : CUP_HMMWV_Base {
    class Turrets : Turrets {
        class MainTurret;
        class SideTurret;
        class CargoTurret_01;
        class CargoTurret_02;
        class CargoTurret_03;
        class CargoTurret_04;
    };
};
class CUP_B_HMMWV_SOV_NATO_T : CUP_HMMWV_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
    };
};
class CUP_B_HMMWV_SOV_USA : CUP_HMMWV_SOV_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class SideTurret : SideTurret {
            class HitPoints {};
        };
        class CargoTurret_01 : CargoTurret_01 {};
        class CargoTurret_02 : CargoTurret_02 {};
        class CargoTurret_03 : CargoTurret_03 {};
        class CargoTurret_04 : CargoTurret_04 {};
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
class CUP_Leopard2_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret : NewTurret {
                    stabilizedInAxes = 3;
                };
            };
        };
    };
};
class CUP_Leopard2_ERA_Base : CUP_Leopard2_Base {};
class CUP_B_Leopard2A6_UA : CUP_Leopard2_ERA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_Leopard2A6DST_GER : CUP_Leopard2_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_Leopard2A6Green_UA : CUP_Leopard2_ERA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
            };
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
        class MainTurret : MainTurret {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A1_desert_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A1_olive_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A1_USA : CUP_M113A1_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_desert_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_GER : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_olive_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_B_M113A3_USA : CUP_M113A3_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {};
        class CargoGunner_1 : CargoGunner_1 {
            class HitPoints {};
        };
        class CargoGunner_2 : CargoGunner_2 {
            class HitPoints {};
        };
        class MainTurretTurnIn : MainTurretTurnIn {
            class HitPoints {};
        };
    };
};
class CUP_M1Abrams_Base : Tank_F {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurret {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abramcs_M1A1SA_Base : CUP_M1Abrams_Base {};
class CUP_B_M1A1_AFU : CUP_M1Abramcs_M1A1SA_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M1Abrams_TUSK_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_M1Abrams_M1A1SA_TUSK_Base : CUP_M1Abrams_TUSK_Base {};
class CUP_B_M1A1_TUSK_AFU : CUP_M1Abrams_M1A1SA_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M1Abrams_M1A1FEP_F_TUSK_Base : CUP_M1Abrams_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1EP_TUSK_OD_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A1EP_TUSK_Woodland_USMC : CUP_M1Abrams_M1A1FEP_F_TUSK_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_M1Abrams_M1A1FEP_Base : CUP_M1Abrams_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics;
                class LoaderTurret;
                class LoaderTurretMG : LoaderTurretMG {
                    stabilizedInAxes = 3;
                };
                class CommanderOpticsGPSE;
            };
        };
    };
};
class CUP_B_M1A1FEP_Desert_USMC : CUP_M1Abrams_M1A1FEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
class CUP_B_M1A1FEP_OD_USMC : CUP_M1Abrams_M1A1FEP_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class Turrets : Turrets {
                class CommanderOptics : CommanderOptics {};
                class LoaderTurret : LoaderTurret {
                    class HitPoints {};
                };
                class LoaderTurretMG : LoaderTurretMG {
                    class HitPoints {};
                };
                class CommanderOpticsGPSE : CommanderOpticsGPSE {
                    class HitPoints {};
                };
            };
        };
    };
};
