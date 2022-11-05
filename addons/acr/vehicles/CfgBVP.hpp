class CUP_B_BMP2_CZ;
class UKSF_ACR_BVP: CUP_B_BMP2_CZ {
    scope = 2;
    faction = "UKSF_ACR";
    side = 0;
    displayName = "BVP";
    crew = "UKSF_ACR_Armour_Crewman";
    typicalCargo[] = {"UKSF_ACR_Armour_Crewman"};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };

    hiddenSelectionsTextures[] = {
        "cup\trackedvehicles\cup_trackedvehicles_bmp\bmp2\data\bmp2_01_acr_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_bmp\bmp2\data\bmp2_02_acr_co.paa"
    };

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};


