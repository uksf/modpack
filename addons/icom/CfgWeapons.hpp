class CfgWeapons {
    class CBA_MiscItem_ItemInfo;
    class CBA_MiscItem;
    class GVAR(icomScanner) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\ui\gear_item_radio_ca.paa);
        displayName = "ICOM Scanner";
        descriptionShort = "Scans open / unsecure comms. Used for COIN Ops.";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };
};
