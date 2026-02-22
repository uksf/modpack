#include "script_component.hpp"

if (isServer) then {
    [QEGVAR(zeus,registerVisualiseProvider), ["aicommander_ground", {call FUNC(getVisualisationData)}]] call CBA_fnc_localEvent;
};
