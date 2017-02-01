/*
    Author:
        Tim Beswick

    Description:
        Called when unit gets into the helicopter. Adds UI.

    Parameter(s):
        0: Helicopter <OBJECT>
        1: Position <STRING>
        2: Unit <OBJECT>
        3: Turret <ARRAY>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli", "_position", "_unit", "_turret"];

if (player == driver _heli || player == gunner _heli) then {
    (QGVAR(metricsLayer) call BIS_fnc_rscLayer) cutRsc [QGVAR(metrics), "PLAIN", 0.01];
    GVAR(metricsHandler) = [{
        params ["_args"];
        _args params ["_heli"];

        _speedKnots = format ["%1 kn", round ((speed _heli) / 1.94)];
        _radarAltitudeFeet = format ["%1 ft", round (3.28084 * ((getPosATL _heli) select 2))];

        disableSerialization;
        _display = uiNameSpace getVariable [QGVAR(metrics), displayNull];
        (_display displayCtrl 1891) ctrlSetText _speedKnots;
        (_display displayCtrl 1892) ctrlSetText _radarAltitudeFeet;
    }, 0, [_heli]] call cba_fnc_addPerFrameHandler;
};
