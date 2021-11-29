#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "uksf_Base_Rifleman",
            "uksf_Base_LMG",
            "uksf_Base_MG",
            "uksf_Base_MG_Ammobearer",
            "uksf_Base_LAT",
            "uksf_Base_HAT",
            "uksf_Base_HAT_Ammobearer",
            "uksf_Base_SL",
            "uksf_Base_Marksman",
            "uksf_Base_Sniper",
            "uksf_Base_Officer",
            "uksf_Base_RadioOperator",
            "uksf_Base_Crewman",
            "uksf_Base_AA",
            "uksf_Base_HeliPilot",
            "uksf_Base_JetPilot",

            "uksf_Base_Paratrooper",
            "uksf_Base_Paratrooper_MG",
            "uksf_Base_Paratrooper_LAT",
            "uksf_Base_Paratrooper_SL",
            "uksf_Base_Paratrooper_Marksman",
            "uksf_Base_Paratrooper_RadioOperator",

            "uksf_Base_Recce_Rifleman",
            "uksf_Base_Recce_LAT",
            "uksf_Base_Recce_Marksman",
            "uksf_Base_Recce_TL",
            "uksf_Base_Recce_RadioOperator",
            "uksf_Base_Recce_MG",
            "uksf_Base_Recce_Officer",

            "uksf_Base_SF_Operator",
            "uksf_Base_SF_MG",
            "uksf_Base_SF_LAT",
            "uksf_Base_SF_Officer",
            "uksf_Base_SF_Marksman",
            "uksf_Base_SF_TL",
            "uksf_Base_SF_RadioOperator",
        };
        weapons[] = {};

        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_main",
            "uksf_common"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = URL;
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgGroups.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

/*
class CfgWorlds {
    class GenericNames {
        class FrenchMen {
            class FirstNames {
                Nathan = "Nathan";
                Lucas = "Lucas";
                Leo = "Léo";
                Enzo = "Enzo";
                Louis = "Louis";
                Gabriel = "Gabriel";
                Jules = "Jules";
                Timeo = "Timéo";
                Hugo = "Hugo";
                Arthur = "Arthur";
                Ethan = "Ethan";
                Raphael = "Raphaël";
                Mael = "Maël";
                Tom = "Tom";
                Noah = "Noah";
                Mathis = "Mathis";
                Theo = "Théo";
                Adam = "Adam";
                Nolan = "Nolan";
                Clement = "Clément";
                Nicolas = "Nicolas";
                Pierre = "Pierre";
                David = "David";
                Sebastien = "Sébastien";
                Thomas = "Thomas";
                Alexandre = "Alexandre";
                Vincent = "Vincent";
                Romain = "Romain";
                Antoine = "Antoine";
                Kevin = "Kévin";
                Mathieu = "Mathieu";
                Arnaud = "Arnaud";
                Paul = "Paul";
                Florian = "Florian";
                Alexis = "Alexis";
                Quentin = "Quentin";
                Loic = "Loïc";
                Valentin = "Valentin";
                Matthieu = "Matthieu";
                Adrien = "Adrien";
                Julien = "Julien";
                Anthony = "Anthony";
                Come = "Côme";
                Jacques = "Jacques";
                Ludovic = "Ludovic";
                Benoit = "Benoît";
                Jonathan = "Jonathan";
                Pierre_olivier = "Pierre-Olivier";
                Pierre_nicolas = "Pierre-Nicolas";
            };
            class LastNames {
                Martin = "Martin";
                Bernard = "Bernard";
                Dubois = "Dubois";
                Robert = "Robert";
                Richard = "Richard";
                Petit = "Petit";
                Durand = "Durand";
                Leroy = "Leroy";
                Moreau = "Moreau";
                Simon = "Simon";
                Laurent = "Laurent";
                Lefebvre = "Lefebvre";
                Michel = "Michel";
                Garcia = "Garcia";
                Bertrand = "Bertrand";
                Roux = "Roux";
                Fournier = "Fournier";
                Morel = "Morel";
                Girard = "Girard";
                Andre = "Andre";
                Lefevre = "Lefevre";
                Mercier = "Mercier";
                Dupont = "Dupont";
                Lambert = "Lambert";
                Bonnet = "Bonnet";
                Martinez = "Martinez";
                Legrand = "Legrand";
                Garnier = "Garnier";
                Faure = "Faure";
                Rousseau = "Rousseau";
                Blanc = "Blanc";
                Guerin = "Guerin";
                Muller = "Muller";
                Henry = "Henry";
                Roussel = "Roussel";
                Perrin = "Perrin";
                Morin = "Morin";
                Gauthier = "Gauthier";
                Dumont = "Dumont";
                Lopez = "Lopez";
                Fontaine = "Fontaine";
                Chevalier = "Chevalier";
                Robin = "Robin";
                Masson = "Masson";
                Sanchez = "Sanchez";
                Gerard = "Gerard";
                Boyer = "Boyer";
                Lemaire = "Lemaire";
                Benoist = "Benoist";
            };
        };
    };
};
*/