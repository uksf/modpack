#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
			"UKSF_Chinook_M134",
			"UKSF_Chinook_M134M240",

			"UKSF_Merlin",
			"UKSF_Merlin_Armed",

			"UK3CB_BAF_Wildcat_AH1_CAS_8A",
			"UK3CB_BAF_Wildcat_AH1_HEL_8A",
			"UK3CB_BAF_Wildcat_AH1_TRN_8A"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main", 
            "uksf_common",
			"chinookpack",
			"UK3CB_BAF_Vehicles_Weapons",
			"UK3CB_BAF_Vehicles_Merlin",
			"UK3CB_BAF_Vehicles_Wildcat",
			"JSRSAPEX_CH67_Huron",
			"JSRSAPEX_CH49_Mohawk",
			"JSRSAPEX_WY55_Hellcat"
        };
        author = QUOTE(UKSF);
        authors[] = {"Beswick.T"};
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class RscInGameUI {
	class RscUnitInfo;
	class Rsc_UKSF_Air_Limited : RscUnitInfo {
		controls[] = {
			"WeaponInfoControlsGroupRight",
			"CA_TextFlaresMode",
			"CA_TextFlares",
			"CA_VehicleToggles",
			"CA_Radar"
		};
	};
};

#include "CfgVehicles.hpp"
