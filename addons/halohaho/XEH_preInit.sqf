#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(oxygenConnected) = false;
GVAR(fatigueZeroed) = false;

private _action = [QGVAR(linkOxygen),"Link Oxygen","",{

    GVAR(oxygenConnected) = true;
    playSound QGVAR(hiss);
    _target removeItem "uksf_halohaho_haloAirSupply";

    [{
        [{
            if (!GVAR(oxygenConnected)) exitWith {[_this#1] call CBA_fnc_removePerFrameHandler};
            playSound QGVAR(breatheOxygenShort);
        }, 5, []] call CBA_fnc_addPerFrameHandler;
    }, 2] call cba_fnc_waitAndExecute;

}, {(goggles _player == "G_mas_usl_jumpmask") && ([_player, "uksf_halohaho_haloAirSupply"] call ace_common_fnc_hasItem) && !GVAR(oxygenConnected)}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

["CAManBase", "init", {
    params ["_unit"];
    GVAR(startingHeight) = (getPosASL _unit) select 2;
}, true, [], true] call CBA_fnc_addClassEventHandler;

ADDON = true;
