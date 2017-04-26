 /*
    Author:
        Bohemia Interactive, edited by Tim Beswick

    Description:
        Module function for initalizing zeus in session.
        Only executed on server and assigned curator client.

    Parameter(s):
        0: The module logic <LOGIC>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "", "_activated"];

if (_activated) then {
    if (hasInterface) then {
        _logic addEventHandler ["CuratorObjectPlaced", {_this call bis_fnc_curatorObjectPlaced}];
        _logic addEventHandler ["CuratorObjectPlaced", {_this call Achilles_fnc_HandleCuratorObjectPlaced}];
        _logic addEventHandler ["curatorObjectEdited", {_this call bis_fnc_curatorObjectEdited}];
        _logic addEventHandler ["CuratorObjectEdited", {_this call Achilles_fnc_HandleCuratorObjectEdited}];
        _logic addEventHandler ["CuratorGroupPlaced", {_this call Achilles_fnc_HandleCuratorGroupPlaced}];
        _logic addEventHandler ["curatorWaypointPlaced", {_this call bis_fnc_curatorWaypointPlaced}];
        _logic addEventHandler ["curatorFeedbackMessage", {_this call bis_fnc_showCuratorFeedbackMessage}];
        _logic addEventHandler ["curatorObjectDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["CuratorObjectDoubleClicked", {_this call Achilles_fnc_HandleCuratorObjectDoubleClicked}];
        _logic addEventHandler ["curatorGroupDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["curatorWaypointDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];
        _logic addEventHandler ["curatorMarkerDoubleClicked", {(_this select 1) call bis_fnc_showCuratorAttributes}];                
        _logic setVariable ["BIS_fnc_curatorAttributesplayer", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesobject", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesgroup", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributeswaypoint", ["%ALL"]];
        _logic setVariable ["BIS_fnc_curatorAttributesmarker", ["%ALL"]];
        [] call Achilles_fnc_setCuratorVisionModes;
        player call bis_fnc_curatorRespawn;
    };
};
