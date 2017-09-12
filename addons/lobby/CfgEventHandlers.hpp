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

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMultiplayerSetup {
        cba_ui = QUOTE(_this call (uiNamespace getVariable QQFUNC(initDisplayMultiplayerLobby)));
    };
};
