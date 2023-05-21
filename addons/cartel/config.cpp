#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // militia
            QGVAR(militia_aksu),
            QGVAR(militia_mac10),
            QGVAR(militia_mac10_rshg),
            QGVAR(militia_aks74),
            QGVAR(militia_bizon),
            QGVAR(militia_enfield),
            QGVAR(militia_mp5),
            QGVAR(militia_galil),
            QGVAR(militia_ak74_gl),
            QGVAR(militia_rpk),
            QGVAR(militia_aks),
            QGVAR(militia_vikhr),

            // armed civs
            QGVAR(armed_civ_1911),
            QGVAR(armed_civ_cz75),
            QGVAR(armed_civ_cz550),

            // couriers
            QGVAR(courier_mac10),
            QGVAR(courier_tec9),

            // commandos
            QGVAR(commando_g3a3),
            QGVAR(commando_mp5_bunkerfaust),
            QGVAR(commando_g36_gl),
            QGVAR(commando_hk416),
            QGVAR(commando_hk416_drum),
            QGVAR(commando_vintorez),
            QGVAR(commando_ak74_rpg),
            QGVAR(commando_ak74),
            QGVAR(commando_saiga),
            QGVAR(commando_rpk),

            // vehicles
            QGVAR(small_truck),
            QGVAR(hilux_white),
            QGVAR(hilux_red),
            QGVAR(datsun),
            QGVAR(kamaz),
            QGVAR(van)
        };
        weapons[] = {
            QGVAR(Mac10_suppressed),
            QGVAR(LeeEnfield_no32),
            QGVAR(G3A3_modern_ris_black_burris_anpeq_flash_hider),
            QGVAR(MP5A5_t1),
            QGVAR(G36A3_AG36_t1_laser),
            QGVAR(HK416_CQB_Black_t1_laser),
            QGVAR(HK416_Black_barska_laser),
            QGVAR(VSSVintorez_VFG_pso1_laser),
            QGVAR(saiga9_1p87),
            QGVAR(RPK74M_1p63_laser)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common",
            "ace_medical_treatment",
            "CUP_Weapons_LoadOrder",
            "CUP_Creatures_People_LoadOrder"
        };
        author = QUOTE(UKSF);
        authors[] = { "Bridgford.A" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;

#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

class CfgWorlds {
    class GenericNames {
        class SpanishMen {
            class FirstNames {
                Carlos = "Carlos";
                Javier = "Javier";
                Luis = "Luis";
                Alejandro = "Alejandro";
                Miguel = "Miguel";
                Antonio = "Antonio";
                Juan = "Juan";
                Manuel = "Manuel";
                Pedro = "Pedro";
                Jorge = "Jorge";
                Fernando = "Fernando";
                Ricardo = "Ricardo";
                Jose = "Jose";
                Diego = "Diego";
                Francisco = "Francisco";
                Gabriel = "Gabriel";
                Andres = "Andres";
                Raul = "Raul";
                Hugo = "Hugo";
                Santiago = "Santiago";
                Ignacio = "Ignacio";
                Roberto = "Roberto";
                Ernesto = "Ernesto";
                Guillermo = "Guillermo";
                Emilio = "Emilio";
                Benjamin = "Benjamin";
                Octavio = "Octavio";
                Rodrigo = "Rodrigo";
                Eduardo = "Eduardo";
                Hector = "Hector";
            };
            class LastNames {
                Garcia = "Garcia";
                Rodriguez = "Rodriguez";
                Gonzalez = "Gonzalez";
                Hernandez = "Hernandez";
                Lopez = "Lopez";
                Martinez = "Martinez";
                Perez = "Perez";
                Sanchez = "Sanchez";
                Ramirez = "Ramirez";
                Torres = "Torres";
                Flores = "Flores";
                Rivera = "Rivera";
                Gomez = "Gomez";
                Diaz = "Diaz";
                Reyes = "Reyes";
                Morales = "Morales";
                Cruz = "Cruz";
                Ortiz = "Ortiz";
                Romero = "Romero";
                Vargas = "Vargas";
                Santos = "Santos";
                Castillo = "Castillo";
                Mendoza = "Mendoza";
                Delgado = "Delgado";
                Ramos = "Ramos";
                Cortez = "Cortez";
                Chavez = "Chavez";
                Guzman = "Guzman";
                Soto = "Soto";
                Mejia = "Mejia";
            };
        };
    };
};
