#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the ceiling, the current decompression stop and the deep stop from tissue tensions.
        A stop sits on the next STOP_INCREMENT boundary below the ceiling. Holding it for its shortened
        time applies the tensions of the simulated stop. The next shallower stop is planned only when the
        simulation cleared it; otherwise the stop follows the real ceiling. A change of breathed gas
        replans the stop, so a prediction never outlives the gas it assumed.

    Parameter(s):
        0: Elapsed time in seconds <NUMBER>

    Return Value:
        None

    Example:
        [1] call uksf_diving_fnc_updateDecompression
*/
params ["_dt"];

private _planStop = {
    params ["_stopDepth"];
    ([_stopDepth] call FUNC(calculateStopTime)) params ["_time", "_endN2", "_endHe", "_cleared"];
    GVAR(decompressDepth) = _stopDepth;
    GVAR(decompressTime) = _time;
    GVAR(decompressEndN2) = _endN2;
    GVAR(decompressEndHe) = _endHe;
    GVAR(stopCleared) = _cleared;
    GVAR(stopGas) = [GVAR(breathedN2), GVAR(breathedHe)];
    GVAR(stopRecalcTime) = CBA_missionTime + STOP_RECALC_INTERVAL;
};

private _clearStop = {
    GVAR(needDecompress) = false;
    GVAR(decompressDepth) = 0;
    GVAR(decompressTime) = 0;
    GVAR(decompressEndN2) = [];
    GVAR(decompressEndHe) = [];
};

private _toStopDepth = {
    params ["_ceiling"];
    if (_ceiling > 0) then {(ceil (_ceiling / STOP_INCREMENT)) * STOP_INCREMENT} else {0}
};

GVAR(decompressDepthB) = [GVAR(saturationN2), GVAR(saturationHe)] call FUNC(calculateCeiling);
private _stopDepth = [GVAR(decompressDepthB)] call _toStopDepth;

if (!GVAR(needDecompress)) then {
    if (_stopDepth > 0) then {
        GVAR(needDecompress) = true;
        [_stopDepth] call _planStop;
    };
} else {
    private _atStop = abs (GVAR(currentDepth) - GVAR(decompressDepth)) <= 1;
    if (_stopDepth > GVAR(decompressDepth)) then {
        [_stopDepth] call _planStop;
    } else {
        if (GVAR(stopGas) isNotEqualTo [GVAR(breathedN2), GVAR(breathedHe)]) exitWith {
            [GVAR(decompressDepth)] call _planStop;
        };
        if (_atStop) then {
            GVAR(decompressTime) = GVAR(decompressTime) - _dt;
            if (GVAR(decompressTime) <= 0) then {
                if (count GVAR(decompressEndN2) == COMPARTMENT_COUNT) then {
                    GVAR(saturationN2) = GVAR(decompressEndN2);
                    GVAR(saturationHe) = GVAR(decompressEndHe);
                };
                GVAR(decompressDepthB) = [GVAR(saturationN2), GVAR(saturationHe)] call FUNC(calculateCeiling);
                private _nextStop = [GVAR(decompressDepthB)] call _toStopDepth;
                if (GVAR(stopCleared)) then {
                    _nextStop = _nextStop min (GVAR(decompressDepth) - STOP_INCREMENT);
                };
                if (_nextStop > 0) then {
                    [_nextStop] call _planStop;
                } else {
                    call _clearStop;
                };
            };
        } else {
            if (CBA_missionTime > GVAR(stopRecalcTime)) then {
                if (_stopDepth > 0) then {
                    [_stopDepth] call _planStop;
                } else {
                    call _clearStop;
                };
            };
        };
    };
};

if (GVAR(needDecompress) && !GVAR(needDeepStop) && !GVAR(deepStopDone) && GVAR(ascendRate) > 0) then {
    private _proposedDepth = round (GVAR(currentDepth) / 2);
    if (_proposedDepth > (GVAR(decompressDepth) + STOP_INCREMENT)) then {
        GVAR(deepStopDepth) = _proposedDepth;
        GVAR(deepStopTime) = DEEP_STOP_TIME / DECO_DIMINISH;
        GVAR(needDeepStop) = true;
    };
};

if (GVAR(needDeepStop)) then {
    if (abs (GVAR(currentDepth) - GVAR(deepStopDepth)) <= 1) then {
        GVAR(deepStopTime) = GVAR(deepStopTime) - _dt;
    } else {
        if ((GVAR(currentDepth) / 2) > (GVAR(deepStopDepth) + 1)) then {
            GVAR(deepStopDepth) = round (GVAR(currentDepth) / 2);
            GVAR(deepStopTime) = DEEP_STOP_TIME / DECO_DIMINISH;
        };
    };
    if (GVAR(deepStopTime) <= 0) then {
        GVAR(deepStopDepth) = 0;
        GVAR(deepStopTime) = 0;
        GVAR(needDeepStop) = false;
        GVAR(deepStopDone) = true;
    };
};
