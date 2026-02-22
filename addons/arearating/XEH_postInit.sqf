#include "script_component.hpp"

if (isServer) then {
    [QEGVAR(zeus,registerVisualiseProvider), ["arearating", {call FUNC(getVisualisationData)}]] call CBA_fnc_localEvent;
};

if (GVAR(ratingAreaModules) isNotEqualTo []) then {
    GVAR(ratingAreasEnabled) = true;

    if (hasInterface) then {
        call FUNC(addDebugActions);
    };

    if (isServer) then {
        {
            private _data = _x call FUNC(initRatingArea);
            GVAR(ratingAreas) pushBack _data;
        } forEach GVAR(ratingAreaModules);

        [true] call FUNC(broadcastRatingAreas);
        [] call FUNC(recalculateGlobalRatingEvents);
    };
};
