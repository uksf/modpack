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
    class ACE_Module;
    class GVAR(module): ACE_Module {
        class EventHandlers {
            init = QUOTE(_this call FUNC(moduleInit));
        };
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

    #include "CfgUniforms.hpp"
};
