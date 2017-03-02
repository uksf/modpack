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

class Extended_FiredBIS_EventHandlers {
    class UKSF_O_Rifleman {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(fired));
        };
    };
    class UKSF_O_HMMWV_M2_VR_Rubber {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(fired));
        };
    };
    class UKSF_O_M1A2_TUSK_MG_VR_Rubber {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(fired));
        };
    };
    class UKSF_O_M6LineBacker_VR_Rubber {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(fired));
        };
    };
};

class Extended_Killed_EventHandlers {
    class UKSF_O_Rifleman {
        class ADDON {
            killed = QUOTE(_this call FUNC(killed));
        };
    };
    class UKSF_O_HMMWV_M2_VR_Rubber {
        class ADDON {
            killed = QUOTE(_this call FUNC(killed));
        };
    };
    class UKSF_O_M1A2_TUSK_MG_VR_Rubber {
        class ADDON {
            killed = QUOTE(_this call FUNC(killed));
        };
    };
    class UKSF_O_M6LineBacker_VR_Rubber {
        class ADDON {
            killed = QUOTE(_this call FUNC(killed));
        };
    };
};
