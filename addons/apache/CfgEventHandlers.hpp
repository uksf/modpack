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
    class UKSF_Apache_base {
        class ADDON {
            init = QUOTE(call FUNC(init));
        };
    };
};

class Extended_GetIn_EventHandlers {
    class UKSF_Apache_base {
        class ADDON {
            getIn = QUOTE(call FUNC(getIn));
        };
    };
};

class Extended_GetOut_EventHandlers {
    class UKSF_Apache_base {
        class ADDON {
            getOut = QUOTE(call FUNC(getOut));
        };
    };
};

class Extended_Killed_EventHandlers {
    class UKSF_Apache_base {
        class ADDON {
            killed = QUOTE(call FUNC(getOut));
        };
    };
};

class Extended_IncomingMissile_EventHandlers {
    class UKSF_Apache_base {
        class ADDON {
            incomingMissile = QUOTE(call FUNC(incomingMissile));
        };
    };
};
