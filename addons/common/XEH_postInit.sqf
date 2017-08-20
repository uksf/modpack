#include "script_component.hpp"

// Delete groups every 5 minutes
[{
    {deleteGroup _x; false} count allGroups;
}, 300, []] call cba_fnc_addPerFrameHandler;

// Set headless client array. Player if singleplayer
GVAR(HCs) = [];
if (isMultiplayer && !is3DENMultiplayer) then {
    GVAR(HCs) = (entities "HeadlessClient_F");
} else {
    GVAR(HCs) pushBack player;
};

// Ensure rating never goes below 0.
player addEventHandler ["HandleRating", {
    if (rating (_this select 0) < 0) then {
        abs (rating (_this select 0));
    };
}];
