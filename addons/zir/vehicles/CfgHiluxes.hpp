// Hilux
class CUP_O_Hilux_unarmed_OPF_G_F;
class GVAR(hilux) : CUP_O_Hilux_unarmed_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux";
    crew = QGVAR(Militia_akn);
    typicalCargo[] = {
        QGVAR(Militia_akn),
        QGVAR(Militia_LAT),
        QGVAR(Militia_sks),
        QGVAR(Militia_gp25),
    };
    INVENTORY_EMPTY;
};

// Hilux
class GVAR(hilux_full) : CUP_O_Hilux_unarmed_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (Full)";
    crew = QGVAR(Militia_akn);
    typicalCargo[] = {
        QGVAR(Militia_akn)
    };
    INVENTORY_EMPTY;
};

// Dshkm
class CUP_O_Hilux_DSHKM_OPF_G_F;
class GVAR(hilux_dshkm) : CUP_O_Hilux_DSHKM_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (DSHKM)";
    crew = QGVAR(Militia_akn);
    typicalCargo[] = {
        QGVAR(Militia_sks)
    };
    INVENTORY_EMPTY;
};

// AGS
class CUP_O_Hilux_AGS30_OPF_G_F;
class GVAR(hilux_ags) : CUP_O_Hilux_AGS30_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (AGS-30)";
    crew = QGVAR(Militia_gp25);
    typicalCargo[] = {
        QGVAR(Militia_sks)
    };
    INVENTORY_EMPTY;
};

// SPG9
class CUP_O_Hilux_SPG9_OPF_G_F;
class GVAR(hilux_spg9) : CUP_O_Hilux_SPG9_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (SPG-9)";
    crew = QGVAR(Militia_gp25);
    typicalCargo[] = {
        QGVAR(Militia_LAT)
    };
    INVENTORY_EMPTY;
};

// UB32
class CUP_O_Hilux_UB32_OPF_G_F;
class GVAR(hilux_ub32) : CUP_O_Hilux_UB32_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (UB32)";
    crew = QGVAR(Militia_sks);
    typicalCargo[] = {
        QGVAR(Militia_sks)
    };
    INVENTORY_EMPTY;
};

// Podnos
class CUP_O_Hilux_podnos_OPF_G_F;
class GVAR(hilux_podnos) : CUP_O_Hilux_podnos_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (Podnos)";
    crew = QGVAR(Militia_sks);
    typicalCargo[] = {
        QGVAR(Militia_gp25)
    };
    INVENTORY_EMPTY;
};

// ZU-32
class CUP_O_Hilux_zu23_OPF_G_F;
class GVAR(hilux_zu23) : CUP_O_Hilux_zu23_OPF_G_F {
    side = 0;
    faction = QUOTE(ADDON);
    displayName = "Hilux (ZU-23)";
    crew = QGVAR(Militia_akn);
    typicalCargo[] = {
        QGVAR(Militia_gp25)
    };
    INVENTORY_EMPTY;
};
