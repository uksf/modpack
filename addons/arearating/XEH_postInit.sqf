#include "script_component.hpp"

call FUNC(registerDebugProvider);

if (GVAR(ratingAreaModules) isNotEqualTo []) then {
    GVAR(ratingAreasEnabled) = true;

    if (isServer) then {
        {
            private _data = _x call FUNC(initRatingArea);
            GVAR(ratingAreas) pushBack _data;
        } forEach GVAR(ratingAreaModules);

        [true] call FUNC(broadcastRatingAreas);
        [] call FUNC(recalculateGlobalRatingEvents);
    };
};
