/*
    Author:
        Tim Beswick

    Description:
        Creates a hash map of groups and their sides (in config format).

    Parameters:
        None

    Return value:
        Nothing
*/
#include "script_component.hpp"

private _factionMap = [];

private _configFactions = [];
{
    _configFactions append ("true" configClasses _x);
    false
} count ("(str _x find ""Empty"") isEqualTo -1" configClasses (configFile >> "CfgGroups"));

{
    private _groups = [];
    {
        _groups append ("true" configClasses _x);
        false
    } count ("(str _x find ""Infantry"") != -1" configClasses _x);
    _factionMap pushBack [configName _x, _groups];
    false
} count _configFactions;

uiNamespace setVariable [QGVAR(factionMap), _factionMap];
