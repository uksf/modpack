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
};
