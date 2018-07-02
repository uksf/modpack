#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (!isMultiplayer) exitWith {};

if (hasInterface) then {
    [QGVAR(initClient), {_this call FUNC(initClient)}] call CBA_fnc_addEventHandler;
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

#include "initSettings.sqf"

ADDON = true;
