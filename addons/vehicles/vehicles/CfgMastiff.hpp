class CUP_Mastiff_Base : Wheeled_APC_F {
    class Turrets {
        class MainTurret : NewTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    fuelCapacity = 25;    // 45
    ace_cargo_space = 8;  // 4
    ace_repair_spareWheels = 4;
    class complexGearbox {
        GearboxRatios[] = { "R1", -10.094, "N", 0, "D1", 5.562, "D2", 3.456, "D3", 2.623, "D4", 1.678, "D5", 1.078, "D6", 1 };
        TransmissionRatios[] = { "High", 5.0 };
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
    };
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions : ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
};
class CUP_B_Mastiff_HMG_GB_D : CUP_Mastiff_Base {
    RIDGEBACK_INVENTORY_HMG
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Mastiff_HMG_GB_W : CUP_Mastiff_Base {
    RIDGEBACK_INVENTORY_HMG
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Mastiff_GMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    RIDGEBACK_INVENTORY_GMG
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Mastiff_GMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    RIDGEBACK_INVENTORY_GMG
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Mastiff_LMG_GB_D : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            magazines[] = { "UK3CB_BAF_762_100Rnd_T" };
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    RIDGEBACK_INVENTORY_GPMG
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Mastiff_LMG_GB_W : CUP_Mastiff_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            magazines[] = { "UK3CB_BAF_762_100Rnd_T" };
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    RIDGEBACK_INVENTORY_GPMG
    COVER_ACTIONS
    REARM_ACTIONS
};
