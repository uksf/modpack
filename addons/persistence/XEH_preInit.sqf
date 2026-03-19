#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.inc.sqf"

if (is3DEN) then {
    GVAR(edenPersistenceIdHash) = [] call CBA_fnc_hashCreate;
    [] call FUNC(edenAttributeChanged);

    ["All", "init", {
        params ["_object"];
        _object addEventHandler ["AttributesChanged3DEN", {call FUNC(edenAttributeChanged)}];
        _object addEventHandler ["RegisteredToWorld3DEN", {call FUNC(edenAttributeChanged)}];
        _object addEventHandler ["UnregisteredFromWorld3DEN", {[_this#0, false, true] call FUNC(edenAttributeChanged)}];
    }, true, [], true] call CBA_fnc_addClassEventHandler;
};

GVAR(dataSaved) = false;
GVAR(shutdownInProgress) = false;
GVAR(readyForShutdownCount) = 0;
GVAR(readyForShutdownExpected) = 0;

if (isMultiplayer) then {
    if (hasInterface) then {
        call FUNC(initClient);
    };

    if (isServer) then {
        // Handle API commands
        [QEGVAR(api,command), {
            params ["_type", "_data"];
            switch (_type) do {
                case "persistence_load": {
                    [_data] call FUNC(handleApiLoadChunk);
                };
                case "shutdown": {
                    call FUNC(startShutdown);
                };
            };
        }] call CBA_fnc_addEventHandler;

        // Handle player acks during shutdown — kick each player as they report ready
        [QGVAR(readyForShutdown), {
            params [["_player", objNull, [objNull]]];

            // Only count player acks — HCs flush but are not tracked
            if (isNull _player || {!isPlayer _player}) exitWith {};

            GVAR(readyForShutdownCount) = GVAR(readyForShutdownCount) + 1;
            INFO_2("Player ready for shutdown (%1 of %2)",GVAR(readyForShutdownCount),GVAR(readyForShutdownExpected));

            // Kick the player after a short delay to ensure their data has been processed
            [{
                params ["_player"];
                if (!isNull _player) then {
                    SERVER_COMMAND serverCommand (format ["#kick %1", owner _player]);
                };
            }, [_player], 1] call CBA_fnc_waitAndExecute;
        }] call CBA_fnc_addEventHandler;

        call FUNC(loadSession);
        call FUNC(initServer);
    };
};

ADDON = true;
