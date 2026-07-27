class CUP_B_M2Bradley_USA_W;
class GVAR(borsuk) : CUP_B_M2Bradley_USA_W {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Borsuk";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
};

class I_APC_Wheeled_03_cannon_F;
class GVAR(rosomak) : I_APC_Wheeled_03_cannon_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 1;
    displayName = "Rosomak";
    crew = QGVAR(Crewman);
    typicalCargo[] = { QGVAR(Crewman) };
    INVENTORY_EMPTY;
    hiddenSelections[] = { "camo1", "camo2", "camo3", "camo4" };
    hiddenSelectionsTextures[] = {
        "A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext_co.paa",
        "A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext2_co.paa",
        "A3\armor_f_gamma\APC_Wheeled_03\data\rcws30_co.paa",
        "A3\armor_f_gamma\APC_Wheeled_03\data\apc_wheeled_03_ext_alpha_co.paa"
    };
};


