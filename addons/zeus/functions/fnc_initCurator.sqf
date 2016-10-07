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

GVAR(curatorObject) = (creategroup sideLogic) createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
SETPVAR(GVAR(curatorObject),text,QUOTE(UKSFCurator));
SETPVAR(GVAR(curatorObject),addons,2);
SETPVAR(GVAR(curatorObject),vehicleinit,QUOTE(SETPVAR(GVAR(curatorObject),QUOTE(addons),2)));
GVAR(curatorObject) addCuratorAddons activatedAddons;
SETMVAR(GVAR(curatorName), "");

INFO("Curator created");

[QGVAR(disconnectEHKey), "onPlayerDisconnected", FUNC(disconnect), [_id, _uid, _name, _jip, _owner]] call BIS_fnc_addStackedEventHandler;