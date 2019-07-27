class CfgVehicles {
    class O_G_Soldier_F;
    class GVAR(base) : O_G_Soldier_F {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_AUG";
        editorSubcategory = "EdSubcat_Personnel";
        displayName = "AUG Base";
        uniformClass = "U_OG_Guerilla1_1";
        weapons[] = {};
        respawnWeapons[] = {};
        magazines[] = {};
        respawnMagazines[] = {};
        items[] = {};
        respawnItems[] = {};
        linkedItems[] = {};
        respawnLinkedItems[] = {};
    };

#include "units\CfgInfantry.hpp"
#include "units\CfgCrew.hpp"
#include "vehicles\CfgAPC.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgKamaz.hpp"
#include "vehicles\CfgLR.hpp"
};
