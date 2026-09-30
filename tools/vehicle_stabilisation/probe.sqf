// Dev-run probe: resolved turret data for every land and sea vehicle with scope > 0.
// Row: [class, isShip, artilleryScanner, isArmour, turrets]
// Turret: [path, stabilizedInAxes, weapons, primaryGunner, forceHideGunner, outGunnerMayFire, hashAll, hashWithoutStabilisation]
uksf_dev_resultPosted = true;
[] spawn {
    private _out = [];
    isNil {
        STAB_fnc_hashes = {
            private _parts = [];
            {
                if (!isClass _x) then {
                    _parts pushBack (configName _x + "=" + str (if (isNumber _x) then {getNumber _x} else {if (isText _x) then {getText _x} else {getArray _x}}));
                };
            } forEach configProperties [_this, "true", true];
            _parts sort true;
            [hashValue (_parts joinString "|"), hashValue ((_parts select {_x find "stabilizedInAxes=" != 0}) joinString "|")]
        };
        STAB_fnc_turrets = {
            params ["_cfg", "_prefix"];
            private _rows = [];
            {
                private _path = _prefix + [configName _x];
                _rows pushBack ([
                    _path joinString "/",
                    getNumber (_x >> "stabilizedInAxes"),
                    getArray (_x >> "weapons"),
                    getNumber (_x >> "primaryGunner"),
                    getNumber (_x >> "forceHideGunner"),
                    getNumber (_x >> "outGunnerMayFire")
                ] + (_x call STAB_fnc_hashes));
                _rows append ([_x >> "Turrets", _path] call STAB_fnc_turrets);
            } forEach ("isClass _x" configClasses _cfg);
            _rows
        };
        {
            private _class = configName _x;
            if (getNumber (_x >> "scope") > 0 && {_class isKindOf "LandVehicle" || {_class isKindOf "Ship"}}) then {
                _out pushBack [
                    _class,
                    _class isKindOf "Ship",
                    getNumber (_x >> "artilleryScanner"),
                    _class isKindOf "Tank" || {_class isKindOf "Wheeled_APC_F"},
                    [_x >> "Turrets", []] call STAB_fnc_turrets
                ];
            };
        } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    };
    [format ["vehicles=%1 stabilisation=%2", count _out, isClass (configFile >> "CfgPatches" >> "uksf_vehicles_stabilisation")]] call uksf_dev_fnc_logLine;
    [_out] call uksf_dev_fnc_postResult;
};
