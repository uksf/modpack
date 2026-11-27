#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Rebuilds schema-defined session, object, player and medical hashmaps from SQF transport arrays.

    Parameter(s):
        0: Parsed session <ARRAY>

    Return Value:
        Rebuilt session <HASHMAP>

    Example:
        _parsed call uksf_persistence_fnc_rebuildHashmaps
*/
private _session = createHashMapFromArray _this;
_session set ["objects", (_session getOrDefault ["objects", []]) apply {createHashMapFromArray _x}];
private _players = createHashMapFromArray (_session getOrDefault ["players", []]);
{
    private _player = createHashMapFromArray _y;
    private _medical = _player getOrDefault ["aceMedical", []];
    if ("aceMedical" in _player && {_medical isEqualType []}) then {
        _medical = createHashMapFromArray _medical;
        {
            private _wounds = _medical getOrDefault [_x, []];
            if (_x in _medical && {_wounds isEqualType []}) then {
                _medical set [_x, createHashMapFromArray _wounds];
            };
        } forEach ["ace_medical_openWounds", "ace_medical_bandagedWounds", "ace_medical_stitchedWounds"];
        _player set ["aceMedical", _medical];
    };
    _players set [_x, _player];
} forEach _players;
_session set ["players", _players];
_session
