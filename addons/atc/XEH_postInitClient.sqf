#include "script_component.hpp"

["visibleMap", {
    params ["_player", "_mapOn"];

    if (!(QGVAR(terminal) in (assignedItems _player)) || {(vehicle _player) != _player}) exitWith {};

    if (_mapOn) then {
        [_player, true] call FUNC(loop);
    } else {
        [_player, false] call FUNC(loop);
    };
}] call CBA_fnc_addPlayerEventHandler;
