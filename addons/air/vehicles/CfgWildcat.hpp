class CUP_AW159_Unarmed_Base: Helicopter_Base_H {
    scope = 1;
    scopeCurator = 0;
    maxspeed = 311;
    fuelCapacity = 40; //1000
    landingSoundInt0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int1", 0.25, 1, 50 };
    landingSoundInt1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int2", 0.25, 1, 50 };
    landingSoundInt[] = { "landingSoundInt0", 0.5, "landingSoundInt1", 0.5 };
    landingSoundOut0[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1", 0.4, 1, 50 };
    landingSoundOut1[] = { "A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2", 0.4, 1, 50 };
    landingSoundOut[] = { "landingSoundOut0", 0.5, "landingSoundOut1", 0.5 };
    attenuationEffectType = "SemiOpenHeliAttenuation";
    unitInfoType = "Rsc_UKSF_Air_Limited";
    unitInfoTypeLite = "Rsc_UKSF_Air_Limited";
    #include "MFDGeneral.hpp"
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            class Components {
                class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                    defaultDisplay = "EmptyDisplay";
                    class Components {
                        class SensorsDisplay {
                            componentType = "SensorsDisplayComponent";
                            range[] = { 16000,8000,4000,2000 };
                            resource = "RscCustomInfoSensors";
                        };
                        class CrewDisplay {
                            componentType = "CrewDisplayComponent";
                            resource = "RscCustomInfoCrew";
                        };
                        class MinimapDisplay {
                            componentType = "MinimapDisplayComponent";
                            resource = "RscCustomInfoMiniMap";
                        };
                        class EmptyDisplay {
                            componentType = "EmptyDisplayComponent";
                        };
                    };
                };
                class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                    defaultDisplay = "SensorsDisplay";
                    class Components {
                        class SensorsDisplay {
                            componentType = "SensorsDisplayComponent";
                            range[] = { 16000,8000,4000,2000 };
                            resource = "RscCustomInfoSensors";
                        };
                        class CrewDisplay {
                            componentType = "CrewDisplayComponent";
                            resource = "RscCustomInfoCrew";
                        };
                        class MinimapDisplay {
                            componentType = "MinimapDisplayComponent";
                            resource = "RscCustomInfoMiniMap";
                        };
                        class EmptyDisplay {
                            componentType = "EmptyDisplayComponent";
                        };
                    };
                };
            };
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
            };
        };
    };
    class ACE_Actions: ACE_Actions {
        class ACE_MainActions: ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
};
class CUP_B_AW159_Unarmed_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_RN_Grey: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
};
class CUP_B_Wildcat_Unarmed_RN_Grey: CUP_B_AW159_Unarmed_RN_Grey {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_BAF: CUP_B_AW159_Unarmed_GB {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_RN_Blackcat: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
};
class CUP_B_Wildcat_Unarmed_RN_Blackcat: CUP_B_AW159_Unarmed_RN_Blackcat {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_RN_Grey: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
    #include "MFDCAS.hpp"
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
            weapons[] = { "CUP_weapon_mastersafe", "CUP_Laserdesignator_mounted", "CUP_Vmlauncher_AGM114K_veh", "CUP_Vmlauncher_AGM114N_veh" };
            magazines[] = { "Laserbatteries", "CUP_2Rnd_AGM_Rack_M", "CUP_4Rnd_AGM114K_Hellfire_II_M", "CUP_4Rnd_AGM114N_Hellfire_II_M" };
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
                class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
            };
        };
    };
};
class CUP_B_AW159_Hellfire_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_GB: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_RN_Grey: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656" };
    #include "MFDCAS.hpp"
    weapons[] = { "CUP_weapon_mastersafe", "CUP_Vacannon_M621_AW159_veh", "CUP_Vmlauncher_CRV7_HEISAP_veh", "CMFlareLauncher" };
    magazines[] = { "CUP_1Rnd_CRV7_Pod_12_M", "CUP_1Rnd_M621_Pod_Heli_M", "CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M", "CUP_12Rnd_CRV7_HEISAP_M", "120Rnd_CMFlare_Chaff_Magazine" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
                class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
            };
        };
    };
};
class CUP_B_AW159_Cannon_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 1;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Hellfire_Armed_Green_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
            weapons[] = { "CUP_weapon_mastersafe", "CUP_Laserdesignator_mounted", "CUP_Vmlauncher_AGM114K_veh", "CUP_Vmlauncher_AGM114N_veh" };
            magazines[] = { "Laserbatteries", "CUP_2Rnd_AGM_Rack_M", "CUP_4Rnd_AGM114K_Hellfire_II_M", "CUP_4Rnd_AGM114N_Hellfire_II_M" };
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
                class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
            };
        };
    };
};
class CUP_I_Wildcat_Cannon_Armed_Green_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
    weapons[] = { "CUP_weapon_mastersafe", "CUP_Vacannon_M621_AW159_veh", "CUP_Vmlauncher_CRV7_HEISAP_veh", "CMFlareLauncher" };
    magazines[] = { "CUP_1Rnd_CRV7_Pod_12_M", "CUP_1Rnd_M621_Pod_Heli_M", "CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M", "CUP_12Rnd_CRV7_HEISAP_M", "120Rnd_CMFlare_Chaff_Magazine" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
                class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
            };
        };
    };
};
class CUP_I_Wildcat_Cannon_Armed_Digital_AAF: CUP_AW159_Unarmed_Base {
    #include "MFDCAS.hpp"
    weapons[] = { "CUP_weapon_mastersafe", "CUP_Vacannon_M621_AW159_veh", "CUP_Vmlauncher_CRV7_HEISAP_veh", "CMFlareLauncher" };
    magazines[] = { "CUP_1Rnd_CRV7_Pod_12_M", "CUP_1Rnd_M621_Pod_Heli_M", "CUP_1200Rnd_TE1_Red_Tracer_M621_20mm_HE_M", "CUP_12Rnd_CRV7_HEISAP_M", "120Rnd_CMFlare_Chaff_Magazine" };
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            defaultDisplay = "SensorsDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000,8000,4000,2000 };
                    resource = "RscCustomInfoSensors";
                };
                class CrewDisplay {
                    componentType = "CrewDisplayComponent";
                    resource = "RscCustomInfoCrew";
                };
                class MinimapDisplay {
                    componentType = "MinimapDisplayComponent";
                    resource = "RscCustomInfoMiniMap";
                };
                class EmptyDisplay {
                    componentType = "EmptyDisplayComponent";
                };
            };
        };
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
                class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
                    class AirTarget {
                        minRange = 5000;
                        maxRange = 5000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    class GroundTarget {
                        minRange = 4000;
                        maxRange = 4000;
                        objectDistanceLimitCoef = -1;
                        viewDistanceLimitCoef = -1;
                    };
                    maxTrackableSpeed = 125;
                    angleRangeVertical = 90;
                    groundNoiseDistanceCoef = -1;
                    maxGroundNoiseDistance = -1;
                    minSpeedThreshold = 0;
                    maxSpeedThreshold = 0;
                    aimDown = 30;
                };
                class PassiveSensorComponent: SensorTemplatePassiveRadar {};
                class LaserSensorComponent: SensorTemplateLaser {};
                class NVSensorComponent: SensorTemplateNV {};
            };
        };
    };
};
