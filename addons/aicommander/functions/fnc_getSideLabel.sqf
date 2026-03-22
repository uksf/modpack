#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Convert side value to a stable label for logs/debug.

    Parameters:
        0: Side <SIDE>

    Return Value:
        Side label <STRING>
*/

params [["_side", sideUnknown, [sideUnknown]]];

switch (true) do {
    case (_side isEqualTo west): {"BLUFOR"};
    case (_side isEqualTo east): {"OPFOR"};
    case (_side isEqualTo independent): {"INDEPENDENT"};
    default {"NONE"};
};
