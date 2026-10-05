// For every class: each HitTurret/HitGun/HitCommanderTurret entry with the resolved owner of the entry and of
// its turret, so an action's reach is known exactly.
private _names = ["hitturret", "hitgun", "hitcommanderturret"];
private _walk = {
    params ["_cfg", "_path"];
    {
        private _tp = _path + "/" + configName _x;
        private _t = _x;
        { if (toLowerANSI configName _x in _names) then { diag_log text format ["HO|%1|%2|%3|%4|%5", _cls, _tp, configName _x, str _x, str _t] } } forEach ("true" configClasses (_t >> "HitPoints"));
        [_t, _tp] call _walk;
    } forEach ("true" configClasses (_cfg >> "Turrets"));
};
{
    private _cls = configName _x;
    { if (toLowerANSI configName _x in _names) then { diag_log text format ["HO|%1||%2|%3|", _cls, configName _x, str _x] } } forEach ("true" configClasses (_x >> "HitPoints"));
    [_x, ""] call _walk;
} forEach ("true" configClasses (configFile >> "CfgVehicles"));
call vc_fnc_done;
