{
    deleteMarkerLocal _x;
} forEach uksf_debugMarkers;
uksf_debugMarkers = [];

{
    _x params ["_logic", "_area"];
    _area params ["_a", "_b", "_angle", "_isRectangle"];

    private _position = getPos _logic;
    private _marker = createMarkerLocal [format ["uksf_debugMarker_areaShape_%1", _forEachIndex], _position];
    _marker setMarkerShapeLocal (["ELLIPSE", "RECTANGLE"] select _isRectangle); _marker setMarkerColorLocal "ColorBlue"; _marker setMarkerAlphaLocal 0.5; _marker setMarkerSizeLocal [_a, _b]; _marker setMarkerDirLocal _angle;

    uksf_debugMarkers pushBack _marker;
} forEach uksf_mission_dynamicPatrolAreas;

{
    _x params ["_logic", "_area"];
    _area params ["_a", "_b", "_angle", "_isRectangle"];

    private _position = getPos _logic;
    private _marker = createMarkerLocal [format ["uksf_debugMarker_exclude_areaShape_%1", _forEachIndex], _position];
    _marker setMarkerShapeLocal (["ELLIPSE", "RECTANGLE"] select _isRectangle); _marker setMarkerColorLocal "ColorRed"; _marker setMarkerAlphaLocal 0.5; _marker setMarkerSizeLocal [_a, _b]; _marker setMarkerDirLocal _angle;

    uksf_debugMarkers pushBack _marker;
} forEach uksf_mission_dynamicPatrolExcludeAreas;
