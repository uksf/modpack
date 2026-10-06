private _list = __LIST__;
private _tur = {
    params ["_t", "_cls"];
    {
        diag_log text format ["CDT|%1|%2|%3|%4|%5", _cls, configName _x, getText (_x >> "animationSourceBody"), getText (_x >> "animationSourceGun"), getArray (_x >> "weapons")];
        { diag_log text format ["CDH|%1|%2", _cls, configName _x] } forEach configProperties [_x >> "HitPoints", "isClass _x", true];
        [_x, _cls] call _tur;
    } forEach ("true" configClasses (_t >> "Turrets"));
};
{
    private _c = configFile >> "CfgVehicles" >> _x;
    if (!isClass _c) then { _c = configFile >> "CfgAmmo" >> _x };
    diag_log text format ["CD|%1|%2|%3|%4", _x, configName inheritsFrom _c, getText (_c >> "simulation"), getArray (_c >> "weapons")];
    private _cls = _x;
    { diag_log text format ["CDH|%1|%2", _cls, configName _x] } forEach configProperties [_c >> "HitPoints", "isClass _x", true];
    [_c, _x] call _tur;
} forEach _list;
call vc_fnc_done;
