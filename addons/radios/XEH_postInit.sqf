#include "script_component.hpp"

call FUNC(setChannelNames);

["vehicle", {
    params ["", "_vehicle"];
    [FUNC(initRacks), [_vehicle]] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addPlayerEventHandler;

if (vehicle acre_player != acre_player) then {
    [FUNC(initRacks), [vehicle acre_player]] call CBA_fnc_execNextFrame;
};

[FUNC(handleCustomSignal)] call acre_api_fnc_setCustomSignalFunc;
