/*
	Author:
		Tim Beswick

	Description:
		Equips ATC loadout

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

player forceAddUniform "UKSF_U_ATC";
player addItemToUniform "ACE_Flashlight_XL50";
player addItemToUniform "ACE_MapTools";
for "_i" from 1 to 3 do {player addItemToUniform "ACE_IR_Strobe_Item";};
player addItemToUniform "ACE_EarPlugs";
for "_i" from 1 to 2 do {player addItemToUniform "Chemlight_blue";};
for "_i" from 1 to 2 do {player addItemToUniform "Chemlight_green";};
for "_i" from 1 to 2 do {player addItemToUniform "Chemlight_red";};
for "_i" from 1 to 2 do {player addItemToUniform "Chemlight_yellow";};
player addItemToUniform "ACE_HandFlare_Red";
player addItemToUniform "ACE_HandFlare_Yellow";
player addItemToUniform "ACE_HandFlare_Green";
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellBlue";};
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellGreen";};
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellOrange";};
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellPurple";};
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellRed";};
for "_i" from 1 to 2 do {player addItemToUniform "SmokeShellYellow";};
player addItemToUniform "Laserbatteries";
player addBackpack "UKSF_ATCPack";
player addHeadgear "UKSF_RAF_Beret";
player addGoggles "G_Aviator";

player addWeapon "UK3CB_BAF_Soflam_Laserdesignator";

player linkItem "ItemMap";
player linkItem "ItemCompass";
player linkItem "ItemWatch";
player linkItem "ItemRadioAcreFlagged";
player linkItem "B_UavTerminal";

player setVariable [QGVAR(loadoutPilot), false, false];
