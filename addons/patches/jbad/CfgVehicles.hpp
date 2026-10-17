class House_F;
class Land_Jbad_PowLines_Conc2L;
class PowerLines_Small_base_F;
class All {
    class AnimationSources;
};
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
class Truck_F : Car_F {};
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
class Jbad_CraneCon : Tank_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Jbad_Lamps_base_powerline : PowerLines_Small_base_F {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Jbad_Pole_1 : Jbad_Lamps_base_powerline {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Jbad_Pole_Speaker : Land_Jbad_PowLines_Conc2L {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Jbad_Pole_withlight : Land_Jbad_PowLines_Conc2L {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Jbad_PowLineB : Jbad_Lamps_base_powerline {
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
};
class Land_Jbad_Ind_Garage01 : House_F {
    class AnimationSources {
        class hitzone_1_source {
            source = "Hit";
            hitpoint = "HitZone_1_hitpoint";
            raw = 1;
        };
    };
};
class Jbad_cat_dumper : Truck_F {
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
        class hitglass6 {
            source = "Hit";
            hitpoint = "HitGlass6";
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
class Jbad_forklift : Truck_F {
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
        class hitglass6 {
            source = "Hit";
            hitpoint = "HitGlass6";
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
