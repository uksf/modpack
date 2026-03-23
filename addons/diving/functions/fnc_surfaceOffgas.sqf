#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs surface off-gassing calculation. Started when diver surfaces,
        stops when all tissue compartments are below threshold.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_surfaceOffgas
*/

GVAR(elapsedDiveTime) = GVAR(elapsedDiveTime) + 1;

private _allClear = true;
for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
    private _newSatN2 = [GVAR(currentPercentN2), _i, 1, 0, GVAR(elapsedDiveTime), GVAR(saturationN2) select _i] call FUNC(calculateSaturation);
    private _newSatHe = [GVAR(currentPercentHe), _i, 1, 0, GVAR(elapsedDiveTime), GVAR(saturationHe) select _i] call FUNC(calculateSaturation);
    private _newSatO2 = [GVAR(currentPercentO2), _i, 1, 0, GVAR(elapsedDiveTime), GVAR(saturationO2) select _i] call FUNC(calculateSaturation);

    GVAR(saturationN2) set [_i, _newSatN2 max 0];
    GVAR(saturationHe) set [_i, _newSatHe max 0];
    GVAR(saturationO2) set [_i, _newSatO2 max 0];

    if ((abs _newSatN2) > SATURATION_OFFGAS_THRESHOLD || (abs _newSatHe) > SATURATION_OFFGAS_THRESHOLD || (abs _newSatO2) > SATURATION_OFFGAS_THRESHOLD) then {
        _allClear = false;
    };
};

if (_allClear) then {
    [GVAR(surfaceOffgasPFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(surfaceOffgasPFHID) = -1;
    GVAR(saturationN2) = [0, 0, 0];
    GVAR(saturationHe) = [0, 0, 0];
    GVAR(saturationO2) = [0, 0, 0];
    GVAR(elapsedDiveTime) = 0;
};
