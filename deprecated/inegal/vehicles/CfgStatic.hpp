// HMG
class I_HMG_01_high_F;
class Inegal_Static_HMG: I_HMG_01_high_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "HMG";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Static_HMG.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// GMG
class I_GMG_01_high_F;
class Inegal_Static_GMG: I_HMG_01_high_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "GMG";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Static_GMG.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
    class eventhandlers {
        init = "(_this select 0) setSkill [""aimingAccuracy"", 0.01]; (_this select 0) setSkill [""aimingSpeed"", 0.01]; (_this select 0) setSkill [""aimingshake"", 0.01]; (_this select 0) setSkill [""spotTime"", 1];";
        class cba_Extended_EventHandlers: cba_Extended_EventHandlers {};
    };
};

// Mortar
class I_Mortar_01_F;
class Inegal_Static_Mortar: I_Mortar_01_F {
    scope = 2;
    side = 0;
    faction = "UKSF_Inegal";
    displayName = "Mk6";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Static_Mortar.jpg);
    crew = "Inegal_F";
    typicalCargo[] = {
        "Inegal_F"
    };
};
