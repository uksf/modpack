#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets rank icon for unit

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        None
*/
params ["_unit"];

private _unitName = name _unit;
private _unitNameParts = _unitName splitString " " joinString "" splitString ".";
TRACE_2("",_unitName,_unitNameParts);
if (count _unitNameParts != 3) exitWith {TRACE_1("exit",_unitName);};

private _rankPart = _unitNameParts#0;
private _rankIcon = [_rankPart, {configFile >> "CfgCustomRanks" >> _rankPart >> "texture"}, ""] call EFUNC(common,readCacheValues);
TRACE_2("",_rankPart,_rankIcon);
if (_rankIcon != "") then {
    _unit setVariable ["ace_nametags_rankIcon", _rankIcon, true];
};
