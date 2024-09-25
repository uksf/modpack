#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(militia_akn),
            QGVAR(militia_gp25),
            QGVAR(militia_MG),
            QGVAR(militia_LAT),
            QGVAR(militia_sks),
            QGVAR(militia_aa),
            QGVAR(militia_enfield),
            QGVAR(militia_sniper),

            QGVAR(pg_soldier),
            QGVAR(pg_commander),

            QGVAR(hilux),
            QGVAR(hilux_full),
            QGVAR(hilux_dhskm),
            QGVAR(hilux_ags),
            QGVAR(hilux_spg9),
            QGVAR(hilux_ub32),
            QGVAR(hilux_podnos),
            QGVAR(hilux_zu23),

            QGVAR(praga_full),
            QGVAR(praga_covered_full)
        };
        weapons[] = {
            QGVAR(enfield_burris),
            QGVAR(cz750_mr10)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgEventHandlers.hpp"
#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

class CfgWorlds {
    class GenericNames {
        class ZirMen {
            class FirstNames {
                Ahmad = "Ahmad";
                Farid = "Farid";
                Khalid = "Khalid";
                Naseer = "Naseer";
                Omar = "Omar";
                Hassan = "Hassan";
                Sajjad = "Sajjad";
                Yusuf = "Yusuf";
                Rahim = "Rahim";
                Feroz = "Feroz";
                Karim = "Karim";
                Haroon = "Haroon";
                Jamshid = "Jamshid";
                Waheed = "Waheed";
                Mahmood = "Mahmood";
                Rashid = "Rashid";
                Zubair = "Zubair";
                Jawed = "Jawed";
                Asad = "Asad";
                Faisal = "Faisal";
                Naveed = "Naveed";
                Zahir = "Zahir";
                Tariq = "Tariq";
                Arif = "Arif";
                Qasim = "Qasim";
                Ihsan = "Ihsan";
                Sami = "Sami";
                Faiz = "Faiz";
                Shafiq = "Shafiq";
                Zaman = "Zaman";
            };
            class LastNames {
                Ahmadi = "Ahmadi";
                Farooqi = "Farooqi";
                Khalili = "Khalili";
                Naseeri = "Naseeri";
                Omarzai = "Omarzai";
                Hassani = "Hassani";
                Sajjadi = "Sajjadi";
                Yousafzai = "Yousafzai";
                Rahimi = "Rahimi";
                Ferozi = "Ferozi";
                Karimi = "Karimi";
                Harooni = "Harooni";
                Jamshidi = "Jamshidi";
                Waheedi = "Waheedi";
                Mahmoodi = "Mahmoodi";
                Rashidi = "Rashidi";
                Zubairi = "Zubairi";
                Jawedi = "Jawedi";
                Asadi = "Asadi";
                Faisali = "Faisali";
                Naveedi = "Naveedi";
                Zahiri = "Zahiri";
                Tariqi = "Tariqi";
                Arifi = "Arifi";
                Qasimi = "Qasimi";
                Ihsani = "Ihsani";
                Samimi = "Samimi";
                Faizi = "Faizi";
                Shafiqi = "Shafiqi";
                Zamani = "Zamani";
            };
        };
    };
};

