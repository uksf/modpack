#include "script_component.hpp"
/*
    Author:
        Tim Beswick, MadMax (https://steamcommunity.com/sharedfiles/filedetails/?id=1891978580)

    Description:
        Starts/stops loop to simulate diving environment and effects.

    Parameter(s):
        0: State <BOOLEAN>

    Return Value:
        None

    Example:
        [_state] call uksf_diving_fnc_loop
*/
params ["_state"];

if (!_state) exitWith {
    [GVAR(updatePFHID)] call CBA_fnc_removePerFrameHandler;
    GVAR(updatePFHID) = -1;
    call FUNC(reset);
    call FUNC(publishDataState);
};

GVAR(updatePFHID) = [{
    if !(alive player) exitWith {
        [false] call FUNC(loop);
    };

    private _inWater = ((eyePos player)#2) < 0;
    if (!_inWater) exitWith {
        if (GVAR(currentDepth) > 0.5) then {
            if (GVAR(needDecompress)) then {
                private _pain = player getVariable ["ace_medical_pain", 0];
                [player, _pain + 1] call ace_medical_fnc_adjustPainLevel;
                [player, 0.8, "body", "unknown"] call ace_medical_fnc_addDamageToUnit;
                [player, 0.5, "head", "unknown"] call ace_medical_fnc_addDamageToUnit;
            };
            call FUNC(reset);
            player allowSprint true;
            call FUNC(publishDataState);
        };
    };

    if (GVAR(currentGasLiters) > 0.1) then {
        GVAR(connectedGas) = true;
    };

    private _speed = vectorMagnitude (velocity player);
    private _breathingVolumePerMinute = [[AIR_USAGE_IDLE, AIR_USAGE_NORMAL] select (_speed > SPEED_NORMAL), AIR_USAGE_FAST] select (_speed > SPEED_FAST);
    if (objectParent player != objNull) then {
        _breathingVolumePerMinute = AIR_USAGE_IDLE;
    };
    if (GVAR(currentPercentO2) > 0) then {
        _breathingVolumePerMinute = _breathingVolumePerMinute / GVAR(currentPercentO2);
    };

    GVAR(currentDepth) = (((getPosASL player) select 2) * -1);
    GVAR(currentAmbientPressure) = ((GVAR(currentDepth) / 10) + 1);
    private _currentAirUsage = GVAR(currentAmbientPressure) * (_breathingVolumePerMinute / 60);
    GVAR(currentGasLiters) = (GVAR(currentGasLiters) - _currentAirUsage);
    GVAR(elapsedDiveTime) = GVAR(elapsedDiveTime) + 1;
    private _depthToDecompress = GVAR(currentDepth) - GVAR(decompressDepth);
    GVAR(currentPressure) = GVAR(currentGasLiters) / GVAR(currentVolume);
    if (_currentAirUsage > 0) then {
        GVAR(remainingDiveTime) = GVAR(currentGasLiters) / _currentAirUsage;
    } else {
        GVAR(remainingDiveTime) = 0;
    };
    private _depthToDeepStop = GVAR(currentDepth) - GVAR(deepStopDepth);

    private _saturationAll = GVAR(saturationO2) + GVAR(saturationHe) + GVAR(saturationN2);
    private _toxicSaturation = GVAR(saturationN2) + GVAR(saturationHe);
    GVAR(partialPressureO2) = GVAR(currentPercentO2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureN2) = GVAR(currentPercentN2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureHe) = GVAR(currentPercentHe) * GVAR(currentAmbientPressure);
    GVAR(maxDepth) = if (GVAR(currentPercentO2) > 0) then {
        ((MOD_PPO2 / GVAR(currentPercentO2)) - 1) * 10
    } else { 0 };

    private _useHe = if (GVAR(currentPercentHe) > 0.1) then { 1 } else { 0.000000001 };
    private _useN2 = if (GVAR(currentPercentN2) > 0.1) then { 1 } else { 0.000000001 };
    private _useO2 = 0.000000001;
    switch (true) do {
        case (GVAR(currentPercentN2) < 0.1): {
            private _saturationA = ((1.37 * GVAR(saturationHe)) + (1.382 * GVAR(saturationO2))) / ((_useHe * 1.37) + (_useO2 * 1.382));
            private _saturationB = ((0.03870 * GVAR(saturationHe)) + (0.03186 * GVAR(saturationO2))) / ((_useHe * 0.03870) + (0.03186 * _useO2));
            private _decompressionDepthA = (((GVAR(saturationHe) + GVAR(saturationO2)) - _saturationA) * _saturationB) * 3.28;
            GVAR(decompressDepthB) = (_decompressionDepthA + _toxicSaturation) * 2.6;
        };
        case (GVAR(currentPercentHe) < 0.1): {
            private _saturationA = ((1.37 * GVAR(saturationN2)) + (1.382 * GVAR(saturationO2))) / ((_useN2 * 1.37) + (_useO2 * 1.382));
            private _saturationB = ((0.03870 * GVAR(saturationN2)) + (0.03186 * GVAR(saturationO2))) / ((_useN2 * 0.03870) + (0.03186 * _useO2));
            private _decompressionDepthA = (((GVAR(saturationN2) + GVAR(saturationO2)) - _saturationA) * _saturationB) * 3.28;
            GVAR(decompressDepthB) = (_decompressionDepthA + _toxicSaturation) * 2.6;
        };
        case ((GVAR(currentPercentO2) > 0.09) && (GVAR(currentPercentHe) >= 0.1) && (GVAR(currentPercentN2) >= 0.1)): {
            private _saturationA = ((1.37 * GVAR(saturationN2)) + (0.0346 * GVAR(saturationHe)))/ ((_useN2 * 1.37) + (_useHe * 0.0346));
            private _saturationB = ((0.03870 * GVAR(saturationN2)) + (0.02380 * GVAR(saturationHe)))/ ((_useN2 * 0.03870) + (_useHe * 0.02380));
            private _decompressionDepthA = (((GVAR(saturationN2) + GVAR(saturationHe)) - _saturationA) * _saturationB) * 3.28;
            GVAR(decompressDepthB) = _decompressionDepthA + 0.00001;
        };
    };

    private _ambientPressureDelta = (GVAR(previousAmbientPressure) - GVAR(currentAmbientPressure)) / 60;
    GVAR(ascendRate) = GVAR(previousDepth) - GVAR(currentDepth);
    GVAR(previousDepth) = GVAR(currentDepth);
    GVAR(previousAmbientPressure) = ((GVAR(previousDepth) / 10) + 1);

    GVAR(saturationN2) = TISSUE_SATURATION_MULTIPLIER * ((GVAR(currentPercentN2) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentN2)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentN2) * (GVAR(currentAmbientPressure) - 0.0567)) - (GVAR(currentPercentN2) * 0.736) - (((_ambientPressureDelta / 60) * GVAR(currentPercentN2)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60))));
    GVAR(saturationHe) = TISSUE_SATURATION_MULTIPLIER * ((GVAR(currentPercentHe) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentHe)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentHe) * (GVAR(currentAmbientPressure) - 0.0567)) - (GVAR(currentPercentHe) * 0.736) - (((_ambientPressureDelta / 60) * GVAR(currentPercentHe)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60))));
    GVAR(saturationO2) = TISSUE_SATURATION_MULTIPLIER * ((GVAR(currentPercentO2) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentO2)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentO2) * (GVAR(currentAmbientPressure) - 0.0567)) - (GVAR(currentPercentO2) * 0.736) - (((_ambientPressureDelta / 60) * GVAR(currentPercentO2)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60))));

    if ((GVAR(decompressDepth) < GVAR(decompressDepthB)) && !GVAR(needDecompress)) then {
        if (GVAR(currentDepth) >= 11) then {
            GVAR(decompressDepth) = (round (GVAR(decompressDepthB) / 10)) * 10;
            GVAR(decompressTime) = (GVAR(decompressDepth) * (round (_saturationAll * 3))) / DECO_DIMINISH;
        };
    };

    if (((GVAR(decompressDepth) >= 10) OR (GVAR(decompressTime) >= 180)) && !GVAR(needDecompress)) then {
        GVAR(needDecompress) = true;
    };

    if ((GVAR(decompressDepthB) > 15) && !GVAR(needDeepStop)) then {
        GVAR(deepStopDepth) = round (GVAR(currentDepth) / 2);
        GVAR(deepStopTime) = (GVAR(decompressDepth) * (round (_saturationAll * 2.5))) / DECO_DIMINISH;
        GVAR(needDeepStop) = true;
    };

    if (GVAR(needDecompress) && _depthToDecompress <= 1 && _depthToDecompress >= -1) then {
        GVAR(decompressTime) = GVAR(decompressTime) - 1;
        if (GVAR(decompressTime) < 1) then {
            GVAR(elapsedDiveTime) = 0;
            GVAR(saturationN2) = 0;
            GVAR(saturationHe) = 0;
            GVAR(saturationO2) = 0;
        };
    } else {
        if (GVAR(decompressTime) <= 60) then {
            private _refreshedTime = (GVAR(decompressDepth) * (round (_saturationAll * 3))) / DECO_DIMINISH;
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
            GVAR(deepStopTime) = (GVAR(decompressDepth) * (round (_saturationAll * 2.5))) / DECO_DIMINISH;
        };
    };

    call FUNC(handleEffects);

    if (CBA_missionTime > (GVAR(dataPublishTime) + 60)) then {
        GVAR(dataPublishTime) = CBA_missionTime;
        call FUNC(publishDataState);
    };
}, 1] call CBA_fnc_addPerFrameHandler;

call FUNC(publishDataState);
