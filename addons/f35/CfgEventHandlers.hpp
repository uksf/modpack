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
    class USAF_F35A {
        class ADDON {
            init = QUOTE(_this call FUNC(init));
        };
    };
};

class Extended_GetIn_EventHandlers {
    class USAF_F35A {
        class ADDON {
            getIn = QUOTE(_this call FUNC(getIn));
        };
    };
};

class Extended_GetOut_EventHandlers {
    class USAF_F35A {
        class ADDON {
            getOut = QUOTE(_this call FUNC(getOut));
        };
    };
};

class Extended_Killed_EventHandlers {
    class USAF_F35A {
        class ADDON {
            killed = QUOTE(_this call FUNC(getOut));
        };
    };
};

class Extended_FiredBIS_EventHandlers {
    class USAF_F35A {
        class ADDON {
            fired = QUOTE(_this call FUNC(fired));
        };
    };
};
