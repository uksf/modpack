#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Return if javelin can be disassembled

    Parameters:
        None

    Return value:
        Boolean

    Example:
        call UK3CB_BAF_Weapons_Launchers_fnc_can_disassemble_javelin
*/

alive ACE_player && {"UK3CB_BAF_Javelin_Launcher" isEqualTo (secondaryWeapon ACE_player)}
