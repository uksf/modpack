class CUP_O_T72_SLA;
class GVAR(T72): CUP_O_T72_SLA {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "T72";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {QGVAR(Armour_Crewman)};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_1_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_2_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_3_co.paa"
    };

    INVENTORY_EMPTY;
};
