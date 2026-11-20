#include "script_component.hpp"
/*
    Author:
        Tim Beswick, MadMax (https://steamcommunity.com/sharedfiles/filedetails/?id=1891978580)

    Description:
        Starts/stops loop to simulate diving environment and effects.
        Runs underwater on the cylinder mix, and on the surface or inside a decompression pod on air at 1 bar.
        Self-terminates out of the water without a rebreather once no obligation remains and tissues are back near surface equilibrium.

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

GVAR(lastTickTime) = CBA_missionTime;

GVAR(updatePFHID) = [{
    if !(alive player) exitWith {
        [GVAR(updatePFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(updatePFHID) = -1;
        call FUNC(reset);
        GVAR(elapsedDiveTime) = 0;
    };

    private _now = CBA_missionTime;
    private _dt = ((_now - GVAR(lastTickTime)) min MAX_TICK_DT) max 0;
    GVAR(lastTickTime) = _now;

    private _inPod = (typeOf (objectParent player)) == QGVAR(decoPod);
    private _inWater = !_inPod && {((eyePos player)#2) < 0};
    GVAR(inWater) = _inWater;
    private _hasRebreather = (vest player) in [QGVAR(rebreather), "UKSF_LARV_1", "UKSF_LARV_2"];

    if (_inWater) then {
        if (GVAR(currentGasLiters) > 0.1) then {
            GVAR(connectedGas) = true;
        };

        GVAR(currentDepth) = (((getPosASL player) select 2) * -1) max 0;
        GVAR(currentAmbientPressure) = (GVAR(currentDepth) / 10) + 1;
        GVAR(elapsedDiveTime) = GVAR(elapsedDiveTime) + _dt;

        if (_hasRebreather) then {
            private _speed = vectorMagnitude (velocity player);
            private _breathingVolumePerMinute = [[AIR_USAGE_IDLE, AIR_USAGE_NORMAL] select (_speed > SPEED_NORMAL), AIR_USAGE_FAST] select (_speed > SPEED_FAST);
            if (!isNull (objectParent player)) then {
                _breathingVolumePerMinute = AIR_USAGE_IDLE;
            };
            if (GVAR(currentPercentO2) > 0) then {
                _breathingVolumePerMinute = _breathingVolumePerMinute / GVAR(currentPercentO2);
            };

            private _usagePerSecond = GVAR(currentAmbientPressure) * (_breathingVolumePerMinute / 60);
            GVAR(currentGasLiters) = (GVAR(currentGasLiters) - _usagePerSecond * _dt) max 0;
            GVAR(currentPressure) = GVAR(currentGasLiters) / GVAR(currentVolume);
            GVAR(remainingDiveTime) = if (_usagePerSecond > 0) then {GVAR(currentGasLiters) / _usagePerSecond} else {0};
        };
    } else {
        if (GVAR(currentDepth) > 0.5 && !_inPod && GVAR(needDecompress) && {_now > GVAR(bentTime) + BENT_COOLDOWN}) then {
            GVAR(bentTime) = _now;
            private _pain = player getVariable ["ace_medical_pain", 0];
            [player, _pain + 1] call ace_medical_fnc_adjustPainLevel;
            [player, 0.8, "body", "unknown"] call ace_medical_fnc_addDamageToUnit;
            [player, 0.5, "head", "unknown"] call ace_medical_fnc_addDamageToUnit;
        };

        GVAR(currentDepth) = 0;
        GVAR(currentAmbientPressure) = 1;
        GVAR(connectedGas) = false;
        GVAR(deepStopDone) = false;
    };

    GVAR(ascendRate) = if (_dt > 0) then {(GVAR(previousDepth) - GVAR(currentDepth)) / _dt} else {0};
    GVAR(previousDepth) = GVAR(currentDepth);

    private _onCylinder = _inWater && _hasRebreather && GVAR(connectedGas);
    private _fractionO2 = [0.21, GVAR(currentPercentO2)] select _onCylinder;
    private _fractionN2 = [0.79, GVAR(currentPercentN2)] select _onCylinder;
    private _fractionHe = [0, GVAR(currentPercentHe)] select _onCylinder;
    GVAR(breathedN2) = _fractionN2;
    GVAR(breathedHe) = _fractionHe;

    ([GVAR(saturationN2), GVAR(saturationHe), _fractionN2, _fractionHe, GVAR(currentAmbientPressure), _dt] call FUNC(updateTissues)) params ["_n2", "_he"];
    GVAR(saturationN2) = _n2;
    GVAR(saturationHe) = _he;

    GVAR(partialPressureO2) = _fractionO2 * GVAR(currentAmbientPressure);
    GVAR(partialPressureN2) = _fractionN2 * GVAR(currentAmbientPressure);
    GVAR(partialPressureHe) = _fractionHe * GVAR(currentAmbientPressure);
    GVAR(maxDepth) = if (GVAR(currentPercentO2) > 0) then {
        ((MOD_PPO2 / GVAR(currentPercentO2)) - 1) * 10
    } else { 0 };

    [_dt] call FUNC(updateDecompression);

    call FUNC(handleEffects);

    private _clear = !_inWater && !_hasRebreather && !GVAR(needDecompress)
        && {(GVAR(saturationN2) findIf {_x > SURFACE_N2 + SATURATION_OFFGAS_THRESHOLD}) == -1}
        && {(GVAR(saturationHe) findIf {_x > SATURATION_OFFGAS_THRESHOLD}) == -1};
    if (_clear) then {
        [GVAR(updatePFHID)] call CBA_fnc_removePerFrameHandler;
        GVAR(updatePFHID) = -1;
        call FUNC(reset);
        GVAR(elapsedDiveTime) = 0;
        call FUNC(publishDataState);
    };

    if (_now > (GVAR(dataPublishTime) + 60)) then {
        GVAR(dataPublishTime) = _now;
        call FUNC(publishDataState);
    };
}, 1] call CBA_fnc_addPerFrameHandler;

call FUNC(publishDataState);
