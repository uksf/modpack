#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Deserializes and sets player radio data

    Parameter(s):
        0: Radio data <ARRAY>
            Formatted as: [type, channel, volume, ear, pttIndex]

    Return Value:
        None
*/

[{
    private _radios = ([acre_player] call acre_sys_core_fnc_getGear) select {(_x select [0, 4]) == "ACRE"};
    {_x call acre_sys_radio_fnc_isUniqueRadio} count _radios == count _radios
}, {
    params ["_radioData"];
    
    private _radios = ([acre_player] call acre_sys_core_fnc_getGear) select {_x call acre_sys_radio_fnc_isUniqueRadio};

    if (_radioData#0 isEqualType []) then {
        private _pttAssignments = [];

        {
            if (count _radioData == 0) exitWith {};
            private _type = [_x] call acre_api_fnc_getBaseRadio;
            private _index = -1;
            {
                if (_x#0 == _type) exitWith {
                    _index = _forEachIndex;
                };
            } forEach _radioData;
            if (_index > -1) then {
                private _data = _radioData deleteAt _index;
                _data params ["", "_channel", "_volume", "_ear", ["_pttIndex", 0]];
                [_x, _channel] call acre_api_fnc_setRadioChannel;
                [_x, _volume] call acre_api_fnc_setRadioVolume;
                [_x, _ear] call acre_api_fnc_setRadioSpatial;
                _pttAssignments pushBack [_pttIndex, _x];
            };
        } forEach _radios;

        _pttAssignments sort true;
        _pttAssignments = _pttAssignments apply {_x#1};
        [_pttAssignments] call acre_api_fnc_setMultiPushToTalkAssignment;
    } else {
        {[_x, _radioData#_forEachIndex] call acre_api_fnc_setRadioChannel;} forEach _radios; // Backwards compatibility for old format
    };
}, _this, 15] call CBA_fnc_waitUntilAndExecute;
