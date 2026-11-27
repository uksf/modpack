class COMSPEC_ATAK_Apps {
    class Athena { hidden = 1; dock = 0; };
    class Resynch { hidden = 1; };
    class YearReview { hidden = 1; };
    class Discord { hidden = 1; };
    class Tenant { hidden = 1; };
    class Fiches { hidden = 1; };
    class Youtube { hidden = 1; };
    class Music { hidden = 1; };
    class Food { hidden = 1; };
    class Dating { hidden = 1; };
    class Aar { hidden = 1; dock = 0; };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMain { comspec_overwatch_connect = ""; };
    class RscDisplayAttributesMan { ADDON = QUOTE(_this call COMPILE_FILE(XEH_attributesLoad)); };
    class RscDisplayAttributesVehicle { ADDON = QUOTE(_this call COMPILE_FILE(XEH_attributesLoad)); };
    class RscDisplayAttributesVehicleEmpty { ADDON = QUOTE(_this call COMPILE_FILE(XEH_attributesLoad)); };
    class RscDisplayAttributesGroup { ADDON = QUOTE(_this call COMPILE_FILE(XEH_attributesLoad)); };
    class RscDisplayInterrupt { comspec_atak_native_athenacfg = ""; };
    class RscDisplayMPInterrupt { comspec_atak_native_athenacfg = ""; };
    class RscDisplayStart {
        comspec_atak_native_main = "";
        comspec_overwatch_main = "";
    };
    class RscDisplayLoadMission { comspec_atak_native_main = ""; };
    class RscDisplayLoading { comspec_atak_native_main = ""; };
};
