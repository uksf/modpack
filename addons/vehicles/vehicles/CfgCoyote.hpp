class UK3CB_BAF_Coyote_L111A1_Base_D : UK3CB_BAF_Jackal_Base_D {
    class Turrets : Turrets {
        class L111A1_MainTurret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
                initFov = 0.0623;
                minFov = 0.0623;
                maxFov = 0.0623;
            };
        };
    };
    class TransportMagazines : TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_100Rnd,9);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,5);
    };
};
class UK3CB_BAF_Coyote_Passenger_L111A1_D : UK3CB_BAF_Coyote_L111A1_Base_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_L134A1_Base_D : UK3CB_BAF_Jackal_Base_D {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines : TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_32Rnd_40mm_G_Box,9);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,5);
    };
};
class UK3CB_BAF_Coyote_Passenger_L134A1_D : UK3CB_BAF_Coyote_L134A1_Base_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L111A1_W : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L134A1_W : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_D : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_W : UK3CB_BAF_Coyote_Logistics_L111A1_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_D : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_W : UK3CB_BAF_Coyote_Logistics_L134A1_D {
    COVER_ACTIONS
};
