#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calculates tissue saturation for a single gas in a single compartment
        using the Buhlmann ZH-L16 model.

    Parameter(s):
        0: Gas percentage <NUMBER>
        1: Compartment index <NUMBER> (0=fast, 1=medium, 2=slow)
        2: Current ambient pressure <NUMBER>
        3: Ambient pressure delta <NUMBER>
        4: Elapsed dive time <NUMBER>
        5: Current saturation value <NUMBER>

    Return Value:
        New saturation value <NUMBER>

    Example:
        [0.78, 0, 3.5, _delta, _time, _currentSat] call uksf_diving_fnc_calculateSaturation
*/
params ["_gasPercent", "_compartmentIndex", "_ambientPressure", "_ambientPressureDelta", "_elapsedTime", "_currentSaturation"];

if (_gasPercent <= 0) exitWith { 0 };

private _coefficient = GVAR(saturationCoefficients) select _compartmentIndex;
private _timeMinutes = _elapsedTime / 60;
private _deltaRate = (_ambientPressureDelta / 60) * _gasPercent;

GVAR(tissueSaturationMultiplier) * (
    (_gasPercent * (_ambientPressure - 0.0567))
    + _deltaRate * (_timeMinutes - (1 / _coefficient))
    - (
        (_gasPercent * (_ambientPressure - 0.0567))
        - (_gasPercent * 0.736)
        - (_deltaRate / _coefficient)
    ) * exp (-_coefficient * _timeMinutes)
)
