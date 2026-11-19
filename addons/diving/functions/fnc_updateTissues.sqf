#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Advances nitrogen and helium tensions in every compartment by an elapsed interval

    Parameter(s):
        0: Nitrogen tensions <ARRAY>
        1: Helium tensions <ARRAY>
        2: Nitrogen fraction breathed <NUMBER>
        3: Helium fraction breathed <NUMBER>
        4: Ambient pressure in bar <NUMBER>
        5: Elapsed time in seconds <NUMBER>

    Return Value:
        [Nitrogen tensions, Helium tensions] <ARRAY>

    Example:
        [GVAR(saturationN2), GVAR(saturationHe), 0.79, 0, 3, 1] call uksf_diving_fnc_updateTissues
*/
params ["_n2", "_he", "_fractionN2", "_fractionHe", "_ambientPressure", "_dt"];

private _newN2 = [];
private _newHe = [];
for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
    _newN2 pushBack ([_fractionN2, GVAR(rateConstantsN2) select _i, _ambientPressure, _n2 select _i, _dt] call FUNC(calculateSaturation));
    _newHe pushBack ([_fractionHe, GVAR(rateConstantsHe) select _i, _ambientPressure, _he select _i, _dt] call FUNC(calculateSaturation));
};

[_newN2, _newHe]
