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

class Extended_Init_Eventhandlers {
    class CAManBase {
        //init = QUOTE((_this select 0) addMPEventHandler [QQUOTE(MPHit), {_this call FUNC(artillerySupport);}]);
        init = QUOTE((_this select 0) addMPEventHandler [QQUOTE(MPHit), {_this call FUNC(rf_aliveCheck);}]);
    };
};


/*class Extended_FiredNear_EventHandlers {
    class CAManBase {
        init = QUOTE(_this call FUNC(mortarSupportFiredNear));
    };
};*/
