class GVAR(crewman) : GVAR(rifleman) {
    displayName = "Crewman";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    editorSubcategory = QEGVAR(common,crew);
    uniformClass = "U_OG_Guerilla1_1";
};
class GVAR(crew_heli) : GVAR(crewman) {
    displayName = "Helicopter Pilot";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    uniformClass = "U_BG_Guerilla2_1";
    backpack = "";
    weapons[] = { "hgun_PDW2000_Holo_F_Holosight" };
    respawnWeapons[] = { "hgun_PDW2000_Holo_F_Holosight" };
    magazines[] = { "30Rnd_9x21_Yellow_Mag", "30Rnd_9x21_Yellow_Mag", "SmokeShellGreen", "Chemlight_green", "30Rnd_9x21_Yellow_Mag", "SmokeShellOrange", "SmokeShellPurple", "Chemlight_green" };
    respawnMagazines[] = { "30Rnd_9x21_Yellow_Mag", "30Rnd_9x21_Yellow_Mag", "SmokeShellGreen", "Chemlight_green", "30Rnd_9x21_Yellow_Mag", "SmokeShellOrange", "SmokeShellPurple", "Chemlight_green" };
    linkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_INDEP", "H_PilotHelmetHeli_I", "V_TacVest_oli", "NVGoggles_INDEP" };
    resapwnLinkedItems[] = { "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_INDEP", "H_PilotHelmetHeli_I", "V_TacVest_oli", "NVGoggles_INDEP" };
};
class GVAR(crew_jet) : GVAR(crew_heli) {
    displayName = "Jet Pilot";
    editorPreview = QPATHTOEF(common,data\previews\PROR_R.jpg);
    backpack = "B_Parachute";
};
