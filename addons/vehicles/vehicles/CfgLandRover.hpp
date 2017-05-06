class CUP_LR_Base: Car_F {
    hullDamageCauseExplosion = 0; //Default: 1
    armor = 80; //Default: 50
    armorWheels = 0.35; //Default: 0.2
    class HitPoints: HitPoints {
        class HitBody {
            armor = 1.25; //Default: 1
        };
        class HitEngine {
            armor = 3; //Default: 2
        };
        class HitFuel {
            armor = 1.5; //Default: 1
        };
    };
    turnCoef = 3.5;
    enginePower = 150;
    peakTorque = 425;
    class complexGearbox {
        GearboxRatios[] = { "R1", -4, "N", 0, "D1", 4.5, "D2", 2.61, "D3", 1.51, "D4", 0.87, "D5", 0.51, "D6", 0.35 };
        TransmissionRatios[] = { "High", 7 };
        gearBoxMode = "auto";
        moveOffGear = 1;
        driveString = "D";
        neutralString = "N";
        reverseString = "R";
        gearUpMaxCoef = 0.95;
        gearDownMaxCoef = 0.85;
        gearUpMinCoef = 0.65;
        gearDownMinCoef = 0.55;
        transmissionDelay = 2;
    };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            class ViewOptics;
        };
    };
    FUEL_CAPACITY_LR
};
class CUP_LR_MG_Base: CUP_LR_Base {    
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
            class ViewOptics: ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_LR_Special_Base: CUP_LR_Base {
    class Turrets: Turrets {
        class PK_Turret;
    };
};
class CUP_B_LR_MG_GB_W: CUP_LR_MG_Base {
    NET_ACTIONS
};
class CUP_B_LR_Special_M2_GB_W: CUP_LR_Special_Base {
    NET_ACTIONS
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_127_100Rnd" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
        class PK_Turret: PK_Turret {
            magazines[] = { "UK3CB_BAF_762_200Rnd_T", "SmokeLauncherMag", "SmokeLauncherMag" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };            
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_127_100Rnd {
            magazine = "UK3CB_BAF_127_100Rnd";
            count = 5;
        };
        class _xx_UK3CB_BAF_762_200Rnd_T {
            magazine = "UK3CB_BAF_762_200Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_B_LR_Special_GMG_GB_W: CUP_LR_Special_Base {
    NET_ACTIONS
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            magazines[] = { "UK3CB_BAF_32Rnd_40mm_G_Box" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
        class PK_Turret: PK_Turret {
            magazines[] = { "UK3CB_BAF_762_200Rnd_T", "SmokeLauncherMag", "SmokeLauncherMag" };
            class ViewOptics {
                visionMode[] = { "Normal", "NVG" };
            };
        };
    };
    class TransportMagazines {
        class _xx_UK3CB_BAF_32Rnd_40mm_G_Box {
            magazine = "UK3CB_BAF_32Rnd_40mm_G_Box";
            count = 5;
        };
        class _xx_UK3CB_BAF_762_200Rnd_T {
            magazine = "UK3CB_BAF_762_200Rnd_T";
            count = 5;
        };
    };
    REARM_ACTIONS
};
class CUP_LR_Ambulance_Base: CUP_LR_Base {};
class CUP_B_LR_Ambulance_GB_W: CUP_LR_Ambulance_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_LR_Ambulance_GB_D: CUP_LR_Ambulance_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_LR_Transport_Base: CUP_LR_Base {};
class CUP_B_LR_Transport_GB_W: CUP_LR_Transport_Base {
    displayname = "Land Rover (Woodland)";
};
class CUP_B_LR_Transport_GB_D: CUP_LR_Transport_Base {
    displayname = "Land Rover (Desert)";
};
class UKSF_B_LR_Ambulance_W: CUP_B_LR_Transport_GB_W {
    displayname = "Land Rover (Ambulance, Woodland)";
    attendant = 1;
    crew = "CUP_B_BAF_Medic_WDL";
    typicalCargo[] = { "CUP_B_BAF_Medic_WDL" };
    hiddenselectionstextures[] = { QPATHTOF(data\gb_w_lr_base_med_co.paa), QPATHTOF(data\gb_w_lr_special_med_co.paa) };
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
class UKSF_B_LR_Ambulance_D: CUP_B_LR_Transport_GB_D {
    displayname = "Land Rover (Ambulance, Desert)";
    attendant = 1;
    crew = "CUP_B_BAF_Medic_DDPM";
    typicalCargo[] = { "CUP_B_BAF_Medic_DDPM" };
    hiddenselectionstextures[] = { QPATHTOF(data\gb_d_lr_base_med_co.paa), QPATHTOF(data\gb_d_lr_special_med_co.paa) };
    class TransportItems {
        class _xx_ACE_EarPlugs {
            name = "ACE_EarPlugs";
            count = 10;
        };
        class _xx_ACE_packingBandage {
            name = "ACE_packingBandage";
            count = 50;
        };
        class _xx_ACE_elasticBandage {
            name = "ACE_elasticBandage";
            count = 50;
        };
        class _xx_ACE_morphine {
            name = "ACE_morphine";
            count = 30;
        };
        class _xx_ACE_epinephrine {
            name = "ACE_epinephrine";
            count = 30;
        };
        class _xx_ACE_bloodIVItem {
            name = "ACE_bloodIVItem";
            count = 20;
        };
        class _xx_ACE_personalAidKit {
            name = "ACE_personalAidKit";
            count = 10;
        };
    };
    NET_MEDICAL_ACTIONS
};
