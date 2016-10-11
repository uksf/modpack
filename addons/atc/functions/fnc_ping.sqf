/*
	Author:
		Tim Beswick

	Description:
		Warns players to stop pinging zeus. 10 pings = death

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

if(!isNil "Beswick") then {
	if(!(GETVAR(Beswick,GVAR(pingSetup),false))) then {
		Beswick addEventHandler ["CuratorPinged", {
		    params ["_curator", "_unit"];
		    private _pingCount = GETVAR(_unit,GVAR(pingCount),0);
		    private _lastPingTime = GETVAR(_unit,GVAR(pingCount),diag_tickTime);
			INFO_2("Zeus pinged by: %1, %2 times", _unit, _pingCount);

			_pingCount = _pingCount + 1;
		    if(_lastPingTime <= diag_tickTime - 15) then {
				SETVAR(_unit,GVAR(pingCount),_pingCount);
				SETVAR(_unit,GVAR(pingCount),diag_tickTime);
		    } else {
		        if(_pingCount == 5) then {
		            "Stop pinging zeus, or you'll die." remoteExecCall ["hint", _unit];
		        };
		        if(_pingCount >= 10) then {
		            "You were warned." remoteExecCall ["hint", _unit];
		            _unit setDamage 1;
					SETVAR(_unit,GVAR(pingCount),0);
					SETVAR(_unit,GVAR(pingCount),diag_tickTime);
		        } else {
					SETVAR(_unit,GVAR(pingCount),_pingCount);
					SETVAR(_unit,GVAR(pingCount),diag_tickTime);
		        };
		    };
		}];
		SETPVAR(Beswick,GVAR(pingSetup),true);
	};
};