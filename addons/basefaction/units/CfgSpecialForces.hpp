class uksf_Base_SF_Operator: uksf_base_Soldier_Base {
    scope = 2;
    displayName = "SF (Operator)";
    editorSubcategory = QEGVAR(common,basefaction);
    editorPreview = "a3\editorpreviews_f\data\cfgvehicles\o_officer_f.jpg";
    uniformClass = "U_O_officer_noInsignia_hex_F";
    model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
};
class uksf_Base_SF_MG: uksf_Base_SF_Operator {
    displayName = "SF (MG)";
    icon = "iconManMG";
};
class uksf_Base_SF_LAT: uksf_Base_SF_Operator {
    displayName = "SF (Light AT)";
    icon = "iconManAT";
};
class uksf_Base_SF_RadioOperator: uksf_Base_SF_Operator {
    displayName = "SF (Radio Operator)";
};
class uksf_Base_SF_Marksman: uksf_Base_SF_Operator {
    displayName = "SF (Marksman)";
};
class uksf_Base_SF_TL: uksf_Base_SF_Operator {
    displayName = "SF (Team Lead)";
    icon = "iconManLeader";
};
class uksf_Base_SF_Officer: uksf_Base_SF_Operator {
    displayName = "SF (Officer)";
    icon = "iconManOfficer";
};
