/*
    Author:
        Tim Beswick

    Description:
        Initialises curator & disconnect EH

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

_group = creategroup sideLogic;

_curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(_curator,text,QUOTE(UKSFCurator_1));
_curator addCuratorAddons activatedAddons;
GVAR(curatorObjects) set [0, _curator];

_curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(_curator,text,QUOTE(UKSFCurator_2));
_curator addCuratorAddons activatedAddons;
GVAR(curatorObjects) set [1, _curator];

_curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(_curator,text,QUOTE(UKSFCurator_3));
_curator addCuratorAddons activatedAddons;
GVAR(curatorObjects) set [2, _curator];

_curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(_curator,text,QUOTE(UKSFCurator_4));
_curator addCuratorAddons activatedAddons;
GVAR(curatorObjects) set [3, _curator];

_curator = _group createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(_curator,text,QUOTE(UKSFCurator_5));
_curator addCuratorAddons activatedAddons;
GVAR(curatorObjects) set [4, _curator];

missionNamespace setVariable [QGVAR(curatorNames), ["","","","",""], true];

[QGVAR(disconnectEHKey), "onPlayerDisconnected", FUNC(disconnect), [_id, _uid, _name, _jip, _owner]] call BIS_fnc_addStackedEventHandler;
