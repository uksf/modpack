class Inegal_Jet_A149;
class GVAR(Gripen) : Inegal_Jet_A149 {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Gripen";
    hiddenSelectionsTextures[] = { "a3\air_f_jets\plane_fighter_04\data\fighter_04_fuselage_01_co.paa", "a3\air_f_jets\plane_fighter_04\data\fighter_04_fuselage_02_co.paa", "a3\air_f_jets\plane_fighter_04\data\fighter_04_misc_01_co.paa", "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_04_ca.paa", "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_04_ca.paa", "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_08_ca.paa" };
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};

class O_Plane_Fighter_02_F;
class GVAR(Shikra) : O_Plane_Fighter_02_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Shikra";
    hiddenSelectionsTextures[] = { "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_01_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_02_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_01_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_02_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_00_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_01_co.paa" };
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};

class O_Plane_Fighter_02_Stealth_F;
class GVAR(Shikra_Stealth) : O_Plane_Fighter_02_Stealth_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Shikra Stealth";
    hiddenSelectionsTextures[] = { "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_01_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_02_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\fighter_02_fuselage_01_grey_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_02_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_00_co.paa", "a3\air_f_jets\plane_fighter_02\data\numbers\fighter_02_number_01_co.paa" };
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};

class CUP_O_C47_SLA;
class GVAR(Li_2) : CUP_O_C47_SLA {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Li-2";
    hiddenSelectionsTextures[] = { "cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_01_sla_co.paa", "cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_02_sla_co.paa" };
    crew = QGVAR(Jet_Pilot);
    typicalCargo[] = { QGVAR(Jet_Pilot) };
    INVENTORY_EMPTY;
};
