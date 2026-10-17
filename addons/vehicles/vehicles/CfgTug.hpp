class Truck_F;
class rksla3_aircraft_tug_base : Truck_F {
    delete editorcategory;
    editorSubcategory = QEGVAR(common,support);
    LESH_AxisOffsetTower[] = { 0, -1.964, 0.32 };
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    // Hit sources must name the HitPoints class, not its selection.
    class AnimationSources {
        class HitLFWheel {
            hitpoint = "HitLFWheel";
        };
        class HitLBWheel : HitLFWheel {
            hitpoint = "HitLBWheel";
        };
        class HitRFWheel : HitLFWheel {
            hitpoint = "HitRFWheel";
        };
        class HitRBWheel : HitLFWheel {
            hitpoint = "HitRBWheel";
        };
    };
};
class rksla3_aircraft_tug_blufor : rksla3_aircraft_tug_base {
    faction = "CUP_B_GB";
};
class rksla3_aircraft_tug_opfor : rksla3_aircraft_tug_base {
    faction = "OPF_F";
};
class rksla3_aircraft_tug_guer : rksla3_aircraft_tug_base {
    faction = "IND_F";
};
class rksla3_aircraft_tug_civ : rksla3_aircraft_tug_base {
    faction = "CIV_F";
};
