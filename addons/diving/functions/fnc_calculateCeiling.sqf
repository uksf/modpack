#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calculates the shallowest depth the diver can safely ascend to, using Buhlmann tolerated ambient pressure.
        The tissue saturation multiplier scales the inert gas load above surface equilibrium.

    Parameter(s):
        0: Nitrogen tensions <ARRAY>
        1: Helium tensions <ARRAY>

    Return Value:
        Ceiling depth in metres, 0 when the diver may surface <NUMBER>

    Example:
        [GVAR(saturationN2), GVAR(saturationHe)] call uksf_diving_fnc_calculateCeiling
*/
params ["_n2", "_he"];

private _multiplier = GVAR(tissueSaturationMultiplier);
private _ceiling = 0;
for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
    private _tensionN2 = _n2 select _i;
    private _loadN2 = _tensionN2 + (((_tensionN2 - SURFACE_N2) max 0) * (_multiplier - 1));
    private _loadHe = (_he select _i) * _multiplier;
    private _inertTotal = _loadN2 + _loadHe;

    if (_inertTotal > 0) then {
        private _a = ((GVAR(buhlmannA_N2) select _i) * _loadN2 + (GVAR(buhlmannA_He) select _i) * _loadHe) / _inertTotal;
        private _b = ((GVAR(buhlmannB_N2) select _i) * _loadN2 + (GVAR(buhlmannB_He) select _i) * _loadHe) / _inertTotal;
        private _toleratedPressure = (_inertTotal - _a) * _b;
        _ceiling = _ceiling max ((_toleratedPressure - 1) * 10);
    };
};

_ceiling max 0
