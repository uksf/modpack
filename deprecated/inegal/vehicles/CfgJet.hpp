//L-159
class I_Plane_Fighter_03_AA_F;
class Inegal_Jet_L159: I_Plane_Fighter_03_AA_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "L-159";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Jet_L159.jpg);
    crew = "Inegal_Crew_P";
    typicalCargo[] = {
        "Inegal_Crew_P"
    };
    hiddenSelectionsTextures[] = { QPATHTOF(data\plane_fighter_03_body_1_co.paa), QPATHTOF(data\plane_fighter_03_body_2_co.paa) };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
