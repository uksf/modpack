class Inegal_Recrues_C: Inegal_Soldier_Base {
    scope = 2;
    displayName = "Conscript";
    editorSubcategory = QEGVAR(common,recrues);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Recrues_C.jpg);
    uniformClass = "U_B_CTRG_1";
    backpack = "Inegal_B_R_C";
    weapons[] = {
        "CUP_arifle_Mk16_CQC_black",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_CQC_black",
        "Throw",
        "Put"
    };
    magazines[] = {
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    respawnMagazines[] = {
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade",
        "HandGrenade"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_morphine",
        "ACE_Banana"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_quikclot",
        "ACE_morphine",
        "ACE_Banana"
    };
    linkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_TacVest_oli",
        "ACE_NVG_Gen1",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged"
    };
    respawnLinkedItems[] = {
        "H_HelmetB_snakeskin",
        "V_TacVest_oli",
        "ACE_NVG_Gen1",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged"
    };
};
class Inegal_Recrues_L: Inegal_Recrues_C {
    displayName = "Leader";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Recrues_L.jpg);
    icon = "iconManLeader";
    uniformClass = "U_B_CTRG_2";
    backpack = "Inegal_B_R_L";
    weapons[] = {
        "CUP_arifle_Mk16_CQC_EGLM_black_Eotech",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_CQC_EGLM_black_Eotech",
        "Throw",
        "Put"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_morphine"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_fieldDressing",
        "ACE_morphine"
    };
    linkedItems[] = {
        "H_MilCap_gry",
        "V_TacVest_oli",
        "ACE_NVG_Gen1",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged"
    };
    respawnLinkedItems[] = {
        "H_MilCap_gry",
        "V_TacVest_oli",
        "ACE_NVG_Gen1",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged"
    };
};
class Inegal_Recrues_R: Inegal_Recrues_C {
    displayName = "Recruit";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Recrues_R.jpg);
    uniformClass = "U_B_CTRG_1";
    backpack = "Inegal_B_R_R";
    weapons[] = {
        "CUP_arifle_Mk16_CQC_black_Eotech",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_arifle_Mk16_CQC_black_Eotech",
        "Throw",
        "Put"
    };
};
