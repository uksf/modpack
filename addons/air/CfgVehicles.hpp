class DefaultVehicleSystemsDisplayManagerRight;
class DefaultVehicleSystemsDisplayManagerLeft;
class SensorTemplateActiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class SensorTemplateDataLink;
class CfgVehicles {
    class AllVehicles;
    class Air: AllVehicles {
        receiveRemoteTargets = 1;
        reportRemoteTargets = 1;
        reportOwnPosition = 1;
    };
    class Helicopter: Air {
        explosionShielding = 0.7;
        epeImpulseDamageCoef = 5;
        crewCrashProtection = 1;
    };
    class Helicopter_Base_F: Helicopter {
        class ACE_Actions;
        class Turrets;
    };
    class Helicopter_Base_H: Helicopter_Base_F {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class ViewOptics;
        class ViewPilot;
        class Turrets: Turrets {
            class MainTurret;
            class CopilotTurret;
        };
        class Components;
    };
    class Heli_Light_01_base_F: Helicopter_Base_H {
        epeImpulseDamageCoef = 5;
    };
    class Plane: Air {
        explosionShielding = 0.6;
        epeImpulseDamageCoef = 5;
        crewCrashProtection = 1;
    };
    class Plane_Base_F: Plane {
        class Turrets {
            delete MainTurret;
        };
    };
    class Plane_CAS_01_base_F: Plane_Base_F {
        epeImpulseDamageCoef = 5;
    };
    class Plane_CAS_02_base_F: Plane_Base_F {
        epeImpulseDamageCoef = 5;
    };
    class Plane_Fighter_01_Base_F: Plane_Base_F {
        epeImpulseDamageCoef = 5;
    };
    class Plane_Fighter_02_Base_F: Plane_Base_F {
        epeImpulseDamageCoef = 5;
    };
    class Plane_Fighter_03_base_F: Plane_Base_F {
        epeImpulseDamageCoef = 5;
    };

    #include "vehicles\CfgBuzzard.hpp"
    #include "vehicles\CfgC130.hpp"
    #include "vehicles\CfgChinook.hpp"
    #include "vehicles\CfgDauphin.hpp"
    #include "vehicles\CfgF35.hpp"
    #include "vehicles\CfgGR9.hpp"
    #include "vehicles\CfgPuma.hpp"
    #include "vehicles\CfgMerlin.hpp"
    #include "vehicles\CfgWildcat.hpp"
    #include "vehicles\CfgMerlinCUP.hpp"
    #include "vehicles\CfgWildcatCUP.hpp"
};
