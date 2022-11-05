class CUP_O_T72_SLA;
class UKSF_ACR_T72: CUP_O_T72_SLA {
    scope = 2;
    faction = "UKSF_ACR";
    side = 0;
    displayName = "T72";
    crew = "UKSF_ACR_Armour_Crewman";
    typicalCargo[] = {"UKSF_ACR_Armour_Crewman"};
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    // hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_1_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_2_co.paa",
        "cup\trackedvehicles\cup_trackedvehicles_t72\data\textures\gue_t72_3_co.paa"
    };

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
