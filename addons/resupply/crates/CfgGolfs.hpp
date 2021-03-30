class Box_NATO_Ammo_F;
class GVAR(ge) : Box_NATO_Ammo_F {
    author = "UKSF";
    faction = "CUP_B_GB";
    scope = 2;
    scopeCurator = 2;
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,golfs);
    displayName = "Empty Golf Crate";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_Empty.jpg);
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {};
    class TransportBackpacks {};
};
class GVAR(gsa) : GVAR(ge) {
    displayName = "G-SA";
    description = "Grab Box - Small Arms Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_556_30Rnd,40);
        MACRO_ADDMAGAZINE(UK3CB_BAF_556_200Rnd,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,10);
        MACRO_ADDMAGAZINE(1Rnd_HE_Grenade_shell,10);
        MACRO_ADDMAGAZINE(HandGrenade,10);
        MACRO_ADDMAGAZINE(SmokeShell,10);
        MACRO_ADDMAGAZINE(SmokeShellRed,5);
        MACRO_ADDMAGAZINE(SmokeShellBlue,5);
        MACRO_ADDMAGAZINE(SmokeShellGreen,5);
        MACRO_ADDMAGAZINE(SmokeShellPurple,5);
        MACRO_ADDMAGAZINE(ACE_M84,5);
    };
};
class GVAR(ggpmg) : GVAR(ge) {
    displayName = "G-GPMG";
    description = "Grab Box - GPMG Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T_EL,5);
    };
};
class GVAR(gat) : GVAR(ge) {
    displayName = "G-AT";
    description = "Grab Box - Anti-Tank";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_WpsLaunch_F.jpg";
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
    icon = "iconCrateLong";
    class TransportMagazines {
        MACRO_ADDMAGAZINE(MRAWS_HEAT_F,10);
        MACRO_ADDMAGAZINE(MRAWS_HE_F,5);
    };
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AT_Launcher,5);
        MACRO_ADDWEAPON(UK3CB_BAF_NLAW_Launcher,5);
    };
};
class GVAR(ghat) : GVAR(ge) {
    displayName = "G-HAT";
    description = "Grab Box - Heavy Anti-Tank";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_WpsLaunch_F.jpg";
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
    icon = "iconCrateLong";
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_Javelin_Slung_Tube,10);
    };
};
class GVAR(ghmg) : GVAR(ge) {
    displayName = "G-HMG";
    description = "Grab Box - HMG Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_100Rnd,6);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd,3);
    };
};
class GVAR(ggmg) : GVAR(ge) {
    displayName = "G-GMG";
    description = "Grab Box - GMG Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_32Rnd_40mm_G_Box,6);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd,3);
    };
};
class GVAR(gmil) : GVAR(ge) {
    displayName = "G-MILAN";
    description = "Grab Box - MILAN Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\Box_NATO_WpsLaunch_F.jpg";
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    model = "\A3\weapons_F\AmmoBoxes\WpnsBox_long_F";
    icon = "iconCrateLong";
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_Milan,10);
    };
};
class GVAR(glmhe) : GVAR(ge) {
    displayName = "G-LMHE";
    description = "Grab Box - Light Mortar HE Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Shells,30);
    };
};
class GVAR(glmsmk) : GVAR(ge) {
    displayName = "G-LMSMK";
    description = "Grab Box - Light Mortar Smoke Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White,30);
    };
};
class GVAR(gmmhe) : GVAR(ge) {
    displayName = "G-MMHE";
    description = "Grab Box - Medium Mortar HE Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Shells,15);
    };
};
class GVAR(gmmsmk) : GVAR(ge) {
    displayName = "G-MMSMK";
    description = "Grab Box - Medium Mortar Smoke Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White,15);
    };
};
class GVAR(gsn) : GVAR(ge) {
    displayName = "G-SN";
    description = "Grab Box - Sniper Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_338_5Rnd_Tracer,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,10);
    };
};
class GVAR(gsnh) : GVAR(ge) {
    displayName = "G-SNH";
    description = "Grab Box - Heavy Sniper Ammo";
    // editorPreview = QPATHTOEF(common,data\previews\UKSF_S_R1.jpg);
    // hiddenSelectionsTextures[] = { QPATHTOF(data\R1_co.paa) };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP,5);
        MACRO_ADDMAGAZINE(SSQN_5Rnd_127x99_HEIAP_Tracer,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_AP,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_10Rnd_T,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,10);
    };
};
class ACE_medicalSupplyCrate;
class GVAR(gmed) : ACE_medicalSupplyCrate {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "G-MED";
    description = "Grab Box - Medical";
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,golfs);
    editorPreview = QPATHTOEF(common,data\previews\UKSF_S_MedicalBox.jpg);
    class TransportItems {
        MACRO_ADDITEM(ACE_elasticBandage,150);
        MACRO_ADDITEM(ACE_packingBandage,150);
        MACRO_ADDITEM(ACE_adenosine,30);
        MACRO_ADDITEM(ACE_morphine,30);
        MACRO_ADDITEM(ACE_epinephrine,30);
        MACRO_ADDITEM(ACE_bloodIV,30);
        MACRO_ADDITEM(ACE_bloodIV_500,30);
        MACRO_ADDITEM(ACE_bloodIV_250,30);
        MACRO_ADDITEM(ACE_splint,30);
        MACRO_ADDITEM(ACE_painkillers,30);
    };
};
