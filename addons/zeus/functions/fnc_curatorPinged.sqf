/*
    Author:
        Tim Beswick

    Description:
        Warn player about pinging. Kill if too many pings. (Pinging has no visual effect for curators)

    Parameter(s):
        0: Curator <OBJECT>
        1: Player <OBJECT>

    Return Value:
        BOOLEAN
*/
#include "script_component.hpp"

params ["_curator", "_player"];

if (((getAssignedCuratorUnit _curator) != player) && {local _player}) then {
    QGVAR(pingCount) = QGVAR(pingCount) + 1;

    if (QGVAR(pingTime) <= time - 15) then {
        QGVAR(pingCount) = 0;
    } else {
        if (QGVAR(pingCount) >= 5) then {
            private _kill = false;
            private _text = composeText [lineBreak, lineBreak, parseText "<t align='center' size='2' color='#ff0000'>Stop pinging zeus, or you'll die.<\t>", lineBreak, lineBreak];
            if (QGVAR(pingCount) >= 10) then {
                _text = composeText [lineBreak, lineBreak, parseText "<t align='center' size='2' color='#ff0000'>You were warned.<\t>", lineBreak, lineBreak];
                _kill = true;
            };

            disableSerialization;
            "cba_diagnostic_Error" cutRsc ["cba_diagnostic_Error", "PLAIN"];
            private _control = uiNamespace getVariable "cba_diagnostic_Error";
            _control ctrlSetBackgroundColor [0.2,0.2,0.2,0.8];
            _control ctrlSetStructuredText _text;
            
            [{
                params ["_player", "_kill"];

                "cba_diagnostic_Error" cutText ["","PLAIN"];
                if (_kill) then {
                    _player setDamage 1;
                    QGVAR(pingCount) = 0;
                };
            }, [_player, _kill], 2] call CBA_fnc_waitAndExecute;
        };
    };
    QGVAR(pingTime) = time;
};

true
