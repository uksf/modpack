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

class Extended_Put_Eventhandlers {
    class CAManBase {
        class ADDON {
            put = QUOTE(_this call UK3CB_BAF_Weapons_Static_fnc_player_put_EH);
        };
    };
};

class Extended_Take_Eventhandlers {
    class CAManBase {
        class ADDON {
            take = QUOTE(_this call UK3CB_BAF_Weapons_Static_fnc_player_take_EH);
        };
    };
};
