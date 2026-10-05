class Boat_Armed_01_base_F : Boat_F {
    class NewTurret;
    class Turrets;
};
class RHICC_MAIN : Boat_Armed_01_base_F {
    maximumLoad = 2000; // 500
    // RHICC declares a non-inheriting EventHandlers (fired only), which drops CBA XEH.
    class EventHandlers {
        class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {};
    };
    class TransportMagazines {};
    class TransportItems {
        delete _xx_FirstAidKit;
        MACRO_ADDITEM(UK3CB_BAF_H_CrewHelmet_B,7);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
    armor = 200; // 100
    class HitPoints {
        class HitBody {
            armor = 0.3;
            material = 50;
            name = "karoserie";
            visual = "zbytek";
            passThrough = 1;
            explosionShielding = 2;
        };
        class HitFuel {
            armor = 1.632;
            material = -1;
            armorComponent = "hit_fuel";
            name = "Fuel_hitpoint";
            visual = "-";
            passThrough = 0.2;
            minimalHit = 0.1;
            explosionShielding = 1.5;
            radius = 0.16;
        };
        class HitEngine {
            armor = 1.632;
            material = -1;
            armorComponent = "hit_engine";
            name = "Engine_hitpoint";
            visual = "-";
            passThrough = 0.2;
            minimalHit = 0.2;
            explosionShielding = 0.5;
            radius = 0.28;
        };
    };
    // The speedboat's gunner screens look through PIP3 points that RHICC's model does not have.
    class RenderTargets {
        class driver_display_1 {
            renderTarget = "rendertarget0";
            class CameraView1 {
                pointPosition = "PIP0_pos";
                pointDirection = "PIP0_dir";
                renderVisionMode = 1;
                renderQuality = 0;
                fov = 0.4;
            };
            BBoxes[] = { "PIP_0_TL", "PIP_0_TR", "PIP_0_BL", "PIP_0_BR" };
        };
    };
    class VehicleTransport {
        class Carrier {
            cargoAlignment[] = { "center", "front" };
        };
    };
    class AcreIntercoms {
        class Intercom_1 {
            displayName = "Crew intercom";
            shortName = "Crew";
            allowedPositions[] = { "crew", { "cargo", "all" } };
            disabledPositions[] = {};
            limitedPositions[] = {};
            masterPositions[] = { "commander" };
            numLimitedPositions = 0;
            connectedByDefault = 1;
        };
    };
    class AcreRacks {
        class Rack_1 {
            displayName = "R1";
            shortName = "R1";
            componentName = "ACRE_VRC103";
            allowedPositions[] = { "crew", "external" };
            disabledPositions[] = {};
            defaultComponents[] = {};
            mountedRadio = "ACRE_PRC117F";
            isRadioRemovable = 0;
            intercom[] = {};
        };
        class Rack_2 : Rack_1 {
            displayName = "R2";
            shortName = "R2";
        };
    };
    // RHICC's model has no turret hitpoint selections, so the turrets' HitTurret and HitGun do nothing except
    // log duplicate names.
    class Turrets {
        class CommanderTurret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "Laserdesignator_vehicle", "RHICC_SmokeLauncher" };
            class ViewOptics {
                initAngleX = 0;
                minAngleX = -30;
                maxAngleX = 30;
                initAngleY = 0;
                minAngleY = -100;
                maxAngleY = 100;
                initFov = 0.155;
                minFov = 0.034;
                maxFov = 0.155;
                visionMode[] = { "Normal", "NVG", "Ti" };
                thermalMode[] = { 2, 3 };
                directionStabilized = 1;
            };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class TopTurret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "HMG_M2_Mounted" };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class CodRiverTurret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "RHICC_M240_Turret" };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class CodRiver1Turret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "RHICC_M240_Turret_2nd" };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class MinigunLeft : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "vtx_wpn_m134" };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class MinigunRight : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "vtx_wpn_m134_2nd" };
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
    };
};

class RHICC_GREEN : RHICC_MAIN {};
class GVAR(rhicc_green) : RHICC_GREEN {
    scope = 2;
    scopeCurator = 2;
    displayName = "RHICC (Green)";
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class RHICC_GREY : RHICC_MAIN {};
class GVAR(rhicc_grey) : RHICC_GREY {
    scope = 2;
    scopeCurator = 2;
    displayName = "RHICC (Grey)";
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
