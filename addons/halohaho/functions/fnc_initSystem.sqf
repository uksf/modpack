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
        - Player is below reset altitude and has no goggles on and is not hypoxic
            -> Turn off, reset
            -> If player had hypoxia
                -> Reset walk status after delay

    Parameter(s):
        None

    Return Value:
        Nothing
*/

if (GVAR(systemPFHID) != -1) then {
    [GVAR(systemPFHID)] call CBA_fnc_removePerFrameHandler;
};

GVAR(systemPFHID) = [{
    params ["_args", "_idPFH"];

    if (!alive player) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        GVAR(systemPFHID) = -1;
        GVAR(oxygenConnected) = false;
        GVAR(hypoxiaLevel) = 0;
        GVAR(maxHypoxiaLevel) = 0;
    };

    private _altitude = (getPosASL player)#2;
    private _aboveHypoxiaAltitude = _altitude >= HYPOXIA_ALTITUDE;
    private _hypoxic = GVAR(hypoxiaLevel) > 0;
    private _hasMask = goggles player == "G_mas_usl_jumpmask";
    private _hasEquipmentConnected = GVAR(oxygenConnected) && _hasMask;

    if (_aboveHypoxiaAltitude && !_hypoxic && !_hasEquipmentConnected) then {
        _hypoxic = true;
        [player, "forceWalk", QGVAR(hypoxic), true] call ace_common_fnc_statusEffect_set;
        ace_advanced_fatigue_anReserve = 10; // Sets stamina right down
    };

    if (_hypoxic) then {
        private _hypoxiaModifier = 0;
        switch (true) do {
            case (_aboveHypoxiaAltitude && !_hasEquipmentConnected): {
                _hypoxiaModifier = linearConversion [HYPOXIA_ALTITUDE, HYPOXIA_UPPER_ALTITUDE, _altitude, 5, 20];
            };
            case (!_aboveHypoxiaAltitude && !_hasEquipmentConnected): {
                _hypoxiaModifier = linearConversion [HYPOXIA_ALTITUDE, SYSTEM_RESET_ALTITUDE, _altitude, -2, -10];
            };
            case (!_aboveHypoxiaAltitude && _hasEquipmentConnected): {
                _hypoxiaModifier = -15;
            };
        };

        GVAR(hypoxiaLevel) = ((GVAR(hypoxiaLevel) + _hypoxiaModifier) min 100) max 0;
        GVAR(maxHypoxiaLevel) = GVAR(maxHypoxiaLevel) max GVAR(hypoxiaLevel);
        [] spawn FUNC(applyHypoxiaEffects);
    };

    if (_altitude < SYSTEM_RESET_ALTITUDE && !_hasMask && !_hypoxic) then {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(systemPFHID) = -1;

        if (GVAR(maxHypoxiaLevel) > 0) then {
            private _resetDelay = linearConversion [0, 100, GVAR(maxHypoxiaLevel), 180, 300];
            [{[player, "forceWalk", QGVAR(hypoxic), false] call ace_common_fnc_statusEffect_set}, [], _resetDelay] call CBA_fnc_waitAndExecute;
            GVAR(maxHypoxiaLevel) = 0;
        };
    };
}, 5, []] call CBA_fnc_addPerFrameHandler;
