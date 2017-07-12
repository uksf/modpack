// Crew
class Inegal_Crew_HP: Inegal_Soldier_Base {
    _generalMacro = "Inegal_Crew_HP";
    scope = 2;
    displayName = "Heli Pilot";
    editorSubcategory = QEGVAR(common,crew);
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Crew_HP.jpg);
    uniformClass = "U_B_CTRG_Soldier_2_F";
    backpack = "";
    weapons[] = {
        "SMG_05_F_Aco",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "SMG_05_F_Aco",
        "Throw",
        "Put"
    };
    magazines[] = {
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "30Rnd_9x21_Mag_SMG_02_Tracer_Yellow",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    linkedItems[] = {
        "H_PilotHelmetHeli_O",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_PilotHelmetHeli_O",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Crew_HC: Inegal_Crew_HP {
    _generalMacro = "Inegal_Crew_HC";
    displayName = "Heli Crew";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Crew_HC.jpg);
    linkedItems[] = {
        "H_CrewHelmetHeli_O",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_CrewHelmetHeli_O",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Crew_C: Inegal_Crew_HP {
    _generalMacro = "Inegal_Crew_C";
    displayName = "Crew";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Crew_C.jpg);
    linkedItems[] = {
        "H_HelmetCrew_B",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_HelmetCrew_B",
        "V_TacVest_oli",
        "NVGogglesB_grn_F",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
class Inegal_Crew_P: Inegal_Crew_HP {
    _generalMacro = "Inegal_Crew_P";
    displayName = "Pilot";
    editorPreview = QPATHTOEF(common,data\previews\Inegal_Crew_P.jpg);
    uniformClass = "U_B_PilotCoveralls";
    backpack = "B_Parachute";
    weapons[] = {
        "CUP_hgun_Colt1911",
        "Throw",
        "Put"
    };
    respawnWeapons[] = {
        "CUP_hgun_Colt1911",
        "Throw",
        "Put"
    };
    magazines[] = {
        "CUP_7Rnd_45ACP_1911",
        "CUP_7Rnd_45ACP_1911",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed"
    };
    respawnMagazines[] = {
        "CUP_7Rnd_45ACP_1911",
        "CUP_7Rnd_45ACP_1911",
        "SmokeShellBlue",
        "SmokeShellBlue",
        "SmokeShellRed",
        "SmokeShellRed"
    };
    items[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    respawnItems[] = {
        "ACE_EarPlugs",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_elasticBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_packingBandage",
        "ACE_morphine",
        "ACE_morphine"
    };
    linkedItems[] = {
        "H_PilotHelmetFighter_O",
        "UKSF_V_Flight",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
    respawnLinkedItems[] = {
        "H_PilotHelmetFighter_O",
        "UKSF_V_Flight",
        "ItemMap",
        "ItemCompass",
        "ItemWatch",
        "ItemRadioAcreFlagged",
        "ItemGPS"
    };
};
