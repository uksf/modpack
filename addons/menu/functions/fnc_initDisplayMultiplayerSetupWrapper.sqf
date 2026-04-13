#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Wrapper for initDisplayMultiplayerSetup to allow live recompilation

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        Nothing

    Example:
        [_display] call uksf_menu_fnc_initDisplayMultiplayerSetupWrapper
*/
_this call FUNC(initDisplayMultiplayerSetup);
