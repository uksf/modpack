class Truck_01_base_F;
class UK3CB_BAF_MAN_HX60_Base : Truck_01_base_F {
    faction = "CUP_B_GB";
    editorSubcategory = QEGVAR(common,support);
};
class UK3CB_BAF_MAN_HX60_Cargo_Base : UK3CB_BAF_MAN_HX60_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Fuel_Base : UK3CB_BAF_MAN_HX60_Base {
    faction = "CUP_B_GB";
    transportFuel = 0;
};
class UK3CB_BAF_MAN_HX60_Repair_Base : UK3CB_BAF_MAN_HX60_Base {
    faction = "CUP_B_GB";
    transportRepair = 0;
};
class UK3CB_BAF_MAN_HX60_Transport_Base : UK3CB_BAF_MAN_HX60_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Cargo_Green_A : UK3CB_BAF_MAN_HX60_Cargo_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Cargo_Green_B : UK3CB_BAF_MAN_HX60_Cargo_Green_A {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Fuel_Green : UK3CB_BAF_MAN_HX60_Fuel_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Repair_Green : UK3CB_BAF_MAN_HX60_Repair_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Transport_Green : UK3CB_BAF_MAN_HX60_Transport_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Cargo_Sand_A : UK3CB_BAF_MAN_HX60_Cargo_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Cargo_Sand_B : UK3CB_BAF_MAN_HX60_Cargo_Sand_A {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Fuel_Sand : UK3CB_BAF_MAN_HX60_Fuel_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Repair_Sand : UK3CB_BAF_MAN_HX60_Repair_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX60_Transport_Sand : UK3CB_BAF_MAN_HX60_Transport_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Base : UK3CB_BAF_MAN_HX60_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Cargo_Base : UK3CB_BAF_MAN_HX58_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Fuel_Base : UK3CB_BAF_MAN_HX58_Base {
    faction = "CUP_B_GB";
    transportFuel = 0;
};
class UK3CB_BAF_MAN_HX58_Repair_Base : UK3CB_BAF_MAN_HX58_Base {
    faction = "CUP_B_GB";
    transportRepair = 0;
};
class UK3CB_BAF_MAN_HX58_Transport_Base : UK3CB_BAF_MAN_HX58_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Cargo_Green_A : UK3CB_BAF_MAN_HX58_Cargo_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Cargo_Green_B : UK3CB_BAF_MAN_HX58_Cargo_Green_A {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Fuel_Green : UK3CB_BAF_MAN_HX58_Fuel_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Repair_Green : UK3CB_BAF_MAN_HX58_Repair_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Transport_Green : UK3CB_BAF_MAN_HX58_Transport_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Cargo_Sand_A : UK3CB_BAF_MAN_HX58_Cargo_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Cargo_Sand_B : UK3CB_BAF_MAN_HX58_Cargo_Sand_A {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Fuel_Sand : UK3CB_BAF_MAN_HX58_Fuel_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Repair_Sand : UK3CB_BAF_MAN_HX58_Repair_Base {
    faction = "CUP_B_GB";
};
class UK3CB_BAF_MAN_HX58_Transport_Sand : UK3CB_BAF_MAN_HX58_Transport_Base {
    faction = "CUP_B_GB";
};

class UK3CB_BAF_MAN_HX58_Rearm_Green : UK3CB_BAF_MAN_HX58_Cargo_Green_B {
    displayname = "MAN HX58 6x6 Rearm Loaded (Green)";
    supplyRadius = 10;
    transportAmmo = 0;
    ace_rearm_defaultSupply = 1200;
    secondaryExplosion = 10000;
};
class UK3CB_BAF_MAN_HX58_Rearm_Sand : UK3CB_BAF_MAN_HX58_Cargo_Sand_B {
    displayname = "MAN HX58 6x6 Rearm Loaded (Sand)";
    supplyRadius = 10;
    transportAmmo = 0;
    ace_rearm_defaultSupply = 1200;
    secondaryExplosion = 10000;
};
class UK3CB_BAF_MAN_HX60_Rearm_Green : UK3CB_BAF_MAN_HX60_Cargo_Green_B {
    displayname = "MAN HX60 4x4 Rearm Loaded (Green)";
    supplyRadius = 10;
    transportAmmo = 0;
    ace_rearm_defaultSupply = 1200;
    secondaryExplosion = 10000;
};
class UK3CB_BAF_MAN_HX60_Rearm_Sand : UK3CB_BAF_MAN_HX60_Cargo_Sand_B {
    displayname = "MAN HX60 4x4 Rearm Loaded (Sand)";
    supplyRadius = 10;
    transportAmmo = 0;
    ace_rearm_defaultSupply = 1200;
    secondaryExplosion = 10000;
};

class UKSF_Hemtt_Ammo : UK3CB_BAF_MAN_HX58_Rearm_Green {
    scope = 1;
};
class UKSF_Hemtt_Fuel : UK3CB_BAF_MAN_HX58_Fuel_Green {
    scope = 1;
};
class UKSF_Hemtt_Repair : UK3CB_BAF_MAN_HX58_Repair_Green {
    scope = 1;
};
