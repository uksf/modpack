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
    backpack = "B_RadioBag_01_eaf_F";
};

class GVAR(Sniper) : GVAR(Soldier_Base) {
    scope = 2;
    displayName = "Sniper";
    editorSubcategory = QGVAR(specialists);
    uniformClass = "U_I_FullGhillie_lsh";
    backpack = "";
    weapons[] = {QGVAR(m2010), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(m2010), "Put", "Throw"};
    magazines[] = {
        "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M",
        "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M"
    };
    respawnMagazines[] = {
        "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M",
        "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M", "CUP_5Rnd_762x67_M2010_M"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"V_SmershVest_01_F", "CUP_G_RUS_Ratnik_Balaclava_Olive_2", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
    respawnLinkedItems[] = {"V_SmershVest_01_F", "CUP_G_RUS_Ratnik_Balaclava_Olive_2", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "NVGoggles_OPFOR"};
};

class GVAR(Crewman) : GVAR(Soldier_Base) {
    scope = 2;
    editorSubcategory = QGVAR(specialists);
    displayName = "Crewman";
    backpack = "";
    weapons[] = {QGVAR(grot), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(grot), "Put", "Throw"};
    magazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    respawnMagazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_Tank_eaf_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_Tank_eaf_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class GVAR(Heli_Pilot) : GVAR(Rifleman) {
    editorSubcategory = QGVAR(specialists);
    displayName = "Helicopter Pilot";
    vest = "V_CarrierRigKBT_01_Olive_F";
     magazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    respawnMagazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_PilotHelmetHeli_I_E", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_PilotHelmetHeli_I_E", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class GVAR(Jet_Pilot) : GVAR(Rifleman) {
    editorSubcategory = QGVAR(specialists);
    displayName = "Jet Pilot";
    vest = "V_CarrierRigKBT_01_Olive_F";
     magazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    respawnMagazines[] = {
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag",
        "30Rnd_65x39_caseless_msbs_mag", "30Rnd_65x39_caseless_msbs_mag"
    };
    items[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    respawnItems[] = {
        "ACE_packingBandage", "ACE_packingBandage", "ACE_packingBandage",
        "ACE_elasticBandage", "ACE_elasticBandage", "ACE_elasticBandage"
    };
    linkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_PilotHelmetFighter_I_E", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    respawnLinkedItems[] = {"V_CarrierRigKBT_01_Olive_F", "H_PilotHelmetFighter_I_E", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
    backpack = "ACE_NonSteerableParachute";
};
