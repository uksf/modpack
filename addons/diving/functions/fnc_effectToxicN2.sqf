#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Applies nitrogen narcosis visual effect — brownish tint, subtle blur, no pain

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_effectToxicN2
*/

[[0.6, 0.3, 0.3, 0.2], [0.01, 0.01, 0.03, 0.03], 0.15, 2, 0] call FUNC(applyToxicEffect);
