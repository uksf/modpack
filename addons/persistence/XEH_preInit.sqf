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

if (!isMultiplayer) exitWith {};

if (hasInterface) then {
    call FUNC(initClient);
};

if (isServer) then {
    GVAR(dataSaved) = false;
    GVAR(key) = getMissionConfigValue ["persistenceKey", ""];
    TRACE_1("Key",GVAR(key));
    if (GVAR(key) != "") then {
        GVAR(key) = format [QUOTE(GVAR(key)_%1), GVAR(key)];
        GVAR(dataSaved) = true;
    };

    private _hash = profileNamespace getVariable [GVAR(key), []];
    TRACE_1("Loaded data",_hash);
    GVAR(dataNamespace) = [_hash] call CBA_fnc_deserializeNamespace;
    if ((count (allVariables GVAR(dataNamespace))) > 0) then {
        private _world =  GVAR(dataNamespace) getVariable [QGVAR(world), ""];
        if (_world != worldName) then {
            ERROR_3("World for key %1 is %2 but expected %3",GVAR(key),_world,worldName);
            GVAR(dataSaved) = false;
        };
    } else {
        GVAR(dataNamespace) = call CBA_fnc_createNamespace;
    };

    call FUNC(initServer);
};

ADDON = true;
