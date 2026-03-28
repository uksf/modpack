#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies decompression sickness visual effect — red tint, blur, pain

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_effectToxicDecompression
*/

[[1, 0, 0, 0.2], [0.001, 0.001, 0.15, 0.15], 0.09, 1, 0.1] call FUNC(applyToxicEffect);
