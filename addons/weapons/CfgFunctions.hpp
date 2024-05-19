class CfgFunctions {
    class UK3CB_BAF_Weapons_Launchers {
        class UK3CB_BAF_Weapons_Launchers {
            class init_EH {
                file = QPATHTOF(functions\fnc_3cbInitEH.sqf);
            };
            class can_assemble_javelin {
                file = QPATHTOF(functions\fnc_3cbCanAssembleJavelin.sqf);
            };
            class can_disassemble_javelin {
                file = QPATHTOF(functions\fnc_3cbCanDisassembleJavelin.sqf);
            };
            class assemble_javelin {
                file = QPATHTOF(functions\fnc_3cbAssembleJavelin.sqf);
            };
        };
    };
    class UK3CB_BAF_Weapons_Static {
        class UK3CB_BAF_Weapons_Static {
            class static_weapon_init {
                postInit = 1;
                file = QPATHTOF(functions\fnc_staticWeaponInit.sqf);
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
