class CfgVehicles {
    class Module_F;
    class GVAR(moduleBase): Module_F {
        author = QUOTE(UKSF);
        category = GVAR(zeus_uksf);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        scope = 1;
        scopeCurator = 2;
    };

    class NonStrategic;
    class HouseBase: NonStrategic {
        class DestructionEffects;
    };
    class House: HouseBase {
        class DestructionEffects: DestructionEffects {
            class Smoke1 {
                qualityLevel = 2;
                simulation = "particles";
                type = "HouseDestructionSmoke1";
                position = "destructionEffect1";
                intensity = 0.15;
                interval = 1;
                lifeTime = 0.05;
            };
        };
    };

    class Man;
    class CAManBase: Man {
        class TurretBase {
            minElev = -4;
            maxElev = 20;
            minTurn = -360;
            maxTurn = 360;
        };
        mingunturn = -90;
        maxgunturn = 90;
        turning = 1;
        mingunturnai = -90;
        maxgunturnai = 90;
    };

    #include "CfgUniforms.hpp"
};
