
class Extended_Init_EventHandlers {
    class UKSF_Clan_ATC {
        class ADDON {
            init = QUOTE(_this call EFUNC(atc,equipATC));
        };
    };
    class UKSF_LandRover_MG {
        class ADDON {
            init = QUOTE(_this call EFUNC(common,initNets));
        };
    };
    class UKSF_LandRover_GL {
        class ADDON {
            init = QUOTE(_this call EFUNC(common,initNets));
        };
    };
    class UKSF_LandRover_Medical {
        class ADDON {
            init = QUOTE(_this call EFUNC(common,initNets));
        };
    };    
};