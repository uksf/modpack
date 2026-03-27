class CfgWeapons {
    class CBA_MiscItem_ItemInfo;
    class CBA_MiscItem;
    class GVAR(ecmBattery) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        displayName = "ECM Battery";
        descriptionShort = "Battery used to power backpack ECM systems.";
        picture = "\A3\Weapons_F\Ammoboxes\Bags\Data\UI\icon_B_C_Kitbag_tan_ca.paa";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 6;
        };
    };
};
