/*
	Author:
		Tim Beswick, Alganthe

	Description:
		Contains several code snippets by several authors
*/

//Adds zeus to named player (increment nubmer after UKSF_dummyLogicGroup and UKSF_curator)
UKSF_dummyLogicGroup1 = creategroup sideLogic;
_dummy = UKSF_dummyLogicGroup1 createunit ["ModuleCurator_F", [0, 90, 90], [], 0.5, "NONE"];
_name = "UKSF_curator1";
_dummy setvariable ["text", "UKSF_curator1"];
_dummy setvariable ["uksfIgnore", true];
_dummy setvariable ["Addons", 2, true];
_dummy setvariable ["vehicleinit","_this setvariable ['Addons',2,true];"];
call compile (_name + " = _dummy");
publicVariable _name;
_dummy addCuratorAddons activatedAddons;
_dummy addCuratorAddons ["Ares", "curatorPresets_Module"];
{
	if(name _x == "SqnLdr.Beswick.T") then {
		_x assignCurator UKSF_curator1;
	};
} forEach allPlayers;

//Disables fatigue & stamina
player enableStamina false; player enablefatigue false; player addEventHandler ['Respawn',{player enableStamina false; player enablefatigue false; }];

//Spawns bombs on position
[_this select 0] spawn {sleep 1; "FIR_GBU39" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 0];};
[_this select 0] spawn {sleep 1; "EAWS_SCALP_ammo" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 0];};
[_this select 0] spawn {sleep 1; "FIR_GBU10" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 0];};
[_this select 0] spawn {sleep 1; "UK3CB_BAF_M_Hellfire_K" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 1];};
[_this select 0] spawn {sleep 1; "UK3CB_BAF_M_Hellfire_L" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 1];};
[_this select 0] spawn {sleep 1; "UK3CB_BAF_M_Hellfire_N" createVehicle [(_this select 0) select 0, (_this select 0) select 1, 1];};
[] spawn {
	sleep 3;"EAWS_SCALP_ammo" createVehicle [3275,6000,0];
	sleep 0.1;"FIR_GBU10" createVehicle [3275,6050,0];
	sleep 0.1;"FIR_GBU39" createVehicle [3275,6100,0];
};

//Switches named animation for named player
{
	{
		if(name _x == "SqnLdr.Beswick.T") then {
			_x switchMove "passenger_injured_medevac_truck01";
			//_x switchMove "Acts_EpicSplit_Out";
		};
	} forEach allPlayers;
} remoteExec ["bis_fnc_call", 0];

//Fully heals units
[_this select 1, _this select 1] call ace_medical_fnc_treatmentAdvanced_fullHealLocal;
[player, player] call ace_medical_fnc_treatmentAdvanced_fullHealLocal;
player setVariable ["ace_medical_allowDamage", false];

//Disables compass handler for UAV controler
{if(getConnectedUAV player == objNull) then {[compass_handler] call CBA_fnc_removePerFrameHandler};} remoteExec ["bis_fnc_call", -2];

//Sets texture for object (this is for the littlebird)
(_this select 1) setObjectTextureGlobal [0,"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"];
_skins = [
	"A3\Air_F\Heli_Light_01\Data\Heli_Light_01_ext_Blufor_CO.paa",
	"A3\Air_F\Heli_Light_01\Data\heli_light_01_ext_uni_mc.paa",
	"A3\Air_F\Heli_Light_01\Data\heli_light_01_ext_indp_co.paa",
	"A3\Air_F\Heli_Light_01\Data\heli_light_01_ext_co.paa",
	"A3\Air_F\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa",
	"A3\Air_F\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa",
	"A3\Air_F\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"
];

Land_i_House_Small_03_V1_F

//Disables simulation for all units except players
{
	if(!(isPlayer _x)) then {
		_x enableSimulation false;
	}
} forEach allUnits;

//Adds weapons for typhoon loadout
{_plane removeWeapon _x} forEach (weapons _plane);
{_plane removeWeapon _x} forEach (weapons _plane);
_plane addmagazine "240Rnd_CMFlare_Chaff_Magazine";
_plane addmagazine "EAWS_150Rnd_BK27";
_plane addmagazine "EAWS_LITENING_POD";
_plane addmagazine "FIR_gbu12_1rnd_M";
_plane addmagazine "EAWS_2xRackTriple";
_plane addmagazine "EAWS_SCALP_mag2x";
_plane addmagazine "EAWS_2xRackDual";
_plane addmagazine "EAWS_PYLONEMPTY_x6";
_plane addmagazine "FIR_GBU39_6rnd_M";
_plane addmagazine "EAWS_PYLONEMPTY_x6";
_plane addmagazine "EAWS_Brimstone_mag4x";
_plane addmagazine "EAWS_PYLONEMPTY_x2";
_plane addmagazine "FIR_AIM120_4rnd_M";
_plane addmagazine "FIR_GBU10_1rnd_M";
_plane addweapon "fir_MasterArm";
_plane addweapon "UK3CB_BAF_CMFlareLauncher";
_plane addweapon "EAWS_BK27";
_plane addweapon "EAWS_AIM120";
_plane addweapon "EAWS_BrimstoneLauncher";
_plane addweapon "EAWS_SCALPLauncher";
_plane addweapon "FIR_GBU39_EF2000";
_plane addweapon "FIR_GBU12_EF2000";
_plane addweapon "FIR_GBU10";

//Sets units as civilian when conditions met
hiddenHandler = [{
	if(currentWeapon player == "" && primaryWeapon player == "" && secondaryWeapon player == "") then {
		if(!(player getVariable ["CAPTIVESET", false])) then {
			player setCaptive true;
			player setVariable ["CAPTIVESET", true];
		};
	} else {
		if(player getVariable ["CAPTIVESET", false]) then {
			player setCaptive false;
			player setVariable ["CAPTIVESET", false];
		};
	};
}, 5, []] call cba_fnc_addPerFrameHandler;
waitUntil {!alive player};
[hiddenHandler] call CBA_fnc_removePerFrameHandler;

//Mortar on trigger-detected unit random position
(getposatl (thislist select 0)) params ["_x", "_y" "_z"];
_x = random (_x - 100, _x, _x + 100);
_y = random (_y - 100, _y, _y + 100);
EnMort1 commandArtilleryFire [[_x, _y, _z]], "8Rnd_82mm_Mo_shells", 6];

// finding a player var based on his name
(playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull]);

// kick everyone out of vehicle
{moveOut _x} foreach (crew (vehicle (playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull])));

// hint an other player
["", ""] remoteExecCall ["hintC", (playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull])];

// all units to zeus
{
    _x addCuratorEditableObjects [allUnits, false];
} forEach allCurators;

// killing player
(playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull]) call BIS_fnc_neutralizeUnit;

(playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull]) setDamage 1;

// enable / disable stamina for player
(playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull]) enableStamina bool;

// fuck / unfuck this person inputs
true remoteExec ["disableUserInput", (playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull])];

// disable action menu
[[],{{inGameUISetEventHandler [_x, ""]} forEach ["PrevAction", "Action", "NextAction"]}] remoteExec ["BIS_fnc_call", (playableUnits select {toUpper (name _x) == toUpper ""} param [0, objNull])]

// base protection
["BASE", position (playableUnits select {toUpper (name _x) == toUpper "alganthe"} param [0, objNull])] remoteExec ["createMarker",-2,true];

player ["Fired", {m
    params ["_unit", "_weapon", "", "", "", "", "_projectile"];

    if (_unit distance2D (getMarkerPos "BASE") < 300) then {
        deleteVehicle _projectile;
        ["Don't goof at base", "Hold your horses soldier, don't throw, fire or place anything inside the base."] remoteExecCall ["hintC", _unit];
    }
}] remoteExec ["addEventHandler", -2, true];

// mortar truck
_reward = createVehicle ["B_G_Offroad_01_repair_F", getMarkerPos "smReward1",smMarkerList,0,"NONE"];
_mortar = createVehicle ["B_Mortar_01_F", getMarkerPos "smReward1",smMarkerList,0,"NONE"];
_mortar attachTo [_reward,[0,-2.5,.3]];

//city destruction magic
[4] remoteExec ["bis_fnc_earthquake",-2];
_boom = {
    params ["_startingPos", ["_buildingTypes", ["house"]], ["_radius", 500]];
    _buildings = nearestObjects [_startingPos, _buildingTypes, _radius];
    _buildings apply {_x setDamage 1};
};
[position player] call _boom;
