class pook_Mi28_OPFOR;
class GVAR(Mi_28N) : pook_Mi28_OPFOR {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Mi-28N";
    hiddenSelectionsTextures[] = { "pook_mi28\data\skins\sand.paa", "pook_mi28\data\_num\number_b6_ca.paa", "pook_mi28\data\_num\number_b7_ca.paa" };
    crew = QGVAR(Heli_Crew);
    typicalCargo[] = { QGVAR(Heli_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_Mi24_Mk4_CSAT_T;
class GVAR(Mi_24_Superhind) : CUP_O_Mi24_Mk4_CSAT_T {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Mi-24 Superhind";
    hiddenSelectionsTextures[] = { "cup\airvehicles\cup_airvehicles_mi35\data\mi24sh_001_co.paa", "cup\airvehicles\cup_airvehicles_mi35\data\mi24sh_002_co.paa", "cup\airvehicles\cup_airvehicles_mi35\data\mi35_sh_co.paa" };
    crew = QGVAR(Heli_Crew);
    typicalCargo[] = { QGVAR(Heli_Crew) };
    INVENTORY_EMPTY;
};

class O_Heli_Light_02_unarmed_F;
class GVAR(Kasatka_Unarmed) : O_Heli_Light_02_unarmed_F {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Kasatka Unarmed";
    hiddenSelectionsTextures[] = { "a3\air_f\heli_light_02\data\heli_light_02_ext_co.paa" };
    crew = QGVAR(Heli_Crew);
    typicalCargo[] = { QGVAR(Heli_Crew) };
    INVENTORY_EMPTY;
};
