#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Color by side for debug overlays.

    Parameters:
        0: Side <SIDE>

    Return Value:
        RGBA color <ARRAY>
*/

params [["_side", sideUnknown, [sideUnknown]]];

switch (true) do {
    case (_side isEqualTo west): {[0.2, 0.55, 1, 0.9]};
    case (_side isEqualTo east): {[1, 0.25, 0.25, 0.9]};
    case (_side isEqualTo independent): {[0.2, 1, 0.35, 0.9]};
    default {[0.85, 0.85, 0.85, 0.9]};
};
