class uksf_Base_Recce_Rifleman: uksf_base_Soldier_Base {
    scope = 2;
    displayName = "Recce (Rifleman)";
    editorSubcategory = QEGVAR(common,basefaction);
    editorPreview = "a3\editorpreviews_f\data\cfgvehicles\o_officer_f.jpg";
    uniformClass = "U_O_officer_noInsignia_hex_F";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
};
class uksf_Base_Recce_LAT: uksf_Base_Recce_Rifleman {
    displayName = "Recce (Light AT)";
    icon = "iconManAT";
};
class uksf_Base_Recce_Marksman: uksf_Base_Recce_Rifleman {
    displayName = "Recce (Marksman)";
};
class uksf_Base_Recce_TL: uksf_Base_Recce_Rifleman {
    displayName = "Recce (TL)";
    icon = "iconManLeader";
};
class uksf_Base_Recce_RadioOperator: uksf_Base_Recce_Rifleman {
    displayName = "Recce (Radio Operator)";
};
class uksf_Base_Recce_MG: uksf_Base_Recce_Rifleman {
    displayName = "Recce (MG)";
    icon = "iconManMG";
};
class uksf_Base_Recce_Officer: uksf_Base_Recce_Rifleman {
    displayName = "Recce (Officer)";
    icon = "iconManOfficer";
};
