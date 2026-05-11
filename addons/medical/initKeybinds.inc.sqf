#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#include "ui\defines.hpp"

["UKSF", QGVAR(toggleHide), "Toggle Uncon Dialog Visibility", {false}, {
    GVAR(interfaceHidden) = !GVAR(interfaceHidden);
    private _display = findDisplay IDD_UNCON;
    if (isNull _display) exitWith {true};
    {
        private _ctrl = _display displayCtrl _x;
        if (isNull _ctrl) then { continue };
        _ctrl ctrlShow !GVAR(interfaceHidden);
    } forEach [IDC_TAB_BAR, IDC_CONTAINER_SPECTATOR, IDC_CONTAINER_HEALTH, IDC_CONTAINER_SETTINGS];
    true
}, [DIK_H, [false, false, true]]] call CBA_fnc_addKeybind;
