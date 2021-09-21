#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles debug info on and off, displaying areas and values on the map

    Parameters:
        None

    Return value:
        None
*/

if (GVAR(debugMode)) exitWith {
    GVAR(debugMode) = false;
    [GVAR(debugPFHID)] call CBA_fnc_removePerFrameHandler;
    {deleteMarkerLocal _x} forEach GVAR(debugMarkers);
    GVAR(debugMarkers) = [];
};

GVAR(debugMode) = true;

GVAR(debugPFHID) = [{
    {deleteMarkerLocal _x} forEach GVAR(debugMarkers);
    GVAR(debugMarkers) = [];

    private _globalRating = call FUNC(getGlobalRating);
    _globalRating params ["_ratings", "_percentages"];
    _ratings params ["_globalStart", "_globalCurrent", "_globalMin", "_globalMax"];
    _percentages params ["_percentageStart", "_percentageCurrent"];

    private _marker = createMarkerLocal [QGVAR(debugMarker_globalText), [worldSize, worldSize, 0]];
    _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal "ColorBlue"; _marker setMarkerTextLocal "Global Ratings (Start, Current, Min, Max)";
    GVAR(debugMarkers) pushBack _marker;

    _marker = createMarkerLocal [QGVAR(debugMarker_globalRatings), [worldSize, worldSize - 250, 0]];
    _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal "ColorBlue"; _marker setMarkerTextLocal (format ["Ratings: %1, %2, %3, %4", _globalStart, _globalCurrent, _globalMin, _globalMax]);
    GVAR(debugMarkers) pushBack _marker;

    _marker = createMarkerLocal [QGVAR(debugMarker_globalPercentages), [worldSize, worldSize - 500, 0]];
    _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal "ColorBlue"; _marker setMarkerTextLocal (format ["Percentages: %1, %2", _percentageStart, _percentageCurrent]);
    GVAR(debugMarkers) pushBack _marker;

    {
        private _areaInfo = [_x] call FUNC(getAreaRating);
        _areaInfo params ["_id", "_displayName", "_logic", "_area", "_ratings", "_percentages"];
        _area params ["_a", "_b", "_angle", "_isRectangle"];
        _ratings params ["_ratingStart", "_ratingCurrent", "_ratingMin", "_ratingMax"];
        _percentages params ["_percentageStart", "_percentageCurrent"];

        private _position = getPos _logic;

        private _colour = "ColorGreen";
        if (_percentageCurrent < 25) then {
            _colour = "ColorRed";
        } else {
            if (_percentageCurrent < 50) then {
                _colour = "ColorOrange";
            } else {
                if (_percentageCurrent < 75) then {
                    _colour = "ColorYellow";
                };
            };
        };

        private _marker = createMarkerLocal [format [QGVAR(debugMarker_areaId_%1), _forEachIndex], _position];
        _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal _colour; _marker setMarkerTextLocal (format ["Area ID: %1", _id]);
        GVAR(debugMarkers) pushBack _marker;

        _marker = createMarkerLocal [format [QGVAR(debugMarker_areaDisplayName_%1), _forEachIndex], [_position#0, _position#1 - 100, _position#2]];
        _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal _colour; _marker setMarkerTextLocal (format ["Area Name: %1", _displayName]);
        GVAR(debugMarkers) pushBack _marker;

        _marker = createMarkerLocal [format [QGVAR(debugMarker_areaText_%1), _forEachIndex], [_position#0, _position#1 - 200, _position#2]];
        _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal _colour; _marker setMarkerTextLocal "Area Ratings (Start, Current, Min, Max)";
        GVAR(debugMarkers) pushBack _marker;

        _marker = createMarkerLocal [format [QGVAR(debugMarker_areaRatings_%1), _forEachIndex], [_position#0, _position#1 - 300, _position#2]];
        _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal _colour; _marker setMarkerTextLocal (format ["Ratings: %1, %2, %3, %4", _ratingStart, _ratingCurrent, _ratingMin, _ratingMax]);
        GVAR(debugMarkers) pushBack _marker;

        _marker = createMarkerLocal [format [QGVAR(debugMarker_areaPercentages_%1), _forEachIndex], [_position#0, _position#1 - 400, _position#2]];
        _marker setMarkerShapeLocal "ICON"; _marker setMarkerTypeLocal "hd_dot"; _marker setMarkerColorLocal _colour; _marker setMarkerTextLocal (format ["Percentages: %1, %2", _percentageStart, _percentageCurrent]);
        GVAR(debugMarkers) pushBack _marker;

        _marker = createMarkerLocal [format [QGVAR(debugMarker_areaShape_%1), _forEachIndex], _position];
        _marker setMarkerShapeLocal (["ELLIPSE", "RECTANGLE"] select _isRectangle); _marker setMarkerColorLocal _colour; _marker setMarkerAlphaLocal 0.5; _marker setMarkerSizeLocal [_a, _b]; _marker setMarkerDirLocal _angle;
        GVAR(debugMarkers) pushBack _marker;
    } forEach GVAR(ratingAreas);
}, 5, []] call CBA_fnc_addPerFrameHandler;
