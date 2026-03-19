// Special Forces units (Men (SF) category)
class GVAR(sf_operator) : GVAR(Soldier_SF_Base) {
    scope = 2;
    scopeCurator = 2;
    displayName = "Operator";
    minSkill = 0.7;
    maxSkill = 0.8;
    backpack = QGVAR(sf_pack);
};

class GVAR(sf_sfc) : GVAR(sf_operator) {
    displayName = "SFC";
    minSkill = 0.7;
    maxSkill = 0.8;
    backpack = "B_RadioBag_01_eaf_F";
};

class GVAR(sf_grenadier) : GVAR(sf_operator) {
    displayName = "Grenadier";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {"CUP_glaunch_M32", "Put", "Throw"};
    respawnWeapons[] = {"CUP_glaunch_M32", "Put", "Throw"};
    magazines[] = {"CUP_6Rnd_HE_M203", "CUP_6Rnd_HE_M203"};
    respawnMagazines[] = {"CUP_6Rnd_HE_M203", "CUP_6Rnd_HE_M203"};
};

class GVAR(sf_autorifleman) : GVAR(sf_operator) {
    displayName = "Autorifleman";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {QGVAR(CUP_arifle_MG36_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(CUP_arifle_MG36_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "Put", "Throw"};
    magazines[] = {"CUP_100Rnd_556x45_BetaCMag"};
    respawnMagazines[] = {"CUP_100Rnd_556x45_BetaCMag"};
    backpack = QGVAR(sf_mg_pack);
};

class GVAR(sf_LAT) : GVAR(sf_operator) {
    displayName = "LAT";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {QGVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "UK3CB_BAF_AT4_CS_AP_Launcher", "Put","Throw"};
    respawnWeapons[] = {QGVAR(CUP_arifle_G36C_VFG_CUP_optic_HensoldtZO_low_RDS_CUP_acc_ANPEQ_15_Black_suppressed), "UK3CB_BAF_AT4_CS_AP_Launcher", "Put","Throw"};
};
