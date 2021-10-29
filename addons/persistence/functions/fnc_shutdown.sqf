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
            {
                private _marker = createVehicle [QGVAR(markerAmmo), _x, [], 0, "CAN_COLLIDE"];
                GVAR(persistenceMarkers) pushBack _marker;
            } forEach (values GVAR(disconnectedPlayerPositions));
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
                GVAR(dataNamespace) setVariable [QGVAR(ratingAreas), call EFUNC(arearating,serializeRatingAreas)];
                GVAR(dataNamespace) setVariable [QGVAR(safehouses), call EFUNC(safehouses,serialize)];
                call FUNC(saveData);
            };

            [{SERVER_COMMAND serverCommand "#shutdown"}, [], 4] call CBA_fnc_waitAndExecute;
        }] call CBA_fnc_waitUntilAndExecute;
    };

    SERVER_COMMAND serverCommand (format ["#kick %1", owner (_players#0)]);
}, 2, []] call CBA_fnc_addPerFrameHandler;

// For local MP debug
/*
[player, "", getPlayerUID player, name player] call uksf_persistence_fnc_handleDisconnect;
{
    private _marker = createVehicle ["uksf_persistence_markerAmmo", _x, [], 0, "CAN_COLLIDE"];
    uksf_persistence_persistenceMarkers pushBack _marker;
} forEach (values uksf_persistence_disconnectedPlayerPositions);
[] call uksf_persistence_fnc_saveObjectData;

[{
    !uksf_persistence_saveObjectQueueProcessing
}, {
    if (uksf_persistence_dataSaved) then {
        private _dateTime = date;
        uksf_persistence_dataNamespace setVariable ["uksf_persistence_dateTime", _dateTime];
        uksf_persistence_dataNamespace setVariable ["uksf_persistence_mapMarkers", uksf_persistence_mapMarkers];
        uksf_persistence_dataNamespace setVariable ["uksf_persistence_ratingAreas", call uksf_arearating_fnc_serializeRatingAreas];
        uksf_persistence_dataNamespace setVariable ["uksf_persistence_safehouses", call uksf_safehouses_fnc_serialize];
        call uksf_persistence_fnc_saveData;
    };

    systemChat "done";
}] call CBA_fnc_waitUntilAndExecute;
*/
