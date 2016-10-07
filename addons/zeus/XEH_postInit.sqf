#include "script_component.hpp"

if(isServer) then {
	call FUNC(ping);
	call FUNC(initCurator);
};

if(hasInterface) then {
	call FUNC(loop);
	[player] call FUNC(addAction);
};