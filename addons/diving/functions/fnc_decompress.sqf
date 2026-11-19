#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Clears the player's decompression debt over 20 seconds while they stay inside the decompression pod

    Parameter(s):
        0: Pod <OBJECT>

    Return Value:
        None

    Example:
        [_pod] call uksf_diving_fnc_decompress
*/
params ["_pod"];

[DECOMPRESS_DURATION, [_pod], {
    call FUNC(reset);
    call FUNC(publishDataState);
    hint "Decompression complete";
}, {}, "Decompressing", {
    params ["_args"];
    _args params ["_pod"];
    alive _pod && {vehicle player == _pod}
}, ["isNotInside", "isNotSwimming"]] call ace_common_fnc_progressBar;
