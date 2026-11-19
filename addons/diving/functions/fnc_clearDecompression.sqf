#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns tissues to surface equilibrium on air and clears every decompression and deep stop obligation.
        Leaves depth, gas and the dive loop untouched.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_diving_fnc_clearDecompression
*/

GVAR(saturationN2) = GVAR(rateConstantsN2) apply {SURFACE_N2};
GVAR(saturationHe) = GVAR(rateConstantsHe) apply {0};
GVAR(decompressDepthB) = 0;
GVAR(decompressDepth) = 0;
GVAR(decompressTime) = 0;
GVAR(decompressEndN2) = [];
GVAR(decompressEndHe) = [];
GVAR(deepStopDepth) = 0;
GVAR(deepStopTime) = 0;
GVAR(needDecompress) = false;
GVAR(needDeepStop) = false;
GVAR(deepStopDone) = false;
