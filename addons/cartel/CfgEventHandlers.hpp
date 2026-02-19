class Extended_InitPost_EventHandlers {
    class GVAR(commando_ak74_rpg) {
        class ADDON {
            init = QUOTE((_this select 0) addSecondaryWeaponItem (selectRandom [ARR_2('CUP_OG7_M','CUP_PG7V_M')]));
        };
    };

    class GVAR(commando_mp5_bunkerfaust) {
        class ADDON {
            init = QUOTE((_this select 0) addSecondaryWeaponItem (selectRandom [ARR_2('CUP_PTFHE_M','CUP_PTFHC_M')]));
        };
    };

    class GVAR(commando_LR_GMG) {
        class ADDON {
            init = "[(_this select 0), nil, ['selection_tool', 0, 'selection_jerry', 1, 'selection_antenna', 1, 'selection_antenna_rear', 0, 'selection_box', 0, 'selection_steps', 0, 'selection_wheelfront', 0, 'selection_wheels', 0, 'selection_bar', 0, 'selection_cut', 1, 'selection_doors', 1]] call BIS_fnc_initVehicle";
        };
    };

    class GVAR(commando_LR_MG) {
        class ADDON {
            init = "[(_this select 0), nil, ['selection_tool', 0, 'selection_jerry', 1, 'selection_antenna', 1, 'selection_antenna_rear', 0, 'selection_box', 0, 'selection_steps', 0, 'selection_wheelfront', 0, 'selection_wheels', 0, 'selection_bar', 0, 'selection_cut', 1, 'selection_doors', 1]] call BIS_fnc_initVehicle";
        };
    };
};
