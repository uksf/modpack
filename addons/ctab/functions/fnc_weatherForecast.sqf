#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the Weather app forecast: the cloud and fog that the engine weather moves to, when it gets there, and whether rain is likely.
        Rain needs heavy cloud, so the forecast expects rain when the cloud target is above RAIN_OVERCAST.

    Parameter(s):
        None

    Return Value:
        Forecast text <STRING>

    Example:
        call uksf_ctab_fnc_weatherForecast
*/

private _change = nextWeatherChange;
private _cloud = overcastForecast;
private _trend = switch (true) do {
    case (_cloud > overcast + 0.05): {"thickening"};
    case (_cloud < overcast - 0.05): {"clearing"};
    default {"steady"};
};
private _rain = switch (true) do {
    case (_cloud > RAIN_OVERCAST): {"likely"};
    case (rain > 0.05): {"easing"};
    default {"unlikely"};
};

[
    "<t size='1.1'>Forecast</t>",
    format ["Cloud %1 to %2%% %3", _trend, round (100 * _cloud), ["in " + (_change call FUNC(formatDuration)), "now"] select (_change <= 0)],
    format ["Fog to %1%%, rain %2", round (100 * fogForecast), _rain]
] joinString "<br/>"
