#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the Weather app with sunrise, sunset, moon, sky, wind, temperature, pressure, and humidity.
        The temperature and pressure come from ACE weather at the player's altitude, and at the oxygen altitude for jump planning.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_weatherRefresh
*/
if (isNull APP_CTRL(weatherInfo)) exitWith {};

private _clock = {
    params ["_hours"];
    if (_hours < 0) exitWith {"none"};
    [_hours, "HH:MM"] call BIS_fnc_timeToString
};

(date call BIS_fnc_sunriseSunsetTime) params ["_sunrise", "_sunset"];
private _phase = moonPhase date;
private _phaseName = switch (true) do {
    case (_phase < 0.06 || {_phase > 0.94}): {"new"};
    case (_phase < 0.44): {"waxing"};
    case (_phase <= 0.56): {"full"};
    default {"waning"};
};

private _windSpeed = vectorMagnitude [wind select 0, wind select 1];
private _windFrom = round ((((-(wind select 0)) atan2 (-(wind select 1))) + 360) mod 360);
private _altitude = (getPosASL cTab_player) select 2;

[APP_CTRL(weatherInfo), [
    format ["Time: %1, sunrise %2, sunset %3", [dayTime, "HH:MM"] call BIS_fnc_timeToString, _sunrise call _clock, _sunset call _clock],
    format ["Moon: %1, %2%% light", _phaseName, round (100 * moonIntensity)],
    format ["Cloud: %1%%, fog: %2%%, rain: %3%%", round (100 * overcast), round (100 * fog), round (100 * rain)],
    format ["Wind: %1 m/s from %2", _windSpeed toFixed 1, _windFrom],
    format ["Temperature: %1 C at %2 m ASL, %3 C at %4 m ASL",
        (_altitude call ace_weather_fnc_calculateTemperatureAtHeight) toFixed 1, round _altitude,
        (JUMP_OXYGEN_ALTITUDE call ace_weather_fnc_calculateTemperatureAtHeight) toFixed 1, JUMP_OXYGEN_ALTITUDE],
    format ["Pressure: %1 hPa, humidity: %2%%", round (_altitude call ace_weather_fnc_calculateBarometricPressure), round (100 * ace_weather_currentHumidity)]
]] call FUNC(setInfo);
