#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(intel) = []; // [["John", "They're over there!", "id_1345", false], ["Bob", "They're coming!", "id_2542", false]]


// add check phone interaction
["CAManBase", "init", {
    private _unit = _this#0;

    if (!(isPlayer _unit)) exitWith {};

    private _action = [QGVAR(checkPhone),"Check Phone","",{
        createDialog "MobilePhoneBase";
    },{_player getVariable [QGVAR(showPhoneInteraction), false]}] call ace_interact_menu_fnc_createAction;
    [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject; // TO DO: Move to equipment menu
}] call CBA_fnc_addClassEventHandler;


// check money when loadout changes
["loadout", {
    private _items = itemsWithMagazines player;
    private _moneyNotesCount = {_x == "Money_bunch"} count _items;
    private _totalMoney = _moneyNotesCount * 150;

    player setVariable [QGVAR(playerMoney), _totalMoney];
}] call CBA_fnc_addPlayerEventHandler;


// check for phone when loadout changes
["loadout", {
    private _items = itemsWithMagazines player;

    if (!("ACE_Cellphone" in _items)) exitWith {};

    player setVariable [QGVAR(showPhoneInteraction), true];
}] call CBA_fnc_addPlayerEventHandler;


// send text event
[QGVAR(sendTextNotification), {playSound QGVAR(phoneVibrate)}] call CBA_fnc_addEventHandler;


ADDON = true;
