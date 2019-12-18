class UK3CB_BAF_LandRover_Amb_Base : UK3CB_BAF_LandRover_Base {
};
class UK3CB_BAF_LandRover_Amb_Green_A : UK3CB_BAF_LandRover_Amb_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_Amb_Sand_A : UK3CB_BAF_LandRover_Amb_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Amb_UN_A : UK3CB_BAF_LandRover_Amb_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Amb_FFR_Green_A : UK3CB_BAF_LandRover_Amb_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Ambulance (Green)";
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Amb_FFR_Sand_A : UK3CB_BAF_LandRover_Amb_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Ambulance (Sand)";
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Amb_FFR_UN_A : UK3CB_BAF_LandRover_Amb_UN_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Ambulance (UN)";
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_Base : UK3CB_BAF_LandRover_Base {};
class UK3CB_BAF_LandRover_Hard_Green_A : UK3CB_BAF_LandRover_Hard_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_Hard_Arctic_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Hard_Green_B : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Hard_MERT_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_RAF_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Hard_Sand_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Hard_UN_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Hard_FFR_Arctic_A : UK3CB_BAF_LandRover_Hard_Arctic_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (Arctic)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_Green_A : UK3CB_BAF_LandRover_Hard_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_Green_B : UK3CB_BAF_LandRover_Hard_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_MERT_A : UK3CB_BAF_LandRover_Hard_MERT_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (MERT)";
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_RAF_A : UK3CB_BAF_LandRover_Hard_RAF_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (RAF Police)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_Sand_A : UK3CB_BAF_LandRover_Hard_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Hard_FFR_UN_A : UK3CB_BAF_LandRover_Hard_UN_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover HardTop (UN)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Snatch_Base : UK3CB_BAF_LandRover_Base {};
class UK3CB_BAF_LandRover_Snatch_Green_A : UK3CB_BAF_LandRover_Snatch_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_Snatch_NI_A : UK3CB_BAF_LandRover_Snatch_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Snatch_Police_A : UK3CB_BAF_LandRover_Snatch_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Snatch_Sand_A : UK3CB_BAF_LandRover_Snatch_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Snatch_FFR_Green_A : UK3CB_BAF_LandRover_Snatch_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Snatch (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Snatch_FFR_Sand_A : UK3CB_BAF_LandRover_Snatch_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Snatch (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Snatch_FFR_NI_A : UK3CB_BAF_LandRover_Snatch_NI_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Snatch (NI)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Snatch_FFR_Police_A : UK3CB_BAF_LandRover_Snatch_Police_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover Snatch (Police)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_Base : UK3CB_BAF_LandRover_Base {};
class UK3CB_BAF_LandRover_Soft_Green_A : UK3CB_BAF_LandRover_Soft_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_Soft_Arctic_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Soft_Green_B : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Soft_MERT_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_RAF_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Soft_Sand_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Soft_UN_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 0;
    scopeCurator = 0;
};
class UK3CB_BAF_LandRover_Soft_FFR_Arctic_A : UK3CB_BAF_LandRover_Soft_Arctic_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (Arctic)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_Green_A : UK3CB_BAF_LandRover_Soft_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_Green_B : UK3CB_BAF_LandRover_Soft_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_MERT_A : UK3CB_BAF_LandRover_Soft_MERT_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (MERT)";
    COVER_MEDICAL_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_RAF_A : UK3CB_BAF_LandRover_Soft_RAF_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (RAF Police)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_Sand_A : UK3CB_BAF_LandRover_Soft_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Soft_FFR_UN_A : UK3CB_BAF_LandRover_Soft_UN_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover SoftTop (UN)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_Base : UK3CB_BAF_LandRover_Base {
    class Turrets : Turrets {
        class GPMG_Turret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportWeapons;
};
class UK3CB_BAF_LandRover_WMIK_HMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class HMG_Turret : MainTurret {
            gunnerOpticsModel = "UK3CB_BAF_Vehicles\addons\UK3CB_BAF_Vehicles_Coyote_Jackal\Weapons\TA31F_Optic_x3";
            gunnerOpticsEffect[] = { "OpticsCHAbera1" };
            class ViewOptics {
                visionMode[] = {};
                initFov = 0.0623;
                minFov = 0.0623;
                maxFov = 0.0623;
            };
        };
    };
    class TransportWeapons : TransportWeapons {
        delete _xx_UK3CB_BAF_Javelin_CLU;
    };
    class TransportItems {
        MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,1);
    };
};
class UK3CB_BAF_LandRover_WMIK_HMG_Green_A : UK3CB_BAF_LandRover_WMIK_HMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_HMG_Green_B : UK3CB_BAF_LandRover_WMIK_HMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_HMG_Sand_A : UK3CB_BAF_LandRover_WMIK_HMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_HMG_FFR_Green_A : UK3CB_BAF_LandRover_WMIK_HMG_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK HMG (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_HMG_FFR_Green_B : UK3CB_BAF_LandRover_WMIK_HMG_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK HMG (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_HMG_FFR_Sand_A : UK3CB_BAF_LandRover_WMIK_HMG_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK HMG (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GPMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class GPMG_2_Turret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportWeapons : TransportWeapons {
        delete _xx_UK3CB_BAF_Javelin_CLU;
    };
    class TransportItems {
        MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,1);
    };
};
class UK3CB_BAF_LandRover_WMIK_GPMG_Green_A : UK3CB_BAF_LandRover_WMIK_GPMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GPMG_Green_B : UK3CB_BAF_LandRover_WMIK_GPMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GPMG_Sand_A : UK3CB_BAF_LandRover_WMIK_GPMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GPMG_FFR_Green_A : UK3CB_BAF_LandRover_WMIK_GPMG_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GPMG (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GPMG_FFR_Green_B : UK3CB_BAF_LandRover_WMIK_GPMG_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GPMG (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GPMG_FFR_Sand_A : UK3CB_BAF_LandRover_WMIK_GPMG_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GPMG (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GMG_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class GMG_Turret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
    class TransportWeapons : TransportWeapons {
        delete _xx_UK3CB_BAF_Javelin_CLU;
    };
    class TransportItems {
        MACRO_ADDITEM(UK3CB_BAF_Javelin_CLU,1);
    };
};
class UK3CB_BAF_LandRover_WMIK_GMG_Green_A : UK3CB_BAF_LandRover_WMIK_GMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GMG_Green_B : UK3CB_BAF_LandRover_WMIK_GMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GMG_Sand_A : UK3CB_BAF_LandRover_WMIK_GMG_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_GMG_FFR_Green_A : UK3CB_BAF_LandRover_WMIK_GMG_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GMG (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GMG_FFR_Green_B : UK3CB_BAF_LandRover_WMIK_GMG_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GMG (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_GMG_FFR_Sand_A : UK3CB_BAF_LandRover_WMIK_GMG_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK GMG (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_Milan_Base : UK3CB_BAF_LandRover_WMIK_Base {
    class Turrets : Turrets {
        class Milan_Turret : MainTurret {
            class ViewOptics {
                visionMode[] = {};
            };
        };
    };
};
class UK3CB_BAF_LandRover_WMIK_Milan_Green_A : UK3CB_BAF_LandRover_WMIK_Milan_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_Milan_Green_B : UK3CB_BAF_LandRover_WMIK_Milan_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_Milan_Sand_A : UK3CB_BAF_LandRover_WMIK_Milan_Base {
    scope = 0;
    scopeCurator = 0;
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
};
class UK3CB_BAF_LandRover_WMIK_Milan_FFR_Green_A : UK3CB_BAF_LandRover_WMIK_Milan_Green_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK Milan (Green)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_Milan_FFR_Green_B : UK3CB_BAF_LandRover_WMIK_Milan_Green_B {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK Milan (Green/Black)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_WMIK_Milan_FFR_Sand_A : UK3CB_BAF_LandRover_WMIK_Milan_Sand_A {
    scope = 2;
    scopeCurator = 2;
    displayname = "Land Rover WMIK Milan (Sand)";
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Panama_Base : UK3CB_BAF_LandRover_Base {};
class UK3CB_BAF_LandRover_Panama_Green_A : UK3CB_BAF_LandRover_Panama_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    COVER_ACTIONS
};
class UK3CB_BAF_LandRover_Panama_Sand_A : UK3CB_BAF_LandRover_Panama_Base {
    faction = "CUP_B_GB";
    crew = "CUP_B_BAF_Soldier_MTP";
    typicalCargo[] = { "CUP_B_BAF_Soldier_MTP" };
    COVER_ACTIONS
};
