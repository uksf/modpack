// Template: replace __LIST__ with the root classes. Logs GP|class|parent|HP=<HitPoints path>.
{
    private _c = configFile >> "CfgVehicles" >> _x;
    diag_log text format ["GP|%1|%2|HP=%3", _x, configName inheritsFrom _c, str (_c >> "HitPoints")];
} forEach __LIST__;
call vc_fnc_done;
