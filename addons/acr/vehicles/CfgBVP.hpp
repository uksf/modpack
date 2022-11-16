class CUP_B_BMP2_CZ;
class GVAR(BVP): CUP_B_BMP2_CZ {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "BVP";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {QGVAR(Armour_Crewman)};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };

    hiddenSelectionsTextures[] = {
        "cup\trackedvehicles\cup_trackedvehicles_bmp\bmp2\data\bmp2_01_acr_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_bmp\bmp2\data\bmp2_02_acr_co.paa"
    };

    INVENTORY_EMPTY;
};


