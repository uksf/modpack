#include "\a3\editor_f\Data\Scripts\dikCodes.h"

["UKSF", QGVAR(toggleDiveComputer), "Toggle Dive Computer", {false}, {
    private _hasDiveComputer = QGVAR(diveComputer) in (assignedItems player);
    if (!_hasDiveComputer) then {
        if (GVAR(diveComputerUpdatePFHID) != -1) then {
            [false] call FUNC(toggleDiveComputer);
        };
    } else {
        [GVAR(diveComputerUpdatePFHID) == -1] call FUNC(toggleDiveComputer);
    };
}, [0x3e, [true, false, false]]] call CBA_fnc_addKeybind;
