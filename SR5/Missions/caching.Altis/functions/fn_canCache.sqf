/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Checks if group can be cached

    Parameters:
    	0: Group to be cached <GROUP>

    Return value:
    	Boolean

    Called from:
    	Caching PFH;
*/
params [["_group",grpNull]];

!isNull _group &&
{count units _group > 1} &&
{!(_group in UKSF_Caching_groups)} &&
{!(_group getVariable ["UKSF_Caching_Disabled",false])} &&
{([leader _group,UKSF_Caching_distance] call UKSF_Caching_fnc_getNearPlayers) isEqualTo []} &&
{isNull (leader _group findNearestEnemy leader _group)}
