// MRLS
class CUP_B_RM70_CZ;
class GVAR(RM_70): CUP_B_RM70_CZ {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "RM70";
    crew = QGVAR(Crewman);
    typicalCargo[] = {QGVAR(Crewman)};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        "cup\wheeledvehicles\cup_wheeledvehicles_rm70\data\rm70body1_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_rm70\data\rm70body2_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_rm70\data\rm70body3_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_rm70\data\rm70uc_co.paa",
        "cup\wheeledvehicles\cup_wheeledvehicles_rm70\data\csla.paa"
    };

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Sholef
class B_MBT_01_arty_F;
GVAR(Sholef): B_MBT_01_arty_F {
    scope = 2;
    faction = QUOTE(ADDON);
    side = 0;
    displayName = "Sholef";
    crew = QGVAR(Armour_Crewman);
    typicalCargo[] = {QGVAR(Armour_Crewman)};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        "a3\armor_f_gamma\mbt_01\data\mbt_01_body_co.paa",
        "a3\armor_f_gamma\mbt_01\data\mbt_01_scorcher_co.paa",
        "a3\data_f\vehicles\turret_co.paa",
        "a3\armor_f\data\camonet_nato_desert_co.paa"
    };

    INVENTORY_EMPTY;
};
