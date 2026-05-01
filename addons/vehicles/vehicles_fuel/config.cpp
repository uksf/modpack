#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

// ace_refuel_fuelCapacity overrides at the CUP/vanilla base class level for ground
// and water vehicles not directly customised by UKSF. Real-world litres where known;
// vanilla fuelCapacity left untouched so engine timing stays intact.
class CfgVehicles {
    // ─── Sea ───────────────────────────────────────────────────────────────

    class Ship_F;
    class Boat_F;

    // Vanilla A3 small RIB (used by UKSF dive ops)
    class Boat_Transport_02_base_F : Boat_F {
        ace_refuel_fuelCapacity = 200; // Zodiac MK-V / RHIB analogue: ~200 L
    };

    class SDV_01_base_F : Boat_F {
        ace_refuel_fuelCapacity = 120; // SDV mini-sub (electric, fictional): keep game value
    };

    // CUP boats (real-world values where known)
    class CUP_LCVP_Base : Ship_F {
        ace_refuel_fuelCapacity = 800; // LCVP Mk.1 / Higgins boat: ~800 L
    };

    class CUP_LCU1600_Base : Ship_F {
        ace_refuel_fuelCapacity = 9500; // LCU-1610: ~9,500 L (large diesel)
    };

    class CUP_ZUBR_Base : Ship_F {
        ace_refuel_fuelCapacity = 56000; // Zubr-class LCAC (Project 12322): ~56,000 L marine diesel
    };

    class CUP_MK10_Base : Ship_F {
        ace_refuel_fuelCapacity = 1500; // Mk.10 landing craft: ~1,500 L
    };

    class CUP_Seafox_Base : Ship_F {
        ace_refuel_fuelCapacity = 600; // Seafox surface combatant boat (small): ~600 L
    };

    class CUP_Fishing_Boat_Base : Ship_F {
        ace_refuel_fuelCapacity = 800; // Small fishing boat: ~800 L
    };

    class CUP_Hovercraft_Base : Ship_F {
        ace_refuel_fuelCapacity = 1200; // Small hovercraft: ~1,200 L
    };

    class CUP_RHIB_Base : Ship_F {
        ace_refuel_fuelCapacity = 200; // Rigid-Hull Inflatable Boat: ~200 L
    };

    // Large warship — Project 11541 Russian frigate
    class CUP_Frigate_Base : Ship_F {
        ace_refuel_fuelCapacity = 700000; // Frigate-class diesel bunker: ~700,000 L
    };

    // HAFM Navy (Hellenic Armed Forces Mod) — naval bases
    class HAFM_RHIB : Ship_F {
        ace_refuel_fuelCapacity = 200; // RHIB / fast small boat: ~200 L
    };

    class HAFM_CB90 : Ship_F {
        ace_refuel_fuelCapacity = 6500; // Combat Boat 90 (CB90) fast attack craft: ~6,500 L
    };

    class HAFM_GunBoat : Ship_F {
        ace_refuel_fuelCapacity = 5000; // Patrol gunboat: ~5,000 L
    };

    class HAFM_MEKO_TN : Ship_F {
        ace_refuel_fuelCapacity = 700000; // MEKO 200 frigate: ~700,000 L diesel
    };

    class HAFM_FREMM : Ship_F {
        ace_refuel_fuelCapacity = 700000; // FREMM multipurpose frigate: ~700,000 L
    };

    class HAFM_BUYAN : Ship_F {
        ace_refuel_fuelCapacity = 50000; // Buyan-M corvette: ~50,000 L
    };

    class HAFM_Admiral : Ship_F {
        ace_refuel_fuelCapacity = 250000; // Slava-class cruiser analogue: ~250,000 L
    };

    class HAFM_Replenishment : Ship_F {
        ace_refuel_fuelCapacity = 5000000; // Replenishment oiler / fleet tanker: ~5,000,000 L
    };

    class HAFM_Russen : Ship_F {
        ace_refuel_fuelCapacity = 250000; // Udaloy-class destroyer analogue: ~250,000 L
    };

    class HAFM_ABurke : Ship_F {
        ace_refuel_fuelCapacity = 9000; // Arleigh Burke-class destroyer (gas turbine): ~9,000 L
    };

    class HAFM_052C : Ship_F {
        ace_refuel_fuelCapacity = 6000; // Type 052C destroyer (gas turbine): ~6,000 L
    };
};
