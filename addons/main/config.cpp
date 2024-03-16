#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_loadOrder"
        };
        author = QUOTE(UKSF);
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgMods {
    class Mod_Base;
    class PREFIX: Mod_Base {
        dir = "@uksf";
        name = "UKSF Mods";
        author = "UKSF";
        picture = QPATHTO_R(data\uksf_logo_ca);
        logo = QPATHTO_R(data\uksf_logo_ca);
        logoOver = QPATHTO_R(data\uksf_logo_ca);
        logoSmall = QPATHTO_R(data\uksf_logo_ca);
        hideName = 0;
        hidePicture = 0;
        actionName = "Website";
        action = "http://uk-sf.com/";
        description = "Issue Tracker: https://github.com/uksf/modpack/issues";
        tooltip = "UKSF Mods";
        tooltipOwned = "UKSF Mods - Owned";
        overview = "Collection of custom mods and patches tailor made for use with UKSF";
    };
    class UK3CB_BAF_Weapons: Mod_Base {
        picture = QPATHTO_R(data\uksf_logo_ca);
        logo = QPATHTO_R(data\uksf_logo_ca);
        logoOver = QPATHTO_R(data\uksf_logo_ca);
        logoSmall = QPATHTO_R(data\uksf_logo_ca);
    };
    class UK3CB_BAF_Equipment: Mod_Base {
        picture = QPATHTO_R(data\uksf_logo_ca);
        logo = QPATHTO_R(data\uksf_logo_ca);
        logoOver = QPATHTO_R(data\uksf_logo_ca);
        logoSmall = QPATHTO_R(data\uksf_logo_ca);
    };
};

#include "CfgIntercept.hpp"
#include "CfgSettings.hpp"
delete enableDebugConsole;
