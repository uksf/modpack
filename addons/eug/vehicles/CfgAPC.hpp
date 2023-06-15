class MM_Buran_APC6;
class GVAR(Buran_APC) : MM_Buran_APC6 {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "Buran APC";
    hiddenSelectionsTextures[] = { "mm_buran\data\mm_buran_ext_sand_co.paa", "mm_buran\data\mm_buran_int_sand_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_BTR80A_CSAT;
class GVAR(BTR_80A): CUP_O_BTR80A_CSAT {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "BTR-80A";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_btr80\data\generic_tan\btr80_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_btr80\data\generic_tan\bppu_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_btr80\data\generic_tan\wheels_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_BTR90_RU;
class GVAR(BTR_90): CUP_O_BTR90_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "BTR-90";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_btr90\data\textures\body_des_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_btr90\data\textures\body2_des_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_BTR90_HQ_RU;
class GVAR(BTR_90HQ): CUP_O_BTR90_HQ_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "BTR-90HQ";
    hiddenSelectionsTextures[] = { "cup\wheeledvehicles\cup_wheeledvehicles_btr90\data\body_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_btr90\data\body2_co.paa", "cup\wheeledvehicles\cup_wheeledvehicles_btr90\data\btr_hq_co.paa" };
    crew = QGVAR(Vehicle_Crew);
    typicalCargo[] = { QGVAR(Vehicle_Crew) };
    INVENTORY_EMPTY;
};

class CUP_O_BMP3_RU;
class GVAR(BMP3): CUP_O_BMP3_RU {
    side = 2;
    faction = QUOTE(ADDON);
    displayName = "BMP3";
    hiddenSelectionsTextures[] = { "cup\trackedvehicles\cup_trackedvehicles_bmp3\data\bmp3_body_co.paa", "cup\trackedvehicles\cup_trackedvehicles_bmp3\data\bmp3_body2_co.paa", "cup\trackedvehicles\cup_trackedvehicles_bmp3\data\bmp3_wheels_co.paa" };
    crew = QGVAR(Tank_Crew);
    typicalCargo[] = { QGVAR(Tank_Crew) };
    INVENTORY_EMPTY;
};
