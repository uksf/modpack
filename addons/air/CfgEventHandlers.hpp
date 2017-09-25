class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_InitPost_EventHandlers {
    class CAManBase {
        class ADDON {
            init = QUOTE((_this select 0) setVariable [ARR_3('UK3CB_voice_enabled',0,true)];);
        };
    };
    class CUP_CH47F_base {
        class ADDON {
            init = QUOTE((_this select 0) setVariable [ARR_3('ace_medical_medicClass',1,true)];);
        };
    };
    class UK3CB_BAF_Merlin_HC3_Base {
        class ADDON {
            init = QUOTE((_this select 0) setVariable [ARR_3('ace_medical_medicClass',1,true)];);
        };
    };
    class CUP_SA330_Base {
        class ADDON {
            init = QUOTE((_this select 0) setVariable [ARR_3('ace_medical_medicClass',1,true)];);
        };
    };
    class UK3CB_BAF_Wildcat_Base {
        class ADDON {
            init = QUOTE((_this select 0) setVariable [ARR_3('ace_medical_medicClass',1,true)];);
        };
    };
};
