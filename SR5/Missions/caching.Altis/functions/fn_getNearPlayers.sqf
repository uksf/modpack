/*
    Author:
    	Nicholas Clark & Tim Beswick

    Description:
    	Gets near players

    Parameters:
    	0: Center position <ARRAY>
		1: Distance from center to check <NUMBER>

    Return value:
    	Nearby players <ARRAY>

    Called from:
    	canCache, canUncache;
*/
#define CHECK_DIST2D(POS1,POS2,DIST) (POS1) distance2D (POS2) <= (DIST)
private ["_pos","_range","_players"];

_pos = _this select 0;
_range = _this select 1;
_players = [];

{
	if (CHECK_DIST2D(_x,_pos,_range)) then {
		_players pushBack _x;
	};
} forEach allPlayers;

_players
