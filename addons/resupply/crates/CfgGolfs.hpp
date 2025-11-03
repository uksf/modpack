class Box_NATO_Ammo_F;
class GVAR(gx) : Box_NATO_Ammo_F {
    author = "UKSF";
    faction = "CUP_B_GB";
    scope = 2;
    scopeCurator = 2;
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,golfs);
    displayName = "GX (Empty)";
    description = "Grab Box - Empty";
    PREVIEW(gx);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\gx.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {};
    class TransportBackpacks {};
};
class GVAR(g1) : GVAR(gx) {
    displayName = "G1 (SA)";
    description = "Grab Box - Small Arms Ammo";
    PREVIEW(g1);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g1.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
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
class GVAR(g2) : GVAR(gx) {
    displayName = "G2 (GPMG)";
    description = "Grab Box - GPMG Ammo";
    PREVIEW(g2);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g2.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T,10);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_100Rnd_T_EL,5);
    };
};
class GVAR(g3) : GVAR(gx) {
    displayName = "G3 (AT)";
    description = "Grab Box - Anti-Tank";
    PREVIEW(g3);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g3.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_LAUNCHER;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(MRAWS_HEAT_F,10);
        MACRO_ADDMAGAZINE(MRAWS_HE_F,5);
        MACRO_ADDMAGAZINE(za_enhancedmaawsCUP_mag_HE,5);
        MACRO_ADDMAGAZINE(za_enhancedmaawsCUP_mag_HEAT551,5);
        MACRO_ADDMAGAZINE(za_enhancedmaawsCUP_mag_ASM509,5);
        MACRO_ADDMAGAZINE(za_enhancedmaawsCUP_mag_ILLUM,5);
        MACRO_ADDMAGAZINE(za_enhancedmaawsCUP_mag_MT756,5);
    };
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_AT4_CS_AT_Launcher,5);
        MACRO_ADDWEAPON(launch_NLAW_F,5);
    };
};
class GVAR(g4) : GVAR(gx) {
    displayName = "G4 (HAT)";
    description = "Grab Box - Heavy Anti-Tank";
    PREVIEW(g4);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g4.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_LAUNCHER;
    class TransportWeapons {
        MACRO_ADDWEAPON(UK3CB_BAF_Javelin_Slung_Tube,10);
    };
};
class GVAR(g5) : GVAR(gx) {
    displayName = "G5 (HMG)";
    description = "Grab Box - HMG Ammo";
    PREVIEW(g5);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g5.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_127_100Rnd,6);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd,3);
    };
};
class GVAR(g6) : GVAR(gx) {
    displayName = "G6 (GMG)";
    description = "Grab Box - GMG Ammo";
    PREVIEW(g6);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g6.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_EXPLOSIVE;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_32Rnd_40mm_G_Box,6);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_200Rnd,3);
    };
};
class GVAR(g7) : GVAR(gx) {
    displayName = "G7 (MILAN)";
    description = "Grab Box - MILAN Ammo";
    PREVIEW(g7);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g7.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_LAUNCHER;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_Milan,10);
    };
};
class GVAR(g8) : GVAR(gx) {
    displayName = "G8 (LMHE)";
    description = "Grab Box - Light Mortar HE Ammo";
    PREVIEW(g8);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g8.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_EXPLOSIVE;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Shells,30);
    };
};
class GVAR(g9) : GVAR(gx) {
    displayName = "G9 (LMSMK)";
    description = "Grab Box - Light Mortar Smoke Ammo";
    PREVIEW(g9);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g9.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_EXPLOSIVE;
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White,30);
    };
};
class GVAR(g10) : GVAR(gx) {
    displayName = "G10 (MMHE)";
    description = "Grab Box - Medium Mortar HE Ammo";
    PREVIEW(g10);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g10.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_EXPLOSIVE;
    maximumLoad = 1400; // Increase space to fix 15 rounds being too many for box size
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Shells,15);
    };
    ace_dragging_ignoreWeight = 1;
};
class GVAR(g11) : GVAR(gx) {
    displayName = "G11 (MMSMK)";
    description = "Grab Box - Medium Mortar Smoke Ammo";
    PREVIEW(g11);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g11.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    BOX_EXPLOSIVE;
    maximumLoad = 1400; // Increase space to fix 15 rounds being too many for box size
    class TransportMagazines {
        MACRO_ADDMAGAZINE(UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White,15);
    };
    ace_dragging_ignoreWeight = 1;
};
class GVAR(g12) : GVAR(gx) {
    displayName = "G12 (SN)";
    description = "Grab Box - Sniper Ammo";
    PREVIEW(g12);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g12.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    class TransportMagazines {
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_Mag,5);
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_300gr_Scenar_Tracer_Mag,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,10);
    };
};
class GVAR(g13) : GVAR(gx) {
    displayName = "G13 (SNH)";
    description = "Grab Box - Heavy Sniper Ammo";
    PREVIEW(g13);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g13.paa), "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
    class TransportMagazines {
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_Mag,5);
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_300gr_Scenar_Tracer_Mag,5);
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_300gr_Scenar_IR_Mag,5);
        MACRO_ADDMAGAZINE(SPS_AI_AXMC_338_HAPI_Mag,5);
        MACRO_ADDMAGAZINE(UK3CB_BAF_762_L42A1_20Rnd,10);
    };
};

class ACE_medicalSupplyCrate;
class GVAR(g14) : ACE_medicalSupplyCrate {
    scope = 2;
    scopeCurator = 2;
    faction = "CUP_B_GB";
    displayName = "G14 (MED)";
    description = "Grab Box - Medical";
    editorCategory = "EdCat_Supplies";
    editorSubcategory = QEGVAR(common,golfs);
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g14.paa) };
    PREVIEW(g14);
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
    };
    class TransportMagazines {
        MACRO_ADDMAGAZINE(ACE_painkillers,30);
    };
};
class GVAR(g14ba) : GVAR(g14) {
    displayName = "G14 (MED-BA)";
    description = "Grab Box - Medical (Bandages)";
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g14ba.paa) };
    PREVIEW(g14);
    class TransportItems {
        MACRO_ADDITEM(ACE_elasticBandage,250);
        MACRO_ADDITEM(ACE_packingBandage,250);
        MACRO_ADDITEM(ACE_surgicalKit,10);
    };
    class TransportMagazines {};
};
class GVAR(g14bl) : GVAR(g14) {
    displayName = "G14 (MED-BL)";
    description = "Grab Box - Medical (Blood)";
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g14bl.paa) };
    PREVIEW(g14);
    class TransportItems {
        MACRO_ADDITEM(ACE_bloodIV_500,50);
        MACRO_ADDITEM(ACE_bloodIV_250,50);
    };
    class TransportMagazines {};
};
class GVAR(g14d) : GVAR(g14) {
    displayName = "G14 (MED-D)";
    description = "Grab Box - Medical (Drugs)";
    hiddenSelectionsTextures[] = { QPATHTOF(data\golf\g14d.paa) };
    PREVIEW(g14);
    class TransportItems {
        MACRO_ADDITEM(ACE_adenosine,100);
        MACRO_ADDITEM(ACE_morphine,100);
        MACRO_ADDITEM(ACE_epinephrine,100);
    };
    class TransportMagazines {};
};
