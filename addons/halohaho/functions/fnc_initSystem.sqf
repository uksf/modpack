#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks player altitude.
        Applies hypoxia effects when altitude is above 3000m and no oxygen is connected.

        System has the following states:
        - Player is dead
            -> Turn off, reset
        - Player is above hypoxia altitude and is not hypoxic and has no oxygen connected or no goggles on
            -> Set as hypoxic, set walk status, zero fatigue
        - Player is hypoxic
            -> If player is above hypoxia altitude and has no oxygen connected or no goggles on
                -> Increase hypoxia level by lerped altitude value
            -> If player is not above hypoxia altitude and has no oxygen connected or no goggles on
                -> Reduce hypoxia level by lerped altitude value
            -> If player is not above hypoxia altitude and has oxygen connected and goggles on
                -> Reduce hypoxia level by set value
            -> Apply hypoxia effects
        - Player is below reset altitude and is not hypoxic
            -> Turn off, reset
            -> If player had hypoxia
                -> Reset walk status after delay

    Parameter(s):
        None

    Return Value:
        Nothing
*/

if (GVAR(systemPFHID) != -1) exitWith {};

GVAR(systemPFHID) = [{
    params ["_args", "_idPFH"];
    _args params ["_runEffects"];

    if (!alive player) exitWith {
        DEBUG("Player dead, exiting system");
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        GVAR(systemPFHID) = -1;
        GVAR(oxygenConnected) = false;
        GVAR(hypoxiaLevel) = 0;
        GVAR(maxHypoxiaLevel) = 0;
    };

    if (CBA_missionTime <= GVAR(previousTime)) exitWith {};
    GVAR(previousTime) = CBA_missionTime;

    private _altitudeASL = (getPosASL player)#2;
    private _aboveHypoxiaAltitude = _altitudeASL >= HYPOXIA_ALTITUDE;
    private _hypoxic = GVAR(hypoxiaLevel) > 0;
    private _hasMask = goggles player == HALOHAHO_MASK;
    private _hasEquipmentConnected = GVAR(oxygenConnected) && _hasMask;
    TRACE_7(""_altitudeASL,_aboveHypoxiaAltitude,GVAR(hypoxiaLevel),_hypoxic,_hasMask,GVAR(oxygenConnected),_hasEquipmentConnected);

    if (_aboveHypoxiaAltitude && !_hypoxic && !_hasEquipmentConnected) then {
        DEBUG("Player is becoming hypoxic");
        _hypoxic = true;
        [player, "forceWalk", QGVAR(hypoxic), true] call ace_common_fnc_statusEffect_set;
    };

    if (_hypoxic) then {
        private _hypoxiaModifier = 0;
        switch (true) do {
            case (_aboveHypoxiaAltitude && !_hasEquipmentConnected): {
                _hypoxiaModifier = linearConversion [HYPOXIA_ALTITUDE, HYPOXIA_UPPER_ALTITUDE, _altitudeASL, 5, 10];
                TRACE_2("Adjusting hypoxia, player is above altitude and does not have equipment",_altitudeASL,_hypoxiaModifier);
            };
            case (!_aboveHypoxiaAltitude && !_hasEquipmentConnected): {
                _hypoxiaModifier = linearConversion [HYPOXIA_ALTITUDE, SYSTEM_RESET_ALTITUDE, _altitudeASL, -1, -4];
                TRACE_2("Adjusting hypoxia, player is not above altitude and does not have equipment",_altitudeASL,_hypoxiaModifier);
            };
            case (!_aboveHypoxiaAltitude && _hasEquipmentConnected): {
                _hypoxiaModifier = -8;
                TRACE_2("Adjusting hypoxia, player is not above altitude and does have equipment",_altitudeASL,_hypoxiaModifier);
            };
        };

        GVAR(hypoxiaLevel) = ((GVAR(hypoxiaLevel) + _hypoxiaModifier) min 100) max 0;
        GVAR(maxHypoxiaLevel) = GVAR(maxHypoxiaLevel) max GVAR(hypoxiaLevel);
        TRACE_2("",GVAR(hypoxiaLevel),GVAR(maxHypoxiaLevel));

        if (_runEffects) then {
            [] spawn FUNC(applyHypoxiaEffects);
        };
        _args set [0, !_runEffects];
    };

    if (!_hypoxic) then {
        private _altitudeATL = (getPosATL player)#2;
        if (_altitudeATL < SYSTEM_RESET_ALTITUDE && !_hasMask) then {
            DEBUG("Player is below reset altitude and does not have a mask");
            [_idPFH] call CBA_fnc_removePerFrameHandler;
            GVAR(systemPFHID) = -1;
        };

        if (GVAR(maxHypoxiaLevel) > 0) then {
            ace_advanced_fatigue_anFatigue = linearConversion [5, 100, GVAR(maxHypoxiaLevel), 0.5, 0.2];
            private _resetDelay = linearConversion [1, 100, GVAR(maxHypoxiaLevel), 10, 30];
            TRACE_2("Player had hypoxia, resetting walking and effects",GVAR(maxHypoxiaLevel),_resetDelay);
            GVAR(maxHypoxiaLevel) = 0;

            [{
                if (GVAR(hypoxiaLevel) == 0) then {
                    [player, "forceWalk", QGVAR(hypoxic), false] call ace_common_fnc_statusEffect_set;
                };
            }, [], _resetDelay] call CBA_fnc_waitAndExecute;

            GVAR(ppColour) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
            GVAR(ppColour) ppEffectCommit _resetDelay;
            GVAR(ppBlur) ppEffectAdjust [0, 0, 0, 0];
            GVAR(ppBlur) ppEffectCommit _resetDelay;
            GVAR(ppDynamicBlur) ppEffectAdjust [0];
            GVAR(ppDynamicBlur) ppEffectCommit _resetDelay;
            GVAR(ppChroma) ppEffectAdjust [0, 0, true];
            GVAR(ppChroma) ppEffectCommit _resetDelay;
        };
    };
}, 5, [false]] call CBA_fnc_addPerFrameHandler;
