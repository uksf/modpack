#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks player height. Continues on when height is above 3000m.

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None
*/
params ["_player"];

private _oxygenRequiredHeight = GVAR(startingHeight) + 3000; // should handle higher maps such as takistan

[{
    params ["_args", "_idPFH"];
    _args params ["_player", "_oxygenRequiredHeight"];

    if ((!alive _player) || (goggles _player != "G_mas_usl_jumpmask")) exitWith {
        GVAR(oxygenConnected) = false;
        GVAR(fatigueZeroed) = false;
        call ace_goggles_fnc_removeGlassesEffect;
        [{
            params ["_player"];
            [_player, "forceWalk", QGVAR(hypoxic), false] call ace_common_fnc_statusEffect_set;
        }, [_player], 10] call cba_fnc_waitAndExecute; // needs changing to scale
        [_idPFH] call cba_fnc_removePerFrameHandler;
    };

    private _currentHeight = (getPosASL _player) select 2;

    if ((_currentHeight >= _oxygenRequiredHeight) && !GVAR(oxygenConnected)) then {
        [_player] call FUNC(applyHypoxicEffects);

        if (GVAR(fatigueZeroed)) exitWith {};
        [_player, "forceWalk", QGVAR(hypoxic), true] call ace_common_fnc_statusEffect_set;
        ace_advanced_fatigue_anReserve = 10;
        GVAR(fatigueZeroed) = true;
    };
}, 5, [_player, _oxygenRequiredHeight]] call CBA_fnc_addPerFrameHandler;
