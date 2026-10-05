private _list = __LIST__;
private _walk = {
    params ["_cfg", "_path"];
    {
        private _t = _x;
        private _tp = _path + [configName _t];
        private _local = (configProperties [_t >> "HitPoints", "isClass _x", false]) apply {toLowerANSI configName _x};
        {
            diag_log text format ["DH|%1|%2|%3|%4|%5|%6", _cls, _tp joinString "/", configName _x, getText (_x >> "name"), [0, 1] select (toLowerANSI configName _x in _local), configName inheritsFrom (_t >> "HitPoints")];
        } forEach ("true" configClasses (_t >> "HitPoints"));
        [_t, _tp] call _walk;
    } forEach ("true" configClasses (_cfg >> "Turrets"));
};
private _models = createHashMap;
{
    private _cls = _x;
    private _c = configFile >> "CfgVehicles" >> _cls;
    { diag_log text format ["DV|%1|%2|%3|%4", _cls, configName _x, getText (_x >> "name"), [0, 1] select (configName _x in ((configProperties [_c >> "HitPoints", "isClass _x", false]) apply {configName _x}))] } forEach ("true" configClasses (_c >> "HitPoints"));
    [_c, []] call _walk;
    private _m = toLowerANSI getText (_c >> "model");
    diag_log text format ["DM|%1|%2", _cls, _m];
    if (!(_m in _models) && {getNumber (_c >> "scope") > 0}) then { _models set [_m, _cls] };
} forEach _list;
{
    private _v = createVehicleLocal [_y, [5000, 5000, 1000], [], 0, "CAN_COLLIDE"];
    if (!isNull _v) then {
        private _s = _v selectionNames "HitPoints";
        for "_i" from 0 to (count _s - 1) step 25 do { diag_log text format ["DS|%1|%2", _x, (_s select [_i, 25]) joinString ","] };
        if (_s isEqualTo []) then { diag_log text format ["DS|%1|", _x] };
        deleteVehicle _v;
    } else {
        diag_log text format ["DS|%1|<nocreate>", _x];
    };
} forEach _models;
call vc_fnc_done;
