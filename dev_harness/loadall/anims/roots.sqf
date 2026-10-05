private _list = __LIST__;
private _roots = createHashMap;
{
    private _c = configFile >> "CfgVehicles" >> _x;
    if (isClass _c) then {
        private _m = getText (_c >> "model");
        private _a = _c;
        while { private _p = inheritsFrom _a; isClass _p && {getText (_p >> "model") == _m} } do { _a = inheritsFrom _a };
        diag_log text format ["RT|%1|%2", _x, configName _a];
        _roots set [configName _a, _a];
    };
} forEach _list;
{
    private _a = _y;
    private _p = inheritsFrom _a;
    private _local = (configProperties [_a, "isClass _x", false]) apply {configName _x};
    private _localP = (configProperties [_p, "isClass _x", false]) apply {configName _x};
    diag_log text format ["RI|%1|%2|%3|%4|%5|%6|%7", _x, configName _p, configName inheritsFrom _p, "AnimationSources" in _local,
        configName inheritsFrom (_a >> "AnimationSources"), "AnimationSources" in _localP, configSourceAddonList _a];
} forEach _roots;
call vc_fnc_done;
