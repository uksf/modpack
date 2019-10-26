#include "script_component.hpp"
/*
    Author:
        dreadedentity, Tim Beswick

    Description:
        Exports Specified config entry and copies to clipboard.
        ONLY WORKS ON SERVER CLIENT IN MULTIPLAYER

    Parameters:
        0: Config entry <CONFIG>

    Return value:
        Exported config <STRING>

    Example:
        [configFile >> "CfgVehicles" >> "UK3CB_BAF_Box_WpsSpecial"] call uksf_common_fnc_configExport;
*/
params ["_config", ["_numtabs", 0, [0]], ["_output", "", [""]]];

private _makeTabs = {
    private _tabs = "";
    for "_t" from 1 to _this do {
        _tabs = _tabs + (toString [9]);
    };
    _tabs;
};

if (!isClass _config) exitWith {"Input Was Not A Class"};

private _newLine = toString [13, 10];
private _parents = [_config] call BIS_fnc_returnParents;

_output = _output + (_numTabs call _makeTabs) + "class " + (configName _config) + _newLine + (_numTabs call _makeTabs) + "{" + _newline;

private _params = [];
{
    private _numParams = (count _x) - 1;
    for "_i" from 0 to _numParams do {
        private _param = configName (_x select _i);
        private _newConfig = _config >> _param;
        if (isClass _newConfig) then {
            _output = [_newConfig, _numTabs + 1, _output] call FUNC(configExport);
        } else {
            private _newParam = _param;
            private _data = nil;
            switch (true) do {
                case (isNumber _newConfig): {
                    _data = getNumber _newConfig;
                };
                case (isText _newConfig): {
                    _data = str(getText _newConfig);
                };
                case (isArray _newConfig): {
                    _newParam = _newParam + "[]";
                    _data = str(getArray _newConfig);
                    _data = "{" + (_data select [1, (count _data) - 2]) + "}";
                };
            };
            if (_params find _param == -1) then {
                _output = _output + ((_numTabs + 1) call _makeTabs) + format["%1 = %2;%3", _newParam, _data, _newLine];
                _params pushBack _param;
            };
        };
    };
} forEach _parents;

_output = _output + (_numTabs call _makeTabs) + "};" + _newline;
copyToClipboard _output;
_output
