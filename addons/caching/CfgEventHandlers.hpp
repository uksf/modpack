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
    class B_UAV_AI {
        class ADDON {
            init = QUOTE((group (_this select 0)) setVariable [ARR_3(QQGVAR(excluded),true,true)];);
        };
    };
    class O_UAV_AI {
        class ADDON {
            init = QUOTE((group (_this select 0)) setVariable [ARR_3(QQGVAR(excluded),true,true)];);
        };
    };
    class I_UAV_AI {
        class ADDON {
            init = QUOTE((group (_this select 0)) setVariable [ARR_3(QQGVAR(excluded),true,true)];);
        };
    };
};

class Extended_Killed_EventHandlers {
    class All {
        class ADDON {
            killed = QUOTE([ARR_2(QQGVAR(disableCache),_this)] call CBA_fnc_serverEvent;);
        };
    };
};
