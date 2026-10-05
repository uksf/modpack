// Every CfgVehicles class's resolved hitpoints: vehicle level and each turret path.
private _walk = {
    params ["_cfg", "_path", "_out"];
    {
        private _tp = _path + "/" + configName _x;
        _out pushBack ("T" + _tp);
        { _out pushBack (_tp + ":" + configName _x) } forEach ("true" configClasses (_x >> "HitPoints"));
        [_x, _tp, _out] call _walk;
    } forEach ("true" configClasses (_cfg >> "Turrets"));
};
{
    private _out = ("true" configClasses (_x >> "HitPoints")) apply {":" + configName _x};
    [_x, "", _out] call _walk;
    private _s = _out joinString ",";
    private _n = configName _x;
    for "_i" from 0 to (count _s - 1) step 900 do { diag_log text format ["HA|%1|%2", _n, _s select [_i, 900]] };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));
diag_log text "HA|<done>|";
call vc_fnc_done;
