#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the MPU-5 radios that the player carries.

    Parameter(s):
        None

    Return Value:
        MPU-5 radio IDs <ARRAY>

    Example:
        call uksf_ctab_fnc_mpu5Radios
*/

([] call acre_api_fnc_getCurrentRadioList) select {([_x] call acre_api_fnc_getBaseRadio) == MPU5_CLASS}
