
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

class Extended_Init_EventHandlers {
	class UKSF_ATC_Station {
	    class ADDON {
	        init = QUOTE(_this call FUNC(init));
	    };
	};
    class Air {
	    class ADDON {
	        init = QUOTE(_this call FUNC(initAir));
	    };
	};
};