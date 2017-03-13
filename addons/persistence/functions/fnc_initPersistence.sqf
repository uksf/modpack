/*
    Author:
        Tim Beswick

    Description:
        Inits persistence. Gets mission ID setting, and looks for database. If none exists, create one.

    Parameter(s):
        None

    Return Value:
        Nothing
*/
#include "script_component.hpp"

"extDB3" callExtension "9:UNLOCK:uksf";
"extDB3" callExtension "9:RESET";

if (("extDB3" callExtension "9:VERSION") isEqualTo "") exitWith {
    ERROR("extDB3 failed to load.");
};

INFO("Attempting connetion to database...");
private _connection = "extDB3" callExtension "9:ADD_DATABASE:Database";
INFO_1("Connection result: %1", _connection);
if (!(_connection isEqualTo [1])) exitWith {
    ERROR("Failed to connect to database.");
};
INFO("Connetion to database successful.");
