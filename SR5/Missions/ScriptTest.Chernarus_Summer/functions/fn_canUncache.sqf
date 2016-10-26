/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Checks if group can be uncached

    Parameters:
    	0: Group to be uncached <GROUP>

    Return value:
    	Boolean

    Called from:
    	Caching PFH;
*/
params [["_group",grpNull]];

_group getVariable ["UKSF_Mission_Disabled",false] ||
{!(([leader _group,UKSF_Mission_distance] call FUNC(getNearPlayers)) isEqualTo [])} ||
{!(isNull (leader _group findNearestEnemy leader _group))}
