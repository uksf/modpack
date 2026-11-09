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
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};

class Extended_InitPost_EventHandlers {
    class Car {
        class GVAR(markingLaser) {
            init = QUOTE(call FUNC(initMarkingLaser));
        };
    };
    class Tank {
        class GVAR(markingLaser) {
            init = QUOTE(call FUNC(initMarkingLaser));
        };
    };
    class Ship {
        class GVAR(markingLaser) {
            init = QUOTE(call FUNC(initMarkingLaser));
        };
    };
};

class Extended_GetIn_EventHandlers {
    class LandVehicle {
        class GVAR(emptyDynamicSimulation) {
            getIn = QUOTE([ARR_2(QQGVAR(setEmptyDynamicSimulation),[_this select 0])] call CBA_fnc_serverEvent);
        };
    };
};

class Extended_GetOut_EventHandlers {
    class LandVehicle {
        class GVAR(emptyDynamicSimulation) {
            getOut = QUOTE([ARR_2(QQGVAR(setEmptyDynamicSimulation),[_this select 0])] call CBA_fnc_serverEvent);
        };
    };
};

class Extended_FiredBIS_EventHandlers {
    class CUP_Mastiff_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
    class CUP_Ridgback_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
    class CUP_Wolfhound_Base {
        class ADDON {
            firedBIS = QUOTE(call UK3CB_BAF_Vehicles_Coyote_Jackal_fnc_fired_EH);
        };
    };
};
