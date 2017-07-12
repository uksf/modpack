class I_MBT_03_cannon_F;
class Inegal_Tank_Leclerc: I_MBT_03_cannon_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "AMX Leclerc";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Tank_Leclerc.jpg);
    crew = "Inegal_Crew_C";
    typicalCargo[] = {
        "Inegal_Crew_C"
    };
    hiddenSelections[] = { "Camo1", "Camo2", "Camo3", "HideHull", "HideTurret", "pasoffsetl", "pasoffsetp" };
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\TankBodyTexture.paa), 
        QPATHTOF(data\TankTurretTexture.paa), 
        QPATHTOF(data\TankTurretMGTexture.paa), 
        QPATHTOF(data\TankTurretTexture.paa), 
        QPATHTOF(data\TankTurretTexture.paa), 
        QPATHTOF(data\TankTrackTexture.paa), 
        QPATHTOF(data\TankTrackTexture.paa)
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
