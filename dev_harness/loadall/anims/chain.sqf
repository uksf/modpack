private _list = __LIST__;
{
    private _c = configFile >> "CfgVehicles" >> _x;
    private _chain = [];
    private _a = _c;
    while { isClass _a && {!("AnimationSources" in ((configProperties [_a, "isClass _x", false]) apply {configName _x}))} } do {
        _chain pushBack [configName _a, configName inheritsFrom _a];
        _a = inheritsFrom _a;
    };
    diag_log text format ["CH|%1|%2|%3|%4", _x, configName _a, configName inheritsFrom _a, _chain];
} forEach _list;
call vc_fnc_done;
