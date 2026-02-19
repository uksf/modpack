#include "script_component.hpp"
/*
    Author:
        BourbonWarfare https://github.com/BourbonWarfare/POTATO/blob/master/addons/miscFixes/XEH_serverPostInit.sqf

    Description:
        Updates headless client position based on average of groups local to the headless client and player positions

    Parameters:
        None

    Return value:
        Nothing
*/

if (!isServer || !GVAR(updateHeadlessClientPosition)) exitWith {};

private _playerPositions = [0, [0, 0, 0]];

private _hcs = [[], [], []];
{
    (_hcs#0) pushBack owner _x;
    (_hcs#1) pushBack [0, [0, 0, 0]];
    (_hcs#2) pushBack _x;
} forEach ((entities "HeadlessClient_F") select {isPlayer _x});

{
    if (!(_x in (_hcs#2))) then {
        private _index = (_hcs#0) find groupOwner _x;

        if (_index > -1 && {(vehicle leader _x) isKindOf "Land"}) then {
            private _groupPositions = ((_hcs#1)#_index);
            _groupPositions set [0, (_groupPositions#0) + 1];
            _groupPositions set [1, (_groupPositions#1) vectorAdd (getPos leader _x)];
        } else {
            {
                if (isPlayer _x && {(vehicle _x) isKindOf "Land"}) then {
                    _playerPositions set [0, (_playerPositions#0) + 1];
                    _playerPositions set [1, (_playerPositions#1) vectorAdd (getPos _x)];
                };
            } forEach (units _x);
        };
    };
} forEach allGroups;

private _playerAvgPos = [];
_playerPositions params ["_playerCount", "_playerPosSum"];
if (_playerCount > 0) then {
    _playerAvgPos = _playerPosSum vectorMultiply (1 / _playerCount);
};

{
    ((_hcs#1)#_forEachIndex) params ["_groupCount", "_position"];
    if (_groupCount > 0) then {
        private _groupAvgPos = _position vectorMultiply (1 / _groupCount);
        if (_playerAvgPos isNotEqualTo []) then {
            _groupAvgPos = (_playerAvgPos vectorAdd _groupAvgPos) vectorMultiply 0.5;
        };

        _x setPos _groupAvgPos;
    };
} forEach (_hcs#2);

[FUNC(updateHeadlessClientPosition), [], GVAR(updateHeadlessClientDelay)] call CBA_fnc_waitAndExecute;
