#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Animals_F_Snakes",
            "A3_Armor_F_Beta",
            "A3_Armor_F_Beta_APC_Tracked_01",
            "A3_Armor_F_Beta_APC_Tracked_02",
            "A3_Armor_F_Beta_APC_Wheeled_01",
            "A3_Armor_F_Beta_APC_Wheeled_02",
            "A3_Armor_F_EPB_APC_Tracked_03",
            "A3_Armor_F_EPB_MBT_03",
            "A3_Armor_F_Exp_APC_Wheeled_02",
            "A3_Armor_F_Gamma_APC_Wheeled_03",
            "A3_Armor_F_Gamma_MBT_01",
            "A3_Armor_F_Gamma_MBT_02",
            "A3_Armor_F_Tank_AFV_Wheeled_01",
            "A3_Armor_F_Tank_LT_01",
            "A3_Armor_F_Tank_MBT_04",
            "A3_Boat_F",
            "A3_Boat_F_Beta_Boat_Transport_01",
            "A3_Boat_F_Boat_Transport_01",
            "A3_Boat_F_Gamma_Boat_Transport_01",
            "A3_Characters_expEden_Loyalists",
            "A3_Characters_expEden_proAAF",
            "A3_Data_F",
            "A3_Data_F_AoW_Loadorder",
            "A3_Data_F_Curator",
            "A3_Data_F_ParticleEffects",
            "A3_Drones_F_Air_F_Gamma_UAV_02",
            "A3_Dubbing_Radio_F",
            "A3_Dubbing_Radio_F_Enoch",
            "A3_Dubbing_Radio_F_EXP",
            "A3_expEden",
            "A3_expEden_characters",
            "A3_Props_F_Enoch_Military_Equipment",
            "A3_Props_F_Globe_Civilian_Gallery",
            "A3_Props_F_Globe_Civilian_InfoBoards",
            "A3_Props_F_Globe_Items",
            "A3_Props_F_Globe_Items_Decorative",
            "A3_Props_F_Globe_Items_Documents",
            "A3_Props_F_Globe_Military_Ammo",
            "A3_Props_F_Globe_Military_Camps",
            "A3_Props_F_Globe_Military_Equipment",
            "A3_Soft_F",
            "A3_Soft_F_Beta_MRAP_03",
            "A3_Soft_F_Beta_Truck_01",
            "A3_Soft_F_Beta_Truck_02",
            "A3_Soft_F_Enoch_UGV_02",
            "A3_Soft_F_EPC_Truck_03",
            "A3_Soft_F_Exp_LSV_01",
            "A3_Soft_F_Exp_Offroad_02",
            "A3_Soft_F_Gamma_Hatchback_01",
            "A3_Soft_F_Gamma_Truck_01",
            "A3_Soft_F_Gamma_Van_01",
            "A3_Soft_F_Orange_Van_02",
            "A3_Sounds_F",
            "A3_Sounds_F_Exp",
            "A3_Sounds_F_Tank",
            "A3_Static_F",
            "A3_Static_F_AA_01",
            "A3_Static_F_AT_01",
            "A3_Static_F_HMG_02_ScopeShieldDeMount_a3_expEden",
            "A3_Static_F_Jets_AAA_System_01",
            "A3_Static_F_Jets_SAM_System_01",
            "A3_Static_F_Jets_SAM_System_02",
            "A3_Structures_F_Argo_Walls_Net",
            "A3_Structures_F_Argo_Walls_Pipe",
            "A3_Structures_F_Argo_Walls_Tin",
            "A3_Structures_F_Enoch_Walls_Pipe",
            "A3_Structures_F_EPB_Civ_Camping",
            "A3_Structures_F_Globe_Infrastructure",
            "A3_Structures_F_Globe_Items_Electronics",
            "A3_Structures_F_Naval_Buoys",
            "A3_Weapons_F_Ammoboxes",
            "A3_Weapons_F_Globe_Items",
            "ace_aircraft",
            "ace_ballistics",
            "ace_cargo",
            "ace_cookoff",
            "ace_dragging",
            "ace_fastroping",
            "ace_frag",
            "ace_hot",
            "ace_hunterkiller",
            "ace_interaction",
            "ace_logistics_uavbattery",
            "ace_markinglaser",
            "ace_medical_damage",
            "ace_medical_treatment",
            "ace_missile_manpad",
            "ace_missile_sam",
            "ace_overpressure",
            "ace_realisticnames",
            "ace_realisticweights",
            "ace_rearm",
            "ace_refuel",
            "ace_reloadlaunchers",
            "ace_repair",
            "ace_tagging",
            "ace_thermals",
            "ace_vehicle_damage",
            "ace_vehicles",
            "acre_sys_attenuate",
            "acre_sys_intercom",
            "acre_sys_rack",
            "cba_jam",
            "cba_xeh",
            "uksf_immersion",
            "uksf_vehicles"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers_base;
class Mode_SemiAuto;

class CfgVehicles {
    #include "CfgVehicles_base.hpp"
    #include "CfgVehicles_men.hpp"
    #include "CfgVehicles_objects.hpp"
    #include "CfgVehicles_structures.hpp"
    #include "CfgVehicles_cars.hpp"
    #include "CfgVehicles_trucks.hpp"
    #include "CfgVehicles_apcs.hpp"
    #include "CfgVehicles_tanks.hpp"
    #include "CfgVehicles_boats.hpp"
    #include "CfgVehicles_statics.hpp"
};

class CfgCloudlets {
    #include "CfgCloudlets.hpp"
};

class CfgVoiceTypes {
    #include "CfgVoiceTypes.hpp"
};

class CfgWeapons {
    #include "CfgWeapons.hpp"
};

class CfgAmmo {
    #include "CfgAmmo.hpp"
};
