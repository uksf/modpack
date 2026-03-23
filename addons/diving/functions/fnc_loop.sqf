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

    if (GVAR(surfaceOffgasPFHID) == -1) then {
        GVAR(surfaceOffgasPFHID) = [{call FUNC(surfaceOffgas)}, 1] call CBA_fnc_addPerFrameHandler;
    };
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

            if (GVAR(surfaceOffgasPFHID) == -1) then {
                GVAR(surfaceOffgasPFHID) = [{call FUNC(surfaceOffgas)}, 1] call CBA_fnc_addPerFrameHandler;
            };
        };
    };

    if (GVAR(surfaceOffgasPFHID) != -1) then {
        [GVAR(surfaceOffgasPFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(surfaceOffgasPFHID) = -1;
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

    private _saturationAll = 0;
    private _toxicSaturation = 0;
    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        private _compartmentTotal = (GVAR(saturationO2) select _i) + (GVAR(saturationHe) select _i) + (GVAR(saturationN2) select _i);
        private _compartmentToxic = (GVAR(saturationN2) select _i) + (GVAR(saturationHe) select _i);
        _saturationAll = _saturationAll max _compartmentTotal;
        _toxicSaturation = _toxicSaturation max _compartmentToxic;
    };
    GVAR(partialPressureO2) = GVAR(currentPercentO2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureN2) = GVAR(currentPercentN2) * GVAR(currentAmbientPressure);
    GVAR(partialPressureHe) = GVAR(currentPercentHe) * GVAR(currentAmbientPressure);
    GVAR(maxDepth) = if (GVAR(currentPercentO2) > 0) then {
        ((MOD_PPO2 / GVAR(currentPercentO2)) - 1) * 10
    } else { 0 };

    private _useHe = if (GVAR(currentPercentHe) > 0.1) then { 1 } else { 0.000000001 };
    private _useN2 = if (GVAR(currentPercentN2) > 0.1) then { 1 } else { 0.000000001 };
    private _useO2 = 0.000000001;

    GVAR(decompressDepthB) = 0;
    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        private _satN2 = GVAR(saturationN2) select _i;
        private _satHe = GVAR(saturationHe) select _i;
        private _satO2 = GVAR(saturationO2) select _i;
        private _compartmentToxic = _satN2 + _satHe;
        private _decompressDepthB = 0;

        switch (true) do {
            case (GVAR(currentPercentN2) < 0.1): {
                private _aN2 = GVAR(buhlmannA_N2) select _i;
                private _bN2 = GVAR(buhlmannB_N2) select _i;
                private _aHe = GVAR(buhlmannA_He) select _i;
                private _bHe = GVAR(buhlmannB_He) select _i;
                private _saturationA = ((_aHe * _satHe) + (_aN2 * _satO2)) / ((_useHe * _aHe) + (_useO2 * _aN2));
                private _saturationB = ((_bHe * _satHe) + (_bN2 * _satO2)) / ((_useHe * _bHe) + (_bN2 * _useO2));
                private _decompressionDepthA = (((_satHe + _satO2) - _saturationA) * _saturationB) * 3.28;
                _decompressDepthB = (_decompressionDepthA + _compartmentToxic) * 2.6;
            };
            case (GVAR(currentPercentHe) < 0.1): {
                private _aN2 = GVAR(buhlmannA_N2) select _i;
                private _bN2 = GVAR(buhlmannB_N2) select _i;
                private _saturationA = ((_aN2 * _satN2) + (1.382 * _satO2)) / ((_useN2 * _aN2) + (_useO2 * 1.382));
                private _saturationB = ((_bN2 * _satN2) + (0.03186 * _satO2)) / ((_useN2 * _bN2) + (0.03186 * _useO2));
                private _decompressionDepthA = (((_satN2 + _satO2) - _saturationA) * _saturationB) * 3.28;
                _decompressDepthB = (_decompressionDepthA + _compartmentToxic) * 2.6;
            };
            case ((GVAR(currentPercentO2) > 0.09) && (GVAR(currentPercentHe) >= 0.1) && (GVAR(currentPercentN2) >= 0.1)): {
                private _aN2 = GVAR(buhlmannA_N2) select _i;
                private _bN2 = GVAR(buhlmannB_N2) select _i;
                private _aHe = GVAR(buhlmannA_He) select _i;
                private _bHe = GVAR(buhlmannB_He) select _i;
                private _saturationA = ((_aN2 * _satN2) + (_aHe * _satHe)) / ((_useN2 * _aN2) + (_useHe * _aHe));
                private _saturationB = ((_bN2 * _satN2) + (_bHe * _satHe)) / ((_useN2 * _bN2) + (_useHe * _bHe));
                private _decompressionDepthA = (((_satN2 + _satHe) - _saturationA) * _saturationB) * 3.28;
                _decompressDepthB = _decompressionDepthA + 0.00001;
            };
        };

        GVAR(decompressDepthB) = GVAR(decompressDepthB) max _decompressDepthB;
    };

    private _ambientPressureDelta = (GVAR(previousAmbientPressure) - GVAR(currentAmbientPressure)) / 60;
    GVAR(ascendRate) = GVAR(previousDepth) - GVAR(currentDepth);
    GVAR(previousDepth) = GVAR(currentDepth);
    GVAR(previousAmbientPressure) = ((GVAR(previousDepth) / 10) + 1);

    for "_i" from 0 to (COMPARTMENT_COUNT - 1) do {
        GVAR(saturationN2) set [_i, [GVAR(currentPercentN2), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(elapsedDiveTime), GVAR(saturationN2) select _i] call FUNC(calculateSaturation)];
        GVAR(saturationHe) set [_i, [GVAR(currentPercentHe), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(elapsedDiveTime), GVAR(saturationHe) select _i] call FUNC(calculateSaturation)];
        GVAR(saturationO2) set [_i, [GVAR(currentPercentO2), _i, GVAR(currentAmbientPressure), _ambientPressureDelta, GVAR(elapsedDiveTime), GVAR(saturationO2) select _i] call FUNC(calculateSaturation)];
    };

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
            GVAR(saturationN2) = [0, 0, 0];
            GVAR(saturationHe) = [0, 0, 0];
            GVAR(saturationO2) = [0, 0, 0];
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
