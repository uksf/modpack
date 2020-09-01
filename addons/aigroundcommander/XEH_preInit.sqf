#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

if (!isServer) exitWith {};

["O_Soldier_base_F","init", {
    _this#0 addMPEventHandler ["MPKilled", {
        params ["", "_killer", "_instigator"];
        if (!(_killer isKindOf "Air")) then {
            GVAR(enemyAggressionLevel) = GVAR(enemyAggressionLevel) + 1;
            if (_instigator isEqualTo objNull || !isPlayer _instigator || surfaceIsWater (getPos _instigator)) exitWith {};
            private _index = GVAR(playersThatHaveFired) findIf {_instigator == (_x#0)};
            if (_index != -1) then {
                GVAR(playersThatHaveFired) set [_index, [_instigator,time]];
            } else {
                GVAR(playersThatHaveFired) pushBack _instigator;
            };
        };
}]}] call CBA_fnc_addClassEventHandler;

GVAR(stagingAreas) = [];

// spawn locations
GVAR(infantrySpawns) = [];
GVAR(carSpawns) = [];
GVAR(apcSpawns) = [];
GVAR(tankSpawns) = [];

// unit cap
GVAR(maxUnitCount) = 80;
GVAR(currentUnitCount) = 0;

// response groups
GVAR(responseGroups) = [];
GVAR(numberOfStayBehindGroups) = 1;
GVAR(tier1ResponseDeployed) = 0;
GVAR(tier2ResponseDeployed) = 0;
GVAR(readyAtStagingArea) = 0;


// up to date aggression level variable
GVAR(enemyAggressionLevel) = 0;

// list of players that have fired their weapon
GVAR(playersThatHaveFired) = [];

ADDON = true;
