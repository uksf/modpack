class PROR_Crew : PROR_R {
    displayName = "Crewman";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Crew.jpg);
    editorSubcategory = QEGVAR(common,crew);
    backpack = "";
    weapons[] = {
        "SMG_03C_TR_black",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "SMG_03C_TR_black",
        "Throw",
        "Put"
    };
    magazines[] = {
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGrenade"
    };
    linkedItems[] = {
        "H_HelmetCrew_I",
        "CUP_V_B_RRV_Scout2",
        "CFP_ANPVS15_Camo_V3",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "H_HelmetCrew_I",
        "CUP_V_B_RRV_Scout2",
        "CFP_ANPVS15_Camo_V3",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Jet_Pilot : PROR_Crew {
    displayName = "Jet Pilot";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Jet_Pilot.jpg);
    backpack = "B_Parachute";
    linkedItems[] = {
        "CUP_H_RUS_ZSH_Shield_Down",
        "CFP_ANPVS15_Camo_V3",
        "CUP_V_B_PilotVest",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "CUP_H_RUS_ZSH_Shield_Down",
        "CFP_ANPVS15_Camo_V3",
        "CUP_V_B_PilotVest",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
class PROR_Heli_Pilot : PROR_Crew {
    displayName = "Heli Pilot";
    editorPreview = QPATHTOEF(common,data\previews\PROR_Heli_Pilot.jpg);
    linkedItems[] = {
        "H_PilotHelmetHeli_O",
        "CUP_V_B_PilotVest",
        "CFP_ANPVS15_Camo_V3",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
    respawnLinkedItems[] = {
        "H_PilotHelmetHeli_O",
        "CUP_V_B_PilotVest",
        "CFP_ANPVS15_Camo_V3",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS",
        "Binocular",
        "CFP_Shemagh_Neck_M81"
    };
};
