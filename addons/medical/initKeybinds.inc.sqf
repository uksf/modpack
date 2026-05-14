#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#include "ui\defines.hpp"

["UKSF", QGVAR(toggleHide), "Toggle Uncon Dialog Visibility", {false}, {
    GVAR(interfaceHidden) = !GVAR(interfaceHidden);
    private _display = findDisplay IDD_UNCON;
    if (isNull _display) exitWith {true};
    private _ids = [
        IDC_TAB_HEALTH, IDC_TAB_SPECTATOR,
        IDC_SPEC_TOO_FAR, IDC_SPEC_INFO, IDC_SPEC_PIP, IDC_SPEC_NO_SIGNAL,
        IDC_SPEC_NVG_0, IDC_SPEC_NVG_1, IDC_SPEC_NVG_2,
        IDC_HEALTH_HR, IDC_HEALTH_BP, IDC_HEALTH_RESP, IDC_HEALTH_SPO2,
        IDC_HEALTH_STATE_TIMER
    ];
    {
        private _ctrl = _display displayCtrl _x;
        if (isNull _ctrl) then { continue };
        _ctrl ctrlShow !GVAR(interfaceHidden);
    } forEach _ids;
    true
}, [DIK_H, [false, false, true]]] call CBA_fnc_addKeybind;
