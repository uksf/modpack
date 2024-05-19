class CUP_I_MTLB_pk_UN;
class GVAR(MTLB) : CUP_I_MTLB_pk_UN {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "MT-LB";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = { QGVAR(Armour_Crewman) };
    INVENTORY_EMPTY;
};

class CUP_O_MTLB_pk_Green_RU;
class GVAR(MTLB_Woodland) : CUP_O_MTLB_pk_Green_RU {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "MT-LB (Woodland)";
    crew = QGVAR(Armour_Crewman_Woodland);
    typicalCargo[] = { QGVAR(Armour_Crewman_Woodland) };
    INVENTORY_EMPTY;
};
