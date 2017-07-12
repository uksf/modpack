class I_mas_ZU23_base;
class I_mas_DSHKM_base;
class I_mas_KORD_Base;
class I_mas_M2StaticMG_base;
class I_mas_M2StaticMG_MiniTripod_base;
class I_mas_AGS_base;
class I_mas_GMG_base;
class I_mas_MK19_TriPod_base;
class I_mas_Metis_Base;
class I_mas_TOW_TriPod_base;
class I_mas_SPG9_base;
class I_mas_Igla_AA_pod_Base;
class I_mas_Stinger_AA_pod_Base;
class I_mas_2b14_82mm_Base;
class I_mas_M252_base;
class I_mas_D30_base;
class I_mas_M119_base;

// ZU23
class I_mas_ZU23_AAF: I_mas_ZU23_base {
    scope = 0;
};
class O_mas_ZU23_AAF: I_mas_ZU23_AAF {
    scope = 0;
};
class Genfor_Static_ZU23: O_mas_ZU23_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_ZU23.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// DSHKM
class I_mas_DSHKM_AAF: I_mas_DSHKM_base {
    scope = 0;
};
class O_mas_DSHKM_AAF: I_mas_DSHKM_AAF {
    scope = 0;
};
class Genfor_Static_DSHKM: O_mas_DSHKM_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_DSHKM.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
};

// DSHKM Mini Tripod
class I_mas_DSHkM_Mini_TriPod: I_mas_DSHKM_base {
    scope = 0;
};
class O_mas_DSHkM_Mini_TriPod: I_mas_DSHkM_Mini_TriPod {
    scope = 0;
};
class Genfor_Static_DSHKMMiniTripod: O_mas_DSHkM_Mini_TriPod {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_DSHKMMiniTripod.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
};

// KORD
class I_mas_KORD_AAF: I_mas_KORD_Base {
    scope = 0;
};
class O_mas_KORD_AAF: I_mas_KORD_AAF {
    scope = 0;
};
class Genfor_Static_KORD: O_mas_KORD_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_KORD.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// KORD High
class I_mas_KORD_high_AAF: I_mas_KORD_Base {
    scope = 0;
};
class O_mas_KORD_high_AAF: I_mas_KORD_high_AAF {
    scope = 0;
};
class Genfor_Static_KORDHigh: O_mas_KORD_high_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_KORDHigh.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// M2
class I_mas_M2StaticMG_AAF: I_mas_M2StaticMG_base {
    scope = 0;
};
class B_mas_M2StaticMG_AAF: I_mas_M2StaticMG_AAF {
    scope = 0;
};
class Genfor_Static_M2: B_mas_M2StaticMG_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_M2.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// M2 Mini Tripod
class I_mas_M2StaticMG_MiniTripod_AAF: I_mas_M2StaticMG_MiniTripod_base {
    scope = 0;
};
class B_mas_M2StaticMG_MiniTripod_AAF: I_mas_M2StaticMG_MiniTripod_AAF {
    scope = 0;
};
class Genfor_Static_M2MiniTripod: B_mas_M2StaticMG_MiniTripod_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_M2MiniTripod.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// AGS
class I_mas_AGS_AAF: I_mas_AGS_base {
    scope = 0;
};
class O_mas_AGS_AAF: I_mas_AGS_AAF {
    scope = 0;
};
class Genfor_Static_AGS: O_mas_AGS_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_AGS.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// GMG
class I_mas_GMG_AAF: I_mas_GMG_base {
    scope = 0;
};
class B_mas_GMG_AAF: I_mas_GMG_AAF {
    scope = 0;
};
class Genfor_Static_GMG: B_mas_GMG_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_GMG.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// MK19
class I_mas_MK19_TriPod_AAF: I_mas_MK19_TriPod_base {
    scope = 0;
};
class B_mas_MK19_TriPod_AAF: I_mas_MK19_TriPod_AAF {
    scope = 0;
};
class Genfor_Static_MK19: B_mas_MK19_TriPod_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_MK19.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Metis
class I_mas_Metis_AAF: I_mas_Metis_Base {
    scope = 0;
};
class O_mas_Metis_AAF: I_mas_Metis_AAF {
    scope = 0;
};
class Genfor_Static_Metis: O_mas_Metis_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_Metis.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// TOW
class I_mas_TOW_TriPod_AAF: I_mas_TOW_TriPod_base {
    scope = 0;
};
class B_mas_TOW_TriPod_AAF: I_mas_TOW_TriPod_AAF {
    scope = 0;
};
class Genfor_Static_TOW: B_mas_TOW_TriPod_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_TOW.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// SPG9
class I_mas_SPG9_AAF: I_mas_SPG9_base {
    scope = 0;
};
class O_mas_SPG9_AAF: I_mas_SPG9_AAF {
    scope = 0;
};
class Genfor_Static_SPG9: O_mas_SPG9_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_SPG9.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Igla
class I_mas_Igla_AA_pod_AAF: I_mas_Igla_AA_pod_Base {
    scope = 0;
};
class O_mas_Igla_AA_pod_AAF: I_mas_Igla_AA_pod_AAF {
    scope = 0;
};
class Genfor_Static_Igla: O_mas_Igla_AA_pod_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_Igla.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Stinger
class I_mas_Stinger_AA_pod_AAF: I_mas_Stinger_AA_pod_Base {
    scope = 0;
};
class B_mas_Stinger_AA_pod_AAF: I_mas_Stinger_AA_pod_AAF {
    scope = 0;
};
class Genfor_Static_Stinger: B_mas_Stinger_AA_pod_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_Stinger.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// 2B14
class I_mas_2b14_82mm_AAF: I_mas_2b14_82mm_Base {
    scope = 0;
};
class O_mas_2b14_82mm_AAF: I_mas_2b14_82mm_AAF {
    scope = 0;
};
class Genfor_Static_2B14: O_mas_2b14_82mm_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_2B14.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// M252
class I_mas_M252_AAF: I_mas_M252_base {
    scope = 0;
};
class B_mas_M252_AAF: I_mas_M252_AAF {
    scope = 0;
};
class Genfor_Static_M252: B_mas_M252_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_M252.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// D30
class I_mas_D30_AAF: I_mas_D30_base {
    scope = 0;
};
class O_mas_D30_AAF: I_mas_D30_AAF {
    scope = 0;
};
class Genfor_Static_D30: O_mas_D30_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_D30.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// D30 AT
class I_mas_D30_AT_AAF: I_mas_D30_AAF {
    scope = 0;
};
class O_mas_D30_AT_AAF: I_mas_D30_AT_AAF {
    scope = 0;
};
class Genfor_Static_D30AT: O_mas_D30_AT_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_D30AT.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// M119
class I_mas_M119_AAF: I_mas_M119_base {
    scope = 0;
};
class B_mas_M119_AAF: I_mas_M119_AAF {
    scope = 0;
};
class Genfor_Static_M119: B_mas_M119_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_M119.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// M119 AT
class I_mas_M119_AT_AAF: I_mas_M119_AAF {
    scope = 0;
};
class B_mas_M119_AT_AAF: I_mas_M119_AT_AAF {
    scope = 0;
};
class Genfor_Static_M119AT: B_mas_M119_AT_AAF {
    scope = 2;
    side = 0;
    faction = "UKSF_Genfor";
    editorPreview = QPATHTOEF(common,data\previews\Genfor_Static_M119AT.jpg);
    crew = "GENFOR_R";
    typicalCargo[] = {
        "GENFOR_R"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

class Weapon_Bag_Base;
class I_mas_Tripod_Bag: Weapon_Bag_Base {
    scope = 0;
};
class O_mas_Tripod_Bag: I_mas_Tripod_Bag {
    scope = 0;
};
class B_mas_Tripod_Bag: I_mas_Tripod_Bag {
    scope = 0;
};
class I_mas_Tripod_h_Bag: I_mas_Tripod_Bag {
    scope = 0;
};
class O_mas_Tripod_h_Bag: I_mas_Tripod_h_Bag {
    scope = 0;
};
class B_mas_Tripod_h_Bag: I_mas_Tripod_h_Bag {
    scope = 0;
};
class I_mas_DShkM_Gun_Bag: Weapon_Bag_Base {
    scope = 0;
};
class O_mas_DShkM_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class I_mas_DShkM_h_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_DShkM_h_Gun_Bag: I_mas_DShkM_h_Gun_Bag {
    scope = 0;
};
class I_mas_Kord_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_Kord_Gun_Bag: I_mas_Kord_Gun_Bag {
    scope = 0;
};
class I_mas_Kord_h_Gun_Bag: I_mas_Kord_Gun_Bag {
    scope = 0;
};
class O_mas_Kord_h_Gun_Bag: I_mas_Kord_h_Gun_Bag {
    scope = 0;
};
class I_mas_Metis_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_Metis_Gun_Bag: I_mas_Metis_Gun_Bag {
    scope = 0;
};
class I_mas_AGS30_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_AGS30_Gun_Bag: I_mas_AGS30_Gun_Bag {
    scope = 0;
};
class I_mas_GMG_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_GMG_Gun_Bag: I_mas_GMG_Gun_Bag {
    scope = 0;
};
class I_mas_SPG9_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_SPG9_Gun_Bag: I_mas_SPG9_Gun_Bag {
    scope = 0;
};
class I_mas_Podnos_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class O_mas_Podnos_Gun_Bag: I_mas_Podnos_Gun_Bag {
    scope = 0;
};
class I_mas_M2_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_M2_Gun_Bag: I_mas_M2_Gun_Bag {
    scope = 0;
};
class I_mas_M2_h_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_M2_h_Gun_Bag: I_mas_M2_h_Gun_Bag {
    scope = 0;
};
class I_mas_Mk19_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_Mk19_Gun_Bag: I_mas_Mk19_Gun_Bag {
    scope = 0;
};
class I_mas_Tow_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_Tow_Gun_Bag: I_mas_Tow_Gun_Bag {
    scope = 0;
};
class I_mas_M252_Gun_Bag: I_mas_DShkM_Gun_Bag {
    scope = 0;
};
class B_mas_M252_Gun_Bag: I_mas_M252_Gun_Bag {
    scope = 0;
};
