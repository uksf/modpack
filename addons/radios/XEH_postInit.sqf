#include "script_component.hpp"

if (hasInterface) then {
    [] call FUNC(setChannelNames);
};

["vehicle", {
    params ["_player", "_vehicle"];
    [FUNC(initRacks), [_vehicle, _player]] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addPlayerEventHandler;

if (vehicle acre_player != acre_player) then {
    [FUNC(initRacks), [vehicle acre_player, acre_player]] call CBA_fnc_execNextFrame;
};
