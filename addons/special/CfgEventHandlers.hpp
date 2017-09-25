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

class Extended_InitPost_EventHandlers {
    class UKSF_O_TK_INS_Suicide_Driver {
        class GVAR(random) {
            init = QUOTE([(_this select 0)] call FUNC(init));
        };
    };
    class UKSF_O_TK_INS_Suicide {
        class ADDON {
            init = QUOTE([(_this select 0)] call FUNC(suicide));
        };
    };
    class UKSF_O_TK_INS_Suicide_Deadman {
        class ADDON {
            init = QUOTE([ARR_2((_this select 0),true)] call FUNC(suicide));
        };
    };
    class UKSF_O_Skoda_Base {
        class GVAR(random) {
            init = QUOTE([(_this select 0)] call FUNC(init));
        };
    };
    class UKSF_O_Skoda_CarBomb {
        class ADDON {
            init = QUOTE([ARR_3((_this select 0),false,true)] call FUNC(suicide));
        };
    };
    class UKSF_O_Skoda_CarBomb_Deadman {
        class ADDON {
            init = QUOTE([ARR_3((_this select 0),true,true)] call FUNC(suicide));
        };
    };
    class UKSF_O_Skoda_CarBomb_Empty {
        class ADDON {
            init = QUOTE([(_this select 0)] call FUNC(carBomb));
        };
    };
};
