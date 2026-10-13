lc_fnc_log = {
    params ["_event", ["_data", ""]];
    private _role = if (isServer) then {"server"} else {["hc", "client"] select hasInterface};
    private _text = if (_data isEqualType "") then {_data} else {str _data};
    private _tick = diag_tickTime toFixed 3;
    if (count _text <= 800) exitWith {
        diag_log text format ["[LC] %1 %2 %3 %4", _event, _role, _tick, _text];
    };
    private _parts = ceil (count _text / 800);
    for "_i" from 0 to (_parts - 1) do {
        diag_log text format ["[LC] %1 %2 %3 #part %4 %5 |%6|", _event, _role, _tick, _i, _parts, _text select [_i * 800, 800]];
    };
};
