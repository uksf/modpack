/*
    Author:
        esteldunedain from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Returns the metadata of a setting if it exists

    Parameter(s):
        0: Setting Name <STRING>

    Return Value:
        Setting Data (Array)
            0: Name <STRING>
            1: Type Name <STRING>
            2: Is Client Settable <BOOL>
            3: Localized Name <STRING>
            4: Localized Description <STRING>
            5: Possible Values <ARRAY>
            6: Is Forced <BOOL>
            7: Default Value <ANY>
            8: Localized Category <STRING>
*/
#include "script_component.hpp"

params ["_name"];

scopeName "main";
{
    if (_x select 0 isEqualTo _name) then {
        _x breakOut "main";
    };
    false
} count GVAR(settings);

[]
