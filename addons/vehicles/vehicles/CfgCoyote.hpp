class UK3CB_BAF_Coyote_L111A1_Base : UK3CB_BAF_Jackal_Base {
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
};
class UK3CB_BAF_Coyote_L134A1_Base : UK3CB_BAF_Jackal_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
};
class UK3CB_BAF_Coyote_Passenger_L111A1_D : UK3CB_BAF_Coyote_L111A1_Base {
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L134A1_D : UK3CB_BAF_Coyote_L134A1_Base {
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L134A1_D2 : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    displayname = "Coyote P GMG Desert (CR)";
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L111A1_D2 : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    displayname = "Coyote P HMG Desert (CR)";
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L134A1_G : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    displayname = "Coyote P GMG Woodland (CR)";
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L111A1_G : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    displayname = "Coyote P HMG Woodland (CR)";
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L134A1_W : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Passenger_L111A1_W : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_D : UK3CB_BAF_Coyote_Passenger_L111A1_D {
    transportAmmo = 0;
    transportFuel = 0;
    transportRepair = 0;
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_D : UK3CB_BAF_Coyote_Passenger_L134A1_D {
    transportAmmo = 0;
    transportFuel = 0;
    transportRepair = 0;
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_D2 : UK3CB_BAF_Coyote_Logistics_L134A1_D {
    displayname = "Coyote L GMG Desert (CR)";
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_D2 : UK3CB_BAF_Coyote_Logistics_L111A1_D {
    displayname = "Coyote L HMG Desert (CR)";
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_G : UK3CB_BAF_Coyote_Logistics_L134A1_D {
    displayname = "Coyote L GMG Woodland (CR)";
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_G : UK3CB_BAF_Coyote_Logistics_L111A1_D {
    displayname = "Coyote L HMG Woodland (CR)";
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L134A1_W : UK3CB_BAF_Coyote_Logistics_L134A1_D {
    JACKAL_INVENTORY_GMG
    COVER_ACTIONS
};
class UK3CB_BAF_Coyote_Logistics_L111A1_W : UK3CB_BAF_Coyote_Logistics_L111A1_D {
    JACKAL_INVENTORY_HMG
    COVER_ACTIONS
};
