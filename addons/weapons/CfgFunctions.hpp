class CfgFunctions {
    class UK3CB_BAF_Weapons_Launchers {
        class UK3CB_BAF_Weapons_Launchers {
            class init_EH {
                file = QPATHTOF(functions\fnc_3cb_initEH.sqf);
            };
            class can_assemble_javelin {
                file = QPATHTOF(functions\fnc_3cb_canAssembleJavelin.sqf);
            };
            class can_disassemble_javelin {
                file = QPATHTOF(functions\fnc_3cb_canDisassembleJavelin.sqf);
            };
            class assemble_javelin {
                file = QPATHTOF(functions\fnc_3cb_assembleJavelin.sqf);
            };
        };
    };
    class UK3CB_BAF_Weapons_Static {
        class UK3CB_BAF_Weapons_Static {
            class static_weapon_init {
                postInit = 1;
                file = QPATHTOF(functions\fnc_3cb_staticWeaponInit.sqf);
            };
        };
    };
    class UK3CB_BAF_Weapons_Accessories {
        class UK3CB_BAF_Weapons_Accessories {
            delete accessory_init;
            delete switch_attachment;
            delete underbarrel;
        };
    };
    class UK3CB_BAF_Weapons_Ammo {
        class UK3CB_BAF_Weapons_Ammo {
            class check_for_smoke_round {
                file = QPATHTOF(functions\fnc_3cbCheckForSmokeRoundWrapper.sqf);
            };
            class create_smoke_round {
                file = QPATHTOF(functions\fnc_3cbCreateSmokeRoundWrapper.sqf);
            };
        };
    };
};
