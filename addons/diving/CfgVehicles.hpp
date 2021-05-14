class CfgVehicles {
    class B_Carryall_khk;
    class GVAR(bag) : B_Carryall_khk {
        author = "UKSF";
        scope = 2;
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Tortila";
        displayName = "Diving Bag (Adv)";
        descriptionShort = "Black backpack for transporting the divers equipment.";
        picture = "\A3\weapons_f\ammoboxes\bags\data\ui\icon_B_C_Tortila_blk.paa";
        hiddenSelectionsTextures[] = { "\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_blk_co.paa" };
        maximumLoad = 500;
        mass = 75;
    };
    DEPRECATE_CLASS(ade_item_bag,GVAR(bag));
};
