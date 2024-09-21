class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class GVAR(U_Base) : U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo : UniformItem {
            uniformModel = "-";
            uniformClass = QGVAR(Soldier_Underwear);
            containerClass = "Supply0";
            mass = 5;
        };
    };
    class CUP_srifle_LeeEnfield_rail;
    class GVAR(enfield_burris) : CUP_srifle_LeeEnfield_rail {
        displayName = "Enfield (Burris)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_DMS_weathered_F";
            };
        };
    };
    class CUP_srifle_CZ750;
    class GVAR(cz750_mr10) : CUP_srifle_CZ750 {
        displayName = "CZ 750 (MR-10)";
        scope = 1;
        class LinkedItems {
            class LinkedItemsOptic {
                slot = "CowsSlot";
                item = "optic_AMS";
            };
        };
    };
    class CBA_MiscItem_ItemInfo;
    class CBA_MiscItem;
    class GVAR(fakePassport) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\FakePassport.paa);
        displayName = "Fake Passport (ME)";
        descriptionShort = "Fake Zardashan passport for use in middle eastern countries";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };
    class GVAR(iedPartWire) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\DetWire.paa);
        displayName = "Detonator Wire";
        descriptionShort = "Wire component used in IEDs";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };
    class GVAR(iedPartPressurePlate) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\PressurePlate.paa);
        displayName = "Pressure Plate";
        descriptionShort = "Pressure plate component used in IEDs";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };
    class GVAR(iedPartHMEContainer) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\HMEContainer.paa);
        displayName = "HME Container";
        descriptionShort = "HME container used in IEDs";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 20;
        };
    };
    class GVAR(iedPartBatteryPack) : CBA_MiscItem {
        author = "UKSF";
        scope = 2;
        scopeArsenal = 2;
        picture = QPATHTOF(data\BatteryPack.paa);
        displayName = "Battery Pack";
        descriptionShort = "Power source used in IEDs";
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };

};
