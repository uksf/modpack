#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets mortar fuses in crate

    Parameter(s):
        0: Crate <OBJECT>
        1: Fuse mode <SCALAR>

    Return Value:
        None
*/
params ["_crate", ["_fuseMode", 0, [0]]];

(getMagazineCargo _crate) params ["_cargoMagazines", "_cargoMagazineQuantities"];
clearMagazineCargoGlobal _crate;

private _regex = [
    ["(UK3CB_BAF_1Rnd_.*_Mo_)(AB_)(Shells)", "$1$3"], // Fuse Mode 0: Impact
    ["(UK3CB_BAF_1Rnd_.*_Mo_)(Shells)", "$1AB_$2"] // Fuse Mode 1: Proximity (Airburst)
] select _fuseMode;

_cargoMagazines = _cargoMagazines apply {
    _x regexReplace _regex;
};

{
    _crate addMagazineCargoGlobal [_x, _cargoMagazineQuantities#_forEachIndex];
} forEach _cargoMagazines;
