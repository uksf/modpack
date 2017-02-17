class CfgVehicles {
    #include "units\CfgScopeZero.hpp"
    #include "units\CfgReg.hpp"
    #include "units\CfgSpecial.hpp"

    #include "vehicles\CfgHilux.hpp"
    #include "vehicles\CfgUaz.hpp"
    #include "vehicles\CfgStatic.hpp"
    #include "vehicles\CfgSpecial.hpp"

    class B_Carryall_khk;
    class Laraka_B_PKM: B_Carryall_khk {
        scope = 1;
        author = "UKSF";
        displayName = "PKM/PKP Pack";
        class TransportMagazines {
            class _xx_rhs_100Rnd_762x54mmR_green {
                magazine = "rhs_100Rnd_762x54mmR_green";
                count = 6;
            };
        };
    };
    class Laraka_B_RPG: Laraka_B_PKM {
        displayName = "RPG Pack";
        class TransportMagazines {
            class _xx_rhs_rpg7_PG7VL_mag {
                magazine = "rhs_rpg7_PG7VL_mag";
                count = 8;
            };
        };
    };
    class Laraka_B_AA: Laraka_B_PKM {
        displayName = "AA Pack";
        class TransportMagazines {
            class _xx_rhs_mag_9k32_rocket {
                magazine = "rhs_mag_9k32_rocket";
                count = 6;
            };
        };
    };
};