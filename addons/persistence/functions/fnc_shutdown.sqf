#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Forces server shutdown after saving data

    Parameter(s):
        None

    Return Value:
        None
*/

if (!isServer) exitWith {
    [QGVAR(shutdown)] call CBA_fnc_serverEvent;
};

LOG("Shutdown");

[QEGVAR(common,textTiles), [parseText format ["<t align = 'center' color = '#00FF00'>Persistence Shutdown Cycle Started: You will be kicked off the server shortly. Please stand still.</t>"], [0.25, 0.5, 0.5, 0.085], [1, 1], 2.5], [] call CBA_fnc_players] call CBA_fnc_targetEvent;

[{
    params ["", "_idPFH"];

    private _players = call CBA_fnc_players;
    if (_players isEqualTo []) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        if (GVAR(dataSaved)) then {
            [] call FUNC(saveObjectData);
        } else {
            GVAR(saveObjectQueueProcessing) = false;
        };

        [{
            !GVAR(saveObjectQueueProcessing)
        }, {
            if (GVAR(dataSaved)) then {
                private _dateTime = date;
                TRACE_1("Saving date time",_dateTime);
                GVAR(dataNamespace) setVariable [QGVAR(dateTime), _dateTime];
                GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), GVAR(mapMarkers)];
                call FUNC(saveData);
            };

            [{SERVER_COMMAND serverCommand "#shutdown"}, [], 4] call CBA_fnc_waitAndExecute;
        }] call CBA_fnc_waitUntilAndExecute;
    };

    SERVER_COMMAND serverCommand (format ["#kick %1", owner (_players#0)]);
}, 2, []] call CBA_fnc_addPerFrameHandler;

// For local MP debug
// [] call FUNC(saveObjectData);

// [{
//     !GVAR(saveObjectQueueProcessing)
// }, {
//     if (GVAR(dataSaved)) then {
//         private _dateTime = date;
//         TRACE_1("Saving date time",_dateTime);
//         GVAR(dataNamespace) setVariable [QGVAR(dateTime), _dateTime];
//         GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), GVAR(mapMarkers)];
//         call FUNC(saveData);
//     };

//     systemChat "done";
//     // [{SERVER_COMMAND serverCommand "#shutdown"}, [], 4] call CBA_fnc_waitAndExecute;
// }] call CBA_fnc_waitUntilAndExecute;
