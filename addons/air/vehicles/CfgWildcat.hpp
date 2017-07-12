class CUP_AW159_Unarmed_Base: Helicopter_Base_H {
    maxspeed = 311;
    fuelCapacity = 40; // 1000
    attenuationEffectType = "SemiOpenHeliAttenuation";
    unitInfoType = "RscUnitInfoNoSpeed";
    unitInfoTypeLite = "RscUnitInfoNoSpeed";
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7", "UKSF_B_Pilot_7" };
    #include "MFDGeneral.hpp"
    class Turrets: Turrets {
        class MainTurret: MainTurret {
            class Components {
                class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                    defaultDisplay = "EmptyDisplay";
                    class Components {
                        class SensorsDisplay {
                            componentType = "SensorsDisplayComponent";
                            range[] = { 16000, 8000, 4000, 2000 };
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
                            range[] = { 16000, 8000, 4000, 2000 };
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
            soundAttenuationTurret = "SemiOpenHeliAttenuation";
        };
    };
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000, 8000, 4000, 2000 };
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
                    range[] = { 16000, 8000, 4000, 2000 };
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
                class DataLinkSensorComponent: SensorTemplateDataLink {};
            };
        };
    };
    class ACE_Actions: ACE_Actions {
        class ACE_MainActions: ACE_MainActions {
            position = "[0,0,1.5]";
        };
    };
};
class CUP_B_AW159_Unarmed_RN_Grey: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7", "UKSF_B_Pilot_7" };
};
class CUP_B_AW159_Unarmed_RN_Blackcat: CUP_AW159_Unarmed_Base {
    crew = "UKSF_B_Pilot_7";
    typicalCargo[] = { "UKSF_B_Pilot_7", "UKSF_B_Pilot_7" };
};
class CUP_AW159_Dynamic_Base: CUP_AW159_Unarmed_Base {};
class CUP_B_AW159_RN_Grey: CUP_AW159_Dynamic_Base {
    crew = "UKSF_B_Pilot_656";
    typicalCargo[] = { "UKSF_B_Pilot_656", "UKSF_B_Pilot_656" };
    #include "MFDCAS.hpp"
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            defaultDisplay = "EmptyDisplay";
            class Components {
                class SensorsDisplay {
                    componentType = "SensorsDisplayComponent";
                    range[] = { 16000, 8000, 4000, 2000 };
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
                    range[] = { 16000, 8000, 4000, 2000 };
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
                class DataLinkSensorComponent: SensorTemplateDataLink {};
            };
        };
    };
};

class CUP_B_AW159_Unarmed_GB: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Unarmed_BAF: CUP_B_AW159_Unarmed_GB {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_GB: CUP_AW159_Dynamic_Base {
    scope = 0;
    scopeCurator = 0;
}
class CUP_B_AW159_RN_Blackcat: CUP_AW159_Dynamic_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_GB: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_RN_Grey: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Hellfire_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_GB: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_RN_Grey: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_AW159_Cannon_RN_Blackcat: CUP_AW159_Unarmed_Base {
    scope = 0;
    scopeCurator = 0;
};

class CUP_B_Wildcat_Unarmed_RN_Grey: CUP_B_AW159_Unarmed_RN_Grey {
    scope = 0;
    scopeCurator = 0;
};
class CUP_B_Wildcat_Unarmed_RN_Blackcat: CUP_B_AW159_Unarmed_RN_Blackcat {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Unarmed_Green_AAF;
class CUP_B_Wildcat_Unarmed_Green_AAF: CUP_I_Wildcat_Unarmed_Green_AAF {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Hellfire_Armed_Green_AAF;
class CUP_B_Wildcat_Hellfire_Armed_Green_AAF: CUP_I_Wildcat_Hellfire_Armed_Green_AAF {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Cannon_Armed_Green_AAF;
class CUP_B_Wildcat_Cannon_Armed_Green_AAF: CUP_I_Wildcat_Cannon_Armed_Green_AAF {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Unarmed_Digital_AAF;
class CUP_B_Wildcat_Unarmed_Digital_AAF: CUP_I_Wildcat_Unarmed_Digital_AAF {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Hellfire_Armed_Digital_AAF;
class CUP_B_Wildcat_Hellfire_Armed_Digital_AAF: CUP_I_Wildcat_Hellfire_Armed_Digital_AAF {
    scope = 0;
    scopeCurator = 0;
};
class CUP_I_Wildcat_Cannon_Armed_Digital_AAF;
class CUP_B_Wildcat_Cannon_Armed_Digital_AAF: CUP_I_Wildcat_Cannon_Armed_Digital_AAF {
    scope = 0;
    scopeCurator = 0;
};
