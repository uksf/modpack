class CfgFunctions {
    class A3_Functions_F_Curator {
        class Curator {
            delete curatorPinged;
        };
    };
    class Achilles {
        class ui_f_eventHandler {
            class onDisplayCuratorLoad { file = QPATHTOF(functions\fnc_onDisplayCuratorLoad.sqf); };
            class onModuleTreeLoad { file = QPATHTOF(functions\fnc_onModuleTreeLoad.sqf); };
        };
        class ui_f_keyEvents {
            class HandleCuratorObjectDoubleClicked { file = QPATHTOF(functions\fnc_handleCuratorObjectDoubleClicked.sqf); };
        };
    };
    class Ares {
        class functions_f_features {
            class AddUnitsToCurator { file = QPATHTOF(functions\fnc_addUnitsToCurator.sqf); };
        };
    };
};
