#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        CargoLoaded handler for the RHICC. Slides a loaded boat aft so it hangs off the stern and clears the
        rear gunners and the last bench row. Arma refuses to load into a cargo bay that extends past the
        stern, so the bay stays inside the hull and the boat moves after loading.
        Runs only where the carrier is local.

    Parameter(s):
        0: Carrier <OBJECT>
        1: Cargo <OBJECT>

    Return Value:
        None

    Example:
        [_rhicc, _zodiac] call uksf_vehicles_fnc_seatBoatCargo
*/
#define BOAT_AFT_OFFSET 1.2

params ["_carrier", "_cargo"];

if (!local _carrier || {!(_cargo isKindOf "Ship")}) exitWith {};

private _offset = _carrier worldToModel (_cargo modelToWorld [0, 0, 0]);
_cargo attachTo [_carrier, _offset vectorAdd [0, -BOAT_AFT_OFFSET, 0]];
_cargo setDir 0;
