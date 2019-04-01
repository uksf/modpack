class CFP_B_USMC_M60A3_Patton_DES_01;
class PROR_Tank_M60: CFP_B_USMC_M60A3_Patton_DES_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_PROR";
    displayName = "M60";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Tank_Leclerc.jpg);
    crew = "PROR_Crew";
    typicalCargo[] = {
        "PROR_Crew"
    };
    
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
