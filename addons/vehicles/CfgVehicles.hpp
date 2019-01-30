class CfgVehicles {
    class LandVehicle;
    class Car : LandVehicle {
        class ACE_Actions;
        class Turrets;
        class HitPoints;
    };
    class Car_F : Car {
        class ACE_Actions : ACE_Actions {
            class ACE_MainActions;
        };
        class Turrets : Turrets {
            class MainTurret;
        };
        class HitPoints : HitPoints {
            class HitBody;
            class HitEngine;
            class HitFuel;
        };
    };
    class UK3CB_BAF_Jackal_Base_D : Car_F {
        faction = "CUP_B_GB";
        crew = "CUP_B_BAF_Soldier_MTP";
        typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
        fuelCapacity = 15;  // Reduced from 100. Gives ~40km range. 230L tank
        hullDamageCauseExplosion = 0;
        maxSpeed = 129;
        peakTorque = 800;
        class Turrets : Turrets {
            class MainTurret;
        };
        class HitPoints : HitPoints {
            class HitBody : HitBody {
                armor = 1.5;  // Default: 0.7
                passThrough = 0;
            };
            class HitEngine : HitEngine {
                armor = 4;  // Default: 2
                passThrough = 0;
            };
            class HitFuel : HitFuel {
                armor = 2;  // Default: 1
            };
        };
    };
    class UK3CB_BAF_LandRover_Base : Car_F {
        fuelCapacity = 10;  // Reduced from 70. Gives ~30km range. 93L tank
        ace_refuel_fuelCapacity = 93;
        hullDamageCauseExplosion = 0;
        peakTorque = 1000;
        maxOmega = 450;
        brakeDistance = 30;  // 50
        class HitPoints : HitPoints {
            class HitBody : HitBody {
                armor = 1.5;  // Default: 0.7
                passThrough = 0;
            };
            class HitEngine : HitEngine {
                armor = 4;  // Default: 2
                passThrough = 0;
            };
            class HitFuel : HitFuel {
                armor = 2;  // Default: 1
            };
        };
        class Turrets : Turrets {
            class MainTurret;
        };
        class Reflectors {
            class Left {
                ambient[] = { 5, 5, 6 };
                color[] = { 130, 130, 140 };
                intensity = 10;
                size = 1;
                position = "lights_front_left";
                direction = "lights_front_left_dir";
                hitpoint = "lights_front_left";
                selection = "lights_front_left";
                innerAngle = 80;
                outerAngle = 160;
                useFlare = 1;
                flareSize = 1;
                coneFadeCoef = 10;
                daylight = 0;
                class Attenuation {
                    start = 1;
                    constant = 0;
                    linear = 0;
                    quadratic = 0.01;
                    hardLimitStart = 50;
                    hardLimitEnd = 80;
                };
            };
            class Right : Left {
                position = "lights_front_right";
                direction = "lights_front_right_dir";
                hitpoint = "lights_front_right";
                selection = "lights_front_right";
            };
        };
        COVER_ACTIONS
    };
    class Wheeled_APC_F : Car_F {
        class NewTurret;
        class HitPoints : HitPoints {
            class HitLFWheel;
            class HitLF2Wheel;
            class HitRFWheel;
            class HitRF2Wheel;
        };
    };

#include "vehicles\CfgBulldog.hpp"
#include "vehicles\CfgCoyote.hpp"
#include "vehicles\CfgCoyoteCUP.hpp"
#include "vehicles\CfgJackal.hpp"
#include "vehicles\CfgJackalCUP.hpp"
#include "vehicles\CfgLandRover.hpp"
#include "vehicles\CfgLandRoverCUP.hpp"
#include "vehicles\CfgMan.hpp"
#include "vehicles\CfgMastiff.hpp"
#include "vehicles\CfgPanther.hpp"
#include "vehicles\CfgRidgeback.hpp"
#include "vehicles\CfgWolfhound.hpp"

    class Tank_F;
    class CUP_2S6_Base : Tank_F {
        radarType = 2;
    };
    class CUP_ZSU23_Base : Tank_F {
        radarType = 2;
    };

    class Boat_F;
    class Rubber_duck_base_F : Boat_F {
        class VehicleTransport {
            class Cargo {
                parachuteClass = "B_Parachute_02_F";
                parachuteHeightLimit = 40;
                canBeTransported = 1;
                dimensions[] = { "bbox_1_1_pos", "bbox_2_2_pos" };
            };
        };
    };
};
