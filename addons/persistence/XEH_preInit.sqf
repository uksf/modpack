#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

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
        GVAR(key) = getMissionConfigValue ["persistenceKey", ""];
        INFO_1("Mission Key: %1",GVAR(key));
        if (GVAR(key) != "") then {
            GVAR(key) = format [QUOTE(GVAR(key)_%1_%2), worldName, GVAR(key)];
            GVAR(dataSaved) = true;
            private _hash = profileNamespace getVariable [GVAR(key), []];
            TRACE_1("Loaded data",_hash);
            GVAR(dataNamespace) = [_hash] call CBA_fnc_deserializeNamespace;
        } else {
            GVAR(dataNamespace) = call CBA_fnc_createNamespace;
        };

        call FUNC(initServer);
    };
};

ADDON = true;
