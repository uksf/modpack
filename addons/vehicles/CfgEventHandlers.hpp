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

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};

class Extended_FiredBIS_EventHandlers {
    class CUP_Mastiff_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
    class CUP_Ridgback_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
    class CUP_Wolfhound_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
};
