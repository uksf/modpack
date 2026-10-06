// Template: replace __LIST__ with the root classes. Logs GS|class|lod|selection for every glass selection.
{
    private _v = createVehicle [_x, [1000 + 80 * (_forEachIndex mod 10), 1000 + 80 * floor (_forEachIndex / 10), 0], [], 0, "CAN_COLLIDE"];
    uiSleep 0.3;
    private _cls = _x;
    { private _lod = _x; { if ((toLowerANSI _x) find "glass" >= 0) then { diag_log text format ["GS|%1|%2|%3", _cls, _lod, _x] } } forEach (_v selectionNames _lod) } forEach ["HitPoints", "Memory", "FireGeometry"];
    deleteVehicle _v;
} forEach __LIST__;
call vc_fnc_done;
