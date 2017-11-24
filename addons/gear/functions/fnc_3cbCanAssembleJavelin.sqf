/*
    Author:
        Tim Beswick

    Description:
        Return if javelin can be assembled

    Parameters:
        None

    Return value:
        Boolean
*/
#include "script_component.hpp"

alive ACE_player &&
{"UK3CB_BAF_Javelin_CLU" in (backpackItems ACE_player)} &&
{"UK3CB_BAF_Javelin_Slung_Tube" isEqualTo (secondaryWeapon ACE_player) ||
{"UK3CB_BAF_Javelin_Slung_Tube_Used" isEqualTo (secondaryWeapon ACE_player)}}
