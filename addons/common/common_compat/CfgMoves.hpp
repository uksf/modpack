class CfgMovesBasic;
class CfgMovesMaleSdr : CfgMovesBasic {
    class States {
        class Crew;
        class RKSLA3_AW159_Pilot : Crew {
            interpolateTo[] = { "Unconscious", 0.02 }; // RKSLA3_AW159_Pilot_Dead does not exist
        };
    };
};

// ACRE radio gestures share RTMs with looped moves, so the engine already plays them looped.
class CfgGesturesMale {
    class States {
        class acre_sys_gestures_base;
        class acre_sys_gestures_helmet : acre_sys_gestures_base {
            looped = 1;
        };
        class acre_sys_gestures_vest : acre_sys_gestures_base {
            looped = 1;
        };
    };
};
