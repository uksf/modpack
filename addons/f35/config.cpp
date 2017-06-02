#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {    
            "uksf_gear",         
            "USAF_F35A",
            "USAF_Missilebox",
            "DynaSound_DS_w_20mmgatling"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class cba_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgRscUI.hpp"
#include "CfgSounds.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
