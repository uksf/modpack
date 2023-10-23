#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sends a text message
        Place the call in a trigger and it should trigger globally
        []

    Parameters:
        0: _intelId <STRING>

    Return value:
        Nothing
*/

(_this#1) params ["_logic"];

private _textMessage = _logic getVariable [QGVAR(intelTextString), ""];
private _intelID = _logic getVariable [QGVAR(intelID), ""];
private _intelRead = _logic getVariable [QGVAR(intelRead), false];
private _syncdObjects = synchronizedObjects _logic;

// exit if intel has already been added - covers repeatable trigger edge case
private _intelIdIndex = GVAR(intel) findIf {_x#1 == _textMessage || _x#2 == _intelId};
if (_intelIdIndex > -1) exitWith {};

// informant should be only object with this var set
private _informantIndex = _syncdObjects findIf {_x getVariable [QGVAR(notAnInformant), true] == false};
if (_informantIndex == -1) exitWith {};
private _informant = _syncdObjects select _informantIndex;
private _name = name _informant;
private _firstName = (_name splitString " ")#0;

private _hhmm = format ["%1%2:%3%4", (["", "0"] select (date select 3 < 10)), date select 3, (["", "0"] select (date select 4 < 10)), date select 4];

GVAR(intel) pushBackUnique [_firstName, _textMessage, _intelId, _intelRead, _hhmm];
publicVariable QGVAR(intel);

// get anyone with a phone
private _players = call EFUNC(mission,getPlayers);
{
    private _player = _x;
    private _cellphoneIndex = (items _player) findIf {_x == "ACE_Cellphone"};
    if (_cellphoneIndex > -1) then {
        [QGVAR(sendTextNotification), [], _player] call CBA_fnc_targetEvent;
    };
} forEach _players;
