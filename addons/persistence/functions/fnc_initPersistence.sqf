/*
    Author:
        Tim Beswick

    Description:
        Initialises connection to database.

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

private _seperator = call compile (GVAR(extensionName) callExtension "separator");
if ((_seperator select 0) isEqualTo "error") exitWith {

    ERROR_SYSTEM_CHAT("The extension failed to load or is missing");
    ERROR_1("Failed to init: %1", _seperator select 1);
};
GVAR(extensionSeparator) = _seperator select 1;
INFO_1("Seperator %1", GVAR(extensionSeparator));

private _connect = call compile (GVAR(extensionName) callExtension "connect");
if ((_connect select 0) isEqualTo "error") exitWith {
    ERROR_SYSTEM_CHAT("The extension failed to connect to the database. Will not run any persistence functionality");
    ERROR_1("Failed to connect to database: %1", _connect select 1);
};

call FUNC(initTable);
