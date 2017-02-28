/*
    Author:
        Tim Beswick

    Description:
        Displays a message showing what was not loaded from loadout.

    Parameter(s):
        0: Items not loaded <ARRAY>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_removed"];

private _compose = [lineBreak, parseText "<t align='center' size='1.3' color='#feb100'>Did not load the following items. Select them manually from the Arsenal if they exist.<\t>", lineBreak, lineBreak];  
{
    private _config = _x;
    private _configType = "";
    private _name = _config;
    switch true do {
        case (isClass (configFile >> "CfgMagazines" >> _config)): {_configType = "CfgMagazines"};
        case (isClass (configFile >> "CfgWeapons" >> _config)): {_configType = "CfgWeapons"};
        case (isClass (configFile >> "CfgVehicles" >> _config)): {_configType = "CfgVehicles"};
        case (isClass (configFile >> "CfgGlasses" >> _config)): {_configType = "CfgGlasses"};
    };
    if (_configType != "") then {
        _name = getText (configFile >> _configType >> _config >> "displayName");
    };
    if ((count _compose) isEqualTo 4) then {
        _compose append [format ["%1", _name]];
    } else {
        _compose append [format [", %1", _name]];
    };
    false
} count _removed;

disableSerialization;
"cba_diagnostic_Error" cutRsc ["cba_diagnostic_Error", "PLAIN"];
private _control = uiNamespace getVariable "cba_diagnostic_Error";
_control ctrlSetBackgroundColor [0.2,0.2,0.2,0.8];
_control ctrlSetStructuredText (composeText _compose);
