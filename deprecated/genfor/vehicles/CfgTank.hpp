// T-72A
class I_mas_T72_AAF_base;
class I_mas_T72_AAF_01: I_mas_T72_AAF_base {
    scope = 0;
};
class O_mas_T72_OPF_01: I_mas_T72_AAF_01 {
    scope = 0;
};
class Genfor_Tank_T72A: O_mas_T72_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-72A";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T72A.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// T-72B Early
class I_mas_T72B_Early_AAF_01: I_mas_T72_AAF_01 {
    scope = 0;
};
class O_mas_T72B_Early_OPF_01: I_mas_T72B_Early_AAF_01 {
    scope = 0;
};
class Genfor_Tank_T7BEarly: O_mas_T72B_Early_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-72B (Early)";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T7BEarly.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// T-72B
class I_mas_T72B_AAF_01: I_mas_T72B_Early_AAF_01 {
    scope = 0;
};
class O_mas_T72B_OPF_01: I_mas_T72B_AAF_01 {
    scope = 0;
};
class Genfor_Tank_T72B: O_mas_T72B_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-72B";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T72B.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// T-72BM
class I_mas_T72BM_AAF_01: I_mas_T72B_AAF_01 {
    scope = 0;
};
class O_mas_T72BM_OPF_01: I_mas_T72BM_AAF_01 {
    scope = 0;
};
class Genfor_Tank_T72BM: O_mas_T72BM_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-72BM";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T72BM.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// T-55A
class I_mas_T55_AAF_base;
class I_mas_T55_AAF_01: I_mas_T55_AAF_base {
    scope = 0;
};
class O_mas_T55_OPF_01: I_mas_T55_AAF_01 {
    scope = 0;
};
class Genfor_Tank_T55A: O_mas_T55_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-55A";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T55A.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// T-34
class I_mas_T34_AAF_base;
class I_mas_T34_AAF_01: I_mas_T34_AAF_base {
    scope = 0;
};
class Genfor_Tank_T34: I_mas_T34_AAF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "T-34";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_T34.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
};

// ZSU
class I_mas_ZSU_AAF_base;
class I_mas_ZSU_AAF_01: I_mas_ZSU_AAF_base {
    scope = 0;
};
class O_mas_ZSU_OPF_01: I_mas_ZSU_AAF_01 {
    scope = 0;
};
class Genfor_Tank_ZSU: O_mas_ZSU_OPF_01 {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    displayName = "ZSU Shilka";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Tank_ZSU.jpg);
    crew = "GENFOR_TC";
    typicalCargo[] = {
        "GENFOR_TC"
    };
    radarType = 2;
    class TransportMagazines {};
    class TransportItems {};
    class TransportWeapons {};
    class TransportBackpacks {};
    class eventhandlers {
        init = "this setSkill [""aimingAccuracy"", 0.05]; this setSkill [""aimingSpeed"", 0.05]; this setSkill [""aimingshake"", 0.05]; this setSkill [""spotTime"", 0.5];";
        class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
    };
};
