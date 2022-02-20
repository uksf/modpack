class CfgWeapons {
    class CBA_MiscItem_ItemInfo;
    class CBA_MiscItem;
    class GVAR(airSupply) : CBA_MiscItem {
        model = "\ade_core\data\models\SingleBottle";
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\ui\iconSingleCylinder.paa);
        displayName = "HALO/HAHO Air Supply";
        descriptionShort = "Air supply for conducting HALO/HAHO jumps.";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 10;
        };
    };
};

