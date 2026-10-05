import json
cand = json.load(open('dupcand.json'))
rows = ','.join('["%s","%s","%s"]' % (c, p, n) for c, p, n, _ in cand)
open('dupown.sqf', 'w').write('''private _rows = [%s];
private _cp = { params ["_c", "_p"]; private _r = configFile >> "CfgVehicles" >> _c; { if (_x != "") then { _r = _r >> "Turrets" >> _x } } forEach (_p splitString "/"); _r };
{
    _x params ["_c", "_p", "_n"];
    private _t = [_c, _p] call _cp;
    private _hps = if (_p == "") then { configFile >> "CfgVehicles" >> _c >> "HitPoints" } else { _t >> "HitPoints" };
    diag_log text format ["DO|%%1|%%2|%%3|%%4", _c, _p, _n, str (_hps >> _n)];
    diag_log text format ["DP|%%1|%%2|%%3|%%4", _c, _p, str _hps, str _t];
} forEach _rows;
call vc_fnc_done;
''' % rows)
