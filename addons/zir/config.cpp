#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Militia_akn),
            QGVAR(Militia_gp25),
            QGVAR(Militia_MG),
            QGVAR(Militia_LAT),
            QGVAR(Militia_sks),
            QGVAR(Militia_sks),
            QGVAR(Militia_aa),
            QGVAR(Militia_enfield),

            // QGVAR(T55),

            // QGVAR(Patriot),

            // QGVAR(Wiesel_MK20),

            // QGVAR(Gripen),

            // QGVAR(CH146_Tpt),

            // QGVAR(ZU23)
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

