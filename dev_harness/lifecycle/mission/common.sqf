lc_fnc_log = {
    params ["_event", ["_data", ""]];
    private _role = if (isServer) then {"server"} else {["hc", "client"] select hasInterface};
    diag_log text format ["[LC] %1 %2 %3 %4", _event, _role, diag_tickTime toFixed 3, _data];
};
