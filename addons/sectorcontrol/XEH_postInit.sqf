#include "script_component.hpp"

if (isServer) then {
    [QEGVAR(zeus,registerVisualiseProvider), ["sectorcontrol", {call FUNC(getVisualisationData)}]] call CBA_fnc_localEvent;
};
