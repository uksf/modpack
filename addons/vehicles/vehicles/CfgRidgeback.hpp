class CUP_Ridgback_Base : Wheeled_APC_F {
    armor = 250;
    armorStructural = 25;
    hullDamageCauseExplosion = 0;
    class Turrets {
        class MainTurret : NewTurret {
            magazines[] = {"UK3CB_BAF_127_100Rnd"};
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    fuelCapacity = 25;    // 45
    ace_cargo_space = 6;  // 4
    class complexGearbox {
        GearboxRatios[] = {"R1", -10.094, "N",  0,     "D1", 5.562, "D2", 3.456,
                           "D3", 2.623,   "D4", 1.678, "D5", 1.078, "D6", 1};
        TransmissionRatios[] = {"High", 5.0};
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
    };
    class HitPoints : HitPoints {
        class HitLFWheel : HitLFWheel {
            explosionShielding = 4;  // 0.5, panther 4
        };
        class HitLF2Wheel : HitLF2Wheel {
            explosionShielding = 4;  // 0.5, panther 4
        };
        class HitRFWheel : HitRFWheel {
            explosionShielding = 4;  // 0.5, panther 4
        };
        class HitRF2Wheel : HitRF2Wheel {
            explosionShielding = 4;  // 0.5, panther 4
        };
        class HitBody {
            armor = 8;               // 1, panther 6
            passThrough = 0;         // 0, panther 1
            minimalHit = 0.01;       // 0.1, panther 0.01
            explosionShielding = 1;  // 0.0001, panther 1.5
        };
        class HitEngine {
            armor = 2;                 // 0.55, panther 0.5
            passThrough = 0;           // 0, panther 0.3
            minimalHit = 0.2;          // 0.1, panther 0.2
            explosionShielding = 0.2;  // 0.01, panther 0.2
        };
        class HitFuel {
            armor = 2;                 // 1, panther 0.5
            passThrough = 0.5;         // 0, panther 0.5
            minimalHit = 0.2;          // 0.1, panther 0.2
            explosionShielding = 0.2;  // 0.01, panther 0.2
        };
    };
    class ACE_Actions : ACE_Actions {
        class ACE_MainActions : ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
};
class CUP_B_Ridgback_HMG_GB_D : CUP_Ridgback_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Ridgback_HMG_GB_W : CUP_Ridgback_Base {
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Ridgback_GMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            magazines[] = {"UK3CB_BAF_32Rnd_40mm_G_Box"};
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Ridgback_GMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class MainTurret : MainTurret {
            magazines[] = {"UK3CB_BAF_32Rnd_40mm_G_Box"};
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Ridgback_LMG_GB_D : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            magazines[] = {"UK3CB_BAF_762_100Rnd_T"};
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_762_100Rnd_T {
            magazine = "UK3CB_BAF_762_100Rnd_T";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
class CUP_B_Ridgback_LMG_GB_W : CUP_Ridgback_Base {
    class Turrets : Turrets {
        class Mainturret : NewTurret {
            magazines[] = {"UK3CB_BAF_762_100Rnd_T"};
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_762_100Rnd_T {
            magazine = "UK3CB_BAF_762_100Rnd_T";
            count = 5;
        };
    };
    COVER_ACTIONS
    REARM_ACTIONS
};
