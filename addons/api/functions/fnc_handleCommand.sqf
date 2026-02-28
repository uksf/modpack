#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles an inbound command from the API via extensionCallback.

    Parameters:
        0: Function name <STRING>
        1: Data (JSON string) <STRING>

    Return Value:
        None
*/
params ["_function", "_data"];

TRACE_2("Received command",_function,_data);

if (_function == "command") then {
    private _parsed = parseSimpleArray _data;
    if (_parsed isEqualType [] && {count _parsed > 0}) then {
        private _type = _parsed param [0, ""];
        switch (_type) do {
            case "shutdown": {
                INFO("Received shutdown command from API");
                if (isServer) then {
                    private _shutdownFunction = uiNamespace getVariable ["uksf_persistence_fnc_shutdown", {
                        serverCommand (format ["#shutdown %1", SERVER_COMMAND]);
                    }];
                    call _shutdownFunction;
                } else {
                    serverCommand (format ["#shutdown %1", SERVER_COMMAND]);
                };
            };
            default {
                WARNING_1("Unknown command type: %1",_type);
            };
        };
    };
};
