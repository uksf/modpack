class Land_BagFence_End_F;
class House_Small_F;
class RoadCone_L_v2;
class RoadCone_L_F;
class RoadBarrier_small_v2;
class RoadBarrier_small_F;
class Land_Pumpkin_01_F;
class Land_PowLines_Transformer_F;
class Land_PowerLine_01_pole_transformer_F;
class PortableHelipadLight_01_yellow_F;
class PortableHelipadLight_01_white_F;
class PortableHelipadLight_01_red_F;
class PortableHelipadLight_01_green_F;
class PortableHelipadLight_01_blue_F;
class Land_Orange_01_F;
class Land_Laptop_02_unfolded_F;
class Lantern_01_base_F;
class Land_PortableHelipadLight_01_F;
class Land_Balloon_01_water_F;
class Land_Balloon_01_air_F;
class Land_IntravenStand_01_base_F;
class GasTank_01_base_F;
class All {
    class AnimationSources;
};
class Thing : All {};
class ThingX : Thing {};
class Items_base_F : ThingX {};
class AllVehicles : All {
    class NewTurret;
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
class LSV_01_base_F : Car_F {
    class Turrets : Turrets {
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
    };
};
class LSV_01_AT_base_F : LSV_01_base_F {
    class Turrets : Turrets {
        class CodRiverTurret;
        class CargoTurret_02;
        class CargoTurret_03;
        class MainTurret;
        class TopTurret : MainTurret {};
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
class LSV_02_base_F : Car_F {
    class Turrets : Turrets {
        class MainTurret;
    };
};
class Land_AirHorn_01_F;
class AirHorn_01_klaxon : Land_AirHorn_01_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class CanisterFuel_Full : Items_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class FireExtinguisher_Full : Items_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class GasTank_01_full_base_G : GasTank_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class IntravenStand_01_randomBag : Land_IntravenStand_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Balloon_01_air_blue : Land_Balloon_01_air_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Balloon_01_water_blue : Land_Balloon_01_water_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_PortableHelipadLight_01_off : Land_PortableHelipadLight_01_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_black_empty : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_black_off : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_blue_empty : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_blue_off : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_green_empty : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_green_off : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_random : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_random_empty : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_random_off : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_red_empty : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Lantern_01_red_off : Lantern_01_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Laptop_02_unfolded_ofp_video : Land_Laptop_02_unfolded_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Orange_01_part : Land_Orange_01_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Particle_Base_F : Thing {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Particle_Bubbles_F : Thing {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Particle_BigFire1_F : Particle_Bubbles_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Particle_Smoke_F : Particle_Bubbles_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_blue_off : PortableHelipadLight_01_blue_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_blue_constant : PortableHelipadLight_01_blue_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_constant : Land_PortableHelipadLight_01_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_green_off : PortableHelipadLight_01_green_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_green_constant : PortableHelipadLight_01_green_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_red_off : PortableHelipadLight_01_red_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_red_constant : PortableHelipadLight_01_red_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_white_off : PortableHelipadLight_01_white_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_white_constant : PortableHelipadLight_01_white_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_yellow_off : PortableHelipadLight_01_yellow_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PortableHelipadLight_01_yellow_constant : PortableHelipadLight_01_yellow_off {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PowerLine_01_pole_transformer_G_on : Land_PowerLine_01_pole_transformer_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class PowLines_Transformer_G_on : Land_PowLines_Transformer_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Pumpkin_01_part : Land_Pumpkin_01_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class RoadBarrier_small_off : RoadBarrier_small_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class RoadBarrier_small_v2_off : RoadBarrier_small_v2 {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class RoadCone_L_off : RoadCone_L_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class RoadCone_L_v2_off : RoadCone_L_v2 {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Skeet_Clay_white : Items_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_TrailerCistern_wreck_G_fuel : House_Small_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    SLX_XEH_DISABLED = 0;
};
class Land_Tank_rust_G_fuel : House_Small_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    SLX_XEH_DISABLED = 0;
};
class Wrecks_Globe_base : ThingX {};
class BagFence_couple : Land_BagFence_End_F {
    class AnimationSources {
        class helmet_x {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class helmet_y {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class helmet_z {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_x {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_y {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
        class weapon_z {
            source = "user";
            animPeriod = 0.5;
            initPhase = 0;
        };
    };
};
class Heli_Light_01_wreck : Wrecks_Globe_base {};
class Heli_Light_02_wreck : Heli_Light_01_wreck {};
class MBT_01_wreck : Heli_Light_02_wreck {
    class AnimationSources : AnimationSources {
        class hatchcommander {
            source = "user";
            animPeriod = 2;
            initPhase = 0;
        };
        class hatchdriver {
            source = "user";
            animPeriod = 1;
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
        class recoil_source {
            source = "user";
            animPeriod = 5;
            initPhase = 0;
        };
        class showcamonethull {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcamonetplates1 {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
        };
        class showcamonetplates2 {
            source = "user";
            animPeriod = 0.001;
            initPhase = 0;
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
