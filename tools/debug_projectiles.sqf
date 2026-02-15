if (!isNil "uksf_zeus_projectilesDebugPFH") then {
    [uksf_zeus_projectilesDebugPFH] call CBA_fnc_removePerFrameHandler;
};

private _mapCtrl = (findDisplay 312) displayCtrl 50;
if (!isNil "uksf_zeus_projectilesDebugMapEH" && {!isNull _mapCtrl}) then {
    _mapCtrl ctrlRemoveEventHandler ["Draw", uksf_zeus_projectilesDebugMapEH];
};

uksf_zeus_projectilesEnabled = true;
if (isNil "uksf_zeus_trackedProjectiles") then {
    uksf_zeus_trackedProjectiles = [];
};
uksf_zeus_ammoTypeCache = createHashMap;
uksf_zeus_ammoNameCache = createHashMap;
uksf_zeus_ammoIconCache = createHashMap;

uksf_zeus_fnc_isHeavyProjectile = {
    params ["_ammo"];
    private _cached = uksf_zeus_ammoTypeCache getOrDefault [_ammo, -1];
    if (_cached != -1) exitWith {_cached};
    private _cfgAmmo = configFile >> "CfgAmmo";
    private _isHeavy = false;
    private _icon = "";
    if (_ammo isKindOf ["MissileBase", _cfgAmmo]) then {
        _isHeavy = true;
        _icon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";
    } else {
        if (_ammo isKindOf ["ShellBase", _cfgAmmo]) then {
            _isHeavy = true;
            _icon = "\a3\ui_f\data\map\markers\military\dot_ca.paa";
        } else {
            if (_ammo isKindOf ["RocketBase", _cfgAmmo]) then {
                _isHeavy = true;
                _icon = "\a3\ui_f\data\map\markers\military\diamond_ca.paa";
            } else {
                if (_ammo isKindOf ["BombCore", _cfgAmmo]) then {
                    _isHeavy = true;
                    _icon = "\a3\ui_f\data\map\markers\military\box_ca.paa";
                };
            };
        };
    };
    uksf_zeus_ammoTypeCache set [_ammo, _isHeavy];
    if (_isHeavy) then {
        private _name = getText (_cfgAmmo >> _ammo >> "displayName");
        if (_name == "") then { _name = _ammo };
        uksf_zeus_ammoNameCache set [_ammo, _name];
        uksf_zeus_ammoIconCache set [_ammo, _icon];
    };
    _isHeavy
};

if (isNil "uksf_zeus_projectilesDebugFiredRegistered") then {
    ["All", "FiredBIS", {
        if (!uksf_zeus_projectilesEnabled) exitWith {};
        params ["_unit", "", "", "", "_ammo", "", "_projectile"];
        if !([_ammo] call uksf_zeus_fnc_isHeavyProjectile) exitWith {};
        if (isNull _projectile) then {
            _projectile = nearestObject [_unit, _ammo];
        };
        if (!isNull _projectile) then {
            private _sideColor = switch (side _unit) do {
                case west:        { [0, 0.3, 0.6, 0.9] };
                case east:        { [0.5, 0, 0, 0.9] };
                case independent: { [0, 0.5, 0, 0.9] };
                default           { [0.4, 0, 0.5, 0.9] };
            };
            uksf_zeus_trackedProjectiles pushBack [_projectile, _ammo, _sideColor];
        };
    }, true] call CBA_fnc_addClassEventHandler;
    uksf_zeus_projectilesDebugFiredRegistered = true;
};

uksf_zeus_projectilesDebugPFH = [{
    if (!uksf_zeus_projectilesEnabled) exitWith {};
    uksf_zeus_trackedProjectiles = uksf_zeus_trackedProjectiles select {!isNull (_x select 0)};
    {
        _x params ["_projectile", "_ammo", "_sideColor"];
        private _pos = ASLToAGL getPosASLVisual _projectile;
        private _name = uksf_zeus_ammoNameCache getOrDefault [_ammo, _ammo];
        private _icon = uksf_zeus_ammoIconCache getOrDefault [_ammo, "\a3\ui_f\data\map\markers\military\dot_ca.paa"];
        drawIcon3D [_icon, _sideColor, _pos, 0.75, 0.75, 0, _name, 1, 0.03, "PuristaMedium", "center", true];
    } forEach uksf_zeus_trackedProjectiles;
}, 0] call CBA_fnc_addPerFrameHandler;

if (!isNull _mapCtrl) then {
    uksf_zeus_projectilesDebugMapEH = _mapCtrl ctrlAddEventHandler ["Draw", {
        if (!uksf_zeus_projectilesEnabled) exitWith {};
        {
            _x params ["_projectile", "_ammo", "_sideColor"];
            if (!isNull _projectile) then {
                private _name = uksf_zeus_ammoNameCache getOrDefault [_ammo, _ammo];
                (_this select 0) drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _sideColor, _projectile, 24, 24, 0, _name, 0.1, 0.04, "PuristaMedium", "center"];
            };
        } forEach uksf_zeus_trackedProjectiles;
    }];
};

["uksf_zeus_toggleProjectiles"] call zen_context_menu_fnc_removeAction;
private _action = ["uksf_zeus_toggleProjectiles", "Show Projectiles", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {
    uksf_zeus_projectilesEnabled = !uksf_zeus_projectilesEnabled;
}, {true}, [], {}, {
    params ["_action"];
    _action set [1, ["Show Projectiles", "Hide Projectiles"] select uksf_zeus_projectilesEnabled];
}] call zen_context_menu_fnc_createAction;
[_action, [], -490] call zen_context_menu_fnc_addAction;
