class B_Radar_System_01_F;
class GVAR(Radar_System) : B_Radar_System_01_F {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "AN/MPQ-105 Radar";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class B_SAM_System_03_F;
class GVAR(SAM_System) : B_SAM_System_03_F {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "MIM-145 Defender";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class B_Ship_MRLS_01_F;
class GVAR(Ship_MRLS) : B_Ship_MRLS_01_F {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "Mk41 VLS";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_ZU23_AFU;
class GVAR(ZU23) : CUP_B_ZU23_AFU {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "ZU-23-2";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_L134A1_TriPod_BAF_WDL;
class GVAR(L134A1) : CUP_B_L134A1_TriPod_BAF_WDL {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "L134A1";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_M252_HIL;
class GVAR(M252) : CUP_B_M252_HIL {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "M252 Mortar";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_M119_HIL;
class GVAR(M119) : CUP_B_M119_HIL {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "M119 Howitzer";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class ace_dragon_staticAssembled;
class GVAR(Dragon) : ace_dragon_staticAssembled {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "M47 Dragon";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class B_G_HMG_02_F;
class GVAR(HMG_02) : B_G_HMG_02_F {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "50 cal HMG";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class CUP_B_RBS70_HIL;
class GVAR(RBS70) : CUP_B_RBS70_HIL {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "RBS 70";
    crew = QGVAR(Rifleman);
    typicalCargo[] = { QGVAR(Rifleman) };
    INVENTORY_EMPTY;
};

class O_HMG_01_A_F;
class GVAR(auto_hmg): O_HMG_01_A_F {
    scope = 2;
    scopeCurator = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "Auto HMG";
    crew = "O_UAV_AI";
};

class O_Radar_System_02_F;
// class SensorTemplateActiveRadar;
class GVAR(Mini_Radar_Dish) : O_Radar_System_02_F {
    scope = 2;
    scopeCurator = 2;
    model = "\A3\Props_F_Enoch\Military\Camps\SatelliteAntenna_01_F.p3d";
    editorPreview = "\A3\EditorPreviews_F_Enoch\Data\CfgVehicles\SatelliteAntenna_01_Black_F.jpg";
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "Mini Radar Dish";
    crew = "O_UAV_AI";
    class Components {
        class SensorsManagerComponent {
            class Components {
                class SensorTemplateActiveRadar;
                class MiniRadarSensorComponent: SensorTemplateActiveRadar{
                    componentType = "ActiveRadarSensorComponent";

                    class AirTarget
                    {
                        minRange = 0;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };

                    class GroundTarget
                    {
                        minRange = 0;
                        maxRange = 2000;
                        objectDistanceLimitCoef = 1;
                        viewDistanceLimitCoef = 1;
                    };

                    angleRangeHorizontal = 360;
                    angleRangeVertical = 90;
                    maxTrackableSpeed = 400;
                };
            };
        };
    };
    INVENTORY_EMPTY;
};
