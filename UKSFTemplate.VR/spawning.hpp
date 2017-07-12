/*
    Author:
        Tim Beswick

    Description:
        Initialises spawning

        Parameters for function call:
            0: position - This can be a marker name passed as a string, a trigger object, or a location
            1: maxGroupsActive (default: 5) - The maximum number of groups that will be active on this position at any time
            2: groupPoolSize (default: 10) - The total number of enemy groups that will ever spawn on this position
            3: factionName (default: "") - The name of the faction to spawn

        Format: 
            ["markername"/trigger object/location, maxGroupsActive, groupPoolSize, factionName] call uksf_spawn_fnc_initPatrol;

        Examples:
            Marker: ["markerName", 10, 15, "CUP_O_RU"] call uksf_spawn_fnc_initPatrol; (NOTE: The marker name must be given)
            Trigger: [thisTrigger, 4, 100, "CUP_I_UN"] call uksf_spawn_fnc_initPatrol; (NOTE: The trigger object)
            Location: [location, 10, 15, "CUP_B_GB"] call uksf_spawn_fnc_initPatrol; (NOTE: Custom locations will not work)

        Markers must be area markers. In editor: Markers > Areas (Circle overlapping rectangle icon)
*/
//EXAMPLE:
//["area1", 3, 10, "CUP_O_RU"] call uksf_spawn_fnc_initPatrol;


/* VALID FACTION NAMES:
    "BLU_F"
    "Guerilla"
    "CUP_B_CZ"
    "CUP_B_GB"
    "CUP_B_CDF"
    "CUP_B_US_Army"
    "CUP_B_USMC"
    "CUP_B_GER"
    "BLU_T_F"
    "BLU_CTRG_F"
    "OPF_F"
    "CUP_O_ChDKZ"
    "CUP_O_RU"
    "CUP_O_TK"
    "CUP_O_TK_MILITIA"
    "CUP_O_SLA"
    "OPF_T_F"
    "VR_Army"
    "IND_F"
    "CUP_I_NAPA"
    "CUP_I_PMC_ION"
    "CUP_I_UN"
    "CUP_I_TK_GUE"
    "CUP_I_RACS"
    "IND_C_F"
*/
