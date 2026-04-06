#include "script_component.hpp"
/*
    Author:
        Tim Beswick, MadMax (https://steamcommunity.com/sharedfiles/filedetails/?id=1891978580)

    Description:
        Starts/stops loop to simulate diving environment and effects.
        Runs both underwater (full simulation) and on surface (off-gassing).
        Self-terminates when all tissue compartments clear and player is not underwater.

    Parameter(s):
        0: State <BOOLEAN>

    Return Value:
        None

    Example:
        [_state] call uksf_diving_fnc_loop
*/
params ["_state"];

if (!_state) exitWith {};

if (GVAR(updatePFHID) != -1) exitWith {};

GVAR(updatePFHID) = [{
    if !(alive player) exitWith {
        [GVAR(updatePFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(updatePFHID) = -1;
        call FUNC(reset);
        GVAR(saturationN2) = [0, 0, 0];
        GVAR(saturationHe) = [0, 0, 0];
        GVAR(saturationO2) = [0, 0, 0];
        GVAR(elapsedDiveTime) = 0;
    };

    private _inWater = ((eyePos player)#2) < 0;
    private _hasRebreather = (vest player) in [QGVAR(rebreather), "UKSF_LARV_1", "UKSF_LARV_2"];

    if (_inWater) then {
        if (GVAR(currentGasLiters) > 0.1) then {
            GVAR(connectedGas) = true;
        };

        GVAR(currentDepth) = (((getPosASL player) select 2) * -1);
        GVAR(currentAmbientPressure) = ((GVAR(currentDepth) / 10) + 1);

        if (_hasRebreather) then {
            private _speed = vectorMagnitude (velocity player);
            private _breathingVolumePerMinute = [[AIR_USAGE_IDLE, AIR_USAGE_NORMAL] select (_speed > SPEED_NORMAL), AIR_USAGE_FAST] select (_speed > SPEED_FAST);
            if (objectParent player != objNull) then {
                _breathingVolumePerMinute = AIR_USAGE_IDLE;
            };
            if (GVAR(currentPercentO2) > 0) then {
                _breathingVolumePerMinute = _breathingVolumePerMinute / GVAR(currentPercentO2);
            };

            private _currentAirUsage = GVAR(currentAmbientPressure) * (_breathingVolumePerMinute / 60);
            GVAR(currentGasLiters) = GVAR(currentGasLiters) - _currentAirUsage;
            GVAR(currentPressure) = GVAR(currentGasLiters) / GVAR(currentVolume);
            if (_currentAirUsage > 0) then {
                GVAR(remainingDiveTime) = GVAR(currentGasLiters) / _currentAirUsage;
            } else {
                GVAR(remainingDiveTime) = 0;
            };
        };
    } else {
        if (GVAR(currentDepth) > 0.5) then {
            if (GVAR(needDecompress)) then {
                private _pain = player getVariable ["ace_medical_pain", 0];
                [player, _pain + 1] call ace_medical_fnc_adjustPainLevel;
                [player, 0.8, "body", "unknown"] call ace_medical_fnc_addDamageToUnit;
                [player, 0.5, "head", "unknown"] call ace_medical_fnc_addDamageToUnit;
            };
            player allowSprint true;
        };

        GVAR(currentDepth) = 0;
        GVAR(currentAmbientPressure) = 1;
        GVAR(connectedGas) = false;
    };

    if (_inWater) then {
        GVAR(elapsedDiveTime) = GVAR(elapsedDiveTime) + 1;
    };

    GVAR(ascendRate) = GVAR(previousDepth) - GVAR(currentDepth);
    private _ambientPressureDelta = (GVAR(currentAmbientPressure) - GVAR(previousAmbientPressure)) * 60;
    GVAR(previousDepth) = GVAR(currentDepth);
    GVAR(previousAmbientPressure) = ((GVAR(previousDepth) / 10) + 1);

    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        GVAR(saturationN2) set [_i, [GVAR(currentPercentN2), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(saturationN2) select _i] call FUNC(calculateSaturation)];
        GVAR(saturationHe) set [_i, [GVAR(currentPercentHe), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(saturationHe) select _i] call FUNC(calculateSaturation)];
        GVAR(saturationO2) set [_i, [GVAR(currentPercentO2), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(saturationO2) select _i] call FUNC(calculateSaturation)];
    };

    private _multiplier = GVAR(tissueSaturationMultiplier);
    private _saturationAll = 0;
    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        private _compartmentTotal = (GVAR(saturationO2) select _i) + (GVAR(saturationHe) select _i) + (GVAR(saturationN2) select _i);
        _saturationAll = _saturationAll max _compartmentTotal;
    };
    _saturationAll = _saturationAll * _multiplier;

    GVAR(partialPressureO2) = GVAR(currentPercentO2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureN2) = GVAR(currentPercentN2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureHe) = GVAR(currentPercentHe) * GVAR(currentAmbientPressure);
    GVAR(maxDepth) = if (GVAR(currentPercentO2) > 0) then {
        ((MOD_PPO2 / GVAR(currentPercentO2)) - 1) * 10
    } else { 0 };

    GVAR(decompressDepthB) = 0;
    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        private _satN2 = (GVAR(saturationN2) select _i) * _multiplier;
        private _satHe = (GVAR(saturationHe) select _i) * _multiplier;
        private _aN2 = GVAR(buhlmannA_N2) select _i;
        private _bN2 = GVAR(buhlmannB_N2) select _i;
        private _aHe = GVAR(buhlmannA_He) select _i;
        private _bHe = GVAR(buhlmannB_He) select _i;
        private _inertTotal = _satN2 + _satHe;

        private _ceilingDepth = 0;
        if (_inertTotal > 0) then {
            private _a = if (_satHe > 0) then {
                ((_aN2 * _satN2) + (_aHe * _satHe)) / _inertTotal
            } else {
                _aN2
            };
            private _b = if (_satHe > 0) then {
                ((_bN2 * _satN2) + (_bHe * _satHe)) / _inertTotal
            } else {
                _bN2
            };
            private _ceilingPressure = (_inertTotal - _a) * _b;
            _ceilingDepth = ((_ceilingPressure - 1) * 10) max 0;
        };

        GVAR(decompressDepthB) = GVAR(decompressDepthB) max _ceilingDepth;
    };

    private _depthToDecompress = GVAR(currentDepth) - GVAR(decompressDepth);
    private _depthToDeepStop = GVAR(currentDepth) - GVAR(deepStopDepth);

    if (GVAR(decompressDepth) < GVAR(decompressDepthB)) then {
        if (GVAR(currentDepth) >= 11) then {
            GVAR(decompressDepth) = (round (GVAR(decompressDepthB) / 10)) * 10;
            GVAR(decompressTime) = (GVAR(decompressDepth) * (ceil (_saturationAll * 3))) / DECO_DIMINISH;
        };
    };

    if (((GVAR(decompressDepth) >= 10) OR (GVAR(decompressTime) >= 180)) && !GVAR(needDecompress)) then {
        GVAR(needDecompress) = true;
    };

    if ((GVAR(decompressDepthB) > 15) && !GVAR(needDeepStop) && GVAR(ascendRate) > 0) then {
        private _proposedDepth = round (GVAR(currentDepth) / 2);
        if (_proposedDepth > GVAR(decompressDepth)) then {
            GVAR(deepStopDepth) = _proposedDepth;
            GVAR(deepStopTime) = (GVAR(deepStopDepth) * (ceil (_saturationAll * 2.5))) / DECO_DIMINISH;
            GVAR(needDeepStop) = true;
        };
    };

    if (GVAR(needDecompress) && _depthToDecompress <= 1 && _depthToDecompress >= -1) then {
        GVAR(decompressTime) = GVAR(decompressTime) - 1;
    } else {
        if (GVAR(decompressTime) <= 60) then {
            private _refreshedTime = (GVAR(decompressDepth) * (ceil (_saturationAll * 3))) / DECO_DIMINISH;
            if (_refreshedTime <= 60) then {
                GVAR(decompressTime) = _refreshedTime;
            };
        };
    };

    if (GVAR(decompressTime) <= 0) then {
        GVAR(decompressTime) = 0;
        GVAR(decompressDepth) = 0;
        GVAR(needDecompress) = false;
    };

    if (GVAR(needDeepStop) && _depthToDeepStop <= 1 && _depthToDeepStop >= -1) then {
        GVAR(deepStopTime) = GVAR(deepStopTime) - 1;
    } else {
        if (GVAR(needDeepStop) && (GVAR(currentDepth) / 2) > GVAR(deepStopDepth)) then {
            GVAR(deepStopDepth) = round (GVAR(currentDepth) / 2);
            GVAR(deepStopTime) = (GVAR(deepStopDepth) * (ceil (_saturationAll * 2.5))) / DECO_DIMINISH;
        };
    };

    call FUNC(handleEffects);

    if (!_inWater && !_hasRebreather && _saturationAll < SATURATION_OFFGAS_THRESHOLD) then {
        [GVAR(updatePFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(updatePFHID) = -1;
        call FUNC(reset);
        GVAR(saturationN2) = [0, 0, 0];
        GVAR(saturationHe) = [0, 0, 0];
        GVAR(saturationO2) = [0, 0, 0];
        GVAR(elapsedDiveTime) = 0;
        call FUNC(publishDataState);
    };

    if (CBA_missionTime > (GVAR(dataPublishTime) + 60)) then {
        GVAR(dataPublishTime) = CBA_missionTime;
        call FUNC(publishDataState);
    };
}, 1] call CBA_fnc_addPerFrameHandler;

call FUNC(publishDataState);
