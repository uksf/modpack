#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Builds a coloured battery bar string.

    Parameters:
        0: Percentage <SCALAR>

    Return value:
        Structured text string <STRING>
*/
params [["_percent", 0]];

private _clamped = (_percent max 0) min 100;
private _filled = ceil (_clamped / 20);
private _fullColor = switch (true) do {
    case (_clamped >= 60): {"#00C853"};
    case (_clamped >= 30): {"#FFD600"};
    default {"#D50000"};
};

private _segments = [];
for "_i" from 1 to 5 do {
    private _color = ["#666666", _fullColor] select (_i <= _filled);
    _segments pushBack (format ["<t color='%1'>|</t>", _color]);
};

_segments joinString ""
