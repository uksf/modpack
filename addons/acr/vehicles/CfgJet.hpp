// F35
class CUP_B_F35B_USMC;
class UKSF_ACR_f35: CUP_B_F35B_USMC {
    scope = 2;
    side = 0;
    faction = "UKSF_ACR";
    displayName="F35";
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Jet_A149.jpg);
    hiddenSelectionsTextures[]={"cup\airvehicles\cup_airvehicles_f35\data\f35_jasdf_co.paa"};
    crew = "UKSF_ACR_Jet_Pilot";
    typicalCargo[] = {
        "UKSF_ACR_Jet_Pilot"
    };

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// Gripen
class Inegal_Jet_A149;
class UKSF_ACR_Gripen: Inegal_Jet_A149 {
    scope = 2;
    side = 0;
    faction = "UKSF_ACR";
    displayName="Gripen";
    crew = "UKSF_ACR_Jet_Pilot";
    typicalCargo[] = {
        "UKSF_ACR_Jet_Pilot"
    };
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Jet_A149.jpg);
    hiddenSelectionsTextures[]={
        "a3\air_f_jets\plane_fighter_04\data\fighter_04_fuselage_01_co.paa",
        "a3\air_f_jets\plane_fighter_04\data\fighter_04_fuselage_02_co.paa",
        "a3\air_f_jets\plane_fighter_04\data\fighter_04_misc_01_co.paa",
        "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_04_ca.paa",
        "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_04_ca.paa",
        "a3\air_f_jets\plane_fighter_04\data\numbers\fighter_04_number_08_ca.paa"
    };


    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};


// Li 2
class CUP_O_C47_SLA;
class UKSF_ACR_Li2: CUP_O_C47_SLA {
    scope = 2;
    side = 0;
    faction = "UKSF_ACR";
    displayName="Li2";
    crew = "UKSF_ACR_Jet_Pilot";
    typicalCargo[] = {
        "UKSF_ACR_Jet_Pilot"
    };
    // editorPreview = QPATHTOEF(common,data\previews\Inegal_Jet_A149.jpg);
    hiddenSelectionsTextures[]={"cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_01_sla_co.paa","cup\airvehicles\cup_airvehicles_dc3\data\textures\c47_body_02_sla_co.paa"};

    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
