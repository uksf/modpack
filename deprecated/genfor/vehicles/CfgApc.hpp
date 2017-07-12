// BMP1
class I_mas_BMP1_AAF_base;
class I_mas_BMP1_AAF_01: I_mas_BMP1_AAF_base {
    scope = 0;
};
class O_mas_BMP1_OPF_01: I_mas_BMP1_AAF_01 {
    scope = 0;
};
class Genfor_Apc_BMP1: O_mas_BMP1_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Apc_BMP1.jpg);
    displayName = "BMP-1";
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// BMP1P
class I_mas_BMP1P_AAF_base;
class I_mas_BMP1P_AAF_01: I_mas_BMP1P_AAF_base {
    scope = 0;
};
class O_mas_BMP1P_OPF_01: I_mas_BMP1P_AAF_01 {
    scope = 0;
};
class Genfor_Apc_BMP1P: O_mas_BMP1P_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Apc_BMP1P.jpg);
    displayName = "BMP-1P";
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// BMP2
class I_mas_BMP2_AAF_base;
class I_mas_BMP2_AAF_01: I_mas_BMP2_AAF_base {
    scope = 0;
};
class O_mas_BMP2_OPF_01: I_mas_BMP2_AAF_01 {
    scope = 0;
};
class Genfor_Apc_BMP2: O_mas_BMP2_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Apc_BMP2.jpg);
    displayName = "BMP-2";
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// BMP2 HQ
class I_mas_BMP2_HQ_AAF_base;
class I_mas_BMP2_HQ_AAF_01: I_mas_BMP2_HQ_AAF_base {
    scope = 0;
};
class O_mas_BMP2_HQ_OPF_01: I_mas_BMP2_HQ_AAF_01 {
    scope = 0;
};
class Genfor_Apc_BMP2HQ: O_mas_BMP2_HQ_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "BMP-2 HQ";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Apc_BMP2HQ.jpg); 
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// BMP2 Ambul
class I_mas_BMP2_Ambul_AAF_base;
class I_mas_BMP2_Ambul_01: I_mas_BMP2_Ambul_AAF_base {
    scope = 0;
};
class O_mas_BMP2_Ambul_01: I_mas_BMP2_Ambul_01 {
    scope = 0;
};
class Genfor_Apc_BMP2Ambul: O_mas_BMP2_HQ_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "BMP-2 Ambulance";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Apc_BMP2Ambul.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};
