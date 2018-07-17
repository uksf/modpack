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
#include "script_component.hpp"

if (!isServer) exitWith {
    [QGVAR(shutdown)] call CBA_fnc_serverEvent;
};
LOG("Shutdown");

{
    [QEGVAR(common,textTiles), [parseText format ["<t align = 'center' color = '#00FF00'>Persistence Shutdown Cycle Started: You will be kicked off the server shortly. Please stand still.</t>"], [0.25, 1, 0.5, 0.05], [1, 1], 2.5], _x] call CBA_fnc_targetEvent;
} forEach ([] call CBA_fnc_players);

[{
    params ["", "_idPFH"];

    private _players = [] call CBA_fnc_players;
    if (count _players == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        [] call FUNC(saveVehicleData);
        private _dateTime = date;
        TRACE_1("Saving date time",_dateTime);
        GVAR(dataNamespace) setVariable [QGVAR(dateTime), _dateTime];
        GVAR(dataNamespace) setVariable [QGVAR(mapMarkers), GVAR(mapMarkers)];
        if (GVAR(dataSaved)) then {
            profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
            LOG("Saved data");
        };
        [{
            SERVER_COMMAND serverCommand "#shutdown";
        }, nil, 2] call CBA_fnc_waitAndExecute;
    };
    SERVER_COMMAND serverCommand (format ["#kick %1", owner (_players#0)]);
}, 2, []] call CBA_fnc_addPerFrameHandler;
