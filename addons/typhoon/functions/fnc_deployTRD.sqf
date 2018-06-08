/*
    Author:
        HCPOOKIE, Tim Beswick

    Description:
        Drops fuel tanks

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

//#define 

params ["_vehicle"];

_vehicle setVariable [QGVAR(trdUsing), true, true];
private _uses = _vehicle getVariable [QGVAR(trdUses), 0];



_vehicle setVariable [QGVAR(trdUses), _uses + 1, true];
_vehicle setVariable [QGVAR(trdUsing), false, true];


private ["_count","_Q"];

// NEED:  Sounds to play on events.

_plane = _this select 0;

_count = 1;

_plane animate ['TRD_Display1_1', 0];
_plane animate ['TRD_Module', 0]; // un-hide for deployment
sleep 0.1;
_plane animate ['TRD_Cable1_extend', 1];
_plane animate ['TRD_Cable2_extend', 1];
_plane animate ['TRD_Cable3_extend', 1];
_plane animate ['TRD_Cable4_extend', 1];
_plane animate ['TRD_Cable5_extend', 1];
_plane animate ['TRD_Cable6_extend', 1];
_plane animate ['TRD_Cable7_extend', 1];
_plane animate ['TRD_Cable8_extend', 1];
_plane animate ['TRD_Cable9_extend', 1];
_plane animate ['TRD_Cable10_extend', 1];
_plane animate ['TRD_Cable11_extend', 1];
_plane animate ['TRD_Cable12_extend', 1];
sleep 3;
// _TRD = "EF2K_TRD_target" createVehicle [0,0,0]; 
// _TRD setPos (_plane modelToWorld [0,-50,-25]);

while {_count < 550} do {
	_p = _plane animationPhase "gear_1"; // gear check - no TRD if gear is down!
	if (_p < 0.5) exitWith {};

//	_TRD setPos (_plane modelToWorld [0,-50,-25]);
	_rndRot1 = ((random 100) * 0.0075);
	_rndCab1 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable1_rot', _rndRot1];
	_plane animate ['TRD_Cable1', _rndCab1];

	_rndRot2 = ((random 100) * 0.0075);
	_rndCab2 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable2_rot', _rndRot2];
	_plane animate ['TRD_Cable2', _rndCab2];

	_rndRot3 = ((random 100) * 0.0075);
	_rndCab3 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable3_rot', _rndRot3];
	_plane animate ['TRD_Cable3', _rndCab3];

	_rndRot4 = ((random 100) * 0.0075);
	_rndCab4 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable4_rot', _rndRot4];
	_plane animate ['TRD_Cable4', _rndCab4];

	_rndRot5 = ((random 100) * 0.0075);
	_rndCab5 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable5_rot', _rndRot5];
	_plane animate ['TRD_Cable5', _rndCab5];

	_rndRot6 = ((random 100) * 0.0075);
	_rndCab6 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable6_rot', _rndRot6];
	_plane animate ['TRD_Cable6', _rndCab6];

	_rndRot7 = ((random 100) * 0.0075);
	_rndCab7 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable7_rot', _rndRot7];
	_plane animate ['TRD_Cable7', _rndCab7];

	_rndRot8 = ((random 100) * 0.0075);
	_rndCab8 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable8_rot', _rndRot8];
	_plane animate ['TRD_Cable8', _rndCab8];

	_rndRot9 = ((random 100) * 0.0075);
	_rndCab9 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable9_rot', _rndRot9];
	_plane animate ['TRD_Cable9', _rndCab9];

	_rndRot10 = ((random 100) * 0.0075);
	_rndCab10 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable10_rot', _rndRot10];
	_plane animate ['TRD_Cable10', _rndCab10];

	_rndRot11 = ((random 100) * 0.0075);
	_rndCab11 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable11_rot', _rndRot11];
	_plane animate ['TRD_Cable11', _rndCab11];

	_rndRot12 = ((random 100) * 0.0075);
	_rndCab12 = ((random 100) * 0.0075);
	_plane animate ['TRD_Cable12_rot', _rndRot12];
	_plane animate ['TRD_Cable12', _rndCab12];
//	_TRD setPos (_plane modelToWorld [0,-50,-25]);
	sleep 0.1;
//	_TRD setPos (_plane modelToWorld [0,-50,-25]);
	_count = _count + 1;

};

// deleteVehicle _TRD;
_plane animate ['TRD_Cable1_extend', 0];
_plane animate ['TRD_Cable1_rot', 0.5];
_plane animate ['TRD_Cable1', 0.5];
_plane animate ['TRD_Cable2_extend', 0];
_plane animate ['TRD_Cable2_rot', 0.5];
_plane animate ['TRD_Cable2', 0.5];
_plane animate ['TRD_Cable3_extend', 0];
_plane animate ['TRD_Cable3_rot', 0.5];
_plane animate ['TRD_Cable3', 0.5];
_plane animate ['TRD_Cable4_extend', 0];
_plane animate ['TRD_Cable4_rot', 0.5];
_plane animate ['TRD_Cable4', 0.5];
_plane animate ['TRD_Cable5_extend', 0];
_plane animate ['TRD_Cable5_rot', 0.5];
_plane animate ['TRD_Cable5', 0.5];
_plane animate ['TRD_Cable6_extend', 0];
_plane animate ['TRD_Cable6_rot', 0.5];
_plane animate ['TRD_Cable6', 0.5];
_plane animate ['TRD_Cable7_extend', 0];
_plane animate ['TRD_Cable7_rot', 0.5];
_plane animate ['TRD_Cable7', 0.5];
_plane animate ['TRD_Cable8_extend', 0];
_plane animate ['TRD_Cable8_rot', 0.5];
_plane animate ['TRD_Cable8', 0.5];
_plane animate ['TRD_Cable9_extend', 0];
_plane animate ['TRD_Cable9_rot', 0.5];
_plane animate ['TRD_Cable9', 0.5];
_plane animate ['TRD_Cable10_extend', 0];
_plane animate ['TRD_Cable10_rot', 0.5];
_plane animate ['TRD_Cable10', 0.5];
_plane animate ['TRD_Cable11_extend', 0];
_plane animate ['TRD_Cable11_rot', 0.5];
_plane animate ['TRD_Cable11', 0.5];
_plane animate ['TRD_Cable12_extend', 0];
_plane animate ['TRD_Cable12_rot', 0.5];
_plane animate ['TRD_Cable12', 0.5];

// cooldown mode!
_plane vehicleChat "Towed Radar Decoy now in cooldown mode for 30 seconds";
sleep 10;
_plane vehicleChat "Towed Radar Decoy in cooldown mode for 20 more seconds";
sleep 10;
_plane vehicleChat "Towed Radar Decoy in cooldown mode for 10 more seconds";
sleep 10;
_plane vehicleChat "Towed Radar Decoy in cooldown mode for 1 more second";

_plane animate ['TRD_Display1_2', 0];
_plane animate ['TRD_Display1_1', 1];
_plane animate ['TRD_Module', 1]; // hide after use

