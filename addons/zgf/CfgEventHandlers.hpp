class Extended_InitPost_EventHandlers {
    class GVAR(tigr_transport_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_8(QQGVAR(soldier_akn),QQGVAR(soldier_enfield),QQGVAR(soldier_gp25),QQGVAR(soldier_MG),QQGVAR(soldier_LAT),QQGVAR(soldier_LAT),QQGVAR(soldier_sks),QQGVAR(soldier_aa))])] call EFUNC(common,populate));
        };
    };
    class GVAR(tigr_command) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_4(QQGVAR(soldier_enfield),QQGVAR(soldier_gp25),QQGVAR(soldier_MG),QQGVAR(officer))])] call EFUNC(common,populate));
        };
    };
    class GVAR(tatra_transport_full) {
        class ADDON {
            init = QUOTE([ARR_2(_this select 0,[ARR_12(QQGVAR(soldier_akn),QQGVAR(soldier_gp25),QQGVAR(soldier_MG),QQGVAR(soldier_LAT),QQGVAR(soldier_sks),QQGVAR(soldier_aa),QQGVAR(soldier_akn),QQGVAR(soldier_gp25),QQGVAR(soldier_MG),QQGVAR(soldier_LAT),QQGVAR(soldier_sks),QQGVAR(soldier_aa))])] call EFUNC(common,populate));
        };
    };
};
