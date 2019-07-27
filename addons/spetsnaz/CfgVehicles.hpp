class CfgVehicles {
    class CUP_O_RUS_Soldier_TL;
    class GVAR(base) : CUP_O_RUS_Soldier_TL {
        author = "UKSF";
        scope = 0;
        faction = "UKSF_Spetsnaz";
        editorSubcategory = "EdSubcat_Personnel";
        displayName = "Spetsnaz Base";
        uniformClass = "CUP_U_B_CZ_DST_Kneepads_Sleeve";
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
#include "units\CfgCiv.hpp"
#include "vehicles\CfgHeli.hpp"
#include "vehicles\CfgJet.hpp"
#include "vehicles\CfgLMV.hpp"
#include "vehicles\CfgStatic.hpp"
};
