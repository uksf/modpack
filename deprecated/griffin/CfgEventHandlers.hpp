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

class Extended_Init_EventHandlers {
    class UKSF_Griffin {
        class ADDON {
            init = QUOTE(_this call FUNC(init));
        };
    };
};

class Extended_GetIn_EventHandlers {
    class UKSF_Griffin {
        class ADDON {
            getIn = QUOTE(_this call FUNC(getIn));
        };
    };
};

class Extended_GetOut_EventHandlers {
    class UKSF_Griffin {
        class ADDON {
            getOut = QUOTE(_this call FUNC(getOut));
        };
    };
};

class Extended_Killed_EventHandlers {
    class UKSF_Griffin {
        class ADDON {
            killed = QUOTE(_this call FUNC(getOut));
        };
    };
};
