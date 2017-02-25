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

class Extended_Init_EventHandlers {
    class CUP_MQ9_Base {
        class ADDON {
            init = QUOTE(_this call FUNC(init));
        };
    };
};

class Extended_Killed_EventHandlers {
    class CUP_MQ9_Base {
        class ADDON {
            killed = QUOTE(_this call FUNC(killed));
        };
    };
};
