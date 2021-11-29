class uksf_base_Rifleman: uksf_base_Soldier_Base {
    scope = 2;
    displayName = "Rifleman";
    editorSubcategory = QEGVAR(common,infantry);
    editorPreview = "a3\editorpreviews_f\data\cfgvehicles\o_officer_f.jpg";
    uniformClass = "U_O_officer_noInsignia_hex_F";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
};
class uksf_Base_LMG: uksf_base_Rifleman {
    displayName = "Light Machinegunner";
    icon = "iconManMG";
};
class uksf_Base_MG: uksf_base_Rifleman {
    displayName = "Machinegunner";
    icon = "iconManMG";
};
class uksf_Base_MG_Ammobearer: uksf_base_Rifleman {
    displayName = "MG Ammo Bearer";
};
class uksf_Base_LAT: uksf_base_Rifleman {
    displayName = "Light AT";
    icon = "iconManAT";
};
class uksf_Base_HAT: uksf_base_Rifleman {
    displayName = "Heavy AT";
    icon = "iconManAT";
};
class uksf_Base_HAT_Ammobearer: uksf_base_Rifleman {
    displayName = "HAT Ammo Bearer";
};
class uksf_Base_SL: uksf_base_Rifleman {
    displayName = "Squad Leader";
    icon = "iconManLeader";
};
class uksf_Base_Marksman: uksf_base_Rifleman {
    displayName = "Marksman";
};
class uksf_Base_Sniper: uksf_base_Rifleman {
    displayName = "Sniper";
};
class uksf_Base_Officer: uksf_base_Rifleman {
    displayName = "Officer";
    icon = "iconManOfficer";
};
class uksf_Base_RadioOperator: uksf_base_Rifleman {
    displayName = "Radio Operator";
};
class uksf_Base_Crewman: uksf_base_Rifleman {
    displayName = "Crewman";
};
class uksf_Base_AA: uksf_base_Rifleman {
    displayName = "Anti-Air";
    icon = "iconManAT";
};
class uksf_Base_HeliPilot: uksf_base_Rifleman {
    displayName = "Helicopter Pilot";
};
class uksf_Base_JetPilot: uksf_base_Rifleman {
    displayName = "Jet Pilot";
};
