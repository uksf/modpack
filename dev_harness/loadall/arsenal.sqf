#define IDD_ARSENAL 1127001
#define IDC_LEFT_LIST 13
#define IDC_RIGHT_LIST 14
#define IDC_RIGHT_LISTNBOX 15
#define CT_LISTNBOX 102
#define WEAPON_TABS [2002, 2004, 2006]
#define WEAPON_RIGHT_TABS [22, 24, 26, 28, 3002, 3004]
#define CONTAINER_TABS [2010, 2012, 2014]
#define CARGO_RIGHT_TABS [32, 34, 36, 38]

private _phase = LA_PHASE;
private _tab = parseNumber (_phase select [3]);
private _seen = createHashMap;
private _cargoSwept = false;

player hideObject false;
if (!isNil "vc_cam") then { vc_cam cameraEffect ["terminate", "back"]; camDestroy vc_cam; vc_cam = nil };
[player, player, true] call ace_arsenal_fnc_openBox;
waitUntil { !isNull findDisplay IDD_ARSENAL };
uiSleep 3;
private _display = findDisplay IDD_ARSENAL;

private _rowCount = {
    [lbSize _this, (lnbSize _this) select 0] select (ctrlType _this == CT_LISTNBOX)
};
private _rowClass = {
    params ["_ctrl", "_i"];
    [_ctrl lbData _i, _ctrl lnbData [_i, 0]] select (ctrlType _ctrl == CT_LISTNBOX)
};
private _clickRow = {
    params ["_ctrl", "_i"];
    if (ctrlType _ctrl == CT_LISTNBOX) then { _ctrl lnbSetCurSelRow _i } else { _ctrl lbSetCurSel _i };
};
private _ownerAddon = {
    private _cfg = [configFile >> "CfgWeapons" >> _this, configFile >> "CfgMagazines" >> _this, configFile >> "CfgVehicles" >> _this, configFile >> "CfgGlasses" >> _this] select {isClass _x};
    if (_cfg isEqualTo []) exitWith {""};
    (configSourceAddonList (_cfg select 0)) param [0, ""]
};
private _clickUnseenRightRows = {
    params ["_rowIdx", "_rightTabs", "_listIdc"];
    {
        private _button = _display displayCtrl _x;
        if (!ctrlShown _button || {!ctrlEnabled _button}) then { continue };
        [_display, _button] call ace_arsenal_fnc_fillRightPanel;
        uiSleep 0.05;
        private _list = _display displayCtrl _listIdc;
        for "_j" from 0 to ((_list call _rowCount) - 1) do {
            private _cls = [_list, _j] call _rowClass;
            if (_cls == "" || {_cls in _seen} || {_cls in LA_SKIP}) then { continue };
            _seen set [_cls, true];
            format ["LA|L|%1|%2|%3|%4", _phase, _rowIdx, _cls, _cls call _ownerAddon] call vc_fnc_log;
            [_list, _j] call _clickRow;
            uiSleep 0.1;
        };
    } forEach _rightTabs;
};

[_display, _display displayCtrl _tab] call ace_arsenal_fnc_fillLeftPanel;
uiSleep 0.5;
private _left = _display displayCtrl IDC_LEFT_LIST;
private _end = LA_END min (_left call _rowCount);
format ["LA|BEGIN|%1|%2|%3|%4", _phase, LA_START, _end, _left call _rowCount] call vc_fnc_log;

for "_i" from LA_START to (_end - 1) do {
    private _cls = [_left, _i] call _rowClass;
    if (_cls == "") then { continue };
    format ["LA|L|%1|%2|%3|%4", _phase, _i, _cls, _cls call _ownerAddon] call vc_fnc_log;
    if (_cls in LA_SKIP) then { format ["LA|SKIP|%1", _cls] call vc_fnc_log; continue };
    [_left, _i] call _clickRow;
    uiSleep 0.15;
    if (_tab in WEAPON_TABS) then { [_i, WEAPON_RIGHT_TABS, IDC_RIGHT_LIST] call _clickUnseenRightRows };
    if (_tab in CONTAINER_TABS && {!_cargoSwept}) then { _cargoSwept = true; [_i, CARGO_RIGHT_TABS, IDC_RIGHT_LISTNBOX] call _clickUnseenRightRows };
};
_display closeDisplay 1;
format ["LA|END|%1|%2", _phase, _end] call vc_fnc_log;
call vc_fnc_done;
