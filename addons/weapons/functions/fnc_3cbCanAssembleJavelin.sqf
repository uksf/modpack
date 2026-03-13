#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Return if javelin can be assembled

    Parameters:
        None

    Return value:
        Boolean

    Example:
        call uksf_weapons_fnc_3cbCanAssembleJavelin
*/

alive ACE_player &&
{"UK3CB_BAF_Javelin_CLU" in (backpackItems ACE_player)} &&
{"UK3CB_BAF_Javelin_Slung_Tube" isEqualTo (secondaryWeapon ACE_player) ||
{"UK3CB_BAF_Javelin_Slung_Tube_Used" isEqualTo (secondaryWeapon ACE_player)}}
