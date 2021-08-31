#include "script_component.hpp"

if (GVAR(ratingAreaModules) isNotEqualTo []) exitWith {
    GVAR(ratingAreasEnabled) = true;

    if (hasInterface) then {
        call FUNC(addDebugActions);
    };

    {
        private _data = _x call FUNC(initRatingArea);
        GVAR(ratingAreas) pushBack _data;
    } forEach GVAR(ratingAreaModules);

    [] call FUNC(recalculateGlobalRatingEvents);
};
