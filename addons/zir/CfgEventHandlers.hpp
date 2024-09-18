class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};


class Extended_InitPost_EventHandlers {
    class GVAR(hilux_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_6(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    class GVAR(praga_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_12(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa),QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    class GVAR(praga_covered_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_12(QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa),QQGVAR(Militia_akn),QQGVAR(Militia_gp25),QQGVAR(Militia_MG),QQGVAR(Militia_LAT),QQGVAR(Militia_sks),QQGVAR(Militia_aa))])] call EFUNC(common,populate));
        };
    };
    // dont allow fleeing on puritan guard

    // add surrender check on unit killed
    class GVAR(Soldier_Base) {
        class ADDON {
            init = QUOTE((_this select 0) call FUNC(surrenderCheck));
        };
    };
};
