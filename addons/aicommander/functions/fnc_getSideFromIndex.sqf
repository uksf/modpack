#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Convert side index to side value.

    Parameters:
        0: Side index <NUMBER>

    Return Value:
        Side <SIDE>
*/

params [["_index", -1, [0]]];

switch (_index) do {
    case 0: {west};
    case 1: {east};
    case 2: {independent};
    default {sideUnknown};
};
