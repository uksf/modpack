// MRLS
class CUP_B_RM70_CZ;
class UKSF_ACR_RM_70: CUP_B_RM70_CZ {
    scope = 2;
    faction = "UKSF_ACR";
    side = 0;
    displayName = "RM70";
    crew = "UKSF_ACR_Crewman";
    typicalCargo[] = {"UKSF_ACR_Crewman"};
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
class UKSF_ACR_Sholef: B_MBT_01_arty_F {
    scope = 2;
    faction = "UKSF_ACR";
    side = 0;
    displayName = "Sholef";
    crew = "UKSF_ACR_Armour_Crewman";
    typicalCargo[] = {"UKSF_ACR_Armour_Crewman"};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        "a3\armor_f_gamma\mbt_01\data\mbt_01_body_co.paa",
        "a3\armor_f_gamma\mbt_01\data\mbt_01_scorcher_co.paa",
        "a3\data_f\vehicles\turret_co.paa",
        "a3\armor_f\data\camonet_nato_desert_co.paa"
    };

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
