/*
    Author:
        Tim Beswick

    Description:
        Plays given audio

    Parameters:
        0: Sound 1 <STRING>
        1: Delay 1 <SCALAR>
        2: Sound 2 <STRING>
        3: Delay 2 <SCALAR>
        4: Sound 3 <STRING>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params [["_sound1", ""], ["_delay1", 0], ["_sound2", ""], ["_delay2", 0], ["_sound3", ""], ["_delay3", 0]];

[{
    !GVAR(soundPlaying)
}, {
    params ["_sound1", "_delay1", "_sound2", "_delay2", "_sound3", "_delay3"];

    GVAR(soundPlaying) = true;
    if (alive player) then {
        if (_sound3 != "") then {
            playsound [_sound1, true];
            [{
                playsound [_this, true];
            }, _sound2, _delay1] call CBA_fnc_waitAndExecute;
            [{
                playsound [_this, true];
            }, _sound3, (_delay1 + _delay2)] call CBA_fnc_waitAndExecute;
        } else {
            if (_sound2 != "") then {
                playsound [_sound1, true];
                [{
                    playsound [_this, true];
                }, _sound2, _delay1] call CBA_fnc_waitAndExecute;
            } else {
                if (_sound1 != "") then {
                    playsound [_sound1, true];
                };
            };
        };
    };

    [{
        GVAR(soundPlaying) = false;
    }, [], (_delay1 + _delay2 + _delay3)] call CBA_fnc_waitAndExecute;    
}, [_sound1, _delay1, _sound2, _delay2, _sound3, _delay3]] call CBA_fnc_waitUntilAndExecute;
