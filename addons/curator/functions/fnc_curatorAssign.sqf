#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Assigns next curator to given player

    Parameter(s):
        0: Player <OBJECT>

    Return Value:
        None

    Example:
        [_player] call uksf_curator_fnc_curatorAssign
*/
if (isRemoteExecuted && {isNil "_uksf_curatorValidated"}) exitWith {};

params ["_player"];

call FUNC(pruneCurators);

if ((name _player) in GVAR(curatorPlayers)) exitWith {};

private _index = GVAR(curatorPlayers) find "";
if (_index != -1) then {
    TRACE_2("",_player,_index);
    private _curator = GVAR(curatorObjects) select _index;
    _player assignCurator _curator;
    GVAR(curatorPlayers) set [_index, name _player];
    GVAR(reservationSerial) = GVAR(reservationSerial) + 1;
    _curator setVariable [QGVAR(reservation), GVAR(reservationSerial)];
    publicVariable QGVAR(curatorObjects);
    publicVariable QGVAR(curatorPlayers);
    [QEGVAR(common,addObjectsToCurators), [allMissionObjects "all", [_curator]]] call CBA_fnc_localEvent;

    [{
        params ["_args", "_idPFH"];
        _args params ["_player", "_curator", "_timeout", "_reservation"];

        if ((getAssignedCuratorUnit _curator) == _player || {time > _timeout} || {(_curator getVariable [QGVAR(reservation), -1]) != _reservation}) exitWith {
            [_idPFH] call CBA_fnc_removePerFrameHandler;
        };

        _player assignCurator _curator;
    }, 0.5, [_player, _curator, time + 15, GVAR(reservationSerial)]] call CBA_fnc_addPerFrameHandler;
};
