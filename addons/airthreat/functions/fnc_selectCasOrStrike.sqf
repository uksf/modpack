#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Selects and spawns either a CAS or strike mission based on the
        zone's configured CAS probability. Server only.

    Parameters:
        0: CAS probability <NUMBER> - Percentage chance of CAS (0-100)

    Return Value:
        Nothing

    Example:
        [50] call uksf_airthreat_fnc_selectCasOrStrike
*/
params [["_casProbability", 50, [0]]];

if (random 100 < _casProbability) then {
    call FUNC(cas);
} else {
    call FUNC(strike);
};
