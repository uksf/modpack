call compile preprocessFileLineNumbers "settings.sqf";

if (!lc_roundTrip) exitWith {};

lc_customSaved = [1.5, -0.000123, 12345.678, "quote "" and, comma", true, [1, [2, [3]]], createHashMapFromArray [["k", 1], ["n", [true, "x"]]]];
["lc_custom", {lc_customSaved}, {
    params ["_data"];
    lc_customLoaded = _data;
}] call uksf_persistence_fnc_registerSerializer;
