class Helmatic : Boat_Armed_01_base_F {
    maximumLoad = 2000;
    class TransportMagazines {};
    class TransportItems {
        delete _xx_FirstAidKit;
        MACRO_ADDITEM(UK3CB_BAF_H_CrewHelmet_B,7);
    };
    class TransportWeapons {};
    class TransportBackpacks {};
    armor = 200;
    class HitPoints {
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
    class RenderTargets {
        class commander_display {
            renderTarget = "rendertarget0";
            class CameraView1 {
                pointPosition = "pip0_pos";
                pointDirection = "pip0_dir";
                renderVisionMode = 0;
                renderQuality = 2;
                fov = 0.5;
                turret[] = { 0 };
            };
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
    class Turrets {
        class CommanderTurret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "Laserdesignator_vehicle" };
            stabilizedInAxes = 4;
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class TopTurret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "HMG_M2_Mounted" };
            stabilizedInAxes = 4;
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class codriverturret : NewTurret {
            weapons[] = { "CUP_weapon_mastersafe", "RHICC_M240_Turret" };
            stabilizedInAxes = 4;
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class Helmatic_Standing : NewTurret {
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
        class Helmatic_Standing2 : NewTurret {
            class HitPoints {
                delete HitTurret;
                delete HitGun;
            };
        };
    };
};

class BAE_FIC : Helmatic {
    class VehicleTransport {
        class Carrier {
            cargoAlignment[] = { "center", "front" };
        };
    };
};
class GVAR(fic) : BAE_FIC {
    scope = 2;
    scopeCurator = 2;
    displayName = "FIC";
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class BAE_FIC_Stealth : Helmatic {};
class GVAR(fic_stealth) : BAE_FIC_Stealth {
    scope = 2;
    scopeCurator = 2;
    displayName = "FIC (Stealth)";
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
