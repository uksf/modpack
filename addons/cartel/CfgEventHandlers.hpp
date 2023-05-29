class Extended_InitPost_EventHandlers {
    class GVAR(commando_ak74_rpg) {
        class ADDON {
            init = (_this select 0) addSecondaryWeaponItem (selectRandom ["CUP_OG7_M","CUP_PG7V_M"]);
        };
    };

    class GVAR(commando_mp5_bunkerfaust) {
        class ADDON {
            init = (_this select 0) addSecondaryWeaponItem (selectRandom ["CUP_PTFHE_M","CUP_PTFHC_M"]);
        };
    };
};
