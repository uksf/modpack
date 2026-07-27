class GVAR(sf_operator) : GVAR(Soldier_SF_Base) {
    scope = 2;
    scopeCurator = 2;
    displayName = "Operator";
    minSkill = 0.7;
    maxSkill = 0.8;
};

class GVAR(sf_grenadier) : GVAR(sf_operator) {
    displayName = "Grenadier";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {QGVAR(hk416_gl), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(hk416_gl), "Put", "Throw"};
    backpack = QGVAR(sf_grenadier_backpack);
};

class GVAR(sf_autorifleman) : GVAR(sf_operator) {
    displayName = "Autorifleman";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {QGVAR(minimi), "Put", "Throw"};
    respawnWeapons[] = {QGVAR(minimi), "Put", "Throw"};
    magazines[] = {"200Rnd_556x45_Box_Red_F"};
    respawnMagazines[] = {"200Rnd_556x45_Box_Red_F"};
    backpack = QGVAR(sf_lmg_backpack);
};

class GVAR(sf_HAT) : GVAR(sf_operator) {
    displayName = "HAT";
    minSkill = 0.7;
    maxSkill = 0.8;
    weapons[] = {QGVAR(hk416), "CUP_launch_MAAWS", "Put","Throw"};
    respawnWeapons[] = {QGVAR(hk416), "CUP_launch_MAAWS", "Put","Throw"};
    backpack = QGVAR(sf_hat_backpack);
};
