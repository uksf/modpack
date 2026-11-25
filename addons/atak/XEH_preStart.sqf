#include "script_component.hpp"

private _languages = [] call comspec_atak_native_fnc_langList;
{
    private _dictionary = _x;
    if (_languages findIf { (_x select 2) isEqualTo _dictionary } < 0) then {
        _languages pushBack ["en", "English", _dictionary, []];
    };
} forEach [QPATHTOF(i18n_en.txt), QPATHTOF(i18n_en_brand.txt)];
uiNamespace setVariable ["COMSPEC_ATAK_I18nUi_en", nil];
missionNamespace setVariable ["COMSPEC_ATAK_I18nLoaded", ""];
[] call comspec_atak_native_fnc_langApply;
