/*
    Author:
        Tim Beswick

    Description:
        Get default loadout from config using given name.

    Parameter(s):
        0: Loadout display name <STRING>

    Return Value:
        Loadout <ARRAY> (Same format as getUnitLoadout)
*/
#include "script_component.hpp"

params ["_loadout"];

private _loadouts = ((format ["getText (_x >> 'name') isEqualTo '%1'", _loadout]) configClasses (configFile >> QGVAR(loadouts)));
if (isClass (getMissionConfig QGVAR(loadouts))) then {
    _loadouts append ((format ["getText (_x >> 'name') isEqualTo '%1'", _loadout]) configClasses (getMissionConfig QGVAR(loadouts)));
};

private _loadoutArray = [];
if ((count _loadouts) > 0) then {
    _loadoutArray = call compile (getText ((_loadouts select 0) >> "loadout"));
};
_loadoutArray
