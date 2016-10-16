#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_main", "JPEX_FrameWork", "JSRSAPEX_Explosions"};
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG_COMMON;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgImprecision.hpp"
#include "CfgVehicles.hpp"

class CfgSounds {
	class GVAR(suicide) {
		name = QGVAR(suicide);
		sound[] = { QPATHTOF(data\sounds\suicide), 10, 1, 50 };
		titles[] = {};
	};
    class GVAR(alarm) {
		name = QGVAR(alarm);
		sound[] = { QPATHTOF(data\sounds\alarm), 20, 1, 200 };
		titles[] = {};
	};
};