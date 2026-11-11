private _isEmptyValue = {
    private _v = _this;
    if (isNil "_v") exitWith { true };
    if (_v isEqualType "") exitWith { _v == "" };
    if (_v isEqualType objNull) exitWith { isNull _v };
    if (_v isEqualType grpNull) exitWith { isNull _v };
    if (_v isEqualType createHashMap) exitWith {
        if (count _v == 0) exitWith { true };
        private _all = true;
        { if (!((_v get _x) call _isEmptyValue)) exitWith { _all = false } } forEach (keys _v);
        _all
    };
    if (_v isEqualType []) exitWith {
        if (count _v == 0) exitWith { true };
        private _all = true;
        { if (!(_x call _isEmptyValue)) exitWith { _all = false } } forEach _v;
        _all
    };
    false
};

private _isEqual = {
    params ["_a", "_b"];
    if (isNil "_a" && isNil "_b") exitWith { true };
    if (isNil "_a") exitWith { _b call _isEmptyValue };
    if (isNil "_b") exitWith { _a call _isEmptyValue };
    if ((_a call _isEmptyValue) && {_b call _isEmptyValue}) exitWith { true };
    if (_a isEqualType west && _b isEqualType "") exitWith { str _a == _b };
    if (_a isEqualType "" && _b isEqualType west) exitWith { _a == str _b };
    if (_a isEqualType "" && _b isEqualType createHashMap) exitWith {
        private _parsed = [_a, 2] call CBA_fnc_parseJSON;
        if (!isNil "_parsed") exitWith { [_parsed, _b] call _isEqual };
        false
    };
    if (_a isEqualType createHashMap && _b isEqualType "") exitWith {
        private _parsed = [_b, 2] call CBA_fnc_parseJSON;
        if (!isNil "_parsed") exitWith { [_a, _parsed] call _isEqual };
        false
    };
    if !(_a isEqualType _b) exitWith { false };
    if (_a isEqualType 0) exitWith { _a == _b || {str _a == str _b} };
    if (_a isEqualType "") exitWith { _a == _b };
    if (_a isEqualType []) exitWith {
        if (count _a != count _b) exitWith { false };
        private _match = true;
        for "_i" from 0 to (count _a - 1) do {
            if !([_a#_i, _b#_i] call _isEqual) exitWith { _match = false };
        };
        _match
    };
    if (_a isEqualType createHashMap) exitWith {
        private _keysA = keys _a;
        private _keysB = keys _b;
        if (count _keysA != count _keysB) exitWith { false };
        private _match = true;
        {
            if !([_a get _x, _b getOrDefault [_x, nil]] call _isEqual) exitWith { _match = false };
        } forEach _keysA;
        _match
    };
    _a isEqualTo _b
};

private _mismatchDetail = {
    params ["_a", "_b"];
    if (isNil "_a" && !isNil "_b") exitWith { "profile=nil" };
    if (!isNil "_a" && isNil "_b") exitWith { "api=nil" };
    if (isNil "_a" && isNil "_b") exitWith { "both nil (shouldn't mismatch)" };
    if (_a isEqualType "" && _b isEqualType createHashMap) then {
        private _parsed = [_a, 2] call CBA_fnc_parseJSON;
        if (!isNil "_parsed") then { _a = _parsed };
    };
    if (_a isEqualType createHashMap && _b isEqualType "") then {
        private _parsed = [_b, 2] call CBA_fnc_parseJSON;
        if (!isNil "_parsed") then { _b = _parsed };
    };
    if !(_a isEqualType _b) exitWith {
        format ["type mismatch: profile=%1, api=%2", typeName _a, typeName _b]
    };
    if (_a isEqualType []) exitWith {
        if (count _a != count _b) exitWith {
            format ["array length: profile=%1, api=%2", count _a, count _b]
        };
        private _detail = "";
        for "_i" from 0 to (count _a - 1) do {
            if !([_a#_i, _b#_i] call _isEqual) exitWith {
                _detail = format ["element[%1] differs: %2", _i, [_a#_i, _b#_i] call _mismatchDetail];
            };
        };
        _detail
    };
    if (_a isEqualType createHashMap) exitWith {
        private _keysA = keys _a;
        private _keysB = keys _b;
        if (count _keysA != count _keysB) exitWith {
            format ["hashmap key count: profile=%1, api=%2", count _keysA, count _keysB]
        };
        private _detail = "";
        {
            private _key = _x;
            if !(_key in _keysB) exitWith { _detail = format ["key '%1' missing from api", _key] };
            if !([_a get _key, _b get _key] call _isEqual) exitWith {
                _detail = format ["key '%1' differs: %2", _key, [_a get _key, _b get _key] call _mismatchDetail];
            };
        } forEach _keysA;
        if (_detail == "") then {
            {
                if !(_x in _keysA) exitWith { _detail = format ["key '%1' missing from profile", _x] };
            } forEach _keysB;
        };
        _detail
    };
    if (_a isEqualType 0) exitWith {
        if (_a == _b) then {
            format ["numbers: == true but isEqualTo false (binary diff), profile=%1, api=%2", _a, _b]
        } else {
            format ["numbers: profile=%1, api=%2, diff=%3", _a, _b, _a - _b]
        };
    };
    if (_a isEqualType "") exitWith {
        if (count _a != count _b) exitWith {
            format ["string length: profile=%1, api=%2", count _a, count _b]
        };
        private _detail = "";
        private _profileChars = toArray _a;
        private _apiChars = toArray _b;
        for "_i" from 0 to (count _profileChars - 1) do {
            if (_profileChars#_i != _apiChars#_i) exitWith {
                _detail = format ["char[%1]: profile=%2 (%3), api=%4 (%5)", _i, toString [_profileChars#_i], _profileChars#_i, toString [_apiChars#_i], _apiChars#_i];
            };
        };
        _detail
    };
    format ["isEqualTo false: profile=%1, api=%2", _a, _b]
};

