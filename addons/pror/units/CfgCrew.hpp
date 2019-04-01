class PROR_Crew : PROR_R {
    displayName = "Crewman";
    uniformClass = "CFP_U_FieldUniform_M81light";
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
        "HandGreande"
    };
    respawnMagazines[] = {
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "50Rnd_570x28_SMG_03",
        "SmokeShell",
        "SmokeShell",
        "SmokeShell",
        "HandGreande"
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
    uniformClass = "CFP_U_FieldUniform_M81light";
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
    uniformClass = "CFP_U_FieldUniform_M81light";
    backpack = "";

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
