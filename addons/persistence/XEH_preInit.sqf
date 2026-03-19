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

        call FUNC(loadSession);
        call FUNC(initServer);
    };
};

ADDON = true;
