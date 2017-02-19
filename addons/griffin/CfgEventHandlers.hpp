
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
    class UKSF_Griffin {
        class ADDON {
            init = QUOTE(if (player  isEqualTo  driver (_this select 0) || player  isEqualTo  gunner (_this select 0)) then {(_this select 0) call FUNC(getIn)};);
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
