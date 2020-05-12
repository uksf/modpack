#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Initialises curator owner, then calls ACE override of BI moduleCurator function

    Parameter(s):
        0: Logic <LOGIC>
        1: Units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
params ["_logic", "_units", "_activated"];

if (!isMultiplayer) then {
    private _owner = _logic getvariable ["owner", ""];
    if (_owner == "") then {
        _logic setVariable ["owner", "#adminLogged"]; // Prevents warning about curator owner not defined
    };

};

call ace_zeus_fnc_bi_moduleCurator;
