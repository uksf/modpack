#include "script_component.hpp"

class CfgPatches {
    class PROP {
        name = COMPONENT_NAME;
        units[] = {
            // Units
            "PROR_R",
			"PROR_MG",
			"PROR_AR",
			"PROR_AT_L",
			"PROR_Officer",
			"PROR_FOO",
			"PROR_JTAC",
			"PROR_Marksman",
			"PROR_Medic",
			"PROR_SL",
			"PROR_AT_H",

            // Vehicles
            "PROR_MRAP_Unarmed",
			"PROR_MRAP_HMG",
			"PROR_MRAP_GMG",
			"PROR_Polaris_HMG",
			"PROR_Striker_GMG",
			"PROR_Striker_HMG",
			"PROR_LAV",
			"PROR_M60",
			"PROR_AA_Radar",
			"PROR_AA_Ozelot",
			"PROR_TRM_Covered",
			"PROR_TRM_Open",
			"PROR_TRM_Ammo",
			"PROR_TRM_Repair",
			"PROR_TRM_Fuel",
			
			// Air
			"PROR_Jet_Harrier",
			"PROR_Heli_Huey",
			"PROR_Heli_Chinook",
			
			// Statics
			"PROR_Static_M119",
			"PROR_Static_HMG_High",
			"PROR_Static_HMG_Low",
			"PROR_Static_GMG_Low",
			"PROR_Static_GMG_High",
			"PROR_Static_AA"
			
			
        };
        weapons[] = {
            "arifle_CTAR_blk_F_Eotech"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
//#include "CfgAmmo.hpp"
//#include "CfgEventHandlers.hpp"
#include "CfgGroups.hpp"
//#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
