/*
    Author:
        Tim Beswick

    Description:
        Adds all objects to all curators

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\achilles\modules_f_ares\module_header.hpp"

private _objects = (allMissionObjects "") select {typeOf _x != "ModuleCurator_F"};
[_objects] call Ares_fnc_AddUnitsToCurator;

[objNull, format ["%1 objects were added to Zeus", count _objects]] call bis_fnc_showCuratorFeedbackMessage;

#include "\achilles\modules_f_ares\module_footer.hpp"
