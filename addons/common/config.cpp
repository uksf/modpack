#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSFModuleRespawnPosition_F"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_3rdperson"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "Cfg3den.hpp"
#include "CfgAILevelPresets.hpp"
#include "CfgAISkill.hpp"
#include "CfgDifficultyPresets.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgImprecision.hpp"
#include "CfgMarkerColors.hpp"
#include "CfgMoves.hpp"
#include "CfgSurfaces.hpp"
#include "CfgWeapons.hpp"
#include "CfgVideoOptions.hpp"
#include "CfgVehicles.hpp"

enableDebugConsole[] = { WHITELIST_NOARRAY };
EnableTargetDebug = 1;
