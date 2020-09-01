#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Init for Commander module/unit:
            - Create PFH
            - Establish time conditions for responses base on commander skil level

    Parameters:
        0: module for skill <NUMBER>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

private _skill = _module getVariable [QGVAR(aiGroundCommanderSkill),0];


if (_skill == 1) exitWith {[{call FUNC(selectResponse)},1200] call CBA_fnc_addPerFrameHandler;};
if (_skill == 2) exitWith {[{call FUNC(selectResponse)},900] call CBA_fnc_addPerFrameHandler;};
if (_skill == 3) exitWith {[{call FUNC(selectResponse)},600] call CBA_fnc_addPerFrameHandler;};

//debugging value
if (_skill == 10) exitWith {[{call FUNC(selectResponse);},180] call CBA_fnc_addPerFrameHandler;};

// add tier 1 and 2 response reset every 30mins
[{
    GVAR(tier1ResponseDeployed) = 0;
    GVAR(tier2ResponseDeployed) = 0;
},1800] call CBA_fnc_addPerFrameHandler;
