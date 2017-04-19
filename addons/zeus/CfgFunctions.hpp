class CfgFunctions {
    class Achilles {
        class Init {
            class onCuratorStart { file = QPATHTOF(functions\fnc_onCuratorStart.sqf); };
        };
    };
    class A3_Functions_F_Curator {
        class Curator {
            class curatorPinged { file = QPATHTOF(functions\fnc_curatorPinged.sqf); };
            class curatorObjectPlaced { file = "\achilles\functions_f_achilles\functions\replacement\fn_curatorObjectPlaced.sqf"; };
            class showCuratorAttributes { file = "\achilles\functions_f_achilles\functions\replacement\fn_showCuratorAttributes.sqf"; };
        };
        class Achilles {
            delete curatorObjectPlaced;
            delete showCuratorAttributes;
        };
    };
};
