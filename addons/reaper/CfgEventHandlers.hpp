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

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_Init_EventHandlers {
    class CUP_MQ9_Base {
        class ADDON {
            init = QUOTE(call FUNC(init));
        };
    };
    class UK3CB_BAF_MQ9_Reaper {
        class ADDON {
            init = QUOTE(call FUNC(init));
        };
    };
};

class Extended_Killed_EventHandlers {
    class CUP_MQ9_Base {
        class ADDON {
            killed = QUOTE(call FUNC(killed));
        };
    };
    class UK3CB_BAF_MQ9_Reaper {
        class ADDON {
            killed = QUOTE(call FUNC(killed));
        };
    };
};
