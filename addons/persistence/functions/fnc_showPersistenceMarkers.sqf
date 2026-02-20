#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles 3D display of persistence marker (logistics marker ammo) positions

    Parameter(s):
        None

    Return Value:
        None
*/

[QGVAR(requestPersistenceMarkers), [player]] call CBA_fnc_serverEvent;

GVAR(persistenceMarkersPFHID) = [{
    {
        _x params ["_pos"];

        drawIcon3D ["", [1,0,1,1], _pos, 0.5, 0.5, 0, format ["Marker (%1m)", round (player distance _pos)], 0, 0.03, "TahomaB", "center"];

        private _segments = 24;
        private _step = 360 / _segments;
        for "_i" from 0 to (_segments - 1) do {
            private _a1 = _i * _step;
            private _a2 = (_i + 1) * _step;
            private _p1 = [(_pos#0) + CENTRE_RADIUS * sin _a1, (_pos#1) + CENTRE_RADIUS * cos _a1, _pos#2];
            private _p2 = [(_pos#0) + CENTRE_RADIUS * sin _a2, (_pos#1) + CENTRE_RADIUS * cos _a2, _pos#2];
            drawLine3D [_p1, _p2, [1,0,1,0.5]];
        };
    } forEach GVAR(persistenceMarkerPositions);
}, 0] call CBA_fnc_addPerFrameHandler;

hint format ["Showing %1 persistence markers (radius %2m)", count GVAR(persistenceMarkerPositions), CENTRE_RADIUS];
