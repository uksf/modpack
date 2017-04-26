class CfgFunctions {
    class A3_Bootcamp {
        class Inventory {
            class arsenal { file = QPATHTOF(functions\fnc_arsenal.sqf); };
            class addVirtualItemCargo { file = QPATHTOF(functions\fnc_addVirtualItemCargo.sqf); };
        };
    };
    class zade_boc {
        class arsenal {
            class arsenal_postInit { file = QPATHTOF(functions\fnc_arsenal_postInit.sqf); postInit = 1; };
        };
    };
};
