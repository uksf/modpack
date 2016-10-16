/*
	Author:
		Tim Beswick

	Description:
		Equips pilot loadout

	Parameter(s):
		None

	Return Value:
		None
*/
#include "script_component.hpp"

removeAllWeapons player;
removeAllItems player;
removeAllAssignedItems player;
removeUniform player;
removeVest player;
removeBackpack player;
removeHeadgear player;
removeGoggles player;

player forceAddUniform "UK3CB_BAF_U_HeliPilotCoveralls_RAF";
for "_i" from 1 to 8 do {player addItemToUniform "ACE_quikclot";};
for "_i" from 1 to 2 do {player addItemToUniform "ACE_morphine";};
player addItemToUniform "ACE_IR_Strobe_Item";
player addItemToUniform "ACE_EarPlugs";
player addItemToUniform "SmokeShell";
player addItemToUniform "Chemlight_red";
player addVest "V_mas_uk_TacVest_p";
player addItemToVest "ACE_MapTools";
player addItemToVest "ACE_Flashlight_XL50";
for "_i" from 1 to 15 do {player addItemToVest "ACE_packingBandage";};
player addItemToVest "SmokeShellBlue";
player addItemToVest "SmokeShellOrange";
player addItemToVest "SmokeShellRed";
player addItemToVest "SmokeShellYellow";
player addBackpack "UKSF_RadioPack";
for "_i" from 1 to 2 do {player addItemToBackpack "ACE_bloodIV_500";};
player addItemToBackpack "ACE_personalAidKit";
player addItemToBackpack "ACE_surgicalKit";
for "_i" from 1 to 5 do {player addItemToBackpack "ACE_epinephrine";};
for "_i" from 1 to 10 do {player addItemToBackpack "ACE_elasticBandage";};
for "_i" from 1 to 10 do {player addItemToBackpack "ACE_packingBandage";};
player addItemToBackpack "ACRE_PRC117F_ID_1";
player addItemToBackpack "ACRE_PRC117F_ID_2";
player addHeadgear "UK3CB_BAF_H_PilotHelmetHeli_A";

player linkItem "ItemCompass";
player linkItem "ItemWatch";
player linkItem "ItemRadioAcreFlagged";
player linkItem "B_UavTerminal";
player linkItem "ACE_NVG_Pilot";

player setVariable [QGVAR(loadoutPilot), true, false];
