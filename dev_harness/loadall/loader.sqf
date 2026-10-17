// Loads every class of one phase, slice [LA_START, LA_END). No scope or model filter.
// The driver prepends: LA_PHASE = "veh"; LA_START = 0; LA_END = 6000;
private _phase = LA_PHASE;
private _root = configFile >> (createHashMapFromArray [["veh", "CfgVehicles"], ["man", "CfgVehicles"], ["logic", "CfgVehicles"], ["wpn", "CfgWeapons"], ["mag", "CfgMagazines"], ["glasses", "CfgGlasses"], ["ammo", "CfgAmmo"], ["nonai", "CfgNonAIVehicles"]] get _phase);
private _filter = switch (_phase) do {
    case "veh": {"!(configName _x isKindOf 'CAManBase') && {!(configName _x isKindOf 'Logic')}"};
    case "man": {"configName _x isKindOf 'CAManBase'"};
    case "logic": {"configName _x isKindOf 'Logic'"};
    default {"true"};
};
private _all = _filter configClasses _root;
private _end = LA_END min count _all;
format ["LA|BEGIN|%1|%2|%3|%4", _phase, LA_START, _end, count _all] call vc_fnc_log;

// [batch size, grid spacing m, camera distance m, origin]
(createHashMapFromArray [
    ["veh", [100, 30, 330, [600, 600, 0]]], ["logic", [100, 5, 60, [600, 600, 0]]], ["man", [100, 3, 36, [600, 600, 0]]],
    ["wpn", [144, 1.5, 22, [600, 600, 0]]], ["mag", [144, 1.5, 22, [600, 600, 0]]], ["glasses", [144, 1, 15, [600, 600, 0]]],
    ["ammo", [49, 20, 160, [3000, 3000, 0]]], ["nonai", [100, 10, 120, [600, 600, 0]]]
] get _phase) params ["_batch", "_spacing", "_camDist", "_origin"];
private _cols = ceil sqrt _batch;

for "_i" from LA_START to (_end - 1) step _batch do {
    private _made = [];
    private _groups = createHashMap;
    private _helper = objNull;
    for "_k" from 0 to ((_batch min (_end - _i)) - 1) do {
        private _cfg = _all select (_i + _k);
        private _cls = configName _cfg;
        private _pos = _origin vectorAdd [(_k mod _cols) * _spacing, floor (_k / _cols) * _spacing, 0];
        format ["LA|L|%1|%2|%3|%4", _phase, _i + _k, _cls, (configSourceAddonList _cfg) param [0, ""]] call vc_fnc_log;
        if (_cls in LA_SKIP) then { format ["LA|SKIP|%1", _cls] call vc_fnc_log; continue };
        switch (_phase) do {
            case "man": {
                private _side = [east, west, independent, civilian] param [getNumber (_cfg >> "side"), civilian];
                private _g = _groups getOrDefault [str _side, grpNull];
                if (isNull _g) then { _g = createGroup [_side, true]; _groups set [str _side, _g] };
                private _u = _g createUnit [_cls, _pos, [], 0, "CAN_COLLIDE"];
                _u allowDamage false;
                _u disableAI "ALL";
                _made pushBack _u;
            };
            case "ammo": { _made pushBack createVehicle [_cls, _pos vectorAdd [0, 0, 60], [], 0, "CAN_COLLIDE"] };
            case "nonai": {
                private _m = getText (_cfg >> "model");
                if (_m != "") then { _made pushBack createSimpleObject [_m, AGLToASL _pos] };
            };
            case "veh";
            case "logic": {
                private _o = createVehicle [_cls, _pos, [], 0, "CAN_COLLIDE"];
                _o allowDamage false;
                _made pushBack _o;
            };
            default {
                // Vehicle weapons (type 65536) go on a helper vehicle; everything else into a ground holder.
                if (_phase == "wpn" && {getNumber (_cfg >> "type") == 65536}) then {
                    if (isNull _helper) then { _helper = createVehicle ["B_MRAP_01_hmg_F", _origin vectorAdd [-30, -30, 0], [], 0, "CAN_COLLIDE"]; _made pushBack _helper };
                    _helper addWeapon _cls;
                } else {
                    private _h = createVehicle ["WeaponHolderSimulated", _pos vectorAdd [0, 0, 0.3], [], 0, "CAN_COLLIDE"];
                    switch (true) do {
                        case (_phase == "mag"): { _h addMagazineCargoGlobal [_cls, 1] };
                        case (_phase == "wpn" && {getNumber (_cfg >> "type") in [1, 2, 4, 4096]}): { _h addWeaponCargoGlobal [_cls, 1] };
                        default { _h addItemCargoGlobal [_cls, 1] };
                    };
                    _made pushBack _h;
                };
            };
        };
    };
    private _centre = _origin vectorAdd [(_cols - 1) * _spacing / 2, (_cols - 1) * _spacing / 2, 0];
    [AGLToASL (_centre vectorAdd [0, -_camDist * 0.75, _camDist * 0.6]), AGLToASL _centre, 0.75] call vc_fnc_cam;
    uiSleep 1;
    { if (!isNull _x) then { deleteVehicleCrew _x; deleteVehicle _x } } forEach _made;
    { deleteGroup _y } forEach _groups;
    { deleteVehicle _x } forEach ((_origin nearObjects 700) select {!isPlayer _x});
    { deleteVehicle _x } forEach allMissionObjects "Crater";
};
format ["LA|END|%1|%2", _phase, _end] call vc_fnc_log;
call vc_fnc_done;
