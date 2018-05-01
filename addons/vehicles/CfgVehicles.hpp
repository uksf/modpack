class CfgVehicles {
    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions;
        class Turrets;
        class HitPoints;
    };
    class Car_F: Car {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class Turrets: Turrets {
            class MainTurret;
        };
        class HitPoints: HitPoints {
            class HitBody;
            class HitEngine;
            class HitFuel;
        };
    };
    class UK3CB_BAF_Jackal_Base_D: Car_F {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
        fuelCapacity = 15; // Reduced from 100. Gives ~40km range. 230L tank
        hullDamageCauseExplosion = 0;
        maxSpeed = 129;
        peakTorque = 800;
        class Turrets: Turrets {
            class MainTurret;
        };
        class HitPoints: HitPoints {
            class HitBody: HitBody {
                armor = 1.5; // Default: 0.7
            };
            class HitEngine: HitEngine {
                armor = 4; // Default: 2
            };
            class HitFuel: HitFuel {
                armor = 2; // Default: 1
            };
        };
    };
    class UK3CB_BAF_LandRover_Base: Car_F {
        fuelCapacity = 10; // Reduced from 70. Gives ~30km range. 93L tank
        ace_refuel_fuelCapacity = 93;
        hullDamageCauseExplosion = 0;
        peakTorque = 1000;
        maxOmega = 550;
        class HitPoints: HitPoints {
            class HitBody: HitBody {
                armor = 1.5; // Default: 0.7
            };
            class HitEngine: HitEngine {
                armor = 4; // Default: 2
            };
            class HitFuel: HitFuel {
                armor = 2; // Default: 1
            };
        };
        class Turrets: Turrets {
            class MainTurret;
        };
        COVER_ACTIONS
    };
    class Wheeled_APC_F: Car_F {
        class NewTurret;
    };

    #include "vehicles\CfgBulldog.hpp"
    #include "vehicles\CfgCoyote.hpp"
    #include "vehicles\CfgJackal.hpp"
    #include "vehicles\CfgLandRover.hpp"
    #include "vehicles\CfgMastiff.hpp"
    #include "vehicles\CfgRidgeback.hpp"
    #include "vehicles\CfgWolfhound.hpp"
    #include "vehicles\CfgHemtt.hpp"
    #include "vehicles\CfgJackalCUP.hpp"
    #include "vehicles\CfgCoyoteCUP.hpp"
    #include "vehicles\CfgLandRoverCUP.hpp"

    class Items_base_F;
    class Land_CanisterFuel_F: Items_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Jerry Can";
        editorCategory = QEGVAR(common,UKSF);
        editorSubcategory = QEGVAR(common,support);
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0, 1, 1};
        ace_dragging_carryDirection = 0;
    };
    class CargoNet_01_base_F;
    class CargoNet_01_barrels_F: CargoNet_01_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Cargo Net (Fuel Barrels)";
        editorCategory = QEGVAR(common,UKSF);
        editorSubcategory = QEGVAR(common,support);
        editorPreview = QPATHTOEF(common,data\previews\CargoNet_01_barrels_F.jpg);
        ace_refuel_fuelCapacity = 800;
        ace_refuel_fuelCargo = 800;
        ace_refuel_flowRate = 2;
        ace_cargo_hasCargo = 0;
        ace_refuel_hooks[] = {{0.498,0.27,0.485}};
        armor = 50;
        fuelExplosionPower = 2;
        destrType = "DestructBuilding";
        explosionEffect = "FuelExplosion";
        class DestructionEffects {
            class Light1 {
                simulation = "light";
                type = "ObjectDestructionLightFuel";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0;
            };
            class Smoke1 {
                simulation = "particles";
                type = "FuelTruck_Explosion";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0.001;
            };
            class LightFlames1 {
                simulation = "particles";
                type = "FlameLightBC";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0.5;
                enabled = "distToWater";
            };
            class LightBig1 {
                simulation = "light";
                type = "ObjectDestructionLight";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 2;
                enabled = "distToWater";
            };
            class Sound {
                simulation = "sound";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 1;
                type = "Fire";
            };
            class FireBig1 {
                simulation = "particles";
                type = "ObjectDestructionFire1";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3;
            };
            class SmokeBig1 {
                simulation = "particles";
                type = "ObjectDestructionSmoke";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3.5;
            };
            class SparksBig1 {
                simulation = "particles";
                type = "ObjectDestructionSparks";
                position = "destructionEffect1";
                intensity = 1;
                interval = 1;
                lifeTime = 0;
            };
            class FireSparksBig1 {
                simulation = "particles";
                type = "FireSparks";
                position = "destructionEffect2";
                intensity = 1;
                interval = 1;
                lifeTime = 2.8;
            };
            class FireBig2 {
                simulation = "particles";
                type = "ObjectDestructionFire2";
                position = "destructionEffect2";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3;
            };
            class SmokeBig1_2 {
                simulation = "particles";
                type = "ObjectDestructionSmoke1_2";
                position = "destructionEffect2";
                intensity = 0.15;
                interval = 1;
                lifeTime = 3.5;
            };
            class SmokeBig2 {
                simulation = "particles";
                type = "ObjectDestructionSmoke2";
                position = "destructionEffect2";
                intensity = 1;
                interval = 1;
                lifeTime = 3.2;
            };
        };
    };

    class Tank_F;
    class CUP_2S6_Base: Tank_F {
        radarType = 2;
    };
    class CUP_ZSU23_Base: Tank_F {
        radarType = 2;
    };

    class Boat_F;
    class Rubber_duck_base_F: Boat_F {
        class VehicleTransport {
            class Cargo {
                parachuteClass = "B_Parachute_02_F";
                parachuteHeightLimit = 40;
                canBeTransported = 1;
                dimensions[] = {"bbox_1_1_pos", "bbox_2_2_pos"};
            };
        };
    };
};
