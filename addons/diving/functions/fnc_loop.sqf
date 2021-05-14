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

    if (CBA_missionTime <= GVAR(previousTime)) exitWith {};
    GVAR(previousTime) = CBA_missionTime;

    private _inWater = ((eyePos player)#2) < 0;
    if (!_inWater) exitWith {
        if (GVAR(currentDepth) != 0) then {
            call FUNC(reset);
            player allowSprint true;
            call FUNC(publishDataState);
        };
    };

    private _speed = vectorMagnitude (velocity player);
    private _breathingVolumePerMinute = [[AIR_USAGE_IDLE, AIR_USAGE_NORMAL] select (_speed > SPEED_NORMAL), AIR_USAGE_FAST] select (_speed > SPEED_FAST);

    GVAR(currentDepth) = (((getPosASL player) select 2) * -1);
    GVAR(currentAmbientPressure) = ((GVAR(currentDepth) / 10) + 1);
    private _currentAirUsage = GVAR(currentAmbientPressure) * (_breathingVolumePerMinute / 60);
    GVAR(currentGasLiters) = (GVAR(currentGasLiters) - _currentAirUsage);
    GVAR(elapsedDiveTime) = GVAR(elapsedDiveTime) + 1;
    private _depthToDecompress = GVAR(currentDepth) - GVAR(decompressDepth);
    GVAR(currentPressure) = GVAR(currentGasLiters) / GVAR(currentVolume);
    GVAR(remainingDiveTime) = ((GVAR(currentGasLiters) / _currentAirUsage));
    private _currentDepth = (((getPosASL player) select 2) * -1);
    private _currentAmbientPressure = ((_currentDepth / 10) + 1);
    private _depthToDeepStop = GVAR(currentDepth) - GVAR(deepStopDepth);

    private _saturationAll = GVAR(saturationO2) + GVAR(saturationHe) + GVAR(saturationN2);
    private _toxicSaturation = GVAR(saturationN2) + GVAR(saturationHe);
    GVAR(partialPressureO2) = GVAR(currentPercentO2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureN2) = GVAR(currentPercentN2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureHe) = GVAR(currentPercentHe) * GVAR(currentAmbientPressure);
    GVAR(maxDepth) = ((1.4 / GVAR(currentPercentO2)) - 1) * 10;

    private _useHe = [0, 1] select (GVAR(currentPercentHe) > 0);
    private _useN2 = [0, 1] select (GVAR(currentPercentN2) > 0);
    switch (true) do {
        case (GVAR(currentPercentN2) < 0.1): {
            private _saturationA = ((0.0346 * GVAR(saturationHe)) + (1.382 * GVAR(saturationO2))) / ((_useHe * 0.0346) + (0.000000001 * 1.382));
            private _saturationB = ((0.02380 * GVAR(saturationHe)) + (0.03186 * GVAR(saturationO2))) / ((_useHe * 0.02380) + (0.03186 * 0.000000001));
            private _decompressionDepthA = (((GVAR(saturationHe) + GVAR(saturationO2)) - _saturationA) * _saturationB) * 3.28;
            GVAR(decompressDepthB) = (_decompressionDepthA + _toxicSaturation) * 2.6;
        };
        case (GVAR(currentPercentHe) < 0.1): {
            private _saturationA = ((1.37 * GVAR(saturationN2)) + (1.382 * GVAR(saturationO2)))/ ((_useN2 * 1.37) + (0.000000001 * 1.382));
            private _saturationB = ((0.03870 * GVAR(saturationN2)) + (0.03186 * GVAR(saturationO2)))/ ((_useN2 * 0.03870) + (0.03186 * 0.000000001));
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

    private _ambientPressureDelta = (GVAR(previousAmbientPressure) - _currentAmbientPressure) / 60;
    GVAR(ascendRate) = GVAR(previousDepth) - _currentDepth;
    GVAR(previousDepth) = _currentDepth;
    GVAR(previousAmbientPressure) = ((GVAR(previousDepth) / 10) + 1);

    GVAR(saturationN2) = (GVAR(currentPercentN2) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentN2)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentN2) * (GVAR(currentAmbientPressure) - 0.0567)) - 0.736 - (((_ambientPressureDelta / 60) * GVAR(currentPercentN2)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60)));
    GVAR(saturationHe) = (GVAR(currentPercentHe) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentHe)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentHe) * (GVAR(currentAmbientPressure) - 0.0567)) - 0.736 - (((_ambientPressureDelta / 60) * GVAR(currentPercentHe)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60)));
    GVAR(saturationO2) = (GVAR(currentPercentO2) * (GVAR(currentAmbientPressure) - 0.0567)) + ((_ambientPressureDelta / 60) * GVAR(currentPercentO2)) * ((GVAR(elapsedDiveTime) / 60) - (1 / GVAR(saturationCoefficient))) - ((GVAR(currentPercentO2) * (GVAR(currentAmbientPressure) - 0.0567)) - 0.736 - (((_ambientPressureDelta / 60) * GVAR(currentPercentO2)) / GVAR(saturationCoefficient))) * exp ((-GVAR(saturationCoefficient) * (GVAR(elapsedDiveTime) / 60)));

    if ((GVAR(decompressDepth) < GVAR(decompressDepthB)) && !GVAR(needDecompress)) then {
        GVAR(decompressDepth) = (round (GVAR(decompressDepthB) / 10)) * 10;
        GVAR(decompressPreviousDepth) = GVAR(decompressDepth);
        GVAR(decompressTime) = GVAR(decompressDepth) * (round (_saturationAll * 4));
    };

    if (((GVAR(decompressDepth) >= 10) OR (GVAR(decompressTime) >= 180)) && !GVAR(needDecompress)) then {
        GVAR(needDecompress) = true;
    };

    if ((GVAR(decompressDepthB) > 10) && !GVAR(needDeepStop)) then {
        GVAR(deepStopDepth) = GVAR(currentDepth) / 2;
        GVAR(deepStopTime) = GVAR(decompressDepth) * (round (_saturationAll * 3.5));
        GVAR(needDeepStop) = true;
    };

    if ((GVAR(needDecompress)) && !(_depthToDecompress > 1) && !(_depthToDecompress < -1)) then {
        GVAR(decompressTime) = GVAR(decompressTime) - 1;
    };

    if (GVAR(decompressTime) <= 0) then {
        GVAR(decompressTime) = 0;
        GVAR(decompressDepth) = 0;
        GVAR(needDecompress) = false;
    };

    if (GVAR(needDeepStop) && !(_depthToDeepStop > 1) && !(_depthToDeepStop < -1)) then {
        GVAR(deepStopTime) = GVAR(deepStopTime) - 1;
    };

    call FUNC(handleEffects);

    if (CBA_missionTime > (GVAR(dataPublishTime) + 5)) then {
        GVAR(dataPublishTime) = CBA_missionTime;
        call FUNC(publishDataState);
    };
}, 1] call CBA_fnc_addPerFrameHandler;

call FUNC(publishDataState);
