#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Infer high-level group type from CfgGroups unit vehicles.

    Parameters:
        0: Group config <CONFIG>

    Return Value:
        Group type <STRING>
*/

params [["_groupCfg", configNull, [configNull]]];

if (isNull _groupCfg) exitWith {"unsupported"};

private _hasUnsupported = false;
private _hasTank = false;
private _hasAPC = false;
private _hasCar = false;

{
    if (!isClass _x) then {continue};
    private _vehicleClass = getText (_x >> "vehicle");
    if (_vehicleClass isEqualTo "") then {continue};

    if (_vehicleClass isKindOf "Air" || {_vehicleClass isKindOf "Ship"}) then {
        _hasUnsupported = true;
        continue;
    };

    if (_vehicleClass isKindOf "Tank") then {_hasTank = true;};
    if ((_vehicleClass isKindOf "APC")) then {_hasAPC = true;};
    if (_vehicleClass isKindOf "Car") then {_hasCar = true;};

} forEach configProperties [_groupCfg, "isClass _x", true];

if (_hasUnsupported) exitWith {"unsupported"};
if (_hasTank) exitWith {"tank"};
if (_hasAPC) exitWith {"apc"};
if (_hasCar) exitWith {"car"};
"man"
