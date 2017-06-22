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

class Extended_InitPost_Eventhandlers {
    class Helicopter {
        class ADDON {
            init = QUOTE(_this call FUNC(correctPilotPylon));
        };
    };
};
