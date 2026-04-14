class B_T_LSV_01_unarmed_F;
class GVAR(LSV_01_unarmed_SF) : B_T_LSV_01_unarmed_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "LSV-01 (SF, unarmed)";
    crew = QGVAR(sf_operator);
    typicalCargo[] = { QGVAR(sf_operator) };
    INVENTORY_EMPTY;
};

class B_T_LSV_01_armed_F;
class GVAR(LSV_01_armed_SF) : B_T_LSV_01_armed_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "LSV-01 (SF, armed)";
    crew = QGVAR(sf_operator);
    typicalCargo[] = { QGVAR(sf_operator) };
    INVENTORY_EMPTY;
};
