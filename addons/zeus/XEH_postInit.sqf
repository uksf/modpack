#include "script_component.hpp"

if ((isServer && !hasInterface) || !isMultiplayer) then {
	call FUNC(ping);
	call FUNC(initCurators);
};

if (hasInterface) then {
	call FUNC(loop);
	[player] call FUNC(addAction);
};

if (!isMultiplayer) then {
	[{
		player assignCurator (GVAR(curatorObjects) select 0);
	}, [], 0.5] call CBA_fnc_waitAndExecute;
};

{_x addCuratorEditableObjects [allMissionObjects "all", true]} forEach allCurators;