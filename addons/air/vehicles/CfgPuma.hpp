class rksla3_pumahc_base: Helicopter_Base_H {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    vehicleClass = "Air";
    unitInfoType = "RscUnitInfoNoSpeed";
    liftForceCoef = 0.9;
    bodyFrictionCoef = 1.1;
    cyclicAsideForceCoef = 0.9;
    cyclicForwardForceCoef = 0.9;
    backRotorForceCoef = 0.9;
    startDuration = 40;
    class Components: Components {
        class SensorsManagerComponent {
            class Components {
                class IRSensorComponent: SensorTemplateIR {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "mainGun";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class VisualSensorComponent: SensorTemplateVisual {
                    class AirTarget {
                        minRange = 500;
                        maxRange = 3000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = 1;
                    };
                    class GroundTarget {
                        minRange = 500;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };
                    maxTrackableSpeed = 70;
                    animDirection = "mainGun";
                    angleRangeHorizontal = 26;
                    angleRangeVertical = 26;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
                class DataLinkSensorComponent: SensorTemplateDataLink {};
            };
        };
    };
    class Turrets: Turrets {
        class MainTurret;
    };
    class pilotCamera {
        class OpticsIn {
            class Wide {
                opticsDisplayName = "W";
                initAngleX = 0;
                minAngleX = 0;
                maxAngleX = 0;
                initAngleY = 0;
                minAngleY = 0;
                maxAngleY = 0;
                initFov = 0.5;
                minFov = 0.5;
                maxFov = 0.5;
                directionStabilized = 1;
                visionMode[] = {"Normal", "NVG"};
                thermalMode[] = {0, 1};
                gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
            };
            showMiniMapInOptics = 0;
            showUAVViewpInOptics = 0;
            showSlingLoadManagerInOptics = 1;
        };
        minTurn = 0;
        maxTurn = 0;
        initTurn = 0;
        minElev = 80;
        maxElev = 80;
        initElev = 80;
        maxXRotSpeed = 0.5;
        maxYRotSpeed = 0.5;
        pilotOpticsShowCursor = 1;
        controllable = 0;
    };
    memoryPointDriverOptics = "slingLoad_cam_pos";
    weapons[] = {"UK3CB_BAF_CMFlareLauncher", "UK3CB_BAF_IRJammer"};
    magazines[] = {"120Rnd_CMFlare_Chaff_Magazine", "UK3CB_BAF_IRJammer_Magazine"};
    INVENTORY_EMPTY;
    #include "MFDMerlin.hpp"
};
class rksla3_puma_hc1_troop: rksla3_pumahc_base {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    vehicleClass = "Air";
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,40);
        MACRO_ADDITEM(ACE_morphine,30);
        MACRO_ADDITEM(ACE_bloodIV,20);
        MACRO_ADDITEM(ACE_bloodIV_500,20);
        MACRO_ADDITEM(ACE_bloodIV_250,20);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
};
class rksla3_puma_hc1_1gpmg: rksla3_pumahc_base {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    vehicleClass = "Air";
    class Turrets: Turrets {
        class RH_Turret: MainTurret {
            weapons[] = {"UK3CB_BAF_Safe", "rksla3_pumahc1_mounted_GPMG_R"};
        };
    };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,40);
        MACRO_ADDITEM(ACE_morphine,30);
        MACRO_ADDITEM(ACE_bloodIV,20);
        MACRO_ADDITEM(ACE_bloodIV_500,20);
        MACRO_ADDITEM(ACE_bloodIV_250,20);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
};
class rksla3_puma_hc1_2gpmg: rksla3_pumahc_base {
    faction = "CUP_B_GB";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    vehicleClass = "Air";
    class Turrets: Turrets {
        class RH_Turret: MainTurret {
            weapons[] = {"UK3CB_BAF_Safe", "rksla3_pumahc1_mounted_GPMG_R"};
        };
        class LH_Turret: RH_Turret {
            weapons[] = {"UK3CB_BAF_Safe", "rksla3_pumahc1_mounted_GPMG_L"};
        };
    };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_M14,2);
        MACRO_ADDMAGAZINE(ACE_HandFlare_Red,2);
        MACRO_ADDMAGAZINE(UK3CB_BAF_SmokeShellRed,2);
        MACRO_ADDMAGAZINE(B_IR_Grenade,2);
    };
    class TransportItems {
        MACRO_ADDITEM(Toolkit,1);
        MACRO_ADDITEM(ACE_elasticBandage,40);
        MACRO_ADDITEM(ACE_morphine,30);
        MACRO_ADDITEM(ACE_bloodIV,20);
        MACRO_ADDITEM(ACE_bloodIV_500,20);
        MACRO_ADDITEM(ACE_bloodIV_250,20);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
};

class CUP_SA330_Base: Helicopter_Base_H {};
class CUP_B_SA330_Puma_HC1_BAF: CUP_SA330_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_SA330_Puma_HC2_BAF: CUP_B_SA330_Puma_HC1_BAF {
    scope = 0;
    scopeCurator = 0;
};
