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
        // init, not clientInit: the registration block runs server-side on a
        // dedicated server, and clientInit never fires there.
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};
