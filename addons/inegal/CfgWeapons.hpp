class CfgWeapons {
    class U_BasicBody;
    class UniformItem;
    class Inegal_U_Base: U_BasicBody {
        author = "UKSF";
        scope = 1;
        displayName = "$STR_A3_Underwear1";
        picture = "\A3\characters_f\data\ui\icon_U_BasicBody_ca.paa";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "Inegal_Soldier_Underwear";
            containerClass = "Supply0";
            mass = 5;
        };
    };
};