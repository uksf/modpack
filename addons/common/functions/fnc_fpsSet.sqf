#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets fps value of given client

    Parameters:
        0: Local Client <OBJECT/SCALAR>
        1: FPS <SCALAR>

    Return value:
        None
*/
params ["_client", "_fps"];

if (_client isEqualType 0) then {
    GVAR(fpsArray) set [0, "Server"];
    GVAR(fpsArray) set [1, _fps];
} else {
    private _index = GVAR(fpsArray) find _client;
    if (_index isEqualTo -1) then {
        GVAR(fpsArray) set [(count GVAR(fpsArray)), _client];
        GVAR(fpsArray) set [(count GVAR(fpsArray)), _fps];
    } else {
        GVAR(fpsArray) set [_index, _client];
        GVAR(fpsArray) set [_index + 1, _fps];
    };
};
