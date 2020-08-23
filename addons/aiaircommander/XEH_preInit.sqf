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

GVAR(aaSites) = [];
GVAR(airspaceCentre) = [];
GVAR(enemyAirfields) = [];

GVAR(airSpawnLocations) = []; // for jets
GVAR(aaSpawnLocations) = []; 
GVAR(heliLocations) = [];
