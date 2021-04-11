class CfgVehicles {
#include "crates\CfgGolfs.hpp"
#include "crates\CfgRomeos.hpp"

    class GVAR(arsenal) : GVAR(rx) {
        displayName = "Arsenal Crate";
        editorSubcategory = QEGVAR(common,resupply);
        PREVIEW(arsenal);
        hiddenSelectionsTextures[] = { QPATHTOF(data\romeo\ra.paa) };
        containerIgnore = 1;
    };

    class UK3CB_BAF_MAN_HX60_Container_Green;
    class GVAR(container) : UK3CB_BAF_MAN_HX60_Container_Green {
        scope = 2;
        scopeCurator = 2;
        author = "UKSF";
        dlc = "";
        faction = "CUP_B_GB";
        displayName = "Resupply Container";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        PREVIEW(container);
    };

    class Items_base_F;
    class Land_CanisterFuel_F : Items_base_F {
        scope = 2;
        scopeCurator = 2;
        faction = "CUP_B_GB";
        displayName = "Jerry Can";
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = { 0, 1, 1 };
        ace_dragging_carryDirection = 0;
    };
    class Misc_thing;
    class Fuel_can : Misc_thing {
        editorPreview = QPATHTOEF(common,data\previews\Land_CanisterFuel_F.jpg);
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = { 0, 1, 1 };
        ace_dragging_carryDirection = 0;
        class ace_refuel {
            init = QUOTE(call ace_refuel_fnc_makeJerryCan);
        };
    };

    class ACE_RepairItem_Base;
    class ACE_Track : ACE_RepairItem_Base {
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
    };
    class ACE_Wheel : ACE_RepairItem_Base {
        editorCategory = "EdCat_Supplies";
        editorSubcategory = QEGVAR(common,resupply);
    };

#include "crates\CfgObsolete.hpp"
};
