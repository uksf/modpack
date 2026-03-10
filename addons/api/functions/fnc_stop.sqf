#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stops the API bridge extension.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_stop
*/

private _result = "uksf" callExtension "stop";
INFO_1("Extension stop: %1",_result);
