#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Called during client sync to emit events for explosives that were placed
        and not subsequently defused. Clears the tracking map after emitting.

    Parameters:
        None

    Return Value:
        None
*/
{
    [createHashMapFromArray [
        ["type", "explosivePlaced"],
        ["explosiveClassname", _y]
    ]] call FUNC(addEvent);
} forEach GVAR(placedExplosives);

GVAR(placedExplosives) = createHashMap;
