class GVAR(civ_undercover_1) : GVAR(base) {
    scope = 2;
    displayName = "Undercover Civ 1";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    editorSubcategory = QEGVAR(common,undercover_civ);
    uniformClass = "U_BG_Guerilla3_1";
    backpack = "";
    weapons[] = { "hgun_Pistol_01_F" };
    respawnWeapons[] = { "hgun_Pistol_01_F" };
    magazines[] = { "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag" };
    respawnMagazines[] = { "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch" };
    resapwnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch" };
};
class GVAR(civ_undercover_2) : GVAR(civ_undercover_1) {
    displayName = "Undercover Civ 2";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    uniformClass = "U_BG_Guerilla2_2";
};
class GVAR(civ_undercover_3) : GVAR(civ_undercover_1) {
    displayName = "Undercover Civ 3";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    uniformClass = "U_BG_Guerilla2_1";
};
class GVAR(civ_undercover_4) : GVAR(civ_undercover_1) {
    displayName = "Undercover Civ 4";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    uniformClass = "U_BG_Guerilla2_3";
};
class GVAR(civ_sniper) : GVAR(civ_undercover_1) {
    displayName = "Civ Sniper";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    weapons[] = { "CUP_srifle_SVD_PSO_camo", "hgun_Pistol_01_F" };
    respawnWeapons[] = { "CUP_srifle_SVD_PSO_camo", "hgun_Pistol_01_F" };
    magazines[] = { "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "10Rnd_9x21_Mag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5" };
    respawnMagazines[] = { "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "10Rnd_9x21_Mag", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "CUP_10Rnd_762x54_SVD_M", "10Rnd_9x21_Mag", "SmokeShell", "SmokeShell", "SmokeShell", "CUP_HandGrenade_RGD5" };
    items[] = { "ACE_EarPlugs" };
    respawnItems[] = { "ACE_EarPlugs" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "V_Rangemaster_belt" };
    resapwnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "H_Booniehat_oli", "V_Rangemaster_belt" };
};
