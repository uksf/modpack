private _list = __LIST__;
{
    private _a = configFile >> "CfgVehicles" >> _x;
    diag_log text format ["RP|%1|%2|%3", _x, str inheritsFrom (_a >> "AnimationSources"), str (inheritsFrom _a >> "AnimationSources")];
    { diag_log text format ["RS|%1|%2", _x, toLower configName _x] } forEach configProperties [_a >> "AnimationSources", "isClass _x", true];
} forEach _list;
call vc_fnc_done;
