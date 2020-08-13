#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "ModuleMine_FlareTripMine_F",
            QGVAR(moduleAddAllObjects),
            QGVAR(moduleDelete),
            QGVAR(moduleExplosionLarge),
            QGVAR(moduleExplosionSmall),
            QGVAR(moduleToggleCaching),
            QGVAR(moduleToggleCleanup),
            QGVAR(moduleToggleFps),
            QGVAR(moduleToggleHasRadio),
            QGVAR(moduleToggleZeusVisibility),
            QGVAR(moduleParadrop),
            QGVAR(moduleMakeSuicideBomber),
            QGVAR(moduleMakeSuicideBomberDeadman),
            QGVAR(moduleMakeCarBomber),
            QGVAR(moduleMakeCarBomberDeadman),
            QGVAR(moduleMakeCarBomb)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_curator",
            "uksf_caching",
            "uksf_cleanup",
            "uksf_mission",
            "uksf_special",
            "zen_modules",
            "zen_context_menu",
            "zen_custom_modules",
            "zen_dialog"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;
#include "Cfg3den.hpp"
#include "CfgContext.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
#include "RscDisplayCurator.hpp"
