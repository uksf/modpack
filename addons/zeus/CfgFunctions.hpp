class CfgFunctions {
    class A3_Functions_F_Curator {
        class Curator {
            delete curatorPinged;
            class curatorObjectPlaced { file = "\achilles\functions_f_achilles\functions\replacement\fn_curatorObjectPlaced.sqf"; };
            class showCuratorAttributes { file = "\achilles\functions_f_achilles\functions\replacement\fn_showCuratorAttributes.sqf"; };
        };
        class Achilles {
            delete curatorObjectPlaced;
            delete showCuratorAttributes;
        };
    };
    class Achilles {
        class ui_f_displayCurator {
            class onDisplayCuratorLoad { file = QPATHTOF(functions\fnc_onDisplayCuratorLoad.sqf); };
            class onModuleTreeLoad { file = QPATHTOF(functions\fnc_onModuleTreeLoad.sqf); };
        };
    };
    class Ares {
        class functions_f_features {
            class AddUnitsToCurator { file = QPATHTOF(functions\fnc_addUnitsToCurator.sqf); };
        };
    };
};
