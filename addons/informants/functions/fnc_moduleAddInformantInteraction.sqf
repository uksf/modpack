#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds informant interaction.

    Parameters:
        0: _logic <OBJECT>

    Return value:
        Nothing
*/

(_this#1) params ["_logic"];

private _informantCost = _logic getVariable [QGVAR(informantCost), 0];
private _informantArray = synchronizedObjects _logic select {_x isKindOf "CAManBase"};
private _informant = _informantArray#0;

private _action = [QGVAR(payToInform),"Pay to inform","",{
    params ["_target", "_player", "_actionParams"];
    _actionParams params ["_informantCost"];

    private _playerMoney = _player getVariable [QGVAR(playerMoney), 0];
    if (_playerMoney < _informantCost || _playerMoney == 0) exitWith {0 cutText [format["<t size='1.5'>%1: <br/>Sorry, I'm taking a risk here. It's $%2 or nothing</t>",  name _target, _informantCost], "PLAIN DOWN", -1, true, true]; };

    _player setVariable [QGVAR(playerMoney), _playerMoney - _informantCost];
    _player removeItem "Money_bunch";

    0 cutText [format["<t size='1.5'>%1: <br/>Here is my number, I'll let you know if I hear anything.</t>",  name _target], "PLAIN DOWN", -1, true, true];

    _target setVariable [QGVAR(notAnInformant), false, true];
},{_target getVariable [QGVAR(notAnInformant), true] || !alive _target}, {}, [_informantCost]] call ace_interact_menu_fnc_createAction;
[_informant, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
