#include "script_component.hpp"

private _dictionary = QPATHTOF(i18n_en.txt);
private _languages = [] call comspec_atak_native_fnc_langList;
if (_languages findIf { (_x select 2) isEqualTo _dictionary } < 0) then {
    _languages pushBack ["en", "English", _dictionary, []];
};
uiNamespace setVariable ["COMSPEC_ATAK_I18nUi_en", nil];
missionNamespace setVariable ["COMSPEC_ATAK_I18nLoaded", ""];
[] call comspec_atak_native_fnc_langApply;
