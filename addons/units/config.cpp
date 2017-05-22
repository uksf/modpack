#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "UKSF_B_Rifleman",
            "UKSF_B_Officer",
            "UKSF_B_SectionLeader",
            "UKSF_B_MachineGunner",
            "UKSF_B_AntiTank",
            "UKSF_B_Medic",
            "UKSF_B_Sniper",
            "UKSF_B_Pilot_7",
            "UKSF_B_Pilot_656",
            "UKSF_B_Pilot_617",
            "UKSF_TK_Civ_Mullah",
            "UKSF_TK_Civ_Sheikh",
            "UKSF_TK_Civ_1",
            "UKSF_TK_Civ_2",
            "UKSF_TK_Civ_3",
            "UKSF_TK_Civ_4",
            "UKSF_TK_Civ_5",
            "UKSF_TK_Civ_6",
            "UKSF_TK_Civ_7"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "uksf_gear",
            "CUP_Creatures_People_Civil_Chernarus",
            "CUP_Creatures_People_Civil_Russia",
            "CUP_Creatures_Military_ACR",
            "CUP_Creatures_Military_BAF",
            "CUP_Creatures_Military_CDF",
            "CUP_Creatures_Military_Chedaki",
            "CUP_Creatures_People_Military_DummyInfantrySet",
            "CUP_Creatures_Military_Germany",
            "CUP_Creatures_Military_NAPA",
            "CUP_Creatures_Military_PMC",
            "CUP_Creatures_Military_RACS",
            "CUP_Creatures_Military_Russia",
            "CUP_Creatures_Military_SLA",
            "CUP_Creatures_Military_Taki",
            "CUP_Creatures_Military_TakiInsurgents",
            "CUP_Creatures_Military_USArmy",
            "CUP_Creatures_Military_USMC"
        };
        author = QUOTE(UKSF);
        authors[] = { "Beswick.T" };
        url = QUOTE(www.uk-sf.com);
        VERSION_CONFIG;
    };
};

class cba_Extended_EventHandlers;
#include "CfgGroups.hpp"
#include "CfgVehicles.hpp"
