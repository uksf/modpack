// Specialist units (Men (Specialists) category)
class GVAR(Officer_HQ) : GVAR(Soldier_Base) {
    scope = 2;
    editorSubcategory = QGVAR(specialists);
    displayName = "HQ Officer";
    backpack = "";
    weapons[] = {"CUP_hgun_Browning_HP", "Put", "Throw"};
    respawnWeapons[] = {"CUP_hgun_Browning_HP", "Put", "Throw"};
    magazines[] = {
        "CUP_13Rnd_9x19_Browning_HP", "CUP_13Rnd_9x19_Browning_HP",
        "CUP_13Rnd_9x19_Browning_HP", "CUP_13Rnd_9x19_Browning_HP"
    };
    respawnMagazines[] = {
        "CUP_13Rnd_9x19_Browning_HP", "CUP_13Rnd_9x19_Browning_HP",
        "CUP_13Rnd_9x19_Browning_HP", "CUP_13Rnd_9x19_Browning_HP"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"V_Rangemaster_belt", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"V_Rangemaster_belt", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class GVAR(Signaller) : GVAR(Rifleman) {
    displayName = "Signaller";
    editorSubcategory = QGVAR(specialists);
    backpack = "B_RadioBag_01_black_F";
};

class GVAR(Sniper) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Sniper";
    editorSubcategory = QGVAR(specialists);
    uniformClass = "U_I_FullGhillie_lsh";
    backpack = "";
    weapons[] = {QGVAR(srifle_DMR_02_camo_F_optic_KHS_old), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(srifle_DMR_02_camo_F_optic_KHS_old), "Put", "Throw"};
    magazines[] = {
        "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag",
        "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag"
    };
    respawnMagazines[] = {
        "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag",
        "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag", "10Rnd_338_Mag"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"UK3CB_BAF_V_PLCE_Webbing_Plate_OLI", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
    respawnLinkedItems[] = {"UK3CB_BAF_V_PLCE_Webbing_Plate_OLI", "CUP_G_RUS_Ratnik_Balaclava_Green_1", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
};

class GVAR(Crewman) : GVAR(Soldier_Base) {
    scope = 2;
    editorSubcategory = QGVAR(specialists);
    displayName = "Crewman";
    backpack = "";
    weapons[] = {"CUP_arifle_G36C", "Put", "Throw"};
    respawnWeapons[] = {"CUP_arifle_G36C", "Put", "Throw"};
    magazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8"
    };
    respawnMagazines[] = {
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8",
        "CUP_30Rnd_556x45_XM8", "CUP_30Rnd_556x45_XM8"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"CUP_V_B_PASGT_no_bags", "H_Tank_eaf_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"CUP_V_B_PASGT_no_bags", "H_Tank_eaf_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class GVAR(Heli_Pilot) : GVAR(Officer_HQ) {
    editorSubcategory = QGVAR(specialists);
    displayName = "Helicopter Pilot";
    vest = "CUP_V_B_PASGT_no_bags";
    linkedItems[] = {"CUP_V_B_PASGT_no_bags", "H_PilotHelmetHeli_B", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"CUP_V_B_PASGT_no_bags", "H_PilotHelmetHeli_B", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};
