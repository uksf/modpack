// TODO: inventories https://github.com/uksf/modpack/issues/708
class UK3CB_BAF_Husky_Base : MRAP_01_base_F {
    fuelCapacity = 15;  // Reduced from 151. Gives ~40km range. 230L tank
    ace_refuel_fuelCapacity = 230;
    ace_repair_spareWheels = 4;
};
class UK3CB_BAF_Husky_GPMG_Base : UK3CB_BAF_Husky_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_GPMG_Base : UK3CB_BAF_Husky_GPMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_GPMG_Sand : UK3CB_BAF_Husky_GPMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    transportAmmo = 0;
    transportFuel = 0;
    transportRepair = 0;
};
class UK3CB_BAF_Husky_Passenger_GPMG_Sand : UK3CB_BAF_Husky_Passenger_GPMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_GPMG_Green : UK3CB_BAF_Husky_Logistics_GPMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_GPMG_Green : UK3CB_BAF_Husky_Passenger_GPMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_HMG_Base : UK3CB_BAF_Husky_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_HMG_Base : UK3CB_BAF_Husky_HMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_HMG_Sand : UK3CB_BAF_Husky_HMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    transportAmmo = 0;
    transportFuel = 0;
    transportRepair = 0;
};
class UK3CB_BAF_Husky_Passenger_HMG_Sand : UK3CB_BAF_Husky_Passenger_HMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_HMG_Green : UK3CB_BAF_Husky_Logistics_HMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_HMG_Green : UK3CB_BAF_Husky_Passenger_HMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_GMG_Base : UK3CB_BAF_Husky_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_GMG_Base : UK3CB_BAF_Husky_GMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_GMG_Sand : UK3CB_BAF_Husky_GMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    transportAmmo = 0;
    transportFuel = 0;
    transportRepair = 0;
};
class UK3CB_BAF_Husky_Passenger_GMG_Sand : UK3CB_BAF_Husky_Passenger_GMG_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Logistics_GMG_Green : UK3CB_BAF_Husky_Logistics_GMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_Husky_Passenger_GMG_Green : UK3CB_BAF_Husky_Passenger_GMG_Sand {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
