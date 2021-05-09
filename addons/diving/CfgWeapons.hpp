class CfgWeapons {
    class Vest_Camo_Base;
    class V_RebreatherB : Vest_Camo_Base {
        class ItemInfo;
    };
    class GVAR(rebreather) : V_RebreatherB {
        author = "UKSF";
        displayName = "Rebreather (Adv)";
        descriptionShort = "Milspec rebreather for various gases.";
        hiddenSelectionsTextures[] = { "\A3\characters_f\common\data\diver_equip_nato_co.paa", "\A3\characters_f\common\data\diver_equip_nato_co.paa", "\A3\characters_f\data\visors_ca.paa" };
        hiddenUnderwaterSelections[] = {"hide"};
        hiddenUnderwaterSelectionsTextures[] = { "\A3\characters_f\data\visors_ca.paa" };
        class ItemInfo : ItemInfo {
            containerClass = "Supply100";
            armor = 1;
            passThrough = 0.8;
            hiddenSelectionsTextures[] = { "\A3\characters_f\common\data\diver_equip_nato_co.paa", "\A3\characters_f\common\data\diver_equip_nato_co.paa", "\A3\characters_f\data\visors_ca.paa" };
            hiddenUnderwaterSelectionsTextures[] = { "\A3\characters_f\data\visors_ca.paa" };
        };
    };
    DEPRECATE_CLASS(ade_item_rebreather,GVAR(rebreather));

    class InventoryItem_Base_F;
    class ItemGPS;
    class GVAR(diveComputer) : ItemGPS {
        author = "UKSF";
        scopeArsenal = 2;
        scopeCurator = 2;
        picture = QPATHTOF(data\ui\iconDiveComputer.paa);
        displayName = "Dive computer";
        descriptionShort = "Wrist mounted, battery powered dive computer. Shows important data to the diver.";
        class ItemInfo : InventoryItem_Base_F {
            mass = 1;
        };
    };
    DEPRECATE_CLASS(ade_item_DiveComputer,GVAR(diveComputer));

    class CBA_MiscItem_ItemInfo;
    class CBA_MiscItem;
    class GVAR(cylinderBase) : CBA_MiscItem {
        author = "UKSF";
    };
    class GVAR(cylinderSingleBase) : GVAR(cylinderBase) {
        model = "\ade_core\data\models\SingleBottle";
        picture = QPATHTOF(data\ui\iconSingleCylinder.paa);
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 10;
        };
    };
    class GVAR(cylinderDoubleBase) : GVAR(cylinderBase) {
        model = "\ade_core\data\models\DoubleBottle";
        picture = QPATHTOF(data\ui\iconDoubleCylinder.paa);
        class ItemInfo : CBA_MiscItem_ItemInfo {
            mass = 20;
        };
    };

    CYLINDERS(Empty,Empty,nothing,0,0,0);
    CYLINDERS(CompressedAir,Compressed air,compressed and filtered air,0.21,0.78,0.01);
    CYLINDERS(Ean28,EAN28,Nitrox 28,0.28,0.72,0);
    CYLINDERS(Ean32,EAN32,Nitrox 32,0.32,0.68,0);
    CYLINDERS(Ean36,EAN36,Nitrox 36,0.36,0.64,0);
    CYLINDERS(Ean40,EAN40,Nitrox 40,0.40,0.60,0);
    CYLINDERS(Heliox85,Heliox 8.5,Heliox 8.5,0.085,0,0.915);
    CYLINDERS(Heliox12,Heliox 12,Heliox 12,0.12,0,0.88);
    CYLINDERS(Heliox21,Heliox 21,Heliox 21,0.21,0,0.79);
    CYLINDERS(Tx2135,Tx21/35,Tx21/35,0.21,0.44,0.35);
    CYLINDERS(Tx1845,Tx18/45,Tx18/45,0.18,0.37,0.45);
    CYLINDERS(Tx1555,Tx15/55,Tx15/55,0.15,0.30,0.55);
    CYLINDERS(Tx1265,Tx12/65,Tx12/65,0.12,0.23,0.65);
    CYLINDERS(Tx1070,Tx10/70,Tx10/70,0.1,0.2,0.7);
};
