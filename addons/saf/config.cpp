#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            QGVAR(Soldier_Underwear),
            QGVAR(Soldier_Base),
            QGVAR(Rifleman),
            QGVAR(Grenadier),
            QGVAR(Squad_Leader),
            QGVAR(Rifleman_LAT),
            QGVAR(Sharpshooter),
            QGVAR(Machine_Gunner),
            QGVAR(Rifleman_HAT),
            QGVAR(Officer),
            QGVAR(Heli_Pilot),
            QGVAR(Jet_Pilot),
            QGVAR(Sniper),
            QGVAR(Crewman),
            QGVAR(Rifleman_AA),
            QGVAR(Officer_HQ),
            QGVAR(Signaller),

            // SF
            QGVAR(sf_operator),
            QGVAR(sf_grenadier),
            QGVAR(sf_autorifleman),
            QGVAR(sf_HAT),

            // Trucks
            QGVAR(Kamaz_Covered),
            QGVAR(Kamaz_Ammo),
            QGVAR(Kamaz_Refuel),
            QGVAR(Kamaz_Repair),

            // Cars
            QGVAR(matv_hmg),
            QGVAR(matv_gmg),
            QGVAR(m1151_m2),
            QGVAR(m1151_m240),
            QGVAR(m1151_mk19),
            QGVAR(m1151),
            QGVAR(rg31_m2),
            QGVAR(rg31_mk19),

            // APCs
            QGVAR(borsuk),
            QGVAR(rosomak),

            // Tanks
            QGVAR(leopard2A6),
            QGVAR(m1a1),

            // Artillery
            QGVAR(kamaz_MRL),
            QGVAR(RM70),

            // Anti Air
            QGVAR(zsu23),
            QGVAR(avenger),
            QGVAR(VADS),
            QGVAR(zu23),

            // Helis
            QGVAR(AH64),
            QGVAR(AW159),
            QGVAR(CH146),

            // Planes
            QGVAR(harrier),
            QGVAR(c130),
            QGVAR(blackwasp),

            // statics
            QGVAR(podnos),
            QGVAR(dshkm),
            QGVAR(dshkm_low),
            QGVAR(mk19)
        };
        weapons[] = {
            QGVAR(grot),
            QGVAR(grot_gl),
            QGVAR(grot_mr),
            QGVAR(m2010),
            QGVAR(hk416),
            QGVAR(hk416_gl),
            QGVAR(minimi)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"uksf_common", "uksf_cdf", "uksf_vaf"};
        author = QUOTE(UKSF);
        authors[] = {"Bridgford.A"};
        url = URL;
        VERSION_CONFIG;
    };
};

class CfgWorlds {
    class GenericNames {
        class PolishMen {
            class FirstNames {
                firstName1 = "Jan";
                firstName2 = "Piotr";
                firstName3 = "Andrzej";
                firstName4 = "Krzysztof";
                firstName5 = "Marek";
                firstName6 = "Tomasz";
                firstName7 = "Paweł";
                firstName8 = "Michał";
                firstName9 = "Adam";
                firstName10 = "Stanisław";
                firstName11 = "Grzegorz";
                firstName12 = "Łukasz";
                firstName13 = "Wojciech";
                firstName14 = "Marcin";
                firstName15 = "Jakub";
                firstName16 = "Mateusz";
                firstName17 = "Rafał";
                firstName18 = "Damian";
                firstName19 = "Sebastian";
                firstName20 = "Szymon";
            };
            class LastNames {
                lastName1 = "Nowak";
                lastName2 = "Kowalski";
                lastName3 = "Wiśniewski";
                lastName4 = "Wójcik";
                lastName5 = "Kowalczyk";
                lastName6 = "Kamiński";
                lastName7 = "Lewandowski";
                lastName8 = "Zieliński";
                lastName9 = "Szymański";
                lastName10 = "Woźniak";
                lastName11 = "Dąbrowski";
                lastName12 = "Kozłowski";
                lastName13 = "Jankowski";
                lastName14 = "Mazur";
                lastName15 = "Kwiatkowski";
                lastName16 = "Krawczyk";
                lastName17 = "Piotrowski";
                lastName18 = "Grabowski";
                lastName19 = "Nowicki";
                lastName20 = "Pawlowski";
            };
        };
    };
};

#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

