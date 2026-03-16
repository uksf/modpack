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

if (isMultiplayer) then {
    if (hasInterface) then {
        call FUNC(initClient);
    };

    if (isServer) then {
        // Handle API extension callbacks for persistence load chunks
        [QEGVAR(api,extensionCallback), {
            params ["_function", "_data"];
            if (_function == "persistence_load") then {
                [_data] call FUNC(handleApiLoadChunk);
            };
        }] call CBA_fnc_addEventHandler;

        // Handle API commands for shutdown
        [QEGVAR(api,command), {
            params ["_type"];
            if (_type == "shutdown") then {
                call FUNC(shutdown);
            };
        }] call CBA_fnc_addEventHandler;

        call FUNC(loadSession);
        call FUNC(initServer);
    };
};

ADDON = true;
