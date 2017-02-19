class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_FiredBIS_EventHandlers {
    class CUP_BAF_Jackal2_BASE_D {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
    class CUP_LR_Base {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
    class CUP_Mastiff_Base {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
    class CUP_Ridgback_Base {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
    class CUP_Wolfhound_Base {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
};
