#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        PreInit for:
            - Init air locations
            - Init radar locations

    Parameters:
        None

    Return value:
        Nothing
*/

GVAR(aaLocations) = [];
GVAR(airspaceCentre) = [];
GVAR(enemyAirfields) = [];

GVAR(airSpawns) = [];
GVAR(aaSpawns) = []; // for jets
GVAR(heliLocations) = [];
