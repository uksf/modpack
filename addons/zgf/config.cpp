#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(soldier_akn),
            QGVAR(soldier_gp25),
            QGVAR(soldier_MG),
            QGVAR(soldier_LAT),
            QGVAR(soldier_sks),
            QGVAR(soldier_aa),
            QGVAR(soldier_enfield),
            QGVAR(officer),

            QGVAR(tigr_transport),
            QGVAR(tigr_transport_full),
            QGVAR(tigr_command),
            QGVAR(tigr_pk),
            QGVAR(tigr_kord),

            QGVAR(tatra_transport),
            QGVAR(tatra_transport_full),
            QGVAR(tatra_ammo),
            QGVAR(tatra_fuel),
        };
        weapons[] = {
            QGVAR(enfield_burris)
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
        class ZgfMen {
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

